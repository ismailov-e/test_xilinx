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

#include "vbw_vec_copy_t.h"


/** Copies a vector of words *in the scratchpad*. 
 * The function properly handles overlapping source and destination addresses.
 *
 * @param[out] v_dst *in scratch*.
 * @param[in] v_src *in scratch*.
 * @param[in] N is number of words to reverse.
 */ 
void VBX_T(vbw_vec_copy)( vbx_sp_t *v_dst, vbx_sp_t *v_src, const int N, const int pipeline_depth)
{
	// if copying backwards, no problem
	int save_vl;
	vbx_get_vl( &save_vl );

	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();

	int WB = this_mxp->vector_lanes*sizeof(int); // VBX_WIDTH_BYTES;
	int overlap = 0, overlap_within_pipe = 0;

	if( v_src < v_dst  &&  v_dst < v_src+N ) {
		overlap = 1;
		if( (v_dst-v_src) < WB * pipeline_depth )  {
        //TODO test if sizeof needed. ie: if( (v_dst-v_src) < (WB*sizeof(vbx_sp_t) * pipeline_depth ))  {
			overlap_within_pipe = 1;
		}
	}

	if( !overlap ) {
		// straight-forward copy, no hazards
		vbx_set_vl( N );
		vbx( VV(T), VMOV, v_dst, v_src, 0 );

	} else if( overlap_within_pipe ) {
		// copy, but rely upon latency of pipeline to avoid hazard.
		vbx_set_vl( N );
		// note: a prior DMA in overlap with v_dst may cause VMOV
		// to stutter, potentially stalling a successive read before
		// an earlier write to v_dst completes. to avoid this, ensure
		// all prior DMA are all finished before issuing the VMOV
		vbx_sync();
		vbx( VV(T), VMOV, v_dst, v_src, 0 );

	} else /* overlap = 1 */ {
		// copy forwards, but start at the tail to
		// avoid the hazard. a 2D VMOV is done to
		// move W words at a time.
		int NROWS = N / WB;
		int ROWS, ID, IA, IB;
		vbx_get_2D( &ROWS, &ID, &IA, &IB );
		vbx_set_vl( WB );
		vbx_set_2D( NROWS, -WB*sizeof(vbx_sp_t), -WB*sizeof(vbx_sp_t), 0 );
		vbx_2D( VV(T), VMOV, v_dst+N-WB, v_src+N-WB, 0 );
		vbx_set_2D( ROWS, ID, IA, IB );
		// the 2D move copies a rectangle W * NROWS.
		// copy any last residual amount at the head.
		vbx_set_vl( N - NROWS*WB );
		vbx( VV(T), VMOV, v_dst, v_src, 0 );
	}

	vbx_set_vl( save_vl );
}

#endif // properly defined VBX_TEMPLATE_T
#endif // defined(VBX_TEMPLATE_T)
