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

#include "vbw_mtx_xp_t.h"


#ifndef VBX_MTX_XP_ONLY_ONCE
#define VBX_MTX_XP_ONLY_ONCE
// defaults: tile using prime factors
int VBX_MTX_TILE_HEIGHT = 256*3*5*7*11*13*17*19;
int VBX_MTX_TILE_WIDTH  = 256*3*5*7*11*13*17*19;

static int gcd(int a, int b )
{
	while( b ) {
		int old_b = b;
		b = a % b;
		a = old_b;
	}
	return a;
}

static void findTileSize(int *ph, int *pw, const int height, const int width, const int factor )
{
#if 0
	int *pthf;
	int *ptwf;

	int num_height_factors = getFactors( pthf, INROWS );
	int num_width_factors  = getFactors( ptwf, INCOLS );
	int w = num_width_factors;

	int h, w, max_num_bytes=0, min_diff = INROWS+INCOLS; good_h, good_w;
	for( h=1; h < num_height_factors-1; h++ ) {
		for( w=1; w < num_width_factors-1; w++ ) {
			int num_tile_elem = tile_height_factors[h] * tile_width_factors[w];
			int num_diff      = abs( tile_height_factors[h] - tile_width_factors[w] );
			int num_bytes = 4 * num_tile_elem * sizeof(vbx_mm_t);
			if( num_bytes > sp )
				break;
			if( num_diff < min_diff ) {
				if( num_bytes > max_num_bytes ) {
					max_num_bytes = num_bytes;
					min_diff = num_diff;
					good_h = h; good_w = w;
				}
			}
		}
	}

#else

	int tile_height = gcd( VBX_MTX_TILE_HEIGHT, height );
	int tile_width  = gcd( VBX_MTX_TILE_WIDTH,  width );

	while( height % tile_height )
		tile_height = tile_height / 2;
	while( width % tile_width )
		tile_width = tile_width / 2;

	int sp = vbx_sp_getfree();
	do {
		if( tile_height >= tile_width && factor*tile_height*tile_width*sizeof(vbx_sp_t) > sp )
			tile_height /= 2;
		if( tile_width >= tile_height && factor*tile_height*tile_width*sizeof(vbx_sp_t) > sp )
			tile_width  /= 2;
	} while( factor*tile_height*tile_width*sizeof(vbx_sp_t) > sp );
	*pw = tile_width;
	*ph = tile_height;
#endif
	// printf("Tile height %d, width %d\n", *ph, *pw );

}
#endif//VBX_MTX_XP_ONLY_ONCE


/** VBX Square Matrix Transpose *in the scratchpad*.
 * New technique.
 * Assumes matrix is perfect square, N x N, and N is a power of 2.
 * size    new    old
 * N=  2   526    504
 * N=  4   519    513
 * N=  8   623    526
 * N= 16   818    658
 * N= 32  1532    917
 * N= 64  3055   3502
 * N=128  8683  14649
 * N=256 out of memory
 *
 * @param[out] v_dst.
 * @param[in] v_src.
 * @param[in] INSIZE.
 */
void VBX_T(vbw_mtx_xp_square)(vbx_sp_t *v_dst, vbx_sp_t *v_src, const int INSIZE)
{
	vbx_sp_t *v[2] = { v_src, v_dst };
	int src = 0;

	const int ROWBYTES = INSIZE * sizeof(vbx_sp_t);

	vbx_sp_push();
	vbx_sp_t *vf = (vbx_sp_t *)vbx_sp_malloc( INSIZE/2 * ROWBYTES );
	if( !vf ) {
		VBX_PRINTF("fatal error\n");
		VBX_EXIT(1);
	}

	int n;
	for( n=1; n<INSIZE; n *= 2 ) {
		const int nn = 2*n;

		// copy the destination matrix
		vbx_set_vl( INSIZE*INSIZE );
		vbx( VV(T), VMOV, v[!src], v[src], 0 );

		// do the work
		vbx_set_vl( n*INSIZE );
		vbx( SE(T), VAND, vf, n, 0 );
		vbx_set_2D(    INSIZE/nn,          nn*ROWBYTES,  nn*ROWBYTES,  0 );
		vbx_2D( VV(T), VCMV_Z,          v[!src]+n*INSIZE,   v[src]+n  , vf );
		vbx_2D( VV(T), VCMV_Z,          v[!src]+n  ,   v[src]+n*INSIZE, vf );

		src = !src;
	}

	src = !src;
	if( v[!src] != v_dst ) {
		vbx_set_vl( INSIZE*INSIZE );
		vbx( VV(T), VMOV, v_dst, v[!src], 0 );
	}

	vbx_sp_pop();
}

