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
VBXCOPYRIGHT( test_rev )

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

#include "vbx.h"
#include "vbx_port.h"
#include "vbx_common.h"
#include "vbx_test.h"
#include "vbw_vec_rev.h"



// INTERNAL DEBUGGING ROUTINES


void print_vector_word( char *str, vbx_word_t *v, int N );
void print_vector_half( char *str, vbx_half_t *v, int N );
void print_vector_byte( char *str, vbx_byte_t *v, int N );

void verify_vector_word( vbx_word_t *v1, vbx_word_t *v2, int N );
void verify_vector_half( vbx_half_t *v1, vbx_half_t *v2, int N );
void verify_vector_byte( vbx_byte_t *v1, vbx_byte_t *v2, int N );


void print_vector_word( char *str, vbx_word_t *v, int N )
{
#if 1
	int i;
	vbx_sync();
	printf( str );
	for( i=0; i<N; i++ ) {
		if( (i&15) == 0 ) printf("\n");
		printf( "%4"PRId32" ", v[i] );
	}
	printf("\n");
	vbx_sync();
#endif
}

void print_vector_half( char *str, vbx_half_t *v, int N )
{
#if 1
	int i;
	vbx_sync();
	printf( str );
	for( i=0; i<N; i++ ) {
		if( (i&15) == 0 ) printf("\n");
		printf( "%4d ", v[i] );
	}
	printf("\n");
	vbx_sync();
#endif
}

void print_vector_byte( char *str, vbx_byte_t *v, int N )
{
#if 1
	int i;
	vbx_sync();
	printf( str );
	for( i=0; i<N; i++ ) {
		if( (i&15) == 0 ) printf("\n");
		printf( "%4d ", v[i] );
	}
	printf("\n");
	vbx_sync();
#endif
}







//  INTERNAL VERIFICATION ROUTINES

void verify_vector_word( vbx_word_t *v1, vbx_word_t *v2, int N )
{
	int i, num_error=0;
	vbx_sync();
	if( !v1 || !v2 ) return;
	for( i=0; i<N; i++ ) {
		if( v1[N-1-i] != v2[i] ) {
			if( ++num_error < 20000 )
				printf( "ERROR at %d/%d, v1=%"PRId32", v2=%"PRId32"\n", i, N, v1[N-1-i], v2[i] );
		}
		else if( num_error ) printf( "noerr at %d/%d, v1=%"PRId32", v2=%"PRId32"\n", i, N, v1[N-1-i], v2[i] );
	}
	if( num_error ) { VBX_TEST_FAIL(num_error); exit(-1); }
	vbx_sync();
}


void verify_vector_half( vbx_half_t *v1, vbx_half_t *v2, int N )
{
	int i, num_error=0;
	vbx_sync();
	if( !v1 || !v2 ) return;
	for( i=0; i<N; i++ ) {
		if( v1[N-1-i] != v2[i] ) {
			if( ++num_error < 20 )
				printf( "ERROR at %d/%d, v1=%d, v2=%d\n", i, N, v1[N-1-i], v2[i] );
		}
		//else if( num_error ) printf( "ERROR at %d/%d, v1=%d, v2=%d\n", i, N, v1[N-1-i], v2[i] );
	}
	if( num_error ) { VBX_TEST_FAIL(num_error); exit(-1); }
	vbx_sync();
}


void verify_vector_byte( vbx_byte_t *v1, vbx_byte_t *v2, int N )
{
	int i, num_error=0;
	vbx_sync();
	if( !v1 || !v2 ) return;
	for( i=0; i<N; i++ ) {
		if( v1[N-1-i] != v2[i] ) {
			if( ++num_error < 20 )
				printf( "ERROR at %d/%d, v1=%d, v2=%d\n", i, N, v1[N-1-i], v2[i] );
		}
		//else if( num_error ) printf( "ERROR at %d/%d, v1=%d, v2=%d\n", i, N, v1[N-1-i], v2[i] );
	}
	if( num_error ) { VBX_TEST_FAIL(num_error); exit(-1); }
	vbx_sync();
}





