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


#include "vbx_copyright.h"
VBXCOPYRIGHT( test_mtx_xp )

/*
 * Matrix Transpose - Scalar NIOS version and VECTOR version
 */

#include <stdio.h>
#include "vbx.h"
#include "vbx_test.h"
#include "scalar_mtx_xp.h"
#include "vbw_mtx_xp_all.h"

#define VBX_TEMPLATE_T   VBX_BYTESIZE_DEF
// signed   VBX_BYTESIZE_DEF    VBX_HALFSIZE_DEF    VBX_WORDSIZE_DEF
// unsigned VBX_UBYTESIZE_DEF   VBX_UHALFSIZE_DEF   VBX_UWORDSIZE_DEF
#include "vbw_template_t.h"

#define TEST_ROWS 64
#define TEST_COLS 64
#define USE_XP 1
#define USE_XP_SQUARE 1
#define USE_XP_EXT 1
#define USE_XP_SQUARE_EXT 1

double test_vector_xp_square( vbx_sp_t *v_out, vbx_sp_t *v_in, int TEST_SIZE, double scalar_time )
{
	vbx_timestamp_t time_start, time_stop;
	printf( "\nExecuting MXP matrix transpose square...\n" );

	vbx_timestamp_start();
	time_start = vbx_timestamp();
	VBX_T(vbw_mtx_xp_square)( v_out, v_in, TEST_SIZE );
	time_stop = vbx_timestamp();

	printf( "...done\n" );
	return vbx_print_vector_time( time_start, time_stop, scalar_time );
}

double test_vector_xp( vbx_sp_t *v_out, vbx_sp_t *v_in, int TEST_ROW, int TEST_COL, double scalar_time )
{
	vbx_timestamp_t time_start, time_stop;
	printf( "\nExecuting MXP matrix transpose...\n" );

	vbx_timestamp_start();
	time_start = vbx_timestamp();
	VBX_T(vbw_mtx_xp)( v_out, v_in, TEST_ROW, TEST_COL );
	time_stop = vbx_timestamp();

	printf("...done\n");
	return vbx_print_vector_time( time_start, time_stop, scalar_time );
}

double test_vector_xp_ext( vbx_mm_t *out, vbx_mm_t *in, int TEST_ROW, int TEST_COL, double scalar_time )
{
	vbx_timestamp_t time_start, time_stop;

	printf( "\nExecuting MXP matrix transpose - external memory...\n" );

	vbx_timestamp_start();
	time_start = vbx_timestamp();
	VBX_T(vbw_mtx_xp_MN_ext)( out, in, TEST_ROW, TEST_COL );
	time_stop = vbx_timestamp();

	printf( "...done\n" );
	return vbx_print_vector_time( time_start, time_stop, scalar_time );
}

double test_vector_xp_square_ext( vbx_mm_t *out, vbx_mm_t *in, int TEST_SIZE, double scalar_time )
{
	vbx_timestamp_t time_start, time_stop;
	printf( "\nExecuting MXP matrix transpose square - external memory...\n" );

	vbx_timestamp_start();
	time_start = vbx_timestamp();
	VBX_T(vbw_mtx_xp_NN_ext)( out, in, TEST_SIZE );
	time_stop = vbx_timestamp();

	printf( "...done\n" );

	return vbx_print_vector_time( time_start, time_stop, scalar_time );
}


double test_scalar( vbx_mm_t *scalar_out, vbx_mm_t *scalar_in, int TEST_ROW, int TEST_COL )
{
	vbx_timestamp_t time_start, time_stop;
	printf( "\nExecuting scalar xp...\n" );

	vbx_timestamp_start();
	time_start = vbx_timestamp();
	VBX_T(scalar_mtx_xp_MN)( scalar_out, scalar_in, TEST_ROW, TEST_COL );
	time_stop = vbx_timestamp();

	printf( "...done\n" );
	return vbx_print_scalar_time( time_start, time_stop );
}

