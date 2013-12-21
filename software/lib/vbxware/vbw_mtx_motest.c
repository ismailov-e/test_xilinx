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

#include "vbx_copyright.h"
VBXCOPYRIGHT( mtx_motest )

//
// Motion Estimation
// Scalar NIOS version and vbx VECTOR version
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "vbx.h"
#include "vbw_mtx_motest.h"


/**Scalar Motion Estimation.
 * Motion estimation.  Scan the block to be estimated over the image,
 * at each location calculating the SAD of the block and the reference image
 * @FIXME Using bytes as input data.
 *
 * @param[in] x.
 * @param[in] y.
 * @param[out] result.
 *
 * @todo move to scalar
 */
void vbw_mtx_motest_scalar_byte(output_type *result, input_type *x, input_type *y)
{
	int i, j, k, l;
	output_type answer;
	input_type *x_line;
	input_type *y_line;

	for( l=0; l<SEARCH_HEIGHT; l++ ) {
		for( k=0; k<SEARCH_WIDTH; k++ ) {
			answer = 0;
			for( j=0; j<BLOCK_HEIGHT; j++ ) {
				x_line = x + ( IMAGE_WIDTH*j );
				y_line = y + ( IMAGE_WIDTH*(l+j)+k );
				for( i=0; i<BLOCK_WIDTH; i++ ) {
					answer += abs( *(x_line++) - *(y_line++) );
				}
			}
			result[l*SEARCH_WIDTH+k] = answer;
		}
	}
}



// 2D and 3D
static input_type        *v_block   = NULL;
static input_type        *v_img     = NULL;
static intermediate_type *v_row_sad = NULL;
static output_type       *v_result  = NULL;

// 2D
static input_type *v_img_sub        = NULL;
static input_type *v_absdiff        = NULL;

//static int db = 0;

/** Setup function before running VBX Motion Estimation.
*/
int vbw_mtx_motest_byte_setup()
{
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	const int DMA_ALIGN = this_mxp->dma_alignment_bytes;

	int used_sub_block_width = VBX_PAD_UP( BLOCK_WIDTH+SEARCH_WIDTH, DMA_ALIGN );
	int sub_block_width      = VBX_PAD_UP( used_sub_block_width,     DMA_ALIGN );

	vbx_sp_push();

	// 2D and 3D
	v_block   = (input_type  *)vbx_sp_malloc(  BLOCK_HEIGHT               *sub_block_width*sizeof(input_type) );
	v_img     = (input_type  *)vbx_sp_malloc( (BLOCK_HEIGHT+SEARCH_HEIGHT)*sub_block_width*sizeof(input_type) );
	v_result  = (output_type *)vbx_sp_malloc( RESULT_SIZE );
	// 2D
#define USE_3D 0
	// USE_3D is slightly faster, but uses SEARCH_WIDTH times more scratchpad memory.
#if USE_3D
	//v_img_sub = (input_type  *)vbx_sp_malloc( (BLOCK_HEIGHT+SEARCH_HEIGHT)*sub_block_width*sizeof(input_type) * SEARCH_WIDTH );
	v_img_sub = (input_type  *)vbx_sp_malloc( (BLOCK_HEIGHT+SEARCH_HEIGHT)*    BLOCK_WIDTH*sizeof(input_type) * SEARCH_WIDTH );
#else
	//v_img_sub = (input_type  *)vbx_sp_malloc( (BLOCK_HEIGHT+SEARCH_HEIGHT)*sub_block_width*sizeof(input_type)                );
	v_img_sub = (input_type  *)vbx_sp_malloc( (BLOCK_HEIGHT+SEARCH_HEIGHT)*    BLOCK_WIDTH*sizeof(input_type)                );
#endif
	v_absdiff = (input_type  *)vbx_sp_malloc(  BLOCK_SIZE                                 *sizeof(input_type) );

	if( v_absdiff == NULL ) {
		vbx_sp_pop();
		VBX_PRINTF( "ERROR: out of memory\n" );
		return -1;
	}

	return 0;
}


/** VBX Motion Estimation.
 * Similar to the scalar version but scans
 * vertically as it makes it easier to align vectors.
 * Assumes that image width is a multiple of vbx_dma_alignment_bytes
 *
 * @param[in] x.
 * @param[in] y.
 * @param[out] result.
 */
