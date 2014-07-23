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

/**
 * @file
 * @defgroup Fix16 Fix16
 * @brief Fix16
 * @ingroup VBXware
 */
///@{

#ifndef __VBW_FIX16_H
#define __VBW_FIX16_H

/** Initial functions:
 * vbw_fix16_abs
 * vbw_fix16_min
 * vbw_fix16_add
 * vbw_fix16_sub
 * vbw_fix16_mul //32-bit and 8-bit
 * vbw_fix16_div //8-bit, require 32/32 divide instr for 32-bit implementaion
 * vbw_fix16_div_hw
 * vbw_fix16_sqrt
 * vbw_fix16_sqrt_hw
 * 
 * flags   
 * no 64-bit
 * no overflow
 */

#include "vbx.h"

#define USE_OVERFLOW 1
typedef fix16_t fxp_t;

/*
static inline fix16_t fix16_abs(fix16_t x)
	{ return (x < 0 ? -x : x); }
*/
static inline void vbw_fix16_abs( vbx_word_t* v_result, vbx_word_t* v_x)
{
  vbx(SVW, VABSDIFF, v_result, 0, v_x );
}

/*
static inline fix16_t fix16_min(fix16_t x, fix16_t y)
	{ return (x < y ? x : y); }
*/
static inline void vbw_fix16_min( vbx_word_t* v_result, vbx_word_t* v_x, vbx_word_t* v_y, vbx_word_t* v_temp )
{
  vbx(VVW, VSUB, v_temp, v_y, v_x );
  vbx(VVW, VCMV_GTZ, v_result, v_y, v_temp);
  vbx(VVW, VCMV_LEZ, v_result, v_x, v_temp);
}

static inline void vbw_fix16_max( vbx_word_t* v_result, vbx_word_t* v_x, vbx_word_t* v_y, vbx_word_t* v_temp )
{
  vbx(VVW, VSUB, v_temp, v_y, v_x );
  vbx(VVW, VCMV_LTZ, v_result, v_y, v_temp);
  vbx(VVW, VCMV_GEZ, v_result, v_x, v_temp);
}


//#ifdef FIXMATH_NO_OVERFLOW 
/*
static inline fix16_t fix16_add(fix16_t inArg0, fix16_t inArg1) { return (inArg0 + inArg1); }
*/
static inline void vbw_fix16_add( vbx_word_t* v_result, vbx_word_t* v_x, vbx_word_t* v_y)
{
  vbx(VVW, VADD, v_result, v_x, v_y );
}

static inline void vbw_fix16_add_s( vbx_word_t* v_result, fxp_t num, vbx_word_t* v_y)
{
  vbx(SVW, VADD, v_result, num, v_y );
}
/*
static inline fix16_t fix16_sub(fix16_t inArg0, fix16_t inArg1) { return (inArg0 - inArg1); }
*/
static inline void vbw_fix16_sub( vbx_word_t* v_result, vbx_word_t* v_x, vbx_word_t* v_y)
{
  vbx(VVW, VSUB, v_result, v_x, v_y );
}

static inline void vbw_fix16_sub_s( vbx_word_t* v_result, fxp_t num, vbx_word_t* v_y)
{
  vbx(SVW, VSUB, v_result, num, v_y );
}
//#endif


/* 64-bit implementation for fix16_mul. Fastest version for e.g. ARM Cortex M3.
 * Performs a 32*32 -> 64bit multiplication. The middle 32 bits are the result,
 * bottom 16 bits are used for rounding, and upper 16 bits are used for overflow
 * detection.
 */
/* 
#if !defined(FIXMATH_NO_64BIT) && !defined(FIXMATH_OPTIMIZE_8BIT)
fix16_t fix16_mul(fix16_t inArg0, fix16_t inArg1)
{
	int64_t product = (int64_t)inArg0 * inArg1;
	
	#ifndef FIXMATH_NO_OVERFLOW
	// The upper 17 bits should all be the same (the sign).
	uint32_t upper = (product >> 47);
	#endif
	
	if (product < 0)
	{
		#ifndef FIXMATH_NO_OVERFLOW
		if (~upper)
				return fix16_overflow;
		#endif
		
		#ifndef FIXMATH_NO_ROUNDING
		// This adjustment is required in order to round -1/2 correctly
		product--;
		#endif
	}
	else
	{
		#ifndef FIXMATH_NO_OVERFLOW
		if (upper)
				return fix16_overflow;
		#endif
	}
	
	#ifdef FIXMATH_NO_ROUNDING
	return product >> 16;
	#else
	fix16_t result = product >> 16;
	result += (product & 0x8000) >> 15;
	
	return result;
	#endif
}
#endif
*/
static inline void vbw_fix16_mul( vbx_word_t* v_result, vbx_word_t* v_x, vbx_word_t* v_y)
{
  vbx(VVW, VMULFXP, v_result, v_x, v_y );
}

