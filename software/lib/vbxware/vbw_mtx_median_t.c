/* VECTORBLOX MXP SOFTWARE DEVELOPMENT KIT
 *
 * Copyright (C) 2012-2013 VectorBlox Computing Inc., Vancouver, British Columbia, Canada.
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

// This is a templated file.
// Do not include a copyright header function.

// This file is meant to be #included in another .c file
// Do not define VBX_TEMPLATE_T locally in this file.
// Only define it externally in the file that includes
// this file.

// Protect this file from inclusion if VBX_TEMPLATE_T is not properly defined.
#ifdef VBX_TEMPLATE_T
#if (VBX_TEMPLATE_T==VBX_BYTESIZE_DEF  || \
		VBX_TEMPLATE_T==VBX_HALFSIZE_DEF  || \
		VBX_TEMPLATE_T==VBX_WORDSIZE_DEF  || \
		VBX_TEMPLATE_T==VBX_UBYTESIZE_DEF || \
		VBX_TEMPLATE_T==VBX_UHALFSIZE_DEF || \
		VBX_TEMPLATE_T==VBX_UWORDSIZE_DEF )

#include "vbw_mtx_median_t.h"


/** VBX median filter using bubble sort.
 * Does essentially the same thing as the scalar median,
 * but on a vbx worth of pixels at a time
 *
 * @param[in] input.
 * @param[out] output.
 */
void VBX_T(vbw_mtx_median)(vbx_mm_t *output, vbx_mm_t *input, const int filter_size, const int filter_height, const int filter_width, const int image_height, const int image_width)
{
	int l,k;
	int filter_mid;
	int rows_per_l,vl,temp_vl;
	int j,i;

	filter_mid = filter_size/2;

	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	const int VBX_WIDTH_BYTES = this_mxp->vector_lanes * sizeof(int);
	const int VBX_DMA_ALIGN   = this_mxp->dma_alignment_bytes;

	vl = this_mxp->scratchpad_size/((filter_size+2)*sizeof(vbx_sp_t));
	vl = VBX_PAD_UP(vl,VBX_DMA_ALIGN) - (VBX_WIDTH_BYTES/sizeof(vbx_sp_t));

	if(vl < image_width){
		rows_per_l = 1;
	}
	else {
		rows_per_l = vl/image_width;
		vl = image_width*rows_per_l;
	}

	vbx_sp_t *v_input = (vbx_sp_t *)vbx_sp_malloc(filter_size*vl*sizeof(vbx_sp_t));
	vbx_sp_t *v_sub   = (vbx_sp_t *)vbx_sp_malloc(vl*sizeof(vbx_sp_t));
	vbx_sp_t *v_temp  = (vbx_sp_t *)vbx_sp_malloc(vl*sizeof(vbx_sp_t));
	vbx_sp_t *v_min,*v_max;

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
				vbx_dma_to_vector(v_input+temp_vl*j,input+(l+j)*image_width+k,temp_vl*sizeof(vbx_mm_t));
			}
			vbx_set_vl(temp_vl);

			for(j = 1; j < filter_height; j++){
				for(i = 0; i < filter_width; i++){
					vbx(VV(T),VOR,v_input+(j*filter_height+i)*temp_vl,v_input+i*temp_vl+j,v_input+i*temp_vl+j);
				}
			}

			//Do the bubble sort up to the filter_size/2^th element on each vbx
			for(j = 0; j < filter_mid; j++){
				v_min = v_input+j*temp_vl;

				for(i = j+1; i < filter_size; i++){
					v_max = v_input+i*temp_vl;

					vbx(VV(T),VOR,v_temp,v_min,v_min);
					vbx(VV(T),VSUB,v_sub,v_max,v_min);
					vbx(VV(T),VCMV_LTZ,v_min,v_max,v_sub);
					vbx(VV(T),VCMV_LTZ,v_max,v_temp,v_sub);
				}
			}

			v_min = v_input+filter_mid*temp_vl;
			for(i = filter_mid+1; i < filter_size; i++){
				v_max = v_input+i*temp_vl;
				vbx(VV(T),VSUB,v_sub,v_max,v_min);
				vbx(VV(T),VCMV_LTZ,v_min,v_max,v_sub);
			}


			vbx_dma_to_host(output+(l*image_width)+k,v_input+temp_vl*filter_mid,temp_vl*sizeof(vbx_mm_t));
		}
	}

	vbx_sp_free();
	vbx_sync();
}

#endif // properly defined VBX_TEMPLATE_T
#endif // defined(VBX_TEMPLATE_T)