int main(void)
{
	vbx_test_init();

#if 0
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	const int VBX_SCRATCHPAD_SIZE = this_mxp->scratchpad_size;
	int N = VBX_SCRATCHPAD_SIZE/sizeof(vbx_mm_t)/8;
#endif

	int M = TEST_ROWS;
	int N = TEST_COLS;

	int PRINT_LENGTH = min( N, MAX_PRINT_LENGTH );
	int PRINT_COLS = PRINT_LENGTH;
	int PRINT_ROWS = min( M,MAX_PRINT_LENGTH );

	double scalar_time, vector_time;
	int errors=0;

	vbx_mxp_print_params();

	printf( "\nMatrix transpose test...\n" );
	printf( "Matrix dimensions: %d,%d\n", M, N );

	vbx_mm_t *scalar_in  = malloc( M*N*sizeof(vbx_mm_t) );
	vbx_mm_t *scalar_out = malloc( M*N*sizeof(vbx_mm_t) );

	vbx_mm_t *vector_in  = vbx_shared_malloc( M*N*sizeof(vbx_mm_t) );
	vbx_mm_t *vector_out = vbx_shared_malloc( M*N*sizeof(vbx_mm_t) );

	vbx_sp_t *v_out = vbx_sp_malloc( M*N*sizeof(vbx_sp_t) );
	vbx_sp_t *v_in  = vbx_sp_malloc( M*N*sizeof(vbx_sp_t) );

	VBX_T(test_zero_array)( scalar_out, M*N );
	VBX_T(test_zero_array)( vector_out, M*N );

	VBX_T(test_init_array)( scalar_in, M*N, 1 );
	VBX_T(test_copy_array)( vector_in, scalar_in, M*N );
	VBX_T(test_print_matrix)( scalar_in, PRINT_ROWS, PRINT_COLS, N );

	scalar_time = test_scalar( scalar_out, scalar_in, M, N );
	VBX_T(test_print_matrix)( scalar_out, PRINT_COLS, PRINT_ROWS, M );

#if USE_XP
	vbx_dma_to_vector( v_in, vector_in, M*N*sizeof(vbx_sp_t) );
	vector_time = test_vector_xp( v_out, v_in, M, N, scalar_time );
	vbx_dma_to_host( vector_out, v_out, M*N*sizeof(vbx_sp_t) );
	VBX_T(test_print_matrix)( vector_out, PRINT_COLS, PRINT_ROWS, M );

	errors += VBX_T(test_verify_array)( scalar_out, vector_out, M*N );
#endif
#if TEST_ROWS == TEST_COLS && USE_XP_SQUARE
	vbx_dma_to_vector( v_in, vector_in, M*N*sizeof(vbx_sp_t) );
	vector_time = test_vector_xp_square( v_out, v_in, M, scalar_time );
	vbx_dma_to_host( vector_out, v_out, M*N*sizeof(vbx_sp_t) );
	VBX_T(test_print_matrix)( vector_out, PRINT_COLS, PRINT_ROWS, M );

	errors += VBX_T(test_verify_array)( scalar_out, vector_out, M*N );
#endif
#if USE_XP_EXT
	vector_time = test_vector_xp_ext( vector_out, vector_in, M, N, scalar_time );
	VBX_T(test_print_matrix)( vector_out, PRINT_COLS, PRINT_ROWS, M );

	errors += VBX_T(test_verify_array)( scalar_out, vector_out, M*N );
#endif
#if TEST_ROWS == TEST_COLS && USE_XP_SQUARE_EXT
	vector_time = test_vector_xp_square_ext( vector_out, vector_in, M, scalar_time );
	VBX_T(test_print_matrix)( vector_out, PRINT_COLS, PRINT_ROWS, M );

	errors += VBX_T(test_verify_array)( scalar_out, vector_out, M*N );
#endif

	VBX_TEST_END(errors);
	return 0;
}
