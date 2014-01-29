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


#include "vbx_copyright.h"
VBXCOPYRIGHT( test_mtx_mm )

/*
  Matrix Multiply
  Scalar version and VECTOR version
*/

#include <stdio.h>
#include "vbx.h"
#include "vbx_test.h"
#include "scalar_mtx_mm.h"
#include "scalar_mtx_xp.h"
#include "vbw_mtx_xp_all.h"
#include "vbw_mtx_mm_all.h"

#define VBX_TEMPLATE_T	 VBX_BYTESIZE_DEF
// signed   VBX_BYTESIZE_DEF    VBX_HALFSIZE_DEF    VBX_WORDSIZE_DEF
// unsigned VBX_UBYTESIZE_DEF   VBX_UHALFSIZE_DEF   VBX_UWORDSIZE_DEF
#include "vbw_template_t.h"

double test_vector_transposed(vbx_mm_t *vector_out, vbx_mm_t  *vector_in1, vbx_mm_t  *vector_in2_xp, int TEST_SIZE, double scalar_time )
{
	vbx_timestamp_t time_start, time_stop;
	printf( "\nExecuting MXP matrix multiply (transposed)...\n" );

	vbx_timestamp_start();
	time_start = vbx_timestamp();
	VBX_T(vbw_mtx_mmt)( vector_out, vector_in1, vector_in2_xp, TEST_SIZE );
	time_stop = vbx_timestamp();

	printf( "...done\n" );
	return vbx_print_vector_time( time_start, time_stop, scalar_time );
}

double test_scalar( vbx_mm_t  *scalar_out, vbx_mm_t	 *scalar_in1, vbx_mm_t	*scalar_in2, int TEST_SIZE )
{
	vbx_timestamp_t time_start, time_stop;
	printf( "\nExecuting scalar matrix multiply...\n" );

	vbx_timestamp_start();
	time_start = vbx_timestamp();
	VBX_T(scalar_mtx_mm)( scalar_out, scalar_in1, scalar_in2, TEST_SIZE );
	time_stop = vbx_timestamp();

	printf( "...done\n" );
	return vbx_print_scalar_time( time_start, time_stop );
}