/** VBX Matrix Transpose *in the scratchpad*.
 * Assumes in != out
 * Transposes entirely within scratchpad (height,width decribe v_src layout)
 *
 * @param[out] v_dst.
 * @param[in] v_src.
 * @param[in] INROWS.
 * @param[in] INCOLS.
 */
void VBX_T(vbw_mtx_xp)(vbx_sp_t *v_dst, vbx_sp_t *v_src, const int INROWS, const int INCOLS )
{
	if( !VBX_SKIP_ALL_CHECKS  &&  abs(v_dst-v_src) < (INROWS*INCOLS*sizeof(vbx_sp_t)) ) {
		VBX_PRINTF( "ERROR: in vbw_mtx_xp, pointers v_dst and v_src must not overlap.\n");
		VBX_EXIT( -1 );
	}

	if( (INROWS==INCOLS) && ((INCOLS==64) || (INCOLS==128)) && VBX_SAFE_TO_CLOBBER_SOURCE ) {
		//WARNING: this call destroys v_src
		VBX_T(vbw_mtx_xp_square)( v_dst, v_src, INCOLS );
	} else {
		vbx_set_vl( 1 );
		vbx_set_2D(  INCOLS, INROWS*sizeof(vbx_sp_t),       sizeof(vbx_sp_t), 0 );
#if 0
		// theoretically this should be faster
		vbx_set_3D( INROWS,        sizeof(vbx_sp_t), INCOLS*sizeof(vbx_sp_t), 0 );
		vbx_3D( VV(T), VMOV, v_dst, v_src, 0 );
#else
		// strangly, 2D is faster than 3D here. why???
		int row_num;
		for( row_num=0; row_num<INROWS; row_num++ ) {
			vbx_2D( VV(T), VMOV, v_dst+row_num, v_src+row_num*INCOLS, 0 );
		}
#endif
	}
}

#define READ_AHEAD 1
#define _read_and_xp_tile( v_out, v_in, tileY, tileX, tile_height, tile_width, matrix_width ) \
	do { \
		int j, k=0; \
		for( j=0; j<tile_height; j++ ) { \
			int row_num = (tileY+j); \
			int col_num = tileX; \
			vbx_dma_to_vector( v_in+j*tile_width, \
					in+row_num*matrix_width+col_num, \
					tile_width*sizeof(vbx_mm_t) ); \
			if( (j>=READ_AHEAD) ) { vbx_2D( VV(T), VMOV, v_out+(k), v_in+(k)*tile_width, 0 ); k++; } \
		} \
		for( j=k; j<tile_height; j++ ) { \
			vbx_2D( VV(T), VMOV, v_out+j, v_in+j*tile_width, 0 ); \
		} \
	} while(0)


#define _write_tile( v_out, tileY, tileX, tile_height, tile_width, matrix_width ) \
	do { \
		int j; \
		for( j = 0; j < tile_width; j++ ) { \
			int row_num = (tileX+j); \
			int col_num = tileY; \
			vbx_dma_to_host( \
					out+row_num*matrix_width+col_num, \
					v_out+j*tile_height, \
					tile_height*sizeof(vbx_mm_t) ); \
		} \
	} while(0)

#define _print_tile( v_out, tileY, tileX, tile_height, tile_width, matrix_width ) \
	do { \
		int i, j; \
		for( i = 0; i < 0*tile_height; i++ ) { \
			for( j = 0; j < 0*tile_width; j++ ) { \
				int row_num = (tileX+j); \
				int col_num = tileY+i; \
				printf("%5d ", *(v_out+j*tile_height+i) ); \
			} \
			printf("\n"); \
		} \
	} while(0)


#define _next_tile( tile_x, tile_y, tile_width, tile_height, INROWS, INCOLS ) \
	do { \
		tile_x += tile_width; \
		if( tile_x >= INCOLS ) { \
			tile_x = 0; \
			tile_y += tile_height; \
			if( tile_y >= INROWS ) tile_y = -1; \
		} \
	} while(0)




