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
VBXCOPYRIGHT( mandel )

#include<stdio.h>
#include<stdlib.h>

#include "vbx_common.h"

//#define X86
//#define BENCHMARK



/*
 * Mandelbrot Demo
 *
 * Define symbol X86 to run this as a benchmark for an Intel-class processor.
 *
 * The Intel processor will have an advantage of a fast memory system and not
 * doing any I/O (just writing to memory).
 *
 * Controls for the DE1 version of this demo are:
 *
 *
 * SW7:0 define max_iterations, the level of detail shown on the mandelbrot.
 * default should be 0xff
 *
 * SW8=1 user INTERACTIVE mode
 * SW8=0 play AUTOMATIC sequence of predefined coordinates
 *
 * SW9=1 use VENICE for next frame
 * SW9=0 use Nios for next frame
 *
 * you need to compute the same frame with both VENICE and Nios to display speedup on the 7seg.
 * if the 7seg shows 1126, the speedup is 112.6 times.
 *
 * during INTERACTIVE mode:
 * key0= shift key
 *
 * key1=zoom in
 * key1+0 = zoom out
 *
 * key3=pan left
 * key2=pan right
 *
 * key3+0=pan up
 * key2+0=pan dn
 * (i may have up/dn reversed)
 *
 * zoom crops the outer 1/8 of the screen and blows up the center to full size (33% zoom).
 * panning moves 1/8 of the screen
 *
 * holding zoom/pan buttons results in less detail until you release, then it redraws in full detail.
 *
 *
 *
 */

int global_k = -1;

#ifdef BENCHMARK

int key   = 0;
int sw    = 0x2ff;
int *pKEY  = &key;
int *pSWITCH = &sw;
typedef unsigned short pixel;

#elif defined(DEMO)
#include "demo.h"

int key   = 0;
int sw    = 0x2ff;
int *pKEY  = &key;
#if defined(SYSTEM_DE4) || defined(SYSTEM_ZEDBOARD)
int *pSWITCH = &sw;
#else
volatile unsigned int *pSWITCH = (unsigned int *)((int)SWITCH_PIO_BASE|0x80000000);
#endif
#define MAX_X_PIXELS	IMAGE_WIDTH
#define MAX_Y_PIXELS	IMAGE_HEIGHT
pixel *pFrameTPad = 0;

#else
#include "259macros.h"
#define MAX_X_PIXELS	320
#define MAX_Y_PIXELS	240

#endif

#ifdef X86

int vector_mandelbrot( int vlen ) { return vlen; }
int  vbx_timestamp_freq()  { return 1; }
void vbx_timestamp_start() { }
int  vbx_timestamp()       { return 1; }


#elif __NIOS2__

#include "system.h"
#include "io.h"

#endif 





#define nDEBUG         //print out intermediate results
#define EARLY_EXIT  1  //whether or not seeking early exit in vector code
#define CHECK_RESULT 0


static int max_iterations = 255;

#if defined(DEMO) && defined(VBX1_MULFXP_WORD_FRACTION_BITS)
// NOTE: Only works if MXP instance is named vbx1.
static int FSHIFT = VBX1_MULFXP_WORD_FRACTION_BITS;
#elif defined(SYSTEM_ZEDBOARD) && defined(XPAR_VECTORBLOX_MXP_ARM_0_MULFXP_WORD_FRACTION_BITS)
static int FSHIFT = XPAR_VECTORBLOX_MXP_ARM_0_MULFXP_WORD_FRACTION_BITS;
#elif defined(SYSTEM_ZEDBOARD) && defined(XPAR_VECTORBLOX_MXP_0_MULFXP_WORD_FRACTION_BITS)
static int FSHIFT = XPAR_VECTORBLOX_MXP_0_MULFXP_WORD_FRACTION_BITS;
#else
static int FSHIFT = 25; // do NOT change
#endif

static int escape_limit;
static int escape_limit_squared;
static int FSCALE;
static int FMASK;

static const int grid_width  = MAX_X_PIXELS; //320;
static const int grid_height = MAX_Y_PIXELS; //240;


#ifdef DEMO
pixel FRAME_VECT[1];
pixel FRAME_NIOS[1];
#else
pixel FRAME_VECT[ MAX_Y_PIXELS*MAX_X_PIXELS ];
pixel FRAME_NIOS[ MAX_Y_PIXELS*MAX_X_PIXELS ];
#endif


static int x_start, x_end;
static int y_start, y_end;

static int x_aspect, y_aspect;