static inline void vbw_fix16_mul_s( vbx_word_t* v_result, fxp_t num, vbx_word_t* v_y)
{
  vbx(SVW, VMULFXP, v_result, num, v_y );
}

static inline void vbw_fix16_smul( vbx_word_t* v_result, vbx_word_t* v_x, vbx_word_t* v_y, vbx_uword_t * v_tmp)
{
  vbx(VVW, VMULFXP, v_result, v_x, v_y );
#if USE_OVERFLOW
  vbx(SVWU, VSHR, v_tmp, 31, (vbx_uword_t*)v_result);
  vbx(SVWU, VADD, v_tmp, 0x7FFFFFFF,  v_tmp);
  vbx(VVWU, VCMV_LTZ, (vbx_uword_t*)v_result, v_tmp, (vbx_uword_t*)v_result);
#endif
}

static inline void vbw_fix16_smul_s( vbx_word_t* v_result, fxp_t num, vbx_word_t* v_y, vbx_uword_t* v_tmp)
{
  vbx(SVW, VMULFXP, v_result, num, v_y );
#if USE_OVERFLOW
  vbx(SVWU, VSHR, v_tmp, 31, (vbx_uword_t*)v_result);
  vbx(SVWU, VADD, v_tmp, 0x7FFFFFFF,  v_tmp);
  vbx(VVWU, VCMV_LTZ, (vbx_uword_t*)v_result, v_tmp, (vbx_uword_t*)v_result);
#endif
}

//#if defined(FIXMATH_OPTIMIZE_8BIT)
static inline void vbw_fix16_div_hw( vbx_word_t* v_result, vbx_word_t* v_a, vbx_word_t* v_b, int length, int hw_div_offset )
{
  vbx_set_vl(length + hw_div_offset);
  vbx(VVW, VCUSTOM0, v_result, v_b, v_a );
  vbx_set_vl(length);
}

/* Alternative 32-bit implementation of fix16_div. Fastest on e.g. Atmel AVR.
 * This does the division manually, and is therefore good for processors that
 * do not have hardware division.
 */