/** VBX Matrix Transpose *in memory*.
 *  Assumes in != out
 *  Assumes array size is a perfect multiple of 16
 *
 * @param[out] out.
 * @param[in] in.
 * @param[in] INROWS.
 * @param[in] INCOLS.
 */
//void vector_transpose_matrix_MN( vbx_mm_t *in, vbx_mm_t *out, int INROWS, int INCOLS )
void VBX_T(vbw_mtx_xp_MN_ext)(vbx_mm_t *out, vbx_mm_t *in, const int INROWS, const int INCOLS )
{

	int tile_height;
	int tile_width;
	int tile_y, tile_x;

	findTileSize( &tile_height, &tile_width, INROWS, INCOLS, 2 );

	vbx_sp_t *v_in;
	vbx_sp_t *v_out;
	v_in  = (vbx_sp_t*)vbx_sp_malloc( tile_height*tile_width * sizeof(vbx_sp_t) );
	v_out = (vbx_sp_t*)vbx_sp_malloc( tile_height*tile_width * sizeof(vbx_sp_t) );

	vbx_set_2D( tile_width, tile_height*sizeof(vbx_sp_t), sizeof(vbx_sp_t), sizeof(vbx_sp_t) );
	// rows, incrDest, incrA, incrB 
	vbx_set_vl( 1 );

	// compute current tile <x,y> in background while prefetching next tile
	for( tile_y = 0; tile_y < INROWS; tile_y += tile_height ) {
		for( tile_x = 0; tile_x < INCOLS; tile_x += tile_width ) {
			// transpose current tile
			_read_and_xp_tile( v_out, v_in, tile_y, tile_x, tile_height, tile_width, INROWS );
			// write out current tile
			_write_tile( v_out, tile_y, tile_x, tile_height, tile_width, INCOLS );
			//_print_tile( v_out, tile_y, tile_x, tile_height, tile_width, INCOLS );
		}
	}

	vbx_sp_free();
	vbx_sync();
}


/** VBX Square Matrix Transpose *in memory*.
 * assumes array size is a perfect multiple of 16
 * assumes array size is a perfect square
 *
 * @param[out] out.
 * @param[in] in.
 * @param[in] INSIZE.
 */
////////void vector_transpose_matrix_NN( vbx_mm_t *in, vbx_mm_t *out, int INSIZE )
void VBX_T(vbw_mtx_xp_NN_ext)(vbx_mm_t *out, vbx_mm_t *in, const int INSIZE )
{
	int l,k,j;

	int tile_height = min( VBX_MTX_TILE_HEIGHT, INSIZE );
	int tile_width  = min( VBX_MTX_TILE_WIDTH,  INSIZE );

	findTileSize( &tile_height, &tile_width, INSIZE, INSIZE, 2 );

	vbx_sp_t *v_in;
	vbx_sp_t *v_out;
	v_in  = (vbx_sp_t *)vbx_sp_malloc( tile_height*tile_width*sizeof(vbx_sp_t) );
	v_out = (vbx_sp_t *)vbx_sp_malloc( tile_height*tile_width*sizeof(vbx_sp_t) );

	vbx_set_2D( tile_width, tile_height*sizeof(vbx_sp_t), sizeof(vbx_sp_t), sizeof(vbx_sp_t) );
	// rows, incr_dest, incrA, incrB

	vbx_set_vl(1);
	for(l = 0; l < INSIZE; l += tile_height){
		for(k = 0; k < INSIZE; k += tile_width){
			for(j = 0; j < tile_height; j++){
				vbx_dma_to_vector( v_in+j*tile_width, in+(l+j)*INSIZE+k, tile_width*sizeof(vbx_mm_t) );
				vbx_2D( VV(T), VMOV, v_out+j, v_in+j*tile_width, 0 );
			}
			for(j = 0; j < tile_width; j++){
				vbx_dma_to_host( out+(k+j)*INSIZE+l, v_out+j*tile_height, tile_height*sizeof(vbx_mm_t) );
			}
		}
	}

	vbx_sync();
	vbx_sp_free();
}

#endif // properly defined VBX_TEMPLATE_T
#endif // defined(VBX_TEMPLATE_T)
