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


#if __MICROBLAZE__ || __ARM_ARCH_7A__

#include "vbx_copyright.h"
VBXCOPYRIGHT( vectorblox_mxp_xil )

#include "xparameters.h"
#include "vbx.h"
#include "vectorblox_mxp.h"

extern VectorBlox_MXP_Config VectorBlox_MXP_ConfigTable[];

/*****************************************************************************
* Initialize fields of vbx_mxp_t structure and call _vbx_init.
*
* @param	mxp is a pointer to a vbx_mxp_t instance.
* @param	device_id is the unique id of the vbx_mxp peripheral.
*
* @return
*		- XST_SUCCESS if initialization was successful
*		- XST_DEVICE_NOT_FOUND if the device doesn't exist
*
* @note		None.
*
******************************************************************************/

int VectorBlox_MXP_Initialize(vbx_mxp_t* mxp, u16 device_id) {

	VectorBlox_MXP_Config *cfg;

	Xil_AssertNonvoid(mxp != NULL);

	cfg = VectorBlox_MXP_LookupConfig(device_id);

	if (!cfg) {
		return XST_DEVICE_NOT_FOUND;
	}

	mxp->scratchpad_addr = (vbx_void_t *) (cfg->baseaddr);
	// this is cfg->highaddr + 1
	mxp->scratchpad_end  = \
		(vbx_void_t *) (cfg->baseaddr + (cfg->scratchpad_kb * 1024));
	mxp->scratchpad_size = (int) (cfg->scratchpad_kb * 1024);
	mxp->dma_alignment_bytes = (short) (cfg->memory_width_bits / 8);
	mxp->scratchpad_alignment_bytes = (short) (cfg->vector_lanes * 4);
	mxp->vector_lanes = (short) (cfg->vector_lanes);
	mxp->vci_enabled = (char) (cfg->vci_enabled);
	mxp->vci_lanes = (short) (cfg->vci_lanes);
	mxp->fxp_word_frac_bits = (char) (cfg->fxp_word_frac_bits);
	mxp->fxp_half_frac_bits = (char) (cfg->fxp_half_frac_bits);
	mxp->fxp_byte_frac_bits = (char) (cfg->fxp_byte_frac_bits);
	mxp->core_freq = (int) (cfg->core_freq);
	mxp->instr_port_addr = (vbx_void_t *) (cfg->instr_port_addr);
	mxp->instr_p = (uint32_t *) (cfg->instr_port_addr);

	mxp->init = (char) 0;
	// Assuming scratchpad is in a non-cacheable region of the MicroBlaze's
	// address space.
	mxp->sp = (vbx_void_t *) (cfg->baseaddr);
	mxp->spstack = (vbx_void_t **) NULL;
	mxp->spstack_top = (int) 0;
	mxp->spstack_max = (int) 0;

	_vbx_init(mxp);

	return XST_SUCCESS;
}

/*****************************************************************************
*
* Looks up the device configuration based on the unique device ID. The table
* VectorBlox_MXP_ConfigTable contains the configuration info for each device
* in the system.
*
* @param	device_id is the unique device ID to search for in the config
*		table.
*
* @return	A pointer to the configuration that matches the given device ID,
* 		or NULL if no match is found.
*
* @note		None.
*
******************************************************************************/
VectorBlox_MXP_Config *VectorBlox_MXP_LookupConfig(u16 device_id) {

	VectorBlox_MXP_Config *cfg = NULL;
	int i;
	int num_instances;

	num_instances = XPAR_VECTORBLOX_MXP_NUM_INSTANCES;
	for (i = 0; i < num_instances; i++) {
		if (VectorBlox_MXP_ConfigTable[i].device_id == device_id) {
			cfg = &VectorBlox_MXP_ConfigTable[i];
			break;
		}
	}

	return cfg;

}

#endif // __MICROBLAZE__ || __ARM_ARCH_7A__
