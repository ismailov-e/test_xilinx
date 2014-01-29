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
 * @defgroup Vector_Reverse Vector Reverse
 * @brief Reverses a vector *in the scratchpad*
 * @ingroup VBXware
 */
/**@{*/

#ifndef __VBX_VEC_REV_H
#define __VBX_VEC_REV_H

#include <stdlib.h>
#include "vbx.h"

// Macros for simple cases: all pointers and lengths are aligned

/** Reverses a vector of source-aligned words allocated *in the scratchpad*.
 *  - SRC word-aligned
 *  - any N
 *
 *  @param[out] DST *in scratch*.
 *  @param[in] SRC *in scratch*.
 *  @param[in] N is number of words to reverse.
 */
#define vbw_vec_reverse_word_fast(DST,SRC,N) \
VBX_S{ \
  int __i = (int)(N); \
  int __vl, __nrows, __id, __ia, __ib; \
  vbx_get_vl( &__vl ); \
  vbx_set_vl( 1 ); \
  vbx_get_2D( &__nrows, &__id, &__ia, &__ib ); \
  vbx_set_2D( (__i), -sizeof(vbx_word_t), sizeof(vbx_word_t), 0 ); \
  vbx_2D( VVW, VMOV, (DST)+(__i)-1, (SRC), 0 ); \
  vbx_set_2D( __nrows, __id, __ia, __ib ); \
  vbx_set_vl( __vl ); \
}VBX_E

/** Reverses a vector of source-aligned words *in the scratchpad*.
 *  - SRC word-aligned, any N
 *  - Same as @ref vbw_vec_reverse_word_fast, but *without* saving/restoring VL
 *
 *  @param[out] DST *in scratch*.
 *  @param[in] SRC *in scratch*.
 *  @param[in] N is number of words to reverse.
 */
#define vbw_vec_reverse_word_fast_help(DST,SRC,N) \
VBX_S{ \
  int __i = (int)(N); \
  int __nrows, __id, __ia, __ib; \
  vbx_set_vl( 1 ); \
  vbx_get_2D( &__nrows, &__id, &__ia, &__ib ); \
  vbx_set_2D( (__i), -sizeof(vbx_word_t), sizeof(vbx_word_t), 0 ); \
  vbx_2D( VVW, VMOV, (DST)+(__i)-1, (SRC), 0 ); \
  vbx_set_2D( __nrows, __id, __ia, __ib ); \
}VBX_E

/** Reverses a vector of source-aligned halfs *in the scratchpad*.
 *  - SRC word-aligned
 *  - N = multiple of 2
 *
 *  @param[out] DST *in scratch*.
 *  @param[in] SRC *in scratch*.
 *  @param[in] N is number of halfs to reverse.
 */
#define vbw_vec_reverse_half_fast(DST,SRC,N) \
VBX_S{ \
  int __k = (int)(N); \
  int __vl; \
  vbx_get_vl( &__vl ); \
  vbx_uword_t *__vd = (vbx_uword_t *)(DST); \
  vbw_vec_reverse_word_fast_help(((vbx_word_t *)__vd),((vbx_word_t*)(SRC)),(__k)/2); \
  vbx_set_vl( (__k)/2 ); \
  vbx( SVWU, VROTL, __vd, 16, __vd ); \
  vbx_set_vl( __vl ); \
}VBX_E

/** Reverses a vector of source-aligned bytes *in the scratchpad*.
 *  - SRC word-aligned
 *  - N = multiple of 4
 *
 *  @param[out] DST *in scratch*.
 *  @param[in] SRC *in scratch*.
 *  @param[in] N is number of bytes to reverse.
 */
#define vbw_vec_reverse_byte_fast(DST,SRC,N) \
VBX_S{ \
  int __j = (int)(N); \
  int __vl; \
  vbx_get_vl( &__vl ); \
  vbx_uword_t *__vd = (vbx_uword_t *)(DST); \
  vbw_vec_reverse_word_fast_help(((vbx_word_t *)__vd),((vbx_word_t*)(SRC)),(__j)/4); \
  vbx_set_vl((__j)/4 ); \
  vbx( SVWU, VROTL, __vd, 16, __vd ); \
  vbx_set_vl( (__j)/2 ); \
  vbx( SVHU, VROTL, (vbx_uhalf_t *)__vd, 8, (vbx_uhalf_t *)__vd ); \
  vbx_set_vl( __vl ); \
}VBX_E


// Macros to test whether to call simple cases, or complex functions

/** Calls either fast reverse or complex reverse on a vector of words *in the scratchpad*.
 *  Calls fast reverse if:
 *  - SRC word-aligned
 *  - any N
 *
 *  @param[out] DST *in scratch*.
 *  @param[in] SRC *in scratch*.
 *  @param[in] N is number of words to reverse.
 */
#define vbw_vec_reverse_word_safe(DST,SRC,N) \
VBX_S{ \
  int __m = (int)(N); \
  if( VBX_IS_ALIGNED(((int)(SRC)),4) && (__m) < 1400 ) { \
    vbw_vec_reverse_word_fast((DST),(SRC),(__m)); \
  } else {\
    DST = vbw_vec_reverse_word((SRC),(__m)); \
  }\
}VBX_E

/** Calls either fast reverse or complex reverse on a vector of halfs *in the scratchpad*.
 *  Calls fast reverse if:
 *  - SRC word-aligned
 *  - N = multiple of 2
 *
 *  @param[out] DST *in scratch*.
 *  @param[in] SRC *in scratch*.
 *  @param[in] N is number of halfs to reverse.
 */
#define vbw_vec_reverse_half_safe(DST,SRC,N) \
VBX_S{  \
  int __n == (int)(N); \
  if( !((__n)&1) && VBX_IS_ALIGNED(((int)(SRC)),4) && (__n) < 2048 ) { \
    vbw_vec_reverse_half_fast((DST),(SRC),(__n)); \
  } else {\
    DST = vbw_vec_reverse_half((SRC),(__n)); \
  } \
}VBX_E

/** Calls either fast reverse or complex reverse on a vector of bytes *in the scratchpad*.
 *  Calls fast reverse if:
 *  - SRC word-aligned
 *  - N = multiple of 4
 *
 *  @param[out] DST *in scratch*.
 *  @param[in] SRC *in scratch*.
 *  @param[in] N is number of bytes to reverse.
 */
#define vbw_vec_reverse_byte_safe(DST,SRC,N) \
VBX_S{  \
  int __o == (int)(N); \
  if( !((__n)&3) && VBX_IS_ALIGNED(((int)(SRC)),4) && (__o) < 8192 ) { \
    vbw_vec_reverse_byte_fast((DST),(SRC),(__o)); \
  } else { \
    DST = vbw_vec_reverse_byte((SRC),(__o)); \
  } \
}VBX_E

vbx_word_t *vbw_vec_reverse_word( vbx_word_t *v_src, const int N );

vbx_half_t *vbw_vec_reverse_half( vbx_half_t *v_src, const int N );

vbx_byte_t *vbw_vec_reverse_byte( vbx_byte_t *v_src, const int N );

#endif // __VBX_VEC_REV_H
/**@}*/