int vbw_mtx_motest_byte(output_type *result, input_type *x, input_type *y)
{
	int  j;

	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	const int DMA_ALIGN = this_mxp->dma_alignment_bytes;

	int used_sub_block_width = VBX_PAD_UP( BLOCK_WIDTH+SEARCH_WIDTH, DMA_ALIGN );
	int sub_block_width      = VBX_PAD_UP( used_sub_block_width,     DMA_ALIGN );

#if 1
	for( j = 0; j < BLOCK_HEIGHT; j++ ) {
		vbx_dma_to_vector( v_block+j*sub_block_width, x+j*IMAGE_WIDTH, used_sub_block_width*sizeof(input_type) );
	}
#endif

#if 1
	for( j = 0; j < BLOCK_HEIGHT+SEARCH_HEIGHT; j++ ) {
		vbx_dma_to_vector( v_img  +j*sub_block_width, y+j*IMAGE_WIDTH, used_sub_block_width*sizeof(input_type) );
	}
#endif

#if 1
	// column-ize the reference block
	vbx_set_vl( BLOCK_WIDTH );
	vbx_set_2D( BLOCK_HEIGHT, BLOCK_WIDTH*sizeof(input_type), sub_block_width*sizeof(input_type), 0 );
	vbx_2D( VVB, VMOV, (vbx_byte_t*)v_block, (vbx_byte_t*)v_block, 0 );
#endif

	//Do column by column

#if !USE_3D
	for( j=0; j < SEARCH_WIDTH; j++ ) 
	{
		// column-ize the search image
		vbx_set_vl( BLOCK_WIDTH );
		vbx_set_2D( BLOCK_HEIGHT+SEARCH_HEIGHT,  BLOCK_WIDTH*sizeof(input_type), sub_block_width*sizeof(input_type), 0 );
		vbx_2D( VVBU, VMOV, v_img_sub, v_img+j, 0 );

		// search the image columnwise
		vbx_set_vl( BLOCK_SIZE );
		vbx_set_2D( SEARCH_HEIGHT, SEARCH_WIDTH*sizeof(output_type), 0,  BLOCK_WIDTH*sizeof(input_type) );
		vbx_acc_2D( VVBWU, VABSDIFF, (vbx_uword_t*)v_result+j, v_block, v_img_sub );
	}
#else
	const int IMGSUB_BLOCK = (BLOCK_HEIGHT+SEARCH_HEIGHT)*BLOCK_WIDTH; // sub_block_width;
	// column-ize the search image
	vbx_set_vl( BLOCK_WIDTH );
	vbx_set_2D( BLOCK_HEIGHT+SEARCH_HEIGHT,  BLOCK_WIDTH*sizeof(input_type), sub_block_width*sizeof(input_type), 0 );
	vbx_set_3D( SEARCH_WIDTH,               IMGSUB_BLOCK*sizeof(input_type),                 sizeof(input_type), 0 );
	vbx_3D( VVBU, VMOV, v_img_sub, v_img, 0 );

	// search the image columnwise
	vbx_set_vl( BLOCK_SIZE );
	vbx_set_2D( SEARCH_HEIGHT, SEARCH_WIDTH*sizeof(output_type), 0,  BLOCK_WIDTH*sizeof(input_type) );
	vbx_set_3D( SEARCH_WIDTH,               sizeof(output_type), 0, IMGSUB_BLOCK*sizeof(input_type) );
	vbx_acc_3D( VVBWU, VABSDIFF, v_result, v_block, v_img_sub );
#endif



	// need this for performance benchmarking right now
	// it should be removed when we properly do prefetching
	vbx_sync();
	// Write back result
	vbx_dma_to_host( result, v_result, RESULT_SIZE );

	return 0;
}

/** Setup function before running VBX Motion Estimation, using vbx_3d ops.
*/
int vbw_mtx_motest_3d_byte_setup()
{
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	const int PADDED_BLOCK_WIDTH = VBX_PAD_UP( BLOCK_WIDTH, this_mxp->dma_alignment_bytes );

	vbx_sp_push();

	v_block   = (input_type        *)vbx_sp_malloc( BLOCK_HEIGHT*BLOCK_WIDTH*sizeof(input_type) );
	v_img     = (input_type        *)vbx_sp_malloc( (BLOCK_HEIGHT+SEARCH_HEIGHT)*(PADDED_BLOCK_WIDTH+SEARCH_WIDTH)*sizeof(input_type) );
	v_row_sad = (intermediate_type *)vbx_sp_malloc( BLOCK_HEIGHT*SEARCH_WIDTH*sizeof(intermediate_type) );
	v_result  = (output_type       *)vbx_sp_malloc( SEARCH_HEIGHT*SEARCH_WIDTH*sizeof(output_type) );

	if( v_result == NULL ) {
		vbx_sp_pop();
		VBX_PRINTF( "ERROR: out of memory\n" );
		return -1;
	}

	return 0;
}