// TEST ROUTINES


int vbw_vec_reverse_test_word()
{
	int aN[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 15, 16, 17, 20, 25, 31, 32, 33, 35, 40, 48, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 70, 80, 90, 99, 100, 101, 110, 128, 128, 144, 144, 160, 160, 176, 176, 192, 192, 224, 224, 256, 256, 288, 288, 320, 320, 352, 352, 384, 384, 400, 450, 512, 550, 600, 650, 700, 768, 768, 900, 900, 1023, 1024, 1200, 1400, 1600, 1800, 2048, 2048, 2500, 3000, 3500, 4096, 4096, 5000, 6000, 7000, 8192, 8192, 16384, 16384 };
	int N;
	int NBYTES;
	int NREPS = 1000;
	int i,k;
	vbx_timestamp_t start=0,finish=0;

	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	const int VBX_SCRATCHPAD_SIZE = this_mxp->scratchpad_size;

	for( i=0; i<sizeof(aN)/4; i++ ) {
		N = aN[i];
		//printf( "testing with vector size %d\n", N );

		NBYTES = 4*N;   // word
		if( 2*NBYTES > VBX_SCRATCHPAD_SIZE ) continue;

		vbx_word_t *vdst = NULL;
		vbx_word_t *vsrc = vbx_sp_malloc( NBYTES );
		if( !vsrc ) VBX_EXIT(-1);
		vbx_set_vl( VBX_SCRATCHPAD_SIZE/4 );
		vbx( SVW, VMOV, vsrc, 0, 0 );

		vbx_set_vl( N );
		vbx( SEW, VAND, vsrc, 0xFFFF, 0 );    // word
#if 1
		// measure performance of function call
		vbx_sync();
		start = vbx_timestamp();
		for(k=0; k<NREPS; k++ ) {
			vbx_sp_push();
			vdst = vbw_vec_reverse_word( vsrc, N );
			vbx_sync();
			vbx_sp_pop();
		}
		finish = vbx_timestamp();
		printf( "length %d:\tf(),macro %llu ", N, (unsigned long long) vbx_mxp_cycles((finish-start)/NREPS) );
		verify_vector_word( vsrc, vdst, N );
#endif

		vbx_set_vl( N );
		vbx( SEW, VAND, vsrc, 0xFFFF, 0 );    // word

		// measure performance of macro
		vbx_sp_push();
//		vdst = (vbx_word_t *)vbx_sp_malloc( NBYTES );
//		if( !vdst ) VBX_EXIT(-1);
		start = vbx_timestamp();
		for(k=0; k<NREPS; k++ ) {
			vbx_sp_push();
			vbw_vec_reverse_word_safe( vdst, vsrc, N );
			vbx_sp_pop();
			vbx_sync();
		}
		finish = vbx_timestamp();
		vbx_sp_pop();
		printf( "%llu cycles\n", (unsigned long long) vbx_mxp_cycles((finish-start)/NREPS) );
		verify_vector_word( vsrc, vdst, N );

#if 0
		int k;
		printf( "starting at position 0 " );
		for( k=1; k < min(N,VBX_WIDTH_BYTES); k++ ) {
			printf( "%d ", k );
			vbx_sp_push();
			vbx_word_t *vdst = vbw_vec_reverse_word( vsrc+k, N-k );
			//print_vector_word( "vsrc: ", vsrc+k, N-k );
			//print_vector_word( "vdst: ", vdst,   N-k );
			verify_vector_word( vsrc+k,  vdst,   N-k );
			vbx_sp_pop();
		}
		printf( ".\n" );
#endif
		vbx_sp_free();
	}

	vbx_sp_free();
	printf("All tests passed successfully.\n");

	return 0;
}

