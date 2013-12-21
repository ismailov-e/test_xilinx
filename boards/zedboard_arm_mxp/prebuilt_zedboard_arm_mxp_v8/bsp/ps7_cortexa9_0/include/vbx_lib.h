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

/**
 * @file
 * @defgroup VBX_lib
 * @brief VBX library
 *
 * @ingroup VBXapi
 */
/**@{*/

#ifndef __VBX_LIB_H
#define __VBX_LIB_H

#ifdef __cplusplus
extern "C" {
#endif

void vbx_sync();

/** Set the 1D length of vector to operate on.
 *
 * @param[in] LENGTH -- number of units to operate on
 */
void vbx_set_vl( int  LENGTH );

/** Gets the value of length of vector to operate on, saves value to LENGTH.
 *
 * @param[out] LENGTH
 */
void vbx_get_vl( int *LENGTH );

/** Sets the value stored at REGADDR to VALUE.
 *
 * @param[in] REGADDR
 * @param[in] VALUE
 */
void vbx_set_reg( int REGADDR, int  VALUE );

/** Gets the value at REGADDR, saves the value to VALUE.
 *
 * @param[in] REGADDR
 * @param[out] VALUE
 */
void vbx_get_reg( int REGADDR, int *VALUE );

/** Set the 2D vector to operate on.
 * Increments applied after every row of 1D vector operation
 * 1D operation of length set @ref vbx_set_vl, repeated @a ROWS times
 *
 *
 * @param[in] ROWS -- number of rows to repeat 1D vector op
 * @param[in] ID -- 2D increment of DEST
 * @param[in] IA -- 2D increment of SRCA
 * @param[in] IB -- 2D increment of SRCB
 */
void vbx_set_2D( int  ROWS, int  ID,   int  IA,   int  IB   );

/** Set the 3D vector to operate on.
 * 3D increments applied after every row of 2D vector operation
 * 1D operation of length set @ref vbx_set_vl, repeated @a ROWS times
 * 2D operation of length set @ref vbx_set_2D, repeated @a MATS times
 *
 * @param[in] MATS -- number of times to repeat 2D vector op
 * @param[in] ID3D -- 3D increment of DEST
 * @param[in] IA3D -- 3D increment of SRCA
 * @param[in] IB3D -- 3D increment of SRCB
 */
void vbx_set_3D( int  MATS, int  ID3D, int  IA3D, int  IB3D );

/** Get the 2D vector parameters.
 *
 * @param[out] ROWS -- number of rows to repeat 1D vector op
 * @param[out] ID -- 2D increment of DEST
 * @param[out] IA -- 2D increment of SRCA
 * @param[out] IB -- 2D increment of SRCB
 */
void vbx_get_2D( int *ROWS, int *ID,   int *IA,   int *IB   );

/** Get the 3D vector parameters.
 *
 * @param[out] MATS -- number of times to repeat 2D vector op
 * @param[out] ID3D -- 3D increment of DEST
 * @param[out] IA3D -- 3D increment of SRCA
 * @param[out] IB3D -- 3D increment of SRCB
 */
void vbx_get_3D( int *MATS, int *ID3D, int *IA3D, int *IB3D );

/** Use DMA engine to transfer values in scratchpad to host
 *
 * @param[out] EXT -- host destination address
 * @param[in] INT -- scratchpad sourc address
 * @param[in] LENGTH -- number of **bytes** to transfer
 */
void vbx_dma_to_host(           void       *EXT, vbx_void_t *INT, int LENGTH );

/** Use DMA engine to transfer values in scratchpad to host -- aligned
 *
 * @param[out] EXT -- host destination address
 * @param[in] INT -- scratchpad sourc address
 * @param[in] LENGTH -- number of **bytes** to transfer
 */
void vbx_dma_to_host_aligned(   void       *EXT, vbx_void_t *INT, int LENGTH );

/** Use DMA engine to transfer values from host to scratchpad
 *
 * @param[out] INT -- host destination address
 * @param[in] EXT -- scratchpad sourc address
 * @param[in] LENGTH -- number of **bytes** to transfer
 */
void vbx_dma_to_vector(         vbx_void_t *INT, void       *EXT, int LENGTH );

/** Use DMA engine to transfer values from host to scratchpad -- aligned
 *
 * @param[out] INT -- host destination address
 * @param[in] EXT -- scratchpad sourc address
 * @param[in] LENGTH -- number of **bytes** to transfer
 */
void vbx_dma_to_vector_aligned( vbx_void_t *INT, void       *EXT, int LENGTH );

/** 2D DMA transfer from scratchpad to host
 *
 * @param[out] dst -- destination address in external memory
 * @param[in] v_src -- source address in scratchpad memory
 * @param[in] xlen -- number of bytes to transfer
 * @param[in] ylen -- number of rows to transfer
 * @param[in] dst_stride -- stride of dst in bytes
 * @param[in] src_stride  -- stride of src in bytes
 */
void vbx_dma_to_host_2D  ( void *dst, vbx_void_t *v_src, uint32_t xlen, uint32_t ylen, int32_t dst_stride, int32_t src_stride );

/** 2D DMA transfer from host to scratchpad
 *
 * @param[out] v_src -- destination address in scratchpad memory
 * @param[in] dst -- source address in external memory
 * @param[in] xlen -- number of bytes to transfer
 * @param[in] ylen -- number of rows to transfer
 * @param[in] dst_stride -- stride of dst in bytes
 * @param[in] src_stride  -- stride of src in bytes
 */
void vbx_dma_to_vector_2D( vbx_void_t *v_dst, void *src, uint32_t xlen, uint32_t ylen, int32_t dst_stride, int32_t src_stride );

void vbx_sp_mark( uint32_t mark );
int  vbx_sp_checkmark( uint32_t mark );

// Unfinished and untested, do not use
vbx_void_t *vbx_sp_malloc_extra( size_t num_bytes);
void        vbx_sp_free_extra( vbx_void_t *old_sp );

#if VBX_ASSEMBLER
#if __NIOS2__
// Dummy calls (only used for the simulator)
// first, force these function prototypes to inline, even if the gcc optimizer is off
inline void vbxsim_init( int num_lanes, int scratchpad_capacity_kb ) __attribute__((always_inline));
inline void vbxsim_destroy() __attribute__((always_inline));
// second, define the inline functions; 'extern' ensures there no addressable/linkable function body is created
extern inline void vbxsim_init( int num_lanes, int scratchpad_capacity_kb )
{ }
extern inline void vbxsim_destroy()
{ }
#else // __MICROBLAZE__ or ARM on Zynq

#include "vbx_extern.h"

// XXX The inline function declarations cause problems with mb-gcc when
// vbx_api.c and vbx_lib.c are compiled into the same library, possibly
// because both files include this header file.
// For now, replacing the functions with empty macros.
#define vbxsim_init(num_lanes, scratchpad_capacity_kb) do{}while(0)
#define vbxsim_destroy() do{}while(0)
#endif
#endif // VBX_ASSEMBLER

#if VBX_SIMULATOR
// Stubs for the simulator
void vbxsim_init( int num_lanes, int scratchpad_capacity_kb );
void vbxsim_destroy();
#endif


#ifdef __cplusplus
}
#endif

#endif // __VBX_LIB_H
/**@}*/
