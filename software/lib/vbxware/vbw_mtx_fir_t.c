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

#include "vbw_mtx_fir_t.h"


/** Transposed 2D FIR filter using vector processor.
 *  FIXME Does not actually use internal width
 *  Vector version, transposed.  Uses the vbx length to scan over the
 *  entire sample for each coefficient, as this allows for longer vbx
 *  lengths than multiplying and using the built in accumulators
 *
 * @param[in] input.
 * @param[out] output.
 * @param[in] coeffs.
 * @param[in] num_row.
 * @param[in] num_column.
 * @param[in] ntaps_row.
 * @param[in] ntaps_column.
 */
void VBX_T(vbw_mtx_2Dfir_transpose)(vbx_mm_t *output, vbx_mm_t *input, int32_t *coeffs, const int num_row, const int num_column, const int ntaps_row, const int ntaps_column )
{
	int l,j,i,modj;

	vbx_sp_t *sample    = (vbx_sp_t    *)vbx_sp_malloc( num_column*ntaps_row*sizeof(vbx_sp_t) );
	vbx_sp_t *accum   = (vbx_sp_t    *)vbx_sp_malloc( num_column*sizeof(vbx_sp_t)    );
#if (VBX_TEMPLATE_T==VBX_BYTESIZE_DEF || VBX_TEMPLATE_T==VBX_HALFSIZE_DEF || VBX_TEMPLATE_T==VBX_WORDSIZE_DEF)
	vbx_word_t *accum_int = (vbx_word_t *)vbx_sp_malloc( num_column*sizeof(vbx_word_t ) );
	vbx_word_t *mult_int  = (vbx_word_t *)vbx_sp_malloc( num_column*sizeof(vbx_word_t) );
#else
	vbx_uword_t *accum_int = (vbx_uword_t *)vbx_sp_malloc( num_column*sizeof(vbx_uword_t ) );
	vbx_uword_t *mult_int  = (vbx_uword_t *)vbx_sp_malloc( num_column*sizeof(vbx_uword_t) );
#endif

	vbx_set_vl(num_column);
	for( j = 0; j < ntaps_row; j++ ) {
		vbx_dma_to_vector( sample+(j*num_column), input+j*num_column, num_column*sizeof(vbx_sp_t) );
	}

	modj = 0;

	for( l = 0; l < num_row-ntaps_row; l++ ) {

		vbx( SV(TW), VMULLO, accum_int, coeffs[0], sample+modj*num_column );

		for( i = 1; i < ntaps_column; i++ ) {
			vbx( SV(TW), VMULLO, mult_int, coeffs[i], sample+modj*num_column+i );
			vbx( VV(W), VADD, accum_int, accum_int, mult_int );
		}
		modj++;
		if(modj == ntaps_row)modj = 0;

		for( j = 1; j < ntaps_row; j++ ) {
			for( i = 0; i < ntaps_column; i++ ) {
				vbx( SV(TW), VMULLO,  mult_int, coeffs[j*ntaps_column+i], sample+modj*num_column+i );
				vbx(  VV(W), VADD,   accum_int, accum_int, mult_int );
			}
			modj++;
			if( modj == ntaps_row ) modj = 0;
		}

		//vbx( VV(IT), VMOV, accum, ((vbx_sp_t *)accum_int)+1, 0);
		vbx( SV(WT), VSHR, accum, 8, accum_int);

		vbx_dma_to_host( output+l*num_column, accum, num_column*sizeof(vbx_sp_t) );

		vbx_dma_to_vector( sample+(modj*num_column), input+(l+ntaps_row)*num_column, num_column*sizeof(vbx_sp_t) );
		modj++;
		if( modj == ntaps_row ) modj = 0;
	}

	vbx_sync();
	vbx_sp_free();
}

#endif // properly defined VBX_TEMPLATE_T
#endif // defined(VBX_TEMPLATE_T)
