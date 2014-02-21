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
 * @defgroup VBX_port VBX portability Library
 * @brief VBX port
 *
 * @ingroup VBXapi 
 */
/**@{*/

#ifndef __VBX_PORT_H
#define __VBX_PORT_H

#ifdef __cplusplus
extern "C" {
#endif


#if VBX_ASSEMBLER

// Why is this in the portability section?
// Perhaps it should be moved to vbx_macros.

/** Converts timestamp cycles into mxp cycles
 *
 * @param[in] TS_CYCLES
 */
#define vbx_mxp_cycles(TS_CYCLES) \
	({ \
		vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP(); \
		float ts_freq   = (float) vbx_timestamp_freq(); \
		float mxp_freq  = (float) this_mxp->core_freq; \
		(vbx_timestamp_t)( ((float) (TS_CYCLES)) * (mxp_freq/ts_freq) ); \
	})

#if __NIOS2__
///////////////////////////////////////////////////////////////////////////
// Altera portability library
///////////////////////////////////////////////////////////////////////////

#include <sys/alt_timestamp.h>
#include <sys/alt_cache.h>

#define VBX_CPU_DCACHE_SIZE      ALT_CPU_DCACHE_SIZE
#define VBX_CPU_DCACHE_LINE_SIZE ALT_CPU_DCACHE_LINE_SIZE

/** Start the timestamp timer for subsequent @ref vbx_timestamp calls */
#define vbx_timestamp_start()	        alt_timestamp_start()

/** Get the timestamp frequency
 *
 * @retval Returns the timestamp frequency
 */
#define vbx_timestamp_freq()	        alt_timestamp_freq()

/** Get a the timestamp value
 *
 * @retval Returns current timestamp
 */
#define vbx_timestamp()	                alt_timestamp()

typedef alt_timestamp_type vbx_timestamp_t;

/** Malloc *external* memory *uncached*
 *
 * @param[in] BYTES -- Number of bytes to allocate uncached
 * @retval Return void pointer to start of uncached memory
 */
#define vbx_uncached_malloc(BYTES)	alt_uncached_malloc(BYTES)

/** Free *external uncached* memory
 *
 * @param[in] PTR -- Uncached address in external memory
 */
#define vbx_uncached_free(PTR)		alt_uncached_free(PTR)


/** Flush entire data cache */
#define vbx_dcache_flush_all()	        	alt_dcache_flush_all()

/** Flush line from data cache
 *
 * @param[in] PTR -- Address from where data cache line will be flushed
 */
#define vbx_dcache_flush_line(PTR)	       	alt_dcache_flush(PTR,1)

/** Flush range from data cache 
 *
 * @param[in] PTR -- Start address *in external memory*
 * @param[in] LEN -- Number of bytes to flush from data cache
 */
#define vbx_dcache_flush(PTR,LEN) \
	VBX_S { \
		int __len__ = (LEN); \
		if( __len__ > 4*ALT_CPU_DCACHE_SIZE ) { \
			alt_dcache_flush_all(); \
		} else { \
			alt_dcache_flush(PTR,__len__); \
		} \
	} VBX_E

/** Allow memory region to be cached
 *
 * @param[in] PTR -- Start of address *in external memory*
 * @param[in] LEN -- Number of bytes to remap as cached
 */
#define vbx_remap_cached(PTR,LEN)			alt_remap_cached(PTR,LEN)

/** Exclude memory region from being cached
 *
 * @param[in] PTR -- Start of address *in external memory*
 */
#define vbx_remap_uncached(PTR)				alt_remap_uncached(PTR,1)

/** Exclude memory region from being cached **and flush**
 *
 * @param[in] PTR -- Start of address *in external memory*
 * @param[in] LEN -- Number of bytes to flush
 */
#define vbx_remap_uncached_flush(PTR,LEN)	\
	({ \
		void* __ptr__ = (void *)(PTR); \
		vbx_dcache_flush(__ptr__,LEN); \
		alt_remap_uncached(__ptr__,1); \
	})

#elif __MICROBLAZE__
///////////////////////////////////////////////////////////////////////////
// Xilinx MicroBlaze portability library
///////////////////////////////////////////////////////////////////////////
#include "xparameters.h"
#include "xil_types.h"
#include "xil_cache.h"
#ifdef XPAR_XTMRCTR_NUM_INSTANCES
#include "xtmrctr.h"
#endif

#define VBX_CPU_DCACHE_SIZE      XPAR_MICROBLAZE_DCACHE_BYTE_SIZE
#define VBX_CPU_DCACHE_LINE_SIZE (4*(XPAR_MICROBLAZE_DCACHE_LINE_LEN))

typedef u32 vbx_timestamp_t;

void vbx_timestamp_init(XTmrCtr *inst_ptr, u32 freq);
int vbx_timestamp_start();
u32 vbx_timestamp_freq();
u32 vbx_timestamp();

volatile void* vbx_uncached_malloc(size_t size);
void vbx_uncached_free(volatile void *p);

#define vbx_dcache_flush_all()         Xil_DCacheFlush()
#define vbx_dcache_flush_line(PTR)     Xil_DCacheFlushRange((u32) (PTR), 1)
#define vbx_dcache_flush(PTR,LEN) \
	VBX_S { \
		int __len__ = (LEN); \
		if( __len__ > 4*VBX_CPU_DCACHE_SIZE ) { \
			Xil_DCacheFlush(); \
		} else { \
			Xil_DCacheFlushRange((u32) (PTR),__len__); \
		} \
	} VBX_E

void *vbx_remap_cached(volatile void *p, u32 len);
volatile void *vbx_remap_uncached(void *p);
volatile void *vbx_remap_uncached_flush(void *p, u32 len);

#elif __ARM_ARCH_7A__ // Xilinx only
///////////////////////////////////////////////////////////////////////////
// Xilinx Zynq PS7 ARM Cortex-A9
///////////////////////////////////////////////////////////////////////////
#include "xparameters.h"
#include "xil_types.h"
#include "xil_cache.h"
#ifdef XPAR_XTMRCTR_NUM_INSTANCES
#include "xtmrctr.h"
#endif

// Cortex-A9 on Zynq:
// L1 dcache is 32KB, 4-way set-associative, write-back.
// L2 (unified) cache is 512KB, 8-way set-associative, write-through OR write-back.
// Both use a 32-byte line size.
//
// XXX
// NOTE: if the MXP DMA is connected to the ACP,
// dcache flushing should not be necessary for sharing data with MXP.

#define VBX_CPU_DCACHE_SIZE      32768
#define VBX_CPU_DCACHE_LINE_SIZE    32

#if VBX_USE_A9_PMU_TIMER
#include "xtime_l.h"
typedef XTime vbx_timestamp_t;
void vbx_timestamp_init(u32 freq);
#else
typedef u32 vbx_timestamp_t;
void vbx_timestamp_init(XTmrCtr *inst_ptr, u32 freq);
#endif

int vbx_timestamp_start();
u32 vbx_timestamp_freq();
vbx_timestamp_t vbx_timestamp();

volatile void* vbx_uncached_malloc(size_t size);
void vbx_uncached_free(volatile void *p);

#define vbx_dcache_flush_all()         Xil_DCacheFlush()
#define vbx_dcache_flush_line(PTR)     Xil_DCacheFlushRange((u32) (PTR), 1)
#define vbx_dcache_flush(PTR,LEN)      Xil_DCacheFlushRange((u32) (PTR), (LEN))

void *vbx_remap_cached(volatile void *p, u32 len);
volatile void *vbx_remap_uncached(void *p);
volatile void *vbx_remap_uncached_flush(void *p, u32 len);

#endif // __NIOS2__ / __MICROBLAZE__ / __ARM_ARCH_7A__


#endif // VBX_ASSEMBLER

///////////////////////////////////////////////////////////////////////////
#if VBX_SIMULATOR
#include "vbxsim_port.h"
#endif // VBX_SIMULATOR

#ifdef __cplusplus
}
#endif

#endif // __VBX_PORT_H
/**@}*/