//#if defined(FIXMATH_OPTIMIZE_8BIT)
static inline void vbw_fix16_div( vbx_word_t* v_result, vbx_word_t* v_a, vbx_word_t* v_b, int length )
{
	// This uses the basic binary restoring division algorithm.
	// It appears to be faster to do the whole division manually than
	// trying to compose a 64-bit divide out of 32-bit divisions on
	// platforms without hardware divide.
	
  vbx_sp_push();
  vbx_word_t* v_tmp = (vbx_word_t *)vbx_sp_malloc(sizeof(vbx_word_t)*length*12);
  vbx_uword_t* v_rev    = (vbx_uword_t *)(v_tmp + 0*length);
  vbx_uword_t* v_while  = (vbx_uword_t *)(v_tmp + 1*length);

  vbx_word_t* v_rem    = (vbx_word_t *)(v_tmp + 2*length);
  vbx_word_t* v_quo    = (vbx_word_t *)(v_tmp + 3*length);
  vbx_uword_t* v_bit    = (vbx_uword_t *)(v_tmp + 4*length);
  vbx_word_t* v_div    = (vbx_word_t *)(v_tmp + 5*length);

  vbx_uword_t* v_t_rem  = (vbx_uword_t *)(v_tmp + 6*length);
  vbx_uword_t* v_t_quo  = (vbx_uword_t *)(v_tmp + 7*length);
  vbx_uword_t* v_t_bit  = (vbx_uword_t *)(v_tmp + 8*length);

  vbx_uword_t* v_t_misc = (vbx_uword_t *)(v_tmp + 9*length);
  vbx_word_t* v_t_sub  = (vbx_word_t *)(v_tmp + 10*length);
  vbx_uword_t* v_t_nz0  = (vbx_uword_t *)(v_tmp + 11*length);

  vbx_uword_t *v_t_div = v_t_misc;
  vbx_uword_t *v_t_nz1 = v_t_misc;
  v_quo    = v_result;

	//uint32_t remainder = (a >= 0) ? a : (-a);
  vbx(SVW, VABSDIFF, v_rem, 0, v_a);

	//uint32_t divider = (b >= 0) ? b : (-b);
  vbx(SVW, VABSDIFF, v_div, 0, v_b);

	//uint32_t quotient = 0;
  vbx(SVW, VMOV, v_quo, 0, 0);
	//uint32_t bit = 0x10000;
  vbx(SVWU, VMOV, v_bit, 0x10000, 0);
	
	/* The algorithm requires D >= R */
  /*
	while (divider < remainder)
	{
		divider <<= 1;
		bit <<= 1;
	}
  */
  int i, max_iter;
  //max_iter = 18;//FIXME double check limits
  max_iter = 30;//FIXME double check limits
  for(i=0;i<max_iter;i++){
    vbx(VVWU, VSUB, v_while, (vbx_uword_t*)v_rem, (vbx_uword_t*)v_div);
    vbx(SVWU, VSHL, v_t_div, 1, (vbx_uword_t*)v_div);
    vbx(SVWU, VSHL, v_t_bit, 1, v_bit);
    vbx(VVWU, VCMV_GTZ, (vbx_uword_t*)v_div, v_t_div, v_while);
    vbx(VVWU, VCMV_GTZ, v_bit, v_t_bit, v_while);
  }
	
#if 1//FIXME where does this happen
  /*
	if (divider & 0x80000000)
	{
		// Perform one step manually to avoid overflows later.
		// We know that divider's bottom bit is 0 here.
		if (remainder >= divider)
		{
				quotient |= bit;
				remainder -= divider;
		}
		divider >>= 1;
		bit >>= 1;
	}
  */

  vbx(VVWU, VSUB, (vbx_uword_t*)v_t_sub, (vbx_uword_t*)v_rem, (vbx_uword_t*)v_div);
  vbx(VVWU, VOR, v_t_misc, (vbx_uword_t*)v_quo, v_bit);
  vbx(VVWU, VCMV_GEZ, v_t_quo, v_t_misc, (vbx_uword_t*)v_t_sub);
  vbx(VVWU, VCMV_LTZ, v_t_quo, (vbx_uword_t*)v_quo, (vbx_uword_t*)v_t_sub);
  vbx(VVWU, VCMV_GEZ, v_t_rem, (vbx_uword_t*)v_t_sub, (vbx_uword_t*)v_t_sub);
  vbx(VVWU, VCMV_LTZ, v_t_rem, (vbx_uword_t*)v_rem, (vbx_uword_t*)v_t_sub);

  vbx(SVWU, VSHR, v_t_bit, 1, v_bit);
  vbx(SVWU, VSHR, v_t_div, 1, (vbx_uword_t*)v_div);

  vbx(SVWU, VAND, v_t_misc, 0x80000000, (vbx_uword_t*)v_div);
  vbx(VVWU, VCMV_NZ, (vbx_uword_t*)v_div, v_t_div, v_t_misc);
  vbx(VVWU, VCMV_NZ, v_bit, v_t_bit, v_t_misc);
  vbx(VVWU, VCMV_NZ, (vbx_uword_t*)v_quo, v_t_quo, v_t_misc);
  vbx(VVWU, VCMV_NZ, (vbx_uword_t*)v_rem, v_t_rem, v_t_misc);

#endif

	/* Main division loop */
  /*
	while (bit && remainder)
	{
		if (remainder >= divider)
		{
				quotient |= bit;
				remainder -= divider;
		} 
		remainder <<= 1;
		bit >>= 1;
	}	 
  */
  for(i=0; i<max_iter;i++){

    vbx(VVWU, VSUB, (vbx_uword_t*)v_t_sub, (vbx_uword_t*)v_rem, (vbx_uword_t*)v_div);
    vbx(VVWU, VOR, v_t_misc, (vbx_uword_t*)v_quo, v_bit);
    vbx(VVWU, VCMV_GEZ, v_t_rem, (vbx_uword_t*)v_t_sub, (vbx_uword_t*)v_t_sub);
    vbx(VVWU, VCMV_LTZ, v_t_rem, (vbx_uword_t*)v_rem, (vbx_uword_t*)v_t_sub);
    vbx(VVWU, VCMV_GEZ, v_t_quo, v_t_misc, (vbx_uword_t*)v_t_sub);
    vbx(VVWU, VCMV_LTZ, v_t_quo, (vbx_uword_t*)v_quo, (vbx_uword_t*)v_t_sub);
    vbx(SVWU, VSHL, v_t_rem, 1, v_t_rem);
    vbx(SVWU, VSHR, v_t_bit, 1, v_bit);

    vbx(SVWU, VCMV_NZ, v_t_nz0, 1, (vbx_uword_t*)v_rem);
    vbx(SVWU, VCMV_Z, v_t_nz0, 0, (vbx_uword_t*)v_rem);
    vbx(SVWU, VCMV_NZ, v_t_nz1, 1, v_bit);
    vbx(SVWU, VCMV_Z, v_t_nz1, 0, (vbx_uword_t*)v_rem);
    vbx(VVWU, VAND, v_t_misc, v_t_nz0, v_t_nz1);

    vbx(VVWU, VCMV_NZ, (vbx_uword_t*)v_quo, v_t_quo, v_t_misc);
    vbx(VVWU, VCMV_NZ, (vbx_uword_t*)v_rem, v_t_rem, v_t_misc);
    vbx(VVWU, VCMV_NZ, v_bit, v_t_bit, v_t_misc);
  }

	#ifndef FIXMATH_NO_ROUNDING
  /*
	if (remainder >= divider)
	{
		quotient++;
	}
  */
  vbx(VVWU, VSUB, (vbx_uword_t*)v_t_sub, (vbx_uword_t*)v_rem, (vbx_uword_t*)v_div);
  vbx(SVWU, VADD, v_t_misc, 1, (vbx_uword_t*)v_quo);
  vbx(VVWU, VCMV_GEZ, (vbx_uword_t*)v_quo, v_t_misc, (vbx_uword_t*)v_t_sub);
	#endif

	/* Figure out the sign of result */
  /*
	if ((a ^ b) & 0x80000000)
	{
		#ifndef FIXMATH_NO_OVERFLOW
		if (result == fix16_min)
				return fix16_overflow;
		#endif
		
		result = -result;
	}
  */
  vbx(VVWU, VXOR, v_t_misc, (vbx_uword_t*)v_a, (vbx_uword_t*)v_b);
  vbx(SVWU, VAND, v_t_misc, 0x80000000, v_t_misc);
  vbx(SVWU, VSUB, v_rev, 0, (vbx_uword_t*)v_quo);
  vbx(VVWU, VCMV_NZ, (vbx_uword_t*)v_quo, v_rev, v_t_misc);

  /*
	if (b == 0)
		return fix16_min;
  */
  vbx(SVWU, VCMV_Z, (vbx_uword_t*)v_quo, fix16_min, (vbx_uword_t*)v_b);
  vbx_sp_pop();
}