///////////////////////////////////////////////////////////////////////////
// Assumes in != out
// For scratchpad size of 64KB, computes tile height, width = (64, 128).
void orig_vbw_mtx_xp_word( int32_t *out, int32_t *in, int N )
{
	int bs,tile_height,tile_width;
	int l,k,j,i;
	vbx_word_t *v_in,*v_out;
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	bs = 0;
	for(i = 0; i < 32; i++){
		if((this_mxp->scratchpad_size/(2*sizeof(int))) & (1<<i)){
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

	// printf("Tile height %d, width %d\n", tile_height, tile_width );

	v_in  = (vbx_word_t *)vbx_sp_malloc(tile_height*tile_width*sizeof(int));
	v_out = (vbx_word_t *)vbx_sp_malloc(tile_height*tile_width*sizeof(int));

	vbx_set_2D(tile_width,tile_height*sizeof(int),sizeof(int),sizeof(int));
	vbx_set_vl(1);

	for(l = 0; l < N; l += tile_height){
		for(k = 0; k < N; k += tile_width){
			for(j = 0; j < tile_height; j++){
				vbx_dma_to_vector(v_in+j*tile_width,in+(l+j)*N+k,tile_width*sizeof(int));
				vbx_2D(VVW,VMOV,v_out+j,v_in+j*tile_width,0);
			}

			for(j = 0; j < tile_width; j++){
				vbx_dma_to_host(out+(k+j)*N+l,v_out+j*tile_height,tile_height*sizeof(int));
			}
		}
	}

	vbx_sp_free();
	vbx_sync();
}

///////////////////////////////////////////////////////////////////////////
void print_results_header( char *str, int N, int BS )
{
	printf( "Results %s:\n",str );
	printf( " %d rows\n",N );
	printf( " %d cols\n",N );
	printf( " BS = %d\n",BS );
}

///////////////////////////////////////////////////////////////////////////
// NOTE: vector_in1 gets transposed into vector_in2.
double test_vector_with_transpose(int32_t *vector_out,
								  int32_t *vector_in1,
								  int32_t *vector_in2,
								  int TEST_SIZE,
								  double scalar_time )
{
	vbx_timestamp_t time_start, time_stop;
	vbx_timestamp_t transpose_start, transpose_cycles;
	int VBS;
	double vector_time;
	double N = (double) TEST_SIZE;

	printf( "\nExecuting MXP matrix transpose then matrix multiply...\n" );

	vbx_timestamp_start();
	time_start = vbx_timestamp();
	// This requests more than 64KB of scratch;
	// computes tile height, width = (128, 256)
	// vbw_mtx_xp_NN_ext_word( vector_in2, vector_in1, TEST_SIZE );
	// For scratchpad size of 64KB,
	// computes tile height, width = (64, 128).
	orig_vbw_mtx_xp_word( vector_in2, vector_in1, TEST_SIZE );
	transpose_start = vbx_timestamp();
	VBS = vbw_mtx_mmt_word( vector_out, vector_in1, vector_in2, TEST_SIZE );
	time_stop = vbx_timestamp();

	transpose_cycles = vbx_mxp_cycles(transpose_start - time_start);
	printf( "Transpose time in cycles: %llu\n", (unsigned long long) transpose_cycles);
	printf( "Transpose cycles/elem: %.3f\n",
	        transpose_cycles/((float)N*N) );

	printf("\n");
	print_results_header( "of vector code including transpose", TEST_SIZE, VBS );
	vector_time = \
		vbx_print_vector_time_per(time_start, time_stop, N*N*N,
		                          "op", scalar_time);
	printf("\n");
	print_results_header( "of vector code excluding transpose", N, VBS );
	vbx_print_vector_time_per(transpose_start, time_stop, N*N*N,
	                          "op", scalar_time);

	return vector_time;
}

///////////////////////////////////////////////////////////////////////////
double test_scalar_tiled( int32_t *scalar_out,
						  int32_t *scalar_in1,
						  int32_t *scalar_in2,
						  int TEST_SIZE )
{
	vbx_timestamp_t time_start, time_stop;
	int BS = 32; // Works best, don't sweep anymore
	double N = (double) TEST_SIZE;

	printf( "\nExecuting scalar matrix multiply, kij tiled...\n" );

	vbx_timestamp_start();
	time_start = vbx_timestamp();
	scalar_block_kijkij_mm_word( scalar_out, scalar_in1, scalar_in2, TEST_SIZE, BS);
	time_stop = vbx_timestamp();

	print_results_header( "of scalar code", N, BS );
	return vbx_print_scalar_time_per( time_start, time_stop, N*N*N, "op" );
}

///////////////////////////////////////////////////////////////////////////
#if __ARM_ARCH_7A__
#define MAX_SCALAR_N 2048
#else
#define MAX_SCALAR_N 512
#endif

// Multiplies a matrix with itself.
int orig_test(void)
{
	const int STARTING_N = 256;
	const int ENDING_N = 2048;   /* 4096 is too big for 128MB tPad */
	const int N_MULTIPLIER = 2;

	int N;
	int32_t *va, *vb, *vc;
	int32_t *a, *b, *c;
	int32_t *scalar_out;

	int PRINT_LENGTH = min( STARTING_N, MAX_PRINT_LENGTH );
	int PRINT_ROWS = PRINT_LENGTH;
	int PRINT_COLS = PRINT_LENGTH;

	double scalar_time, vector_time;
	int errors=0;

	printf( "\nOriginal matrix multiply test...\n" );

	for( N=STARTING_N; N <=ENDING_N ; N *= N_MULTIPLIER ) {

		printf( "\nAllocating space for N=%d...\n", N );
		va = vbx_shared_malloc( sizeof(int32_t)*N*N );
		// Note: va gets transposed into vb.
		vb = vbx_shared_malloc( sizeof(int32_t)*N*N );
		vc = vbx_shared_malloc( sizeof(int32_t)*N*N );

		scalar_out = malloc( sizeof(int32_t)*N*N );

		if( !va || !vb || !vc || !scalar_out ) {
			VBX_PRINTF( "ERROR: Out of memory.\n" );
			VBX_EXIT( -1 );
		}

		a = vbx_remap_cached( va, sizeof(int32_t)*N*N );
		b = vbx_remap_cached( vb, sizeof(int32_t)*N*N );
		c = vbx_remap_cached( vc, sizeof(int32_t)*N*N );
		test_init_array_word( a, N*N, 1 );
		test_zero_array_word( b, N*N );
		test_zero_array_word( c, N*N );
		test_zero_array_word( scalar_out, N*N );
		vbx_dcache_flush_all();

		if( N <= MAX_SCALAR_N ) {
			scalar_time = test_scalar_tiled(scalar_out, a, a, N);
			// test_print_matrix_word( scalar_out, PRINT_COLS, PRINT_ROWS, N );
		} else {
			// Takes too long to run in scalar mode.
			scalar_time = 0.0;
		}

		vector_time = test_vector_with_transpose(vc, va, vb, N, scalar_time);
		// test_print_matrix_word( vc, PRINT_COLS, PRINT_ROWS, N );

		if ( N <= MAX_SCALAR_N ) {
			errors += test_verify_array_word( scalar_out, vc, N*N );
		}

		free(scalar_out);
		vbx_shared_free(vc);
		vbx_shared_free(vb);
		vbx_shared_free(va);

	} // end for

	return errors;
}

///////////////////////////////////////////////////////////////////////////
int main(void)
{
	vbx_test_init();

	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	const int VBX_SCRATCHPAD_SIZE = this_mxp->scratchpad_size;
	int N = VBX_SCRATCHPAD_SIZE / sizeof(vbx_mm_t );
	N = 512;

	int PRINT_LENGTH = min( N, MAX_PRINT_LENGTH );
	int PRINT_ROWS = PRINT_LENGTH;
	int PRINT_COLS = PRINT_LENGTH;

	double scalar_time, vector_time;
	int errors=0;

	vbx_mxp_print_params();
	printf( "\nMatrix multiply test...\n" );
	printf( "Matrix dimensions: %d,%d\n", N, N );


	vbx_mm_t  *scalar_in1 = malloc( N*N*sizeof(vbx_mm_t ) );
	vbx_mm_t  *scalar_in2 = malloc( N*N*sizeof(vbx_mm_t ) );
	vbx_mm_t  *scalar_out = malloc( N*N*sizeof(vbx_mm_t ) );
	vbx_mm_t  *vector_in1 = vbx_shared_malloc( N*N*sizeof(vbx_mm_t ) );
	vbx_mm_t  *vector_in2 = vbx_shared_malloc( N*N*sizeof(vbx_mm_t ) );
	vbx_mm_t  *vector_out = vbx_shared_malloc( N*N*sizeof(vbx_mm_t ) );

	VBX_T(test_zero_array)(scalar_out, N*N );
	VBX_T(test_zero_array)(vector_out, N*N );

	VBX_T(test_init_array)( scalar_in1, N*N, 1 );
	VBX_T(test_copy_array)( vector_in1, scalar_in1, N*N );
	VBX_T(test_init_array)( scalar_in2, N*N, 1 );
	VBX_T(scalar_mtx_xp_MN)( vector_in2, scalar_in2, N, N );

	VBX_T(test_print_matrix)( scalar_in1, PRINT_ROWS, PRINT_COLS, N );
	VBX_T(test_print_matrix)( scalar_in2, PRINT_ROWS, PRINT_COLS, N );

	scalar_time = test_scalar( scalar_out, scalar_in1, scalar_in2, N);
	VBX_T(test_print_matrix)( scalar_out, PRINT_COLS, PRINT_ROWS, N );

	vector_time = test_vector_transposed( vector_out, vector_in1, vector_in2, N, scalar_time );
	VBX_T(test_print_matrix)( vector_out, PRINT_COLS, PRINT_ROWS, N );

	errors += VBX_T(test_verify_array)( scalar_out, vector_out, N*N );

	vbx_shared_free(vector_out);
	vbx_shared_free(vector_in2);
	vbx_shared_free(vector_in1);
	free(scalar_out);
	free(scalar_in2);
	free(scalar_in1);

	errors += orig_test();

	VBX_TEST_END(errors);
	return 0;
}
