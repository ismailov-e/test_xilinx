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

#include "vbw_vec_fir_t.h"


/** 1D Fir Filter.
 *
 *  @param[in] input.
 *  @param[out] output.
 *  @param[in] coeffs.
 *  @param[in] sample_size.
 *  @param[in] num_taps.
 */
void VBX_T(vbw_vec_fir_1d)(vbx_mm_t *output, vbx_mm_t *input, vbx_mm_t *coeffs, const int sample_size, const int num_taps)
{

	int chunk_size_old, chunk_size, chunk_size_new, chunk_start_old, chunk_start, chunk_start_new;
	int j;

	vbx_set_vl(num_taps);

	vbx_mm_t *coeffs_shared = vbx_shared_malloc( num_taps*sizeof(vbx_mm_t) );
	for( j = 0; j < num_taps; j++ ) {
		coeffs_shared[j] = coeffs[j];
	}

	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	const int VBX_WIDTH_BYTES = this_mxp->vector_lanes * sizeof(int);
	const int align = this_mxp->dma_alignment_bytes;

	chunk_size_old = (this_mxp->scratchpad_size-(5*num_taps*sizeof(vbx_mm_t)))/(2*sizeof(vbx_mm_t)+2*sizeof(vbx_mm_t));
	chunk_size_old = VBX_PAD_UP(chunk_size_old-2*VBX_WIDTH_BYTES+1, align);

	vbx_sp_t *v_coeffs = (vbx_sp_t *)vbx_sp_malloc(num_taps*sizeof(vbx_sp_t));
	vbx_sp_t *v_sample_a = (vbx_sp_t *)vbx_sp_malloc((chunk_size_old+num_taps)*sizeof(vbx_sp_t));
	vbx_sp_t *v_sample_b = (vbx_sp_t *)vbx_sp_malloc((chunk_size_old+num_taps)*sizeof(vbx_sp_t));
	vbx_sp_t *v_output_a = (vbx_sp_t *)vbx_sp_malloc((chunk_size_old+num_taps)*sizeof(vbx_sp_t));
	vbx_sp_t *v_output_b = (vbx_sp_t *)vbx_sp_malloc((chunk_size_old+num_taps)*sizeof(vbx_sp_t));
	vbx_sp_t  *v_sample_to_vpu,*v_sample_on_vpu;
	vbx_sp_t *v_output_to_host;

	if( v_output_b == NULL ) {
		printf("Failed malloc!\n");
		VBX_EXIT(0xBADDEAD);
	}

	vbx_dma_to_vector(v_coeffs, coeffs_shared, num_taps*sizeof(vbx_sp_t));

	v_sample_to_vpu = v_sample_a;
	v_sample_on_vpu = v_sample_b;
	v_output_to_host = v_output_a;

	chunk_start_old = 0;
	chunk_size_old  = (chunk_start_old+chunk_size_old > sample_size) ? (sample_size-chunk_start_old) : chunk_size_old;

	//Transfer input to vbx local memory
	vbx_dma_to_vector(v_sample_to_vpu, input+chunk_start_old, (chunk_size_old+num_taps)*sizeof(vbx_sp_t));

	v_sample_to_vpu = (v_sample_to_vpu == v_sample_a) ? v_sample_b : v_sample_a;
	v_sample_on_vpu = (v_sample_on_vpu == v_sample_a) ? v_sample_b : v_sample_a;

	chunk_start = chunk_start_old+chunk_size_old;
	chunk_size  = (chunk_start+chunk_size_old > sample_size) ? (sample_size-chunk_start) : chunk_size_old;

	if( chunk_start < sample_size ) {
		//Transfer input to vbx local memory
		vbx_dma_to_vector(v_sample_to_vpu, input+chunk_start, (chunk_size+num_taps)*sizeof(vbx_sp_t));
	}

	while(chunk_start_old < sample_size) {
		//process here
		for( j = 0; j < chunk_size_old; j++ ) {
			vbx_acc(VV(T), VMULLO, v_output_to_host+j, v_coeffs, v_sample_on_vpu+j);
		}

		// Wait for completion of the transfer to vbx mem
		v_sample_to_vpu = (v_sample_to_vpu == v_sample_a) ? v_sample_b : v_sample_a;
		v_sample_on_vpu = (v_sample_on_vpu == v_sample_a) ? v_sample_b : v_sample_a;

		chunk_start_new = chunk_start+chunk_size;
		chunk_size_new = (chunk_start_new+chunk_size > sample_size) ? (sample_size-chunk_start_new) : chunk_size;

		vbx_dma_to_host(output+chunk_start_old, v_output_to_host, chunk_size_old*sizeof(vbx_sp_t));

		v_output_to_host = (v_output_to_host == v_output_a) ? v_output_b : v_output_a;

		if( chunk_start_new < sample_size ) {
			//Transfer input to vbx local memory
			vbx_dma_to_vector(v_sample_to_vpu, input+chunk_start_new, (chunk_size_new+num_taps)*sizeof(vbx_sp_t) );
		}

		chunk_size_old  = chunk_size;
		chunk_start_old = chunk_start;
		chunk_size      = chunk_size_new;
		chunk_start     = chunk_start_new;
	}

	vbx_sp_free();
	vbx_sync();
}

