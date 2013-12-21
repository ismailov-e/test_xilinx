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

#include "vbw_mtx_mm_t.h"

/** VBX matrix multiply.
 * @todo See if double buffering helps
 * N must be power of 2
 * Needs matrix B transposed already
 *
 * @param[in] in.
 * @param[out] out.
 * @param[in] N.
 */
int VBX_T(vbw_mtx_mmt)( vbx_mm_t *out, vbx_mm_t *in1, vbx_mm_t *in2, int N )
{
	int bs,tile_height,tile_width;
	int l,k,j,i;

	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();

	bs = 0;
	for(i = 0; i < 32; i++){
		if((this_mxp->scratchpad_size/(4*sizeof(vbx_sp_t))) & (1<<i)){
			bs = i;
		}
	}
	tile_height = bs>>1;
	tile_width  = bs-(bs>>1);
	tile_height = 1<<tile_height;
	tile_width = 1<<tile_width;
	if(tile_height > N){
		tile_height = N;
	}
	if(tile_width > N){
		tile_width = N;
	}
#ifdef SIMPLE_INIT
	tile_height = 8;
	tile_width  = 8;
#endif

	bs = tile_height*tile_width;

	vbx_sp_t *v_in1      = (vbx_sp_t *)vbx_sp_malloc(tile_height*tile_width*sizeof(vbx_sp_t));
	vbx_sp_t *v_in2      = (vbx_sp_t *)vbx_sp_malloc(tile_height*tile_width*sizeof(vbx_sp_t));
	vbx_sp_t *v_out      = (vbx_sp_t *)vbx_sp_malloc(tile_height*tile_height*sizeof(vbx_sp_t));
	vbx_sp_t *v_out_temp = (vbx_sp_t *)vbx_sp_malloc(tile_height*tile_height*sizeof(vbx_sp_t));

	vbx_set_2D(tile_height,tile_height*sizeof(vbx_sp_t),tile_width*sizeof(vbx_sp_t),0);

	for(l = 0; l < N; l += tile_height){
		for(k = 0; k < N; k += tile_height){

			//FIRST, work in v_out directly
			i = 0;
			//Copy in1 block
			//Copy in2 block
			for(j = 0; j < tile_height; j++){
				vbx_dma_to_vector(v_in1+(j*tile_width),in1+((l+j)*N)+i,tile_width*sizeof(vbx_mm_t));
			}

			vbx_set_vl(tile_width);
			vbx_dma_to_vector(v_in2,in2+(k*N)+i,tile_width*sizeof(vbx_mm_t));
			for(j = 0; j < tile_height-1; j++){
				vbx_dma_to_vector(v_in2+((j+1)*tile_width),in2+((k+(j+1))*N)+i,tile_width*sizeof(vbx_mm_t));
				//Multiply-accum in1 by in2[j] into v_out
				vbx_acc_2D(VV(T), VMULLO,v_out+j,v_in1,v_in2+(j*tile_width));
			}
			vbx_acc_2D(VV(T), VMULLO,v_out+(tile_height-1),v_in1,v_in2+((tile_height-1)*tile_width));

			//REST, work in v_out_temp, add to v_out
			for(i = tile_width; i < N; i += tile_width){
				//Copy in1 block
				//Copy in2 block
				for(j = 0; j < tile_height; j++){
					vbx_dma_to_vector(v_in1+(j*tile_width),in1+((l+j)*N)+i,tile_width*sizeof(vbx_mm_t));
				}

				vbx_set_vl(tile_width);
				vbx_dma_to_vector(v_in2,in2+(k*N)+i,tile_width*sizeof(vbx_mm_t));
				for(j = 0; j < tile_height-1; j++){
					vbx_dma_to_vector(v_in2+((j+1)*tile_width),in2+((k+(j+1))*N)+i,tile_width*sizeof(vbx_mm_t));
					//Multiply-accum in1 by in2[j] into v_out_temp
					vbx_acc_2D(VV(T), VMULLO,v_out_temp+j,v_in1,v_in2+(j*tile_width));
				}
				vbx_acc_2D(VV(T), VMULLO,v_out_temp+(tile_height-1),v_in1,v_in2+((tile_height-1)*tile_width));

				//Add v_out_temp to v_out
				vbx_set_vl(tile_height*tile_height);
				vbx(VV(T), VADD,v_out,v_out,v_out_temp);
			}

			//Copy v_out to host
			for(j = 0; j < tile_height; j++){
				vbx_dma_to_host(out+((l+j)*N)+k,v_out+(j*tile_height),tile_height*sizeof(vbx_mm_t));
			}
		}
	}

	vbx_sp_free();
	vbx_sync();

	return bs;
}

#endif // properly defined VBX_TEMPLATE_T
#endif // defined(VBX_TEMPLATE_T)
