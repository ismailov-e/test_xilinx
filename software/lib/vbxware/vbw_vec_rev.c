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
VBXCOPYRIGHT( vec_rev )

#include "vbw_vec_rev.h"

/** Reverses a vector of words allocated *in the scratchpad*.
 * ####Notes
 * + the input pointer can have any alignment
 * + any vector size is permitted (any value of N, including odd)
 * + the _starting_ address of the output result is always aligned
 *
 *  @param[in] v_src *in scratch*.
 *  @param[in] N is number of words to reverse.
 *  @retval returns callee-allocated pointer.
 */ 
vbx_word_t *vbw_vec_reverse_word( vbx_word_t *v_src, const int N )
{
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	const int VBX_WIDTH_BYTES = this_mxp->vector_lanes*sizeof(int);
	const int alignment = VBX_WIDTH_BYTES;

	vbx_word_t *v_src_start = (vbx_word_t*)VBX_PAD_DN( v_src,   alignment );
	vbx_word_t *v_src_end   = (vbx_word_t*)VBX_PAD_UP( v_src+N, alignment );
	int dst_bytes = (v_src_end - v_src_start) * sizeof(vbx_word_t);
	int bytes_needed = 3*dst_bytes;

	vbx_word_t *v_dst = NULL;

	// data must already be in the scratchpad
	//	if( !VBX_IS_VPTR(v_src) )
	//		return v_dst;

	// small cases (for speed: 2D move, 1 word/cycle)
	//  N < 650/(VBX_VECTOR_LANES/16)
	if( N < 1024 || this_mxp->vector_lanes < 16 || bytes_needed > vbx_sp_getfree() ) {
		if( N==0 ) return NULL;
		v_dst = vbx_sp_malloc( N*sizeof(vbx_word_t) );
		if( !v_dst ) VBX_EXIT(-1);
		vbw_vec_reverse_word_fast( v_dst, v_src, N );
		return v_dst;
	}

	// allocate the buffer we are going to return with the result
	// mark this spot in the scratchpad, so we can de-allocate back to this point
	v_dst = vbx_sp_malloc( dst_bytes );
	if( !v_dst ) VBX_EXIT(-1);

	vbx_sp_push();

	vbx_word_t *v_dst1 = v_dst;
	vbx_word_t *v_dst2 = vbx_sp_malloc( dst_bytes );
	if( !v_dst2 ) VBX_EXIT(-1);

	// copy src to dst1, reverse using chunks of 'alignment'
	int num_rows = VBX_PAD_UP(dst_bytes,alignment)/alignment;
	int tail_padding   = ( v_src_end - (v_src_start+N) ) * sizeof(vbx_word_t);

	if( this_mxp->vector_lanes == 1 ) {
		// V1 simple case
		// use a 2D move that reverses 'chunks' the same width as the vector engine
		// for a V1 architecture, this 2D move is sufficient to reverse the entire array
		vbx_set_vl( alignment/4 );
		vbx_set_2D( num_rows, -alignment, alignment, 0 );
		vbx_2D( VVW, VMOV, v_dst1+dst_bytes/4-alignment/4, v_src-tail_padding/4, 0 );
	} else {
		// should peel the do..while loop below by 1 iteration and move half the scratchpad width
		// but for now we'll just do the V1 simple case
		int W = alignment/4;
		vbx_set_vl( W/2 );

		vbx_set_2D( num_rows, -alignment, alignment, 0 );
		vbx_2D( VVW, VMOV, v_dst1+dst_bytes/4-W/2, v_src-tail_padding/4,   0 );

		vbx_set_2D( num_rows, -alignment, alignment, 0 );
		vbx_2D( VVW, VMOV, v_dst1+dst_bytes/4-W, v_src-tail_padding/4+W/2, 0 );
	}

	vbx_word_t *v_result = v_dst1;
	//N = dst_bytes / 4;
	int NN = dst_bytes / 4;

	// the first block of v_dst1 is packed full (taken from the tail of v_src)
	// the last block of v_dst1 is padded by amount 'tail_padding'
	int W = alignment/4;

	W = W/2;

	if( W > 1 ) {
		vbx_word_t *vmsk = vbx_sp_malloc( VBX_WIDTH_BYTES );
		if( !vmsk ) VBX_EXIT(-1);

		const int NUM_LANES = this_mxp->vector_lanes;
		vbx_set_vl( NUM_LANES );
		vbx_set_2D( NN/NUM_LANES, VBX_WIDTH_BYTES, VBX_WIDTH_BYTES, 0 );
		do {
			// set up odd/even mask register
			W = W >> 1;
			vbx( SEW, VAND, vmsk, W, 0 );
			vbx_2D( VVW, VCMV_Z, v_dst2+W, v_dst1,   vmsk );
			vbx_2D( VVW, VCMV_Z, v_dst2,   v_dst1+W, vmsk );
			v_result = v_dst2; // swap v_dst1, v_dst2
			v_dst2 = v_dst1;
			v_dst1 = v_result;
		} while( W > 1 );
	}

	// if an odd number of buffer swaps were done
	// move the final result back to v_dst
	if( v_result != v_dst ) {
		vbx_set_vl( NN );
		vbx( VVW, VMOV, v_dst, v_result, 0 );
	}

	vbx_sp_pop();
	return v_dst;
}