int vbw_vec_reverse_test_half()
{
	int aN[] = { 1, 2, 4, 6, 8, 12, 16, 20, 32, 40, 48, 60, 62, 64, 64, 66, 68, 70, 80, 90, 100, 110, 128, 128, 144, 144, 160, 160, 176, 176, 192, 192, 224, 224, 256, 256, 288, 288, 320, 320, 352, 352, 384, 384, 400, 450, 512, 550, 600, 650, 700, 768, 768, 900, 900, 1024, 2048, 2048, 4096, 4096, 8192, 8192, 16384, 16384, 32768, 65536 };
	int N;
	int NBYTES;
	int NREPS = 1000;
	int i,k;
	int start=0,finish=0;

	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	const int VBX_SCRATCHPAD_SIZE = this_mxp->scratchpad_size;

	for( i=0; i<sizeof(aN)/4; i++ ) {
		N = aN[i];
		//printf( "testing with vector size %d\n", N );

		NBYTES = 2*N;  // half
		if( 2*NBYTES > VBX_SCRATCHPAD_SIZE ) continue;

		vbx_half_t *vdst = NULL;
		vbx_half_t *vsrc = vbx_sp_malloc( NBYTES );
		if( !vsrc ) VBX_EXIT(-1);
		vbx_set_vl( VBX_SCRATCHPAD_SIZE/4 );
		vbx( SVW, VMOV, (vbx_word_t*)vsrc, 0, 0 );

		vbx_set_vl( N );
		vbx( SEH, VAND, vsrc, 0x7FFF, 0 );  // half

		// measure performance of function call
		vbx_sync();
		start = vbx_timestamp();
		for(k=0; k<NREPS; k++ ) {
			vbx_sp_push();
			vdst = vbw_vec_reverse_half( vsrc, N );
			vbx_sp_pop();
			vbx_sync();
		}
		finish = vbx_timestamp();
		printf( "length %d:\tf(),macro %llu ", N, (unsigned long long) vbx_mxp_cycles((finish-start)/NREPS) );
		verify_vector_half( vsrc, vdst, N );

		vbx_set_vl( N );
		vbx( SEH, VAND, vsrc, 0x7FFF, 0 );  // half

		// measure performance of macro
		vbx_sp_push();
		vdst = (vbx_half_t *)vbx_sp_malloc( NBYTES );
		if( !vdst ) VBX_EXIT(-1);
		start = vbx_timestamp();
		for(k=0; k<NREPS; k++ ) {
			vbx_sp_push();
//FIXME using the wrong macro/function call here
			vbw_vec_reverse_half_fast( vdst, vsrc, N );
			vbx_sp_pop();
			vbx_sync();
		}
		finish = vbx_timestamp();
		vbx_sp_pop();
		printf( "%llu cycles\n", (unsigned long long) vbx_mxp_cycles((finish-start)/NREPS) );
		verify_vector_half( vsrc, vdst, N );

#if 0
		int k;
		//printf( "starting at position 0.." );
		for( k=0; k<=min(N-1,VBX_WIDTH_BYTES); k++ ) {
			//printf( "position %d ", k );
			vbx_sp_push();
			vbx_half_t *vdst = vbw_vec_reverse_half( vsrc+k, N-k );
			//print_vector_half( "vsrc: ", vsrc+k, N-k );
			//print_vector_half( "vdst: ", vdst,   N-k );
			verify_vector_half( vsrc+k,  vdst,   N-k );
			vbx_sp_pop();
		}
		//printf( "%d\n", k-1 );
#endif
		vbx_sp_free();
	}

	vbx_sp_free();
	printf("All tests passed successfully.\n");

	return 0;
}

