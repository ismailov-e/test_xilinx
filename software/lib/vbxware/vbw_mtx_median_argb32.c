/* VECTORBLOX MXP SOFTWARE DEVELOPMENT KIT
 *
 * Copyright (C) 2012-2014 VectorBlox Computing Inc., Vancouver, British Columbia, Canada.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 *     * Neither the name of VectorBlox Computing Inc. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * This agreement shall be governed in all respects by the laws of the Province
 * of British Columbia and by the laws of Canada.
 *
 * This file is part of the VectorBlox MXP Software Development Kit.
 *
 */

/**@file*/
#include "vbx_copyright.h"
VBXCOPYRIGHT(vbw_mtx_median_argb32)

#include "vbx.h"
#include "vbw_mtx_median_argb32.h"

/** VBX median filter using bubble sort.
 * Does essentially the same thing as the scalar median,
 * but on a vbx worth of pixels at a time
 *
 * @param[in] input.
 */

void vbw_mtx_median_argb32(unsigned *input, const short filter_height, const short filter_width, const short image_height, const short image_width, const short image_pitch)
{
	int l,k;
	int filter_mid, filter_size;
	int rows_per_l,vl,temp_vl, temp_vl_byte;
	int j,i;

	filter_size = filter_height*filter_width;
	filter_mid = filter_size/2;

	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	const int VBX_WIDTH_BYTES = this_mxp->vector_lanes * sizeof(int);
	const int VBX_DMA_ALIGN   = this_mxp->dma_alignment_bytes;

	vl = this_mxp->scratchpad_size/((filter_size+2)*sizeof(vbx_uword_t));
	vl = VBX_PAD_UP(vl,VBX_DMA_ALIGN) - (VBX_WIDTH_BYTES/sizeof(vbx_uword_t));

	if(vl < image_width){
		rows_per_l = 1;
	}
	else {
		rows_per_l = vl/image_width;
		vl = image_width*rows_per_l;
	}

	vbx_uword_t *v_input = (vbx_uword_t *)vbx_sp_malloc(filter_size*vl*sizeof(vbx_uword_t));
	vbx_ubyte_t *v_sub   = (vbx_ubyte_t *)vbx_sp_malloc(vl*sizeof(vbx_uword_t));
	vbx_ubyte_t *v_temp  = (vbx_ubyte_t *)vbx_sp_malloc(vl*sizeof(vbx_uword_t));
	vbx_ubyte_t *v_min, *v_max;
	vbx_ubyte_t *v_input_byte = (vbx_ubyte_t *)v_input; 

	for(l = 0; l < image_height-filter_height; l+= rows_per_l){
		if(l+rows_per_l > image_height-filter_height){
			rows_per_l = (image_height-filter_height)-l;
			vl = image_width*rows_per_l;
		}
		temp_vl = vl;
		for(k = 0; k < image_width; k += temp_vl){
			if(rows_per_l == 1){
				if(k + temp_vl > image_width){
					temp_vl = image_width - k;
				}
			}

			for(j = 0; j < filter_height; j++){
				vbx_dma_to_vector_2D(v_input+temp_vl*j,
									 input+(l+j)*image_pitch+k,
									 temp_vl/rows_per_l*sizeof(vbx_uword_t),
									 rows_per_l,
									 image_width*sizeof(vbx_uword_t),
									 image_pitch*sizeof(vbx_uword_t));
			}

			// arrange all pixels within a filter window into single columns, seperated by temp_vl 
			//
			// ex. vl = 5, filter = 3
			// vinput before         vinput after
			//
			// a00 a01 a02 a03 a04 | a00 a01 a02 a03 a04 |  
			// a10 a11 a12 a13 a14 | a10 a11 a12 a13 a14 |  
			// a20 a21 a22 a23 a24 | a20 a21 a22 a23 a24 |  
			// ??? ??? ??? ??? ??? | a01 a02 a03 a04 a10 |  
			// ??? ??? ??? ??? ??? | a11 a12 a13 a14 a20 |  
			// ??? ??? ??? ??? ??? | a21 a22 a23 a24 a30 |  
			// ??? ??? ??? ??? ??? | a02 a03 a04 a10 a11 |  
			// ??? ??? ??? ??? ??? | a12 a13 a14 a20 a21 |  
			// ??? ??? ??? ??? ??? | a22 a23 a24 a30 a31 |  
			// 
			vbx_set_vl(temp_vl);
			for(j = 1; j < filter_height; j++){
				for(i = 0; i < filter_width; i++){
					vbx(VVWU, VMOV, v_input+(j*filter_height+i)*temp_vl,
									v_input+i*temp_vl+j,
									0);
				}
			}

			//Do the bubble sort up to the filter_size/2^th element on each vbx
			
			// work on individual color channels
			temp_vl_byte = temp_vl*sizeof(vbx_uword_t)/sizeof(vbx_ubyte_t);
			vbx_set_vl(temp_vl_byte);

			// sort lower half of the values in the window
			for(j = 0; j < filter_mid; j++){
				v_min = v_input_byte+j*temp_vl_byte;

				for(i = j+1; i < filter_size; i++){
					v_max = v_input_byte+i*temp_vl_byte;

					vbx(VVBU, VMOV,     v_temp, v_min,  0);
					vbx(VVBU, VSUB,     v_sub,  v_max,  v_min);
					vbx(VVBU, VCMV_LTZ, v_min,  v_max,  v_sub);
					vbx(VVBU, VCMV_LTZ, v_max,  v_temp, v_sub);
				}
			}

			// grab next smallest value, the median, don't sort the rest
			v_min = v_input_byte+filter_mid*temp_vl_byte;
			for(i = filter_mid+1; i < filter_size; i++){
				v_max = v_input_byte+i*temp_vl_byte;

				vbx(VVBU, VSUB,     v_sub, v_max, v_min);
				vbx(VVBU, VCMV_LTZ, v_min, v_max, v_sub);
			}

			// dma out median value
			// back to pixels
			vbx_dma_to_host_2D(input+(l*image_pitch)+k,
							   v_input+temp_vl*filter_mid,
							   temp_vl/rows_per_l*sizeof(vbx_uword_t),
							   rows_per_l,
							   image_pitch*sizeof(vbx_uword_t),
							   image_width*sizeof(vbx_uword_t));
		}
	}

	vbx_sp_free();
	vbx_sync();
}
