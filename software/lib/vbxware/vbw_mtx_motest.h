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
 * @file vbw_mtx_motest.h
 * @defgroup Matrix_Motion_Estimation Matrix Motion Estimation
 * @brief Matrix Motion Estimation
 * @ingroup VBXware 
 */
/**@{*/

#ifndef __VBX_MTX_MOTEST_H
#define __VBX_MTX_MOTEST_H

//
// Motion Estimation
// Scalar NIOS version and vbx VECTOR version
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "vbx.h"

#if 1 // BENCHMARK SETTINGS

#define BLOCK_HEIGHT  16
#define BLOCK_WIDTH   16
#define IMAGE_WIDTH   96
#define IMAGE_HEIGHT  96
#define SEARCH_WIDTH  16
#define SEARCH_HEIGHT 16

#else // TESTING SETTINGS

#define BLOCK_HEIGHT  16
#define BLOCK_WIDTH   16
#define IMAGE_WIDTH   256
#define IMAGE_HEIGHT  256
#define SEARCH_WIDTH  64
#define SEARCH_HEIGHT 64

#endif


#define BLOCK_SIZE    (BLOCK_WIDTH*BLOCK_HEIGHT)
#define IMAGE_SIZE    (IMAGE_WIDTH*IMAGE_HEIGHT)



typedef unsigned char  input_type;
typedef unsigned short intermediate_type;
typedef unsigned int   output_type;

#define RESULT_SIZE (SEARCH_WIDTH*SEARCH_HEIGHT*sizeof(output_type))

void vbw_mtx_motest_scalar_byte  (output_type *result, input_type *x, input_type *y);

int  vbw_mtx_motest_byte         (output_type *result, input_type *x, input_type *y);

int  vbw_mtx_motest_3d_byte      (output_type *result, input_type *x, input_type *y);

int  vbw_mtx_motest_byte_setup   ();

int  vbw_mtx_motest_3d_byte_setup();

#endif // __VBX_MTX_MOTEST_H
/**@}*/