/* The square root algorithm is quite directly from
 * http://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Binary_numeral_system_.28base_2.29
 * An important difference is that it is split to two parts
 * in order to use only 32-bit operations.
 *
 * Note that for negative numbers we return -sqrt(-inValue).
 * Not sure if someone relies on this behaviour, but not going
 * to break it for now. It doesn't slow the code much overall.
 */
static inline void vbw_fix16_sqrt_hw( vbx_word_t* v_out, vbx_word_t* v_x, int length, int hw_sqrt_offset)
{
  vbx_set_vl(length + hw_sqrt_offset);
  vbx(VVW, VCUSTOM1, v_out, v_x, 0 );
  vbx_set_vl(length);
}


/* The square root algorithm is quite directly from
 * http://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Binary_numeral_system_.28base_2.29
 * An important difference is that it is split to two parts
 * in order to use only 32-bit operations.
 *
 * Note that for negative numbers we return -sqrt(-inValue).
 * Not sure if someone relies on this behaviour, but not going
 * to break it for now. It doesn't slow the code much overall.
 */
static inline void vbw_fix16_sqrt( vbx_word_t* v_out, vbx_word_t* v_x, int length)
{
  vbx_sp_push();
  //vbx_word_t* v_tmp = (vbx_word_t *)vbx_sp_malloc(sizeof(vbx_word_t)*length*11);
  vbx_word_t* v_tmp = (vbx_word_t *)vbx_sp_malloc(sizeof(vbx_word_t)*length*10);
  vbx_word_t* v_result   = v_tmp + 0*length;
  vbx_uword_t* v_bit      = (vbx_uword_t*)v_tmp + 1*length;
  vbx_word_t* v_num      = v_tmp + 2*length;
  vbx_uword_t* v_else_num = (vbx_uword_t*)v_tmp + 3*length;

  vbx_uword_t* v_t_bit    = (vbx_uword_t*)v_tmp + 4*length;
  vbx_uword_t* v_t_num    = (vbx_uword_t*)v_tmp + 5*length;

  vbx_uword_t* v_t_add    = (vbx_uword_t*)v_tmp + 6*length;
  vbx_word_t* v_t_sub    = v_tmp + 7*length;
  vbx_uword_t* v_t_result = (vbx_uword_t*)v_tmp + 8*length;
  vbx_uword_t* v_if_num   = (vbx_uword_t*)v_tmp + 9*length;
  //vbx_word_t* v_neg   = v_tmp + 10*length;

  v_result = v_out;

	//uint8_t  neg = (inValue < 0);
  //vbx(SVW, VMOV, v_neg, 0, 0 );
  //vbx(SVW, VCMV_LTZ, v_neg, 1, v_x);

	//uint32_t num = (neg ? -inValue : inValue);
  vbx(SVW, VABSDIFF, v_num, 0, v_x);
	//uint32_t result = 0;
  vbx(SVW, VMOV, v_result, 0, 0 );
	//uint32_t bit;
  vbx(SVWU, VMOV, v_bit, (1<<30), 0 );
	
  //*
	// Many numbers will be less than 15, so
	// this gives a good balance between time spent
	// in if vs. time spent in the while loop
	// when searching for the starting value.
  /*
	if (num & 0xFFF00000)
		bit = (uint32_t)1 << 30;
	else
		bit = (uint32_t)1 << 18;
        */

  
//	while (bit > num) bit >>= 2;
 
  int i, max_iter;
  max_iter = 16; //1<<30 and >>2 every iter, so max iter = 30/2 + 1
  for(i=0; i<max_iter; i++){
    vbx(VVW, VSUB, v_t_sub, (vbx_word_t*)v_bit, v_num);
    vbx(SVWU, VSHR, v_t_bit, 2, v_bit);
    vbx(VVW, VCMV_GTZ, (vbx_word_t*)v_bit, (vbx_word_t*)v_t_bit, v_t_sub);
  }
	
	// The main part is executed twice, in order to avoid
	// using 64 bit values in computations.
  /*
		while (bit)
		{
			if (num >= result + bit)
			{
				num -= result + bit;
				result = (result >> 1) + bit;
			}
			else
			{
				result = (result >> 1);
			}
			bit >>= 2;
		}
  */
  max_iter = 16;
  for(i=0; i<max_iter; i++){

      //v_result + bit
    vbx(VVW, VADD, (vbx_word_t*)v_t_add, (vbx_word_t*)v_bit, v_result);
      //v_num - (v_result + bit)
    vbx(VVW, VSUB, v_t_sub, v_num, (vbx_word_t*)v_t_add);

    //if (v_num - (v_result + bit) >= 0) v_num = v_num - (v_result + bit)
    vbx(VVW, VCMV_GEZ, (vbx_word_t*)v_t_num, v_t_sub, v_t_sub);
    //else v_num stays
    vbx(VVW, VCMV_LTZ, (vbx_word_t*)v_t_num, v_num, v_t_sub);

    vbx(SVW, VSHR, (vbx_word_t*)v_t_result, 1, v_result);
    vbx(VVW, VADD, (vbx_word_t*)v_t_add, (vbx_word_t*)v_bit, (vbx_word_t*)v_t_result);
    //if (v_num - (v_result + bit) >= 0) v_result = v_result >> 1 + bit 
    //else  v_result >> 1
    vbx(VVW, VCMV_GEZ, (vbx_word_t*)v_t_result, (vbx_word_t*)v_t_add, v_t_sub);

    vbx(SVW, VSHR, (vbx_word_t*)v_t_bit, 2, (vbx_word_t*)v_bit);

    vbx(VVW, VCMV_GTZ, v_num, (vbx_word_t*)v_t_num, (vbx_word_t*)v_bit);
    vbx(VVW, VCMV_GTZ, v_result, (vbx_word_t*)v_t_result, (vbx_word_t*)v_bit);
    vbx(VVW, VCMV_GTZ, (vbx_word_t*)v_bit, (vbx_word_t*)v_t_bit, (vbx_word_t*)v_bit);
  }

  //vbx(SVW, VSHL, v_result, 8, v_result);

//#if 0
 /* 
  if (num > 65535)
  {
    // The remainder 'num' is too large to be shifted left
    // by 16, so we have to add 1 to result manually and
    // adjust 'num' accordingly.
    // num = a - (result + 0.5)^2
    //	 = num + result^2 - (result + 0.5)^2
    //	 = num - result - 0.5
    num -= result;
    num = (num << 16) - 0x8000;
    result = (result << 16) + 0x8000;
  }
  else
  {
    num <<= 16;
    result <<= 16;
  }
  
  bit = 1 << 14;
  */
  vbx(SVW, VSUB, v_t_sub, 65535, v_num);
  vbx(VVWU, VSUB, v_if_num, (vbx_uword_t*)v_num, (vbx_uword_t*)v_result);
  vbx(SVWU, VSHL, v_if_num, 16, v_if_num);
  vbx(SVWU, VADD, v_if_num, (-1*(0x8000)), v_if_num);

  vbx(SVWU, VSHL, v_t_result, 16, (vbx_uword_t*)v_result);
  vbx(SVWU, VADD, v_t_add, (0x8000), v_t_result);
  vbx(SVWU, VSHL, v_else_num, 16, (vbx_uword_t*)v_num);

  vbx(VVWU, VCMV_LTZ, (vbx_uword_t*)v_num, v_if_num, (vbx_uword_t*)v_t_sub);
  vbx(VVWU, VCMV_GEZ, (vbx_uword_t*)v_num, v_else_num, (vbx_uword_t*)v_t_sub);
  vbx(VVWU, VCMV_LTZ, (vbx_uword_t*)v_result, v_t_add, (vbx_uword_t*)v_t_sub);
  vbx(VVWU, VCMV_GEZ, (vbx_uword_t*)v_result, v_t_result, (vbx_uword_t*)v_t_sub);

  vbx(SVWU, VMOV, v_bit, (1<<14), 0);

  max_iter = 8; //1<<14 and >>2 every iter, so 14/2 + 1
  for(i=0; i<max_iter; i++){

    vbx(VVWU, VADD, v_t_add, v_bit, (vbx_uword_t*)v_result);
    vbx(VVWU, VSUB, (vbx_uword_t*)v_t_sub, (vbx_uword_t*)v_num, v_t_add);

    vbx(VVW, VCMV_GEZ, (vbx_word_t*)v_t_num, v_t_sub, v_t_sub);
    vbx(VVW, VCMV_LTZ, (vbx_word_t*)v_t_num, v_num, v_t_sub);

    vbx(SVWU, VSHR, v_t_result, 1, (vbx_uword_t*)v_result);
    vbx(VVWU, VADD, v_t_add, v_bit, v_t_result);
    vbx(VVW, VCMV_GEZ, (vbx_word_t*)v_t_result, (vbx_word_t*)v_t_add, v_t_sub);

    vbx(SVWU, VSHR, v_t_bit, 2, v_bit);

    vbx(VVWU, VCMV_NZ, (vbx_uword_t*)v_num, v_t_num, v_bit);
    vbx(VVWU, VCMV_NZ, (vbx_uword_t*)v_result, v_t_result, v_bit);
    vbx(VVWU, VCMV_NZ, v_bit, v_t_bit, v_bit);
  }

#ifndef FIXMATH_NO_ROUNDING
  /*
	// Finally, if next bit would have been 1, round the result upwards.
	if (num > result)
	{
		result++;
	}
  */
  vbx(VVW, VSUB, v_t_sub, v_num, v_result);
  vbx(SVW, VADD, (vbx_word_t*)v_t_result, 1, v_result);
  vbx(VVW, VCMV_GTZ, v_result, (vbx_word_t*)v_t_result, v_t_sub);
#endif

  /*
	return (neg ? -result : result);
  */
  vbx(SVW, VSUB, (vbx_word_t*)v_t_result, 0, v_result);
  vbx(VVW, VCMV_LTZ, v_result, (vbx_word_t*)v_t_result, v_x);

  vbx_sp_pop();
}

static inline void vbw_fix16_clamp(vbx_word_t* v_out, vbx_word_t* v_x, fix16_t lo, fix16_t hi, vbx_word_t* v_tmp)
{
	//{ return fix16_min(fix16_max(x, lo), hi); }
  vbx(VVW, VMOV, v_out, v_x, 0); //cap overflow
  vbw_fix16_sub_s(v_tmp, lo, v_x);
  vbx(SVW, VCMV_GTZ, v_out, lo, v_tmp); //cap overflow
  vbw_fix16_sub_s(v_tmp, hi, v_x);
  vbx(SVW, VCMV_LTZ, v_out, hi, v_tmp); //cap @ 10
}

#endif // __VBW_FIX16_H
///@}