/** 2D Fir Filter.
 *
 *  @param[in] input.
 *  @param[out] output.
 *  @param[in] coeffs.
 *  @param[in] sample_size.
 *  @param[in] num_taps.
 */
void VBX_T(vbw_vec_fir_2d)(vbx_mm_t *output, vbx_mm_t *input, vbx_mm_t *coeffs, const int sample_size, const int num_taps)
{

	int chunk_size_old,chunk_size,chunk_size_new,chunk_start_old,chunk_start,chunk_start_new;
	int j;

	vbx_set_vl(num_taps);

	vbx_mm_t *coeffs_shared = vbx_shared_malloc(num_taps*sizeof(vbx_sp_t));
	for( j = 0; j < num_taps; j++ ) {
		coeffs_shared[j] = coeffs[j];
	}

	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	const int VBX_WIDTH_BYTES = this_mxp->vector_lanes * sizeof(int);
	const int align = this_mxp->dma_alignment_bytes;

	chunk_size_old = (this_mxp->scratchpad_size-(2*(sizeof(vbx_uword_t)-sizeof(vbx_sp_t)))-(5*num_taps*sizeof(vbx_sp_t)))/(2*sizeof(vbx_sp_t)+2*sizeof(vbx_sp_t));
	chunk_size_old = VBX_PAD_UP(chunk_size_old-2*VBX_WIDTH_BYTES+1, align);

	vbx_sp_t *v_coeffs = (vbx_sp_t *)vbx_sp_malloc(num_taps*sizeof(vbx_sp_t));
	vbx_sp_t *v_sample_a = (vbx_sp_t *)vbx_sp_malloc((chunk_size_old+num_taps)*sizeof(vbx_sp_t));
	vbx_sp_t *v_sample_b = (vbx_sp_t *)vbx_sp_malloc((chunk_size_old+num_taps)*sizeof(vbx_sp_t));
	vbx_sp_t *output_a = (vbx_sp_t *)vbx_sp_malloc((chunk_size_old+num_taps)*sizeof(vbx_sp_t)+(sizeof(vbx_uword_t)-sizeof(vbx_sp_t)));
	vbx_sp_t *output_b = (vbx_sp_t *)vbx_sp_malloc((chunk_size_old+num_taps)*sizeof(vbx_sp_t)+(sizeof(vbx_uword_t)-sizeof(vbx_sp_t)));
	vbx_sp_t  *v_sample_to_vpu, *v_sample_on_vpu;
	vbx_sp_t *v_output_to_host;

	if( output_b == NULL ) {
		printf("Failed malloc!\n");
		VBX_EXIT(0xBADDEAD);
	}

	vbx_dma_to_vector(v_coeffs, coeffs_shared, num_taps*sizeof(vbx_sp_t));

	v_sample_to_vpu = v_sample_a;
	v_sample_on_vpu = v_sample_b;
	v_output_to_host = output_a;

	chunk_start_old = 0;
	chunk_size_old  = (chunk_start_old+chunk_size_old > sample_size) ? (sample_size-chunk_start_old) : chunk_size_old;

	//Transfer input to vbx local memory
	vbx_dma_to_vector(v_sample_to_vpu, input+chunk_start_old, (chunk_size_old+num_taps)*sizeof(vbx_sp_t));

	v_sample_to_vpu = (v_sample_to_vpu == v_sample_a) ? v_sample_b : v_sample_a;
	v_sample_on_vpu = (v_sample_on_vpu == v_sample_a) ? v_sample_b : v_sample_a;

	chunk_start = chunk_start_old+chunk_size_old;
	chunk_size  = (chunk_start+chunk_size_old > sample_size) ? (sample_size-chunk_start) : chunk_size_old;

	if( chunk_start < sample_size ) {
		//Transfer input to vbx local memory
		vbx_dma_to_vector(v_sample_to_vpu, input+chunk_start, (chunk_size+num_taps)*sizeof(vbx_sp_t));
	}

	while( chunk_start_old < sample_size ) {
		//process here
		vbx_set_2D(chunk_size_old, sizeof(vbx_sp_t), 0, sizeof(vbx_sp_t));
		vbx_acc_2D(VV(T), VMULLO, v_output_to_host, v_coeffs, v_sample_on_vpu);

		// Wait for completion of the transfer to vbx mem
		v_sample_to_vpu = (v_sample_to_vpu == v_sample_a) ? v_sample_b : v_sample_a;
		v_sample_on_vpu = (v_sample_on_vpu == v_sample_a) ? v_sample_b : v_sample_a;

		chunk_start_new = chunk_start+chunk_size;
		chunk_size_new = (chunk_start_new+chunk_size > sample_size) ? (sample_size-chunk_start_new) : chunk_size;

		vbx_dma_to_host(output+chunk_start_old, v_output_to_host, chunk_size_old*sizeof(vbx_sp_t));

		v_output_to_host = (v_output_to_host == output_a) ? output_b : output_a;

		if( chunk_start_new < sample_size ) {
			//Transfer input to vbx local memory
			vbx_dma_to_vector(v_sample_to_vpu, input+chunk_start_new, (chunk_size_new+num_taps)*sizeof(vbx_sp_t) );
		}

		chunk_size_old  = chunk_size;
		chunk_start_old = chunk_start;
		chunk_size      = chunk_size_new;
		chunk_start     = chunk_start_new;
	}

	vbx_sp_free();
	vbx_sync();
}