typedef struct box {
	int xs,xe,ys,ye;
} box_t;


// This flightPlan was assembled for FSHIFT == 20.
#define CALCULATE_FIRST_IMAGE_ONLY 0

box_t flightPlan[] = {
#if CALCULATE_FIRST_IMAGE_ONLY
	// Repeatedly compute first image
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864},
	{-2621440, 1572864, -1572864, 1572864}
#else // !CALCULATE_FIRST_IMAGE_ONLY
#if 1
	{-2621440, 1572864, -1572864, 1572864},
	{-2097152, 1048576, -1179648, 1179648},
	{-1703936, 655360, -884736, 884736},
	{-1409024, 360448, -663552, 663552},
	{-1187840, 139264, -497664, 497664},
	{-1021952, -26624, -373248, 373248},
	{-897536, 97792, -373248, 373248},
	{-897536, 97792, -466560, 279936},
	{-897536, 97792, -559872, 186624},
	{-897536, 97792, -653184, 93312},
#endif
#if 1
	{-897536, 97792, -746496, 0},
	{-897536, 97792, -839808, -93312},
	{-897536, 97792, -933120, -186624},
	{-897536, 97792, -1026432, -279936},
	{-773120, -26624, -1026432, -466560},
	{-679808, -119936, -956448, -536544},
	{-609824, -189920, -903960, -589032},
	{-557336, -242408, -864594, -628398},
	{-517970, -281774, -835070, -657922},
	{-488446, -311298, -812927, -680065},
#endif
	{-466303, -333441, -796320, -696672},
	{-449696, -316834, -796320, -696672},
	{-433089, -300227, -796320, -696672},
	{-416482, -283620, -796320, -696672},
	{-399875, -267013, -796320, -696672},
	{-383268, -250406, -796320, -696672},
	{-366661, -233799, -796320, -696672},
	{-350054, -217192, -796320, -696672},
	{-333447, -200585, -796320, -696672},
	{-316840, -183978, -796320, -696672},
	{-300233, -200585, -783864, -709128},
	{-287777, -213041, -774522, -718470},
	{-278435, -222383, -767516, -725476},
	{-271429, -229389, -762261, -730731},
	{-266174, -234644, -758320, -734672},
	{-262233, -238585, -755364, -737628},
	{-262233, -238585, -753147, -735411},
	{-262233, -238585, -750930, -733194},
	{-262233, -238585, -753147, -735411},
	{-262233, -238585, -755364, -737628},
	{-262233, -238585, -757581, -739845},
	{-262233, -238585, -759798, -742062},
	{-262233, -238585, -762015, -744279},
	{-259277, -241541, -759798, -746496},
#if (FSHIFT>=25)
	{-257060, -243758, -758136, -748158},
	{-255398, -245420, -756889, -749405},
	{-254151, -246667, -755954, -750340},
	{-253216, -247602, -755253, -751041},
	{-252515, -248303, -754727, -751567},
	{-251989, -248829, -754332, -751962},
	{-251594, -249224, -754036, -752258},
	{-251298, -249520, -753814, -752480},
	{-251076, -249742, -753648, -752646},
	{-250910, -249908, -753523, -752771},
	{-250785, -250033, -753429, -752865},
	{-250691, -250127, -753359, -752935},
	{-250621, -250197, -753306, -752988},
	{-250568, -250250, -753267, -753027},
	{-250529, -250289, -753237, -753057},
	{-250499, -250319, -753215, -753079},
	{-250477, -250341, -753198, -753096},
	{-250460, -250358, -753186, -753108},
#endif //(FSHIFT>=25)
	{0,0,0,0}
#endif // !CALCULATE_FIRST_IMAGE_ONLY
};




pixel *palette;

pixel BLACK;
pixel RED;
pixel GREEN;
pixel WHITE;




// -------------------------------------------
// Some fixed-point math routines

inline int mul( int x, int y )
{
#ifdef QUICKS
	return (x*y)>>FSHIFT;
#else
	long long xx = x;
	long long yy = y;
	long long xxyy = (xx * yy) >> FSHIFT;
	return (int)xxyy;
#endif
}

inline int cmplx_mul_imag( int r, int i )
{
#ifdef QUICKS
	return (r*i)>>(FSHIFT-1);
#else
	long long xx = r;
	long long yy = i;
	long long xxyy = (xx * yy) >> (FSHIFT-1);
	return (int)xxyy;
#endif
}