int vbw_vec_reverse_test_byte()
{
	//int aN[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 15, 16, 17, 20, 25, 31, 32, 33, 35, 40, 48, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 70, 80, 90, 99, 100, 101, 110, 128, 128, 144, 144, 160, 160, 176, 176, 192, 192, 224, 224, 256, 256, 288, 288, 320, 320, 352, 352, 384, 384, 400, 450, 512, 550, 600, 650, 700, 768, 768, 900, 900, 1023, 1024, 2048, 2048, 4096, 4096, 8192, 8192, 16384, 16384, 32768, 32768, 65536, 65536 };
	int aN[] = { 4, 8, 12, 16, 20, 32, 40, 48, 60, 64, 64, 68, 80, 100, 128, 128, 144, 144, 160, 160, 176, 176, 192, 192, 224, 224, 256, 256, 288, 288, 320, 320, 352, 352, 384, 384, 400, 512, 600, 700, 768, 768, 900, 900, 1024, 2048, 2048, 4096, 4096, 8192, 8192, 16384, 16384, 32768, 32768 };
	int N;
	int NBYTES;
	int NREPS = 1000;
	int i,k;
	int start=0,finish=0;

	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	const int VBX_SCRATCHPAD_SIZE = this_mxp->scratchpad_size;
	const int VBX_WIDTH_BYTES     = this_mxp->vector_lanes * sizeof(int);

	for( i=0; i<sizeof(aN)/4; i++ ) {
		N = aN[i];
		//printf( "testing with vector size %d\n", N );

		NBYTES = 1*N;       // byte
		if( 2*NBYTES > VBX_SCRATCHPAD_SIZE ) continue;

		vbx_byte_t *vdst = NULL;
		vbx_byte_t *vsrc = vbx_sp_malloc( NBYTES );
		if( !vsrc ) VBX_EXIT(-1);
		vbx_set_vl( VBX_SCRATCHPAD_SIZE/4 );
		vbx( SVW, VMOV, (vbx_word_t*)vsrc, 0, 0 );

		vbx_set_vl( N );
		vbx( SEB, VAND, vsrc, 0x007F, 0 );   // byte

		// measure performance of function call
		vbx_sync();
		start = vbx_timestamp();
		for(k=0; k<NREPS; k++ ) {
			vbx_sp_push();
			vdst = (vbx_byte_t *)vbw_vec_reverse_byte( vsrc, N );
			vbx_sync();
			vbx_sp_pop();
		}
		finish = vbx_timestamp();
		printf( "length %d:\tf(),macro %llu ", N, (unsigned long long) vbx_mxp_cycles((finish-start)/NREPS) );
		verify_vector_byte( vsrc, vdst, N );

		vbx_set_vl( N );
		vbx( SEB, VAND, vsrc, 0x007F, 0 );   // byte

		// measure performance of macro
		vbx_sp_push();
		vdst = (vbx_byte_t *)vbx_sp_malloc( NBYTES );
		if( !vdst ) VBX_EXIT(-1);
		start = vbx_timestamp();
		for(k=0; k<NREPS; k++ ) {
			vbw_vec_reverse_byte_fast( vdst, vsrc, N );
			vbx_sync();
		}
		finish = vbx_timestamp();
		vbx_sp_pop();
		printf( "%llu cycles\n", (unsigned long long) vbx_mxp_cycles((finish-start)/NREPS) );
		verify_vector_byte( vsrc, vdst, N );

#if 1
		int k;
		//printf( "starting at position 0.." );
		for( k=0; k<=min(N-1,VBX_WIDTH_BYTES); k++ ) {
			//printf( "position %d ", k );
			vbx_sp_push();
			vbx_byte_t *vdst = vbw_vec_reverse_byte( vsrc+k, N-k );
			//print_vector_byte( "vsrc: ", vsrc+k, N-k );
			//print_vector_byte( "vdst: ", vdst,   N-k );
			verify_vector_byte( vsrc+k,  vdst,   N-k );
			vbx_sp_pop();
		}
		//printf( "%d\n", k-1 );
#endif
		vbx_sp_free();
	}

	vbx_sp_free();
	printf("All tests passed successfully.\n");

	return 0;
}



int main()
{
	int errors = 0;

	vbx_test_init();

	vbx_timestamp_start();

	// Requires > 64KB scratch:
	// errors += vbw_vec_reverse_test_byte();
	errors += vbw_vec_reverse_test_half();
	errors += vbw_vec_reverse_test_word();

	VBX_TEST_END(errors);
	return 0;
}