/** VBX 1D Transposed Fir Filter.
 * Uses the vbx length to scan over the
 * entire sample for each coefficient, as this allows for longer vbx
 * lengths than multiplying and using the built in accumulators
 *
 *  @param[in] input.
 *  @param[out] output.
 *  @param[in] coeffs.
 *  @param[in] sample_size.
 *  @param[in] num_taps.
 */
void VBX_T(vbw_vec_fir_transpose)(vbx_mm_t *output, vbx_mm_t *input, vbx_mm_t *coeffs, const int sample_size, const int num_taps)
{
	int chunk_size_old,chunk_size,chunk_size_new,chunk_start_old,chunk_start,chunk_start_new;
	int j;


	//Set up vbx increments... Used to 'shift' vbxs as part of the FIR
	//5 vbxs size chunk_size+scratchpad+padding, round to 1/8th vbx memory
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	chunk_size_old = (this_mxp->scratchpad_size >> 3)/sizeof(vbx_sp_t);

	vbx_sp_t *v_sample_a  = (vbx_sp_t  *)vbx_sp_malloc((         chunk_size_old+num_taps)*sizeof(vbx_sp_t));
	vbx_sp_t *v_sample_b  = (vbx_sp_t  *)vbx_sp_malloc((         chunk_size_old+num_taps)*sizeof(vbx_sp_t));
	vbx_sp_t *mult      = (vbx_sp_t *)vbx_sp_malloc((         chunk_size_old+num_taps)*sizeof(vbx_sp_t));
    vbx_sp_t *v_dest_a    = (vbx_sp_t *)vbx_sp_malloc((num_taps+chunk_size_old+num_taps)*sizeof(vbx_sp_t));
    vbx_sp_t *v_dest_b    = (vbx_sp_t *)vbx_sp_malloc((num_taps+chunk_size_old+num_taps)*sizeof(vbx_sp_t));
	vbx_sp_t *v_sample_to_vpu,*v_sample_on_vpu;
	vbx_sp_t *v_dest_on_vpu,*v_dest_from_vpu;
	vbx_sp_t *v_temp_dest;

	if( v_dest_b == NULL ) {
		printf("Failed malloc!\n");
		VBX_EXIT(0xBADDEAD);
	}

	//There is padding before and after the actual dest for the edges of the convolution
	v_dest_a += num_taps;
	v_dest_b += num_taps;

	v_sample_to_vpu = v_sample_a;
	v_sample_on_vpu = v_sample_b;
	v_dest_on_vpu   = v_dest_a;
	v_dest_from_vpu = v_dest_b;

	chunk_start_old = 0;
	chunk_size_old  = (chunk_start_old+chunk_size_old > sample_size) ? (sample_size-chunk_start_old) : chunk_size_old;

	//Transfer input to vbx local memory
	vbx_dma_to_vector(v_sample_to_vpu, input+chunk_start_old, (chunk_size_old+num_taps)*sizeof(vbx_sp_t));

	v_sample_to_vpu = (v_sample_to_vpu == v_sample_a) ? v_sample_b : v_sample_a;
	v_sample_on_vpu = (v_sample_on_vpu == v_sample_a) ? v_sample_b : v_sample_a;

	chunk_start = chunk_start_old+chunk_size_old;
	chunk_size  = (chunk_start+chunk_size_old > sample_size) ? (sample_size-chunk_start) : chunk_size_old;


	//input:   a  b  c  d  e  f  g  h  i  j  k   l  m  n  o  p  q  r  s  t
	//coeff:   1  2  3  4
	//coeff:      1  2  3  4
	//coeff:         1  2  3  4
	//coeff:            1  2  3  4
	//coeff:               1  2  3  4
	//
	//      a1b2c3d4 b1c2d3e4 ...


	if(chunk_start < sample_size){
		//Transfer input to vbx local memory
		vbx_dma_to_vector(v_sample_to_vpu, input+chunk_start, (chunk_size+num_taps)*sizeof(vbx_sp_t));
	}

	while( chunk_start_old < sample_size ) {
		//tap 0, special case
		//Use vmullou directly to begin the accumulation; this way the local vbx
		//memory doesn't have to be zeroe'd first
		v_temp_dest = v_dest_on_vpu;
		vbx_set_vl(chunk_size_old+num_taps);
		vbx(SV(T), VMULLO, v_temp_dest, coeffs[0], v_sample_on_vpu);

		//For each of the other taps, accumulate to a shifted place in the
		//destination
		for( j = 1; j < num_taps; j++ ) {
			v_temp_dest--;
			vbx(SV(T), VMULLO, mult,  coeffs[j], v_sample_on_vpu);
			vbx(VV(T), VADD, v_temp_dest, v_temp_dest, mult);
		}


		// Wait for completion of the transfer to vbx mem
		v_sample_to_vpu = (v_sample_to_vpu == v_sample_a) ? v_sample_b : v_sample_a;
		v_sample_on_vpu = (v_sample_on_vpu == v_sample_a) ? v_sample_b : v_sample_a;

		chunk_start_new = chunk_start+chunk_size;
		chunk_size_new = (chunk_start_new+chunk_size > sample_size) ? (sample_size-chunk_start_new) : chunk_size;

		vbx_dma_to_host(output+chunk_start_old, v_dest_on_vpu, chunk_size_old*sizeof(vbx_sp_t) );

		if( chunk_start_new < sample_size ) {
			//Transfer input to vbx local memory
			vbx_dma_to_vector(v_sample_to_vpu, input+chunk_start_new, (chunk_size_new+num_taps)*sizeof(vbx_sp_t) );
		}

		v_dest_on_vpu   = (v_dest_on_vpu   == v_dest_a) ? v_dest_b : v_dest_a;
		v_dest_from_vpu = (v_dest_from_vpu == v_dest_a) ? v_dest_b : v_dest_a;

		chunk_size_old  = chunk_size;
		chunk_start_old = chunk_start;
		chunk_size      = chunk_size_new;
		chunk_start     = chunk_start_new;
	}

	vbx_sp_free();
	vbx_sync();
}

#endif // properly defined VBX_TEMPLATE_T
#endif // defined(VBX_TEMPLATE_T)
