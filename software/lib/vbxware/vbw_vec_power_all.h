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


#ifndef __VBX_VEC_POWER_ALL_H
#define __VBX_VEC_POWER_ALL_H

#include "vbx.h"

// Now, include the H file six times
// First three for byte, half, word
// Next three for ubyte, uhalf, uword

#ifdef VBX_TEMPLATE_T
#error Do not define VBX_TEMPLATE_T before including this file.
#endif

#define VBX_TEMPLATE_T VBX_BYTESIZE_DEF
#include "vbw_vec_power_t.h"

#undef VBX_TEMPLATE_T
#define VBX_TEMPLATE_T VBX_HALFSIZE_DEF
#include "vbw_vec_power_t.h"

#undef VBX_TEMPLATE_T
#define VBX_TEMPLATE_T VBX_WORDSIZE_DEF
#include "vbw_vec_power_t.h"

#undef VBX_TEMPLATE_T
#define VBX_TEMPLATE_T VBX_UBYTESIZE_DEF
#include "vbw_vec_power_t.h"

#undef VBX_TEMPLATE_T
#define VBX_TEMPLATE_T VBX_UHALFSIZE_DEF
#include "vbw_vec_power_t.h"

#undef VBX_TEMPLATE_T
#define VBX_TEMPLATE_T VBX_UWORDSIZE_DEF
#include "vbw_vec_power_t.h"

#undef VBX_TEMPLATE_T

#endif // __VBX_VEC_POWER_ALL_H