/** Reverses a vector of halfs allocated *in the scratchpad*.
 *
 * @param[in] v_src *in scratch*.
 * @param[in] N is number of halfs to reverse.
 * @retval returns callee-allocated pointer.
 */ 
vbx_half_t *vbw_vec_reverse_half( vbx_half_t *v_src, const int N )
{
	int isOdd = N&1;
	int NN = N/2 + isOdd;
	//vbx_word_t *vwsrc = (vbx_word_t*) ((int)v_src&(~1));
	vbx_half_t *v_dst = NULL;

	if( !(N&1) && VBX_IS_ALIGNED((int)v_src,4) && N < 4096  ) {
		// Fast case: N is even, v_src is word-aligned
		v_dst = (vbx_half_t *) vbx_sp_malloc( N*sizeof(vbx_half_t) );
		if( !v_dst ) VBX_EXIT(-1);
		vbw_vec_reverse_half_fast( v_dst, v_src, N );
		return v_dst;
	}

	// if v_src is unaligned, bring it back into alignment first
	if( VBX_IS_MISALIGNED((int)v_src,4) ) {
		v_dst = (vbx_half_t *) vbx_sp_malloc( N*sizeof(vbx_half_t) );
		if( !v_dst ) VBX_EXIT(-1);
		vbx_sp_push();
		vbx_set_vl( N );
		vbx( VVH, VMOV, v_dst, v_src, 0 );
		v_src = v_dst;
	}

	vbx_half_t *vh = (vbx_half_t *) vbw_vec_reverse_word( (vbx_word_t*)v_src, NN );
	if( !v_dst ) v_dst = vh;
	else vbx_sp_pop();

	vbx_set_vl( NN );
	vbx( SVWU, VROTL, (vbx_uword_t *)v_dst, 16, (vbx_uword_t *)vh );
	if( isOdd ) {
		vbx_set_vl( N );
		vbx( VVH, VMOV, v_dst, v_dst+1, 0 );
	}
	return v_dst;
}

/** Reverses a vector of bytes allocated *in the scratchpad*.
 *
 * @param[in] v_src *in scratch*.
 * @param[in] N is number of bytes to reverse.
 * @retval returns callee-allocated pointer.
 */ 
vbx_byte_t *vbw_vec_reverse_byte( vbx_byte_t *v_src, const int N )
{
	int isOdd = (N&3) ? 1 : 0;
	int NN = N/4 + isOdd;
	vbx_byte_t *v_dst = NULL;

	if( !(N&3) && VBX_IS_ALIGNED((int)v_src,4) && N < 16384 ) {
		// Fast case: N is even, v_src is word-aligned
		v_dst = (vbx_byte_t *) vbx_sp_malloc( N );
		if( !v_dst ) VBX_EXIT(-1);
		vbw_vec_reverse_byte_fast( v_dst, v_src, N );
		return v_dst;
	}

	// if v_src is unaligned, bring it back into alignment first
	if( VBX_IS_MISALIGNED((int)v_src,4) ) {
		v_dst = (vbx_byte_t *) vbx_sp_malloc( N );
		if( !v_dst ) VBX_EXIT(-1);
		vbx_sp_push();
		vbx_set_vl( N );
		vbx( VVB, VMOV, v_dst, v_src, 0 );
		v_src = v_dst;
	}

	vbx_byte_t *v_b = (vbx_byte_t *) vbw_vec_reverse_word( (vbx_word_t*)v_src, NN );
	if( !v_dst ) v_dst = v_b;
	else vbx_sp_pop();

	vbx_set_vl( NN );
	vbx( SVWU, VROTL, (vbx_uword_t *)v_dst, 16, (vbx_uword_t *)v_b );

	vbx_set_vl( N/2+isOdd*2 );
	vbx( SVHU, VROTL, (vbx_uhalf_t *)v_dst, 8, (vbx_uhalf_t *)v_dst );

	if( isOdd ) {
		vbx_set_vl( N );
		vbx( VVB, VMOV, v_dst, v_dst+(4-(N&3)), 0 );
	}

	return v_dst;
}

