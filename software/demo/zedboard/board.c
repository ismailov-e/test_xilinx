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
VBXCOPYRIGHT( board_zedboard )

#include "board.h"

///////////////////////////////////////////////////////////////////////////
// map switch value to mode number.
int slide_switches(XGpio *slide_switches)
{
	u32 r = XGpio_DiscreteRead(slide_switches, 1) & 0x7;
	switch (r) {
	case SWITCH_VECTOR_SPLIT:
		return MODE_VECTOR_SPLIT;
	case SWITCH_SCALAR_SPLIT:
		return MODE_SCALAR_SPLIT;
	case SWITCH_VECTOR_MANDEL:
		return MODE_VECTOR_MANDEL;
	case SWITCH_SCALAR_MANDEL:
		return MODE_SCALAR_MANDEL;
	case SWITCH_VECTOR_REPULSION:
		return MODE_VECTOR_REPULSION;
	case SWITCH_SCALAR_REPULSION:
		return MODE_SCALAR_REPULSION;
	case SWITCH_VECTOR_MANDEL2:
		return MODE_VECTOR_MANDEL;
	case SWITCH_SCALAR_MANDEL2:
		return MODE_SCALAR_MANDEL;
	default:
		return MODE_VECTOR_MANDEL;
	}
}

///////////////////////////////////////////////////////////////////////////
int application_mode(demo_t *pDemo, int local_mode)
{
	return slide_switches(&(pDemo->slide_switches));
}

///////////////////////////////////////////////////////////////////////////
int escape_application(demo_t *pDemo, int local_mode)
{
	if (application_mode(pDemo, local_mode) != local_mode) {
		return 1;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////
void board_init()
{
}

///////////////////////////////////////////////////////////////////////////
