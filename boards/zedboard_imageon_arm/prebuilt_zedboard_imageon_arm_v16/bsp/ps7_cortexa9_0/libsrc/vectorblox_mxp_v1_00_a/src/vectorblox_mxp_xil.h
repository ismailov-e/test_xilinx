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


#ifndef __VECTORBLOX_MXP_XIL_H
#define __VECTORBLOX_MXP_XIL_H

#include "xil_assert.h"
#include "xstatus.h"
#include "vbx_types.h"

// An array of these structs is statically initialized with instance-specific
// values (#defines) in the generated file vectorblox_mxp_g.c.
// The field values are passed in from the hardware specification.
// The fields of a vbx_mxp_t instance struct are derived from these values.
typedef struct {
	u16  device_id;
	u32  baseaddr;
	u32  highaddr;
	u16  vector_lanes;
	u32  scratchpad_kb;
	u16  memory_width_bits;
	u8   fxp_word_frac_bits;
	u8   fxp_half_frac_bits;
	u8   fxp_byte_frac_bits;
	u32  core_freq;
	u32  instr_port_addr;
	u8   vci_enabled;
	u16  vci_lanes;
} VectorBlox_MXP_Config;

XStatus VectorBlox_MXP_SelfTest();

int VectorBlox_MXP_Initialize(vbx_mxp_t* mxp, u16 device_id);
VectorBlox_MXP_Config *VectorBlox_MXP_LookupConfig(u16 device_id);

#endif // __VECTORBLOX_MXP_XIL_H
