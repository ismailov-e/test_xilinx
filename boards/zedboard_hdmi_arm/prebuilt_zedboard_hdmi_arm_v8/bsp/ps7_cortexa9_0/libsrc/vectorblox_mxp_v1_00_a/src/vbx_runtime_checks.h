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


#ifndef __vbx_runtime_checks_h
#define __vbx_runtime_checks_h

#if defined ( VBX_RTC_ALL ) && defined ( VBX_RTC_NONE )
#error Cannot define both VBX_RTC_ALL and VBX_RTC_NONE
#endif

#ifdef VBX_RTC_ALL

#ifndef VBX_RTC_SP_BOUNDS
#define VBX_RTC_SP_BOUNDS
#endif

#ifndef VBX_RTC_COP_FWD
#define VBX_RTC_COP_FWD
#endif

#ifndef VBX_RTC_DMA
#define VBX_RTC_DMA
#endif

#ifndef VBX_RTC_VEC_LEN
#define VBX_RTC_VEC_LEN
#endif

#endif //VBX_RTC_ALL

#if defined ( VBX_RTC_NONE ) || defined ( SKIP_ALL_CHECKS )

#ifdef VBX_RTC_SP_BOUNDS
#undef VBX_RTC_SP_BOUNDS
#endif

#ifdef VBX_RTC_COP_FWD
#undef VBX_RTC_COP_FWD
#endif

#ifdef VBX_RTC_DMA
#undef VBX_RTC_DMA
#endif

#ifdef VBX_RTC_VEC_LEN
#undef VBX_RTC_VEC_LEN
#endif


#endif //VBX_RTC_NONE

#ifndef VBX_RTC_SP_BOUNDS
#  define vbx_chk(...)    vbx_chk_1D_cop_fwd(__VA_ARGS__)
#  define vbx_2D_chk(...) vbx_chk_2D_cop_fwd(__VA_ARGS__)
#  define vbx_3D_chk(...) vbx_chk_3D_cop_fwd(__VA_ARGS__)
#  define vbx_acc_chk(...)
#  define vbx_acc_2D_chk(...)
#  define vbx_acc_3D_chk(...)
#else
#  define vbx_chk(...)        do{vbx_check(__VA_ARGS__)   ; vbx_chk_1D_cop_fwd(__VA_ARGS__);}while(0)
#  define vbx_2D_chk(...)     do{vbx_2D_check(__VA_ARGS__); vbx_chk_2D_cop_fwd(__VA_ARGS__);}while(0)
#  define vbx_3D_chk(...)     do{vbx_3D_check(__VA_ARGS__); vbx_chk_3D_cop_fwd(__VA_ARGS__);}while(0)
#  define vbx_acc_chk(...)    vbx_acc_check(__VA_ARGS__)
#  define vbx_acc_2D_chk(...) vbx_acc_2D_check(__VA_ARGS__)
#  define vbx_acc_3D_chk(...) vbx_acc_3D_check(__VA_ARGS__)
void vbx_check(size_t dest_size, void* dest, size_t srcA_size,
	               void* srcA, size_t srcB_size,void* srcB, vinstr_t v_op);
void vbx_2D_check(size_t dest_size, void* dest, size_t srcA_size,
	                  void* srcA, size_t srcB_size,void* srcB, vinstr_t v_op);
void vbx_3D_check(size_t dest_size, void* dest, size_t srcA_size,
	                  void* srcA, size_t srcB_size,void* srcB, vinstr_t v_op);
void vbx_acc_check(size_t dest_size, void* dest, size_t srcA_size,
	                   void* srcA, size_t srcB_size,void* srcB, vinstr_t v_op);
void vbx_acc_2D_check(size_t dest_size, void* dest, size_t srcA_size,
	                      void* srcA, size_t srcB_size,void* srcB, vinstr_t v_op);
void vbx_acc_3D_check(size_t dest_size, void* dest, size_t srcA_size,
	                      void* srcA, size_t srcB_size,void* srcB, vinstr_t v_op);
#endif //VBX_RTC_SP_BOUNDS

#ifdef VBX_RTC_COP_FWD
#  define vbx_chk_1D_cop_fwd(...) vbx_check_1D_cop_fwd(__VA_ARGS__)
#  define vbx_chk_2D_cop_fwd(...) vbx_check_2D_cop_fwd(__VA_ARGS__)
#  define vbx_chk_3D_cop_fwd(...) vbx_check_3D_cop_fwd(__VA_ARGS__)
void vbx_check_1D_cop_fwd(size_t dest_size, void* dest, size_t srcA_size,
                          void* srcA, size_t srcB_size,void* srcB, vinstr_t v_op);
