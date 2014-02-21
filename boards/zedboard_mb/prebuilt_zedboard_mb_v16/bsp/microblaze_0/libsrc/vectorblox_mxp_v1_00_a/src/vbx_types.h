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
 * @defgroup VBX_types VBX Types
 * @brief VBX Types
 *
 * @ingroup VBXapi
 */



#ifndef __VBX_TYPES_H
#define __VBX_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdint.h>

/**
 * @name Scratchpad Data Typedef
 *
 * Pointers to these datatypes should always be used for scratchpad accesses
 */
/**@{*/

#if defined( __GNUC__)
typedef uint32_t vbx_uword_t; ///< 4-byte word, unsigned
typedef uint16_t vbx_uhalf_t; ///< 2-byte half, unsigned
typedef uint8_t vbx_ubyte_t;  ///< byte, unsigned
typedef int32_t vbx_word_t;   ///< 4-byte word
typedef int16_t vbx_half_t;   ///< 2-byte half
typedef int8_t vbx_byte_t;    ///< byte
typedef void vbx_void_t;      ///< void, used for generic pointers
#endif

/*
 * If not compiling with gcc, it would have to be verified that values loaded into
 * registers are not reused across vbx_sync() call. Under gcc this is true. If unsure
 * you can define types using'volatile' as below, with a potential performance penalty
 * for scratchpad accesses:
 *
 *  typedef volatile uint32_t vbx_uword_t; ///< 4-byte word, unsigned
 *  typedef volatile uint16_t vbx_uhalf_t; ///< 2-byte half, unsigned
 *  typedef volatile uint8_t vbx_ubyte_t;  ///< byte, unsigned
 *  typedef volatile int32_t vbx_word_t;   ///< 4-byte word
 *  typedef volatile int16_t vbx_half_t;   ///< 2-byte half
 *  typedef volatile int8_t vbx_byte_t;    ///< byte
 *  typedef volatile void vbx_void_t;      ///< void, used for generic pointers
 *
 */

typedef void vbx_enum_t; ///< Enumerated type, used for type checking c/cpp
/**@}*/


// 1D, 2D, and 3D address generator state
//
// NB: the order of entries must exactly follow the MXP register order.
//     be wary of gaps: the vbx_simulator wants this structure to be packed
//     and hold up to 32 entries, hence it requires dummy fill for gaps.
//     however, this will waste space when saving these cpu state on the
//     sp_stack.

/** Struct containing VBX 1D Instruction Setup */
typedef struct {
	uint32_t vl; ///< 1D vector length measured by the data type being used
} vbx_1d_t;

/** Struct containing entire VBX 2D Instruction Setup */
typedef struct {
	uint32_t vl; ///< 1D vector length measured by the data type being used
	uint32_t nrows; ///< Number of times the 1D operation will be repeated
	int32_t id2, ia2, ib2; ///< Offset applied to destination and source vectors before repeating 1D operation
} vbx_2d_t;

/** Struct containing entire VBX 3D Instruction Setup*/
typedef struct {
	uint32_t vl; ///< 1D vector length measured by the data type being used
	uint32_t nrows; ///< Number of times the 1D operation will be repeated
	int32_t id2, ia2, ib2; ///< Offset applied to destination and source vectors before repeating 1D operation
	uint32_t nmats;  ///< Number of times the 2D operation will be repeated
	int32_t id3, ia3, ib3;///< Offset applied to destination and source vectors before repeating 2D operation
} vbx_3d_t;



/** MXP processor state*/
typedef struct {

	/* Fixed MXP CPU characteristics */
	vbx_void_t  *scratchpad_addr; ///< Start address of the scratchpad memory
	vbx_void_t  *scratchpad_end; ///< End address of the scratchpad memory
#if __ARM_ARCH_7A__
	vbx_void_t  *instr_port_addr;
	uint32_t    *instr_p;
	uint8_t     instr_offs;
#endif
	int         scratchpad_size; ///< Size of the scratchpad memory
	int         core_freq; ///< MXP processor frequency
	short       dma_alignment_bytes;
	short       scratchpad_alignment_bytes;
	short       vector_lanes; ///< Num of 32-bit vector lanes
	short       vci_lanes; ///<Num of custom instruction lanes
	char        fxp_word_frac_bits; ///< Num of fractional bit used with @ref vbx_word_t or @ref vbx_uword_t data types
	char        fxp_half_frac_bits; ///< Num of fractional bit used with @ref vbx_half_t or @ref vbx_uhalf_t data types
	char        fxp_byte_frac_bits; ///< Num of fractional bit used with vbx_byte_t or f vbx_ubyte_t data types

	/* MXP flags */
	char        init;

	/* MXP run-time state */
	vbx_void_t  *sp; ///< Current location of scratchpad pointer
	vbx_void_t  **spstack;
	int         spstack_top;
	int         spstack_max;

} vbx_mxp_t;

/**
	* @name VBX Instruction Set
	* @brief Valid Instructions
 */
typedef
enum {
	VMOV,  ///< Moves src operand to dst
	VAND,  ///< Bitwise AND of two src operands
	VOR,   ///< Bitwise OR of two src operands
	VXOR,  ///< Bitwise XOR of two src operands
	VADD,  ///< Adds the two src operands, carry flag generated
	VSUB,  ///< Subtracts the two src operands, borrow flag generated
	VADDC, ///< Adds the two src operands, performs
	VSUBB, ///< Subtracts the two src operands, performs
	VMUL,  ///< Multiplies the two src operands, saves lower result to dst
	VMULLO=VMUL, ///< Multiplies the two src operands, saves lower result to dst
	VMULHI, ///< Multiplies the two src operands, saves upper result to dst
	VMULFXP,///< Fix-point multiply, where the number of fractional bits is set at compile time
	VSHL,  ///< Shifts src operand to left by given amount
	VSHR,  ///< Shifts src operand to right by given amount
	VROTL, ///< Rotates src operand to left by given amount
	VROTR, ///< Rotates src operand to right by given amount
	VCMV_LEZ, ///< Moves src operand to dst if <= 0
	VCMV_GTZ, ///< Moves src operand to dst if >  0
	VCMV_LTZ, ///< Moves src operand to dst if < 0
	VCMV_FS=VCMV_LTZ,
	VCMV_GEZ, ///< Moves src operand to dst if >= 0
	VCMV_FC=VCMV_GEZ,
	VCMV_Z, ///< Moves src operand to dst if == 0
	VCMV_NZ, ///< Moves src operand to dst if != 0
	VABSDIFF, ///< Calculates the absolute difference between the two src operands
	VCUSTOM0, ///<
	VCUSTOM=VCUSTOM0, ///<
	VCUSTOM1, ///<
	VCUSTOM2, ///<
	VCUSTOM3 ///<
} vinstr_t;


#ifdef __cplusplus
}
#endif


#endif //__VBX_TYPES_H