/** VBX Motion Estimation, using vbx_3d ops.
 * Using bytes as input data.
 *
 * @param[in] x.
 * @param[in] y.
 * @param[out] result.
 */
int vbw_mtx_motest_3d_byte(output_type *result, input_type *x, input_type *y)
{
	int  l,j;
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	const int PADDED_BLOCK_WIDTH = VBX_PAD_UP( BLOCK_WIDTH, this_mxp->dma_alignment_bytes );

	if( (PADDED_BLOCK_WIDTH)==(BLOCK_WIDTH) ) {

		for( j = 0; j < BLOCK_HEIGHT; j++ ) {
			vbx_dma_to_vector( v_block+j*BLOCK_WIDTH, x+j*IMAGE_WIDTH, BLOCK_WIDTH*sizeof(input_type) );
		}
		for( j = 0; j < BLOCK_HEIGHT+SEARCH_HEIGHT; j++ ) {
			vbx_dma_to_vector( v_img+j*(BLOCK_WIDTH+SEARCH_WIDTH), y+j*IMAGE_WIDTH, (BLOCK_WIDTH+SEARCH_WIDTH)*sizeof(input_type) );
		}

	} else { //PADDED_BLOCK_WIDTH==BLOCK_WIDTH

		vbx_set_vl( BLOCK_WIDTH );
		for( j = 0; j < BLOCK_HEIGHT; j++ ) {
			vbx_dma_to_vector( v_img+j*PADDED_BLOCK_WIDTH, x+j*IMAGE_WIDTH, PADDED_BLOCK_WIDTH*sizeof(input_type) );
		}
		for( j = 0; j < BLOCK_HEIGHT; j++ ) {
			vbx( VVBU, VMOV, v_block+j*BLOCK_WIDTH, v_img+j*PADDED_BLOCK_WIDTH, 0 );
		}
		vbx_set_vl( BLOCK_WIDTH+SEARCH_WIDTH );
		for( j = 0; j < BLOCK_HEIGHT+SEARCH_HEIGHT; j++ ) {
			vbx_dma_to_vector( v_img+j*(PADDED_BLOCK_WIDTH+SEARCH_WIDTH), y+j*IMAGE_WIDTH, (PADDED_BLOCK_WIDTH+SEARCH_WIDTH)*sizeof(input_type) );
		}
		for( j = 0; j < BLOCK_HEIGHT+SEARCH_HEIGHT; j++ ) {
			vbx( VVBU, VMOV, v_img+j*(BLOCK_WIDTH+SEARCH_WIDTH), v_img+j*(PADDED_BLOCK_WIDTH+SEARCH_WIDTH), 0 );
		}

	} //PADDED_BLOCK_WIDTH==BLOCK_WIDTH

	vbx_set_3D( SEARCH_WIDTH, BLOCK_HEIGHT*sizeof(intermediate_type), sizeof(input_type), 0 );

	for( l = 0; l < SEARCH_HEIGHT; l++ ) {
		//Accumulate each row into a vbx of row SADs
		vbx_set_vl( BLOCK_WIDTH );
		vbx_set_2D( BLOCK_HEIGHT, sizeof(intermediate_type), (BLOCK_WIDTH+SEARCH_WIDTH)*sizeof(input_type), BLOCK_WIDTH*sizeof(input_type) );
		vbx_acc_3D( VVBHU, VABSDIFF, v_row_sad, v_img+l*(BLOCK_WIDTH+SEARCH_WIDTH), v_block );

		//Accumulate the SADs
		vbx_set_vl( BLOCK_HEIGHT/2 );
		vbx_set_2D( SEARCH_WIDTH, sizeof(output_type), BLOCK_HEIGHT*sizeof(intermediate_type), BLOCK_HEIGHT*sizeof(intermediate_type) );
		vbx_acc_2D( VVHWU, VADD, (vbx_uword_t*)v_result+l*SEARCH_WIDTH, v_row_sad, v_row_sad+(BLOCK_HEIGHT/2) );

		//Transfer the line to host
		vbx_dma_to_host( result+l*SEARCH_WIDTH, v_result+l*SEARCH_WIDTH, SEARCH_WIDTH*sizeof(output_type) );

	}

	return 0;
}