void vbx_check_2D_cop_fwd(size_t dest_size, void* dest, size_t srcA_size,
                          void* srcA, size_t srcB_size,void* srcB, vinstr_t v_op);
void vbx_check_3D_cop_fwd(size_t dest_size, void* dest, size_t srcA_size,
                          void* srcA, size_t srcB_size,void* srcB, vinstr_t v_op);

#else
#  define vbx_chk_1D_cop_fwd(...)
#  define vbx_chk_2D_cop_fwd(...)
#  define vbx_chk_3D_cop_fwd(...)
#endif


#ifdef VBX_RTC_DMA
#  define vbx_dma_to_host(external,internal,len) \
   vbx_dma_to_host_debug(external,internal,len)
#  define vbx_dma_to_vector(internal,external,len) \
	vbx_dma_to_vector_debug(internal,external,len)
#else
#  define vbx_dma_to_host(external,internal,len) \
	vbx_dma_to_host_nodebug(external,internal,len)
#  define vbx_dma_to_vector(internal,external,len) \
	vbx_dma_to_vector_nodebug(internal,external,len)
#endif //VBX_RTC_DMA


#ifdef VBX_RTC_VEC_LEN
#  define vbx_set_vl(len) vbx_set_vl_debug(len)
#  define vbx_set_2D(nrows,incd,inca,incb) vbx_set_2D_debug(nrows,incd,inca,incb)
#  define vbx_set_3D(nmats,incd,inca,incb) vbx_set_3D_debug(nmats,incd,inca,incb)
#else
#  define vbx_set_vl(len) vbx_set_vl_nodebug(len)
#  define vbx_set_2D(nrows,incd,inca,incb) vbx_set_2D_nodebug(nrows,incd,inca,incb)
#  define vbx_set_3D(nmats,incd,inca,incb) vbx_set_3D_nodebug(nmats,incd,inca,incb)
#endif //VBX_RTC_VEC_LEN


// -------------------------------------------
//              RUNTIME CHECK FLAGS
// (only relevant if enabled at compile time)
// --------------------------------------------

/// set if last runtime check failed, must be manually reset
/// probably only used by tests to check whether the warning
/// had been triggered
extern int RUNTIME_CHECK_FAILED;

extern int runtime_check_suppress;

#define RT_CHECK_SP_BOUND 1<<0
#define RT_CHECK_COP_FWD  1<<1
#define RT_CHECK_DMA      1<<2
#define RT_CHECK_VEC_LEN  1<<3
#define RT_CHECK_ALL      ~0

// if no runtime checks are enabled, make these macros do nothing
#if defined ( VBX_RTC_SP_BOUNDS ) || \
	defined ( VBX_RTC_COP_FWD ) ||\
	defined ( VBX_RTC_DMA ) || \
	defined ( VBX_RTC_VEC_LEN )

/**
 * set check as expressive,
 * \param check runtime check to enable.
 *  legal values are :
 *   RT_CHECK_SP_BOUND
 *   RT_CHECK_COP_FWD
 *   RT_CHECK_DMA
 *   RT_CHECK_VEC_LEN
 *   RT_CHECK_ALL
 */
#define EXPRESS_RT_CHECK(check)  runtime_check_suppress|=(check)
/**
 * suppress check,
 * \param check runtime check to enable.
 *  legal values are :
 *   RT_CHECK_SP_BOUND
 *   RT_CHECK_COP_FWD
 *   RT_CHECK_DMA
 *   RT_CHECK_VEC_LEN
 *   RT_CHECK_ALL
 */
#define SUPPRESS_RT_CHECK(check) runtime_check_suppress&=~(check)
#else

/**
 * set check as expressive,
 * \param check runtime check to enable.
 *  legal values are :
 *   RT_CHECK_SP_BOUND
 *   RT_CHECK_COP_FWD
 *   RT_CHECK_DMA
 *   RT_CHECK_VEC_LEN
 *   RT_CHECK_ALL
 */
#  define EXPRESS_RT_CHECK(check)

/**
 * suppress check,
 * \param check runtime check to enable.
 *  legal values are :
 *   RT_CHECK_SP_BOUND
 *   RT_CHECK_COP_FWD
 *   RT_CHECK_DMA
 *   RT_CHECK_VEC_LEN
 *   RT_CHECK_ALL
 */
#  define SUPPRESS_RT_CHECK(check)
#endif

#endif //__vbx_runtime_checks_h