inline int cmplx_mul_real( int r, int i )
{
#ifdef QUICKS
	int xpy = r+i;
	int xmy = r-i;
	return (xpy * xmy) >> FSHIFT;
#else
	long long xx = r;
	long long yy = i;
	long long xpy = xx+yy;
	long long xmy = xx-yy;
	long long xxyy = (xpy * xmy) >> FSHIFT;
	return (int)xxyy;
#endif
}

inline int cmplx_mag( int x, int y )
{
#if QUICKS
	return ((x*x)+(y*y))>>FSHIFT;
#else
	long long xx = x;
	long long yy = y;
	long long xxyy = (xx*xx + yy*yy) >> FSHIFT;
	if( xxyy >  0x7fffffff ) return  0x7fffffff;
	if( xxyy <  0 )          return  0x7fffffff;
	return (int)xxyy;
#endif
}


// -------------------------------------------
// Some math routines

inline int gcd( int a, int b )
{
	while( b ) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

inline void reduce( int *pa, int *pb )
{
	const int g = gcd( *pa, *pb );
	*pa /= g;
	*pb /= g;
}

inline int safescale( int a, int factor, int divisor )
{
	reduce( &factor, &divisor );
	reduce(      &a, &divisor );
	return a*factor/divisor;
}


// -------------------------------------------
// Some framebuffer routines

inline pixel *getPixelAddr( int x, int y, int isVec )
{
#if 0
	// for error checking
	if( x < 0 ) return (pixel *)0;
	if( y < 0 ) return (pixel *)0;
	if( x >= MAX_X_PIXELS ) return (pixel *)0;
	if( y >= MAX_Y_PIXELS ) return (pixel *)0;
#endif
	pixel *p;

#ifdef BENCHMARK

	pixel *p = ( isVec ? FRAME_VECT : FRAME_NIOS );
	p += y * MAX_X_PIXELS + x;
	//*pFrameStart = colour;

#elif defined DEMO
	p = pFrameTPad;
	p += y * MAX_X_PIXELS + x;
	//*pFrameStart = colour;

#else
	p = (pixel *)ADDR_VGA;
	p += (y<<MAX_X_BITS) | x;
	//*pVGA = colour;

#if CHECK_RESULT
	pixel *p2 = ( isVec ? FRAME_VECT : FRAME_NIOS );
	p2 += y * MAX_X_PIXELS + x;
	*p2 = colour;
#endif //CHECK_RESULT

#endif //DEMO, BENCHMARK
	return p;
}

inline void setPixel( int x, int y, pixel colour, int isVec )
{
	pixel *p = getPixelAddr( x, y, isVec );
#if 0
	// for error checking
	if( p ) *p = colour;
#else
	*p = colour;
#endif
}


inline pixel makeColour( int r, int g, int b )
{
	pixel rgb;
#ifdef DEMO
	rgb.r = r<<2;
	rgb.g = g<<2;
	rgb.b = b<<2;
	rgb.a = 0;
#else
	int rr  = (r&63)>>1;
	int gg  = (g&63);
	int bb  = (b&63)>>1;
	pixel rgb = ( (rr<<11) | (gg<<5) | (bb) )  &  0xffff;
#endif
	return rgb;
}

inline void drawPixel( int x, int y, pixel colour )
{
	setPixel( x, y, colour, 0 );
}






#ifndef X86

vbx_word_t *v_Cr, *v_Ci;
vbx_word_t *v_Zr, *v_Zi;
vbx_word_t *v_newZr, *v_newZi;
vbx_word_t *v_magZ2;
vbx_word_t *v_flags;

vbx_uword_t *v_escap;
vbx_uword_t *v_iters;
volatile vbx_uword_t *v_ndone;

int vector_calculate_nrows( int x, int y, int vlen, int nrows, 
				int x_start, int y_start, int x_delta, int y_delta )
{
	int i, limit;
	int total_saved = 0;
	limit = escape_limit_squared;

	// whether to seek early exit
	vbx_set_vl(1);
	vbx(SVWU, VMOV, (vbx_uword_t*)v_ndone, 0, 0);
	//*v_ndone = 0;

	// compute Cr,Ci here
	// do this operation, vectorized
	//	for(x = 0; x < grid_width; x++) {
	//		Cr[x] = (x_start + (x_delta / 100) + 4) * x / 8;
	//		Ci[x] = (y_start + (y_delta /  75) + 4) * y / 8;
	//	}
	// x_delta/100 and y_delta/75 are already precomputed
	// note: 100,75 = 800/8,600/8

	vbx_set_vl( vlen );
	vbx( SVWU, VMOV,   v_escap,   0, v_escap );
	vbx( SVWU, VMOV,   v_iters,   0, v_iters );

	vbx_set_vl( vlen/nrows );
	for( i=0; i<nrows; i++ ) {
		vbx( SEW, VADD,   v_Cr+i*vlen/nrows,   x,         0 );
	}
	vbx_set_vl( vlen );
	vbx( SVW, VMULLO, v_Cr, x_delta, v_Cr );
	vbx( SVW, VADD,   v_Cr,       4, v_Cr );
	vbx( SVW, VSHR,   v_Cr,       3, v_Cr );
	vbx( SVW, VADD,   v_Cr, x_start, v_Cr );

	vbx_set_vl( vlen/nrows );
	for( i=0; i<nrows; i++ ) {
		vbx( SVW, VMOV,   v_Ci+i*vlen/nrows,     y+i,         0 );
	}
	vbx_set_vl( vlen );
	vbx( SVW, VMULLO, v_Ci, y_delta, v_Ci );
	vbx( SVW, VADD,   v_Ci,       4, v_Ci );
	vbx( SVW, VSHR,   v_Ci,       3, v_Ci );
	vbx( SVW, VADD,   v_Ci, y_start, v_Ci );

	vbx( SVW, VMOV,   v_Zr,       0,   0  );
	vbx( SVW, VMOV,   v_Zi,       0,   0  );

	// Precompute v_newZr for loop below
	// v_newZr = newZr = Zr*Zr - Zi*Zi = (Zr-Zi)*(Zr+Zi)
	vbx( VVW,    VSUB, v_newZr, v_Zr, v_Zi );
	vbx( VVW,    VADD, v_newZi, v_Zr, v_Zi );
	vbx( VVW, VMULFXP, v_newZr, v_newZr, v_newZi );

	for( i = 0; i < max_iterations; i++ ) {

		//###START Z = Z*Z + C START###
		// newZr is already calculated in the previous iteration
		vbx( VVW, VMULFXP, v_newZi,    v_Zr, v_Zi    );
		vbx( SVW,    VSHL, v_newZi,       1, v_newZi );

		vbx( VVW,    VADD, v_Zr,    v_newZr, v_Cr    ); // Zr = newZr + Cr
		vbx( VVW,    VADD, v_Zi,    v_newZi, v_Ci    ); // Zi = newZi + Ci
		//###END Z = Z*Z + C END###

		// Now compute Zr*Zr + Zi*Zi for escape limit test
		vbx( VVW, VMULFXP, v_newZr, v_Zr,    v_Zr    ); // t1 = Zr*Zr
		vbx( VVW, VMULFXP, v_newZi, v_Zi,    v_Zi    ); // t2 = Zi*Zi
		vbx( VVW,    VADD, v_magZ2, v_newZr, v_newZi ); // Zr*Zr + Zi*Zi for this iteration
		vbx( VVW,    VSUB, v_newZr, v_newZr, v_newZi ); // Zr*Zr - Zi*Zi for next iteration
		// v_magZ2 = Zr*Zr + Zi*Zi
		// v_newZr = Zr*Zr - Zi*Zi
		// after this point, don't change v_newZr, it is needed next iteration

		// look at previous loop iteration's result, see if we can terminate early
		if( *v_ndone == vlen ) {
			total_saved = max_iterations - i;
			break;
		}

		// ESCAPE DETECTION: update elements that have not yet escaped
		// if( limit > v_escap[i] ) { v_iters[i]++; v_escap[i] = v_magZ2[i]; }

		vbx_word_t *v_temp1 = v_newZi;  // no longer using v_newZi, re-use as temp1 space
		vbx( SVWU, VADD,     (vbx_uword_t*)v_temp1,        1, v_iters );
		vbx( SVWU, VSUB,     (vbx_uword_t*)v_flags,    limit, v_escap );
		vbx( VVWU, VCMV_GTZ, v_escap,  (vbx_uword_t*)v_magZ2, (vbx_uword_t*)v_flags );
		vbx( VVWU, VCMV_GTZ, v_iters,  (vbx_uword_t*)v_temp1, (vbx_uword_t*)v_flags );

		//seeking chance to break early
		//v_ndone[0] = sum( (limit <= v_escape[i]) ? _0_ : 1  );
		vbx_acc( SVWU, VCMV_LEZ, (vbx_uword_t*)v_ndone, 1, (vbx_uword_t*)v_flags ); //sum number of pixels done
	}

	// reuse some now-unused variables as temp space
	vbx_word_t *v_temp1 = v_newZi;
	vbx_word_t *v_temp2 = v_newZr;
	vbx_word_t *v_temp3 = v_magZ2;

	// map full height==0 for black
	vbx( SVWU, VSUB,     (vbx_uword_t*)v_flags, 255, v_iters );
	vbx( SVWU, VCMV_LEZ, v_iters,   0, (vbx_uword_t*)v_flags );

	// compute colour palette, based upon # iterations
	// blue component
	vbx( SVWU, VAND, (vbx_uword_t*)v_temp1,   0x0000007e, v_iters  );
	vbx( SVWU, VMUL, (vbx_uword_t*)v_temp3,   0x00000002, (vbx_uword_t*)v_temp1  );
	// green component
	vbx( SVWU, VAND, (vbx_uword_t*)v_temp1,   0x0000001f, v_iters  );
	vbx( SVWU, VMUL, (vbx_uword_t*)v_temp2,   0x00000800, (vbx_uword_t*)v_temp1  );
	vbx( VVWU, VOR,  (vbx_uword_t*)v_temp3,   (vbx_uword_t*)v_temp3, (vbx_uword_t*)v_temp2  );
	// red component
	vbx( SVWU, VAND, (vbx_uword_t*)v_temp1,   0x000000fc, v_iters  );
	vbx( SVWU, VMUL, (vbx_uword_t*)v_temp2,   0x00010000, (vbx_uword_t*)v_temp1  );
	vbx( VVWU, VOR,  v_iters,      (vbx_uword_t*)v_temp3, (vbx_uword_t*)v_temp2  );

	int xlen       = (vlen / nrows) * sizeof(unsigned int);
	int dst_stride = MAX_X_PIXELS   * sizeof(pixel);
	vbx_dma_to_host_2D( pFrameTPad + y*MAX_X_PIXELS + x, v_iters, xlen, nrows, dst_stride, xlen );

	return total_saved;
}

unsigned int vector_mandelbrot_nosplitrow( int vlen )
{
	int x, y, tvlen;
	unsigned int ms = 0;
	unsigned int start;
	unsigned int stop;
	int total_saved = 0;

	int nrows=vlen;
	while( nrows*nrows > vlen ) nrows /= 2;  // nrows = sqrt(vlen)

	int x_delta = (x_end - x_start) / ( grid_width/8); // 100
	int y_delta = (y_end - y_start) / (grid_height/8); //  75

	int logo=0;
	for(y = 0; y < grid_height; y+=nrows) {
		start = vbx_timestamp();

		tvlen = vlen;
		for( x=0; x < grid_width; x += vlen/nrows ) {
			int saved = vector_calculate_nrows(x, y, tvlen, nrows, 
							 x_start, y_start, x_delta, y_delta );
			total_saved += saved;
		}
		stop = vbx_timestamp();
		ms += 1000 * ((double)(stop - start)/(double)vbx_timestamp_freq());

		{
			vbx_set_vl( vlen );
			vbx_word_t *v_temp1 = v_newZr;  // temp space
			vbx( SVW, VMOV, v_temp1, (63<<2)<<8, 0 );
#if 1
			const int xfer_len = vlen * sizeof(pixel);
			const int num_rows = 2 * max(1, (grid_width / vlen ));
			const int dst_stride = vlen * sizeof(pixel);
			pixel *pNextFrameLine = pFrameTPad + (y+nrows)*grid_width;
			vbx_dma_to_host_2D( pNextFrameLine, v_temp1, xfer_len, num_rows, dst_stride, 0/*src_stride*/ );
#else
			int yy;
			for( yy=0; yy<2/*nrows*/; yy++ ) { // progress bar is this many pixels tall
				pixel *pPixel = getPixelAddr( 0, y+yy+nrows, 1 );
				if( pPixel ) {
					tvlen = vlen;
					for( x=0; x<grid_width; x+= vlen ) {
						if( grid_width-x < vlen ) {
							tvlen = (grid_width - x);
						}
						vbx_dma_to_host( pPixel+x, v_temp1, tvlen * sizeof(pixel) );
					}
				}
			}
#endif
		}

#ifndef BENCHMARK
        if( escape_application(&demo, MODE_VECTOR_MANDEL) ){
            global_k = 0;
            return -1;
        }

		if(!logo && y >= Y_MARGIN+VBLOGO_HEIGHT){
			vbx_sync();
			draw_vblogo(pFrameTPad, 0);
			vbx_dcache_flush_all();
			logo=1;
		}
#endif // !defined(BENCHMARK)

	}
	//printf("total iteration saved is %d\n", total_saved);
	//printf("percent of saved is %0.4f = %d/%d\n",
	//		(float)total_saved/(float)(max_iterations*grid_height*3), total_saved, max_iterations*grid_height*3);
	return ms;
}


#endif  /* !defined(X86) */


// ---------------------------------------------------------------------------------------------------------------


typedef struct _cmplx_t {
	int r;
	int i;
} cmplx_t;

unsigned short scalar_escape_iterations( cmplx_t Z )
{
	cmplx_t C, tempZ;
	C.r = Z.r;
	C.i = Z.i;
	Z.r = 0;
	Z.i = 0;

	int iterations = 0;
	int escape;

	while( iterations < max_iterations) {
		//The following 5 lines of code compute Z = Z*Z + C
		tempZ.r = cmplx_mul_real( Z.r, Z.i );
		tempZ.i = cmplx_mul_imag( Z.r, Z.i );
		Z.r = tempZ.r + C.r;
		Z.i = tempZ.i + C.i;

		escape = cmplx_mag( Z.r, Z.i );
		if( escape >= escape_limit_squared )
			return iterations;
		if( escape < 0 ) {
			return iterations;
		}
		iterations++;
	}
	return max_iterations;
};

unsigned int scalar_mandelbrot()
{
	int x, y;
	unsigned short count;
	pixel colour;
	unsigned int ms = 0;
	unsigned int start, stop;

	cmplx_t z;
	for(y = 0; y < grid_height; y++) {
		if( y==0 ) for( x = 0; x < grid_width; x++ ) {
			setPixel( x, y, GREEN, 0 );
		}

		int x_delta = (x_end - x_start) / ( grid_width/8); // 100
		int y_delta = (y_end - y_start) / (grid_height/8); //  75
		start = vbx_timestamp();
		for( x = 0; x < grid_width; x++ ) {
			z.r = x_start + x_delta * x / 8;
			z.i = y_start + y_delta * y / 8;
			count = scalar_escape_iterations(z);
			colour = palette[count];
			setPixel(x, y  , colour, 0);
			setPixel(x, y+1,  GREEN, 0);
#ifdef X86
			ms += colour;
#endif
		}
		stop = vbx_timestamp();
		ms += 1000 * ((double)(stop - start)/(double)vbx_timestamp_freq());
#ifndef BENCHMARK
        if( escape_application(&demo, MODE_SCALAR_MANDEL) ){
            global_k = 0;
            return -1;
        }

		if(y == Y_MARGIN+VBLOGO_HEIGHT){
#if !NO_MXP
			vbx_sync();
			draw_vblogo(pFrameTPad, 0);
#endif
			vbx_dcache_flush_all();
		}
#endif
	}
	return ms;
}

void makePalette()
{
	int i;
	for( i=0; i<max_iterations; i++ ) {
		palette[i] = makeColour( (i>>2)%64, (i%64)<<1, (i>>1)%64 );
	}
	palette[max_iterations] = BLACK;
}

#ifdef X86
#define vbx_shared_malloc malloc
#endif

int compute_vlen( int num_vectors )
{

	// figure out vlen
	int k=1;
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	const int scratchpad_size = this_mxp->scratchpad_size;
	const int align           = this_mxp->dma_alignment_bytes;

	int vmem = scratchpad_size;
	int vlen = scratchpad_size/4;
	do {
		// find 
		do {
			vlen = scratchpad_size/4 / ++k;
		} while( 1*4 + num_vectors*4*VBX_PAD_UP(vlen,align) > vmem );
		// find the smallest power of 2 <= vlen
		int p=1;
		while( p<=vlen ) {
			p*=2;
		}
		vlen=p/2;
	} while( vmem < 1*4 + num_vectors*4*VBX_PAD_UP(vlen, align) );

	// put an upper limit on vector length
	// since large blocks will certainly contain complex pixels requiring more compute time
	k = 32 * this_mxp->vector_lanes;
	vlen = min(   k, vlen );

	// printf( "vlen=%d\n", vlen );
	return vlen;
}


int Init()
{
	FSCALE = 0x1 << FSHIFT;
	FMASK  = FSCALE-1;

	// escape limit proven to be 2.0
	escape_limit = 2 * FSCALE + 1;
	escape_limit_squared = mul(escape_limit, escape_limit);

	int xres = grid_width;
	int yres = grid_height;
	reduce( &xres, &yres );
	x_aspect = xres;
	y_aspect = yres;

	// at first, assume 4:3 aspect ratio
	// entire mandelbrot set is contained within disc of radius 2.
	x_start =  5*FSCALE/2*(-1); // -2.5 // 4 units wide
	x_end   =  3*FSCALE/2;      //  1.5
	y_start =  3*FSCALE/2*(-1); // -1.5 // 3 units high
	y_end   =  3*FSCALE/2;      //  1.5

	// now, correct for actual aspect ratio
	if( x_aspect!=4 || y_aspect!=3 ) {
		int x1span = x_end - x_start;
		int y1span = y_end - y_start;
		int new_xspan = safescale( y1span, x_aspect, y_aspect );
		new_xspan = (new_xspan - x1span) / 2;
		x_start -= new_xspan;
		x_end   += new_xspan;
	}

	BLACK = makeColour(0,0,0);
	RED   = makeColour(63,0,0);
	GREEN = makeColour(0,63,0);
	WHITE = makeColour(63,63,63);

	if( !palette ) {
		palette = (pixel *)malloc( (max_iterations+1) * sizeof(pixel) );
		makePalette();
	}

#ifndef X86
	const int num_vectors = 10;
	int vlen = compute_vlen( num_vectors );

	v_Cr    = (vbx_word_t  *)vbx_sp_malloc( vlen * sizeof(vbx_word_t) );
	v_Ci    = (vbx_word_t  *)vbx_sp_malloc( vlen * sizeof(vbx_word_t) );
	v_Zr    = (vbx_word_t  *)vbx_sp_malloc( vlen * sizeof(vbx_word_t) );
	v_Zi    = (vbx_word_t  *)vbx_sp_malloc( vlen * sizeof(vbx_word_t) );

	v_newZr = (vbx_word_t  *)vbx_sp_malloc( vlen * sizeof(vbx_word_t) );
	v_newZi = (vbx_word_t  *)vbx_sp_malloc( vlen * sizeof(vbx_word_t) );
	v_magZ2 = (vbx_word_t  *)vbx_sp_malloc( vlen * sizeof(vbx_word_t) );
	v_flags = (vbx_word_t  *)vbx_sp_malloc( vlen * sizeof(vbx_word_t) );

	v_escap = (vbx_uword_t *)vbx_sp_malloc( vlen * sizeof(vbx_uword_t) );
	v_iters = (vbx_uword_t *)vbx_sp_malloc( vlen * sizeof(vbx_uword_t) );

	v_ndone = (vbx_uword_t *)vbx_sp_malloc(    1 * sizeof(vbx_uword_t) );
	if( !v_ndone ) VBX_EXIT(-1);

#else
	int vlen = 0;

#endif

	return vlen;
};

#ifdef X86
#define vbx_shared_free free
#define vbx_sp_free() while(0)
#endif

int Destruct()
{
	free(palette); palette = NULL;

#if !NO_MXP
	vbx_sp_free();
#endif
	return 0;
};

void check_result()
{
	int i, j, wrong;
	pixel vect_result, nios_result;
	int vect_int, nios_int;
	int max_error = 0;
	wrong = 0;
    for(i = 0; i < grid_height; i++){
        for(j=0; j<grid_width; j++)
        {
            int pos = i * MAX_X_PIXELS + j;
            vect_result = FRAME_VECT[pos];
            nios_result = FRAME_NIOS[pos];
#ifdef DEMO
            vect_int = *((int*)(&vect_result));
            nios_int = *((int*)(&nios_result));
#else
            vect_int = (int)vect_result;
            nios_int = (int)nios_result;
#endif
            if( vect_int != nios_int ){
                max_error = max(abs(vect_int-nios_int), max_error);
                wrong++;
                if(wrong < 12)
                    printf("error at [%d,%d]: scalar - %d, vector - %d\n", i, j, nios_int, vect_int);
            }
        }
    }
	printf("error rate is %0.4f = %d/%d\n", (float)wrong/(float)(grid_width*grid_height), wrong, grid_width*grid_height);
	printf("num_wrong is %d\n", wrong);
	printf("max_error is %d\n", max_error);
}

void drawMarkers()
{
	int i;
	for( i=0; i<grid_height; i++ ) {
		drawPixel(            0, i, GREEN );
		drawPixel( grid_width-1, i, GREEN );
	}
	for( i=0; i<grid_width;  i++ ) {
		drawPixel( i,             0, GREEN );
		drawPixel( i, grid_height-1, GREEN );
	}
}



#ifdef DEMO
int mandelbrot( pixel *buffer, int vector_mode )
#else
int main(void)
#endif
{

#ifdef DEMO
	pFrameTPad = (pixel*)vbx_remap_uncached(buffer);  // force uncached
#endif

	//unsigned int time_start, time_stop;
	int scalar_time=-1, vector_time=-1;
	int xs, xe, ys, ye;
	int x1, x2, y1, y2;
	int redraw = 0, old_switch = 0;

#ifndef DEMO
	vbx_timestamp_start(); // start timer
#endif
	int vlen = Init();
	//printf("vlen is %d\n", vlen);

	xs = x_start;
	xe = x_end;
	ys = y_start;
	ye = y_end;

#define DX 8
#define DY 8
#define SCALE 1

	x1 = 0; x2 = SCALE*(grid_width);
	y1 = 0; y2 = SCALE*(grid_height);

	//scalar_time = scalar_mandelbrot();

	int new_max_iterations = -1;

	int num_k = sizeof(flightPlan)/sizeof(box_t);
	while( 1 ) {
		// if max_iterations changes, adjust the palette
		new_max_iterations = max_iterations;
		if( new_max_iterations != max_iterations ) {
			max_iterations = new_max_iterations;
			redraw=1;

			if( CHECK_RESULT ) {
				drawMarkers();
				scalar_time = scalar_mandelbrot();
				drawMarkers();
			}
		}

		{
			// zoom through a series of predetermined coordinates
			global_k++; if( global_k >= num_k ) global_k=0;

			// The flight plan is based upon FSHIFT=20. Correct it here.

			// compute the new bounding-box
			if( FSHIFT <= 20 ) {
				x_start = ( flightPlan[global_k].xs >> (20-FSHIFT) );
				x_end   = ( flightPlan[global_k].xe >> (20-FSHIFT) );
				y_start = ( flightPlan[global_k].ys >> (20-FSHIFT) );
				y_end   = ( flightPlan[global_k].ye >> (20-FSHIFT) );
			} else {
				x_start = ( flightPlan[global_k].xs << (FSHIFT-20) );
				x_end   = ( flightPlan[global_k].xe << (FSHIFT-20) );
				y_start = ( flightPlan[global_k].ys << (FSHIFT-20) );
				y_end   = ( flightPlan[global_k].ye << (FSHIFT-20) );
			}

			// The flight plan is for a 4:3 aspect ratio
			// Correct the xs, xe coordinates to the new aspect ratio
			if( x_aspect==4 && y_aspect==3 ) {
				// do nothing
			} else {
				int x1span = x_end - x_start;
				int y1span = y_end - y_start;
				int new_xspan = safescale( y1span, x_aspect, y_aspect );
				new_xspan = (new_xspan - x1span) / 2;
				x_start -= new_xspan;
				x_end   += new_xspan;
			}

			redraw=1;
		}

		//drawMarkers();
		//printf("starting vector fractal...\n");
		int new_switch = *pSWITCH & 0x200;
		if( redraw ) {
			//printf("xs=%d, xe=%d, ys=%d, ye=%d\n", x_start, x_end, y_start, y_end );
			vector_time = scalar_time = -1;
		}
		if( redraw || new_switch != old_switch ) {
			//printf("xs=%d, xe=%d, ys=%d, ye=%d, k=%d\n", x_start, x_end, y_start, y_end, k );
			old_switch = new_switch;
			makePalette();
			drawMarkers();

#ifdef X86
			scalar_time += scalar_mandelbrot();
#elif defined BENCHMARK
			if( vector_mode )
				vector_time += vector_mandelbrot_nosplitrow( vlen );
			else
				scalar_time += scalar_mandelbrot();
#else
			if( vector_mode ) {
				vector_time = vector_mandelbrot_nosplitrow( vlen );
				if( vector_time == -1 ){
					global_k--;
				}
				Destruct();
				return vector_time;
			} else {
				scalar_time = scalar_mandelbrot();
				if( scalar_time == -1 ){
					global_k--;
				}
				Destruct();
				return scalar_time;
			}
#endif

			drawMarkers();
			redraw = 0;
		}

		if( CHECK_RESULT ) check_result();

#ifdef BENCHMARK
		printf("xs=%d, xe=%d, ys=%d, ye=%d, k=%d\n", x_start, x_end, y_start, y_end, global_k );
		if( global_k+2 >= num_k ) break;
#endif
	}

#ifdef BENCHMARK
	printf( "scalar checksum %d\n", scalar_time );
	printf( "vector checksum %d\n", vector_time );
#endif

	Destruct();
	return 0;

}
