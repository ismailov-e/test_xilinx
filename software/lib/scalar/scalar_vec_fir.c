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

#include "scalar_vec_fir.h"

// Scalar FIR filter byte
void scalar_vec_fir_byte(int8_t *output, int8_t *input, const int8_t *const coeffs, const int32_t sample_size, const int32_t num_taps)
{
	int32_t i, j;

	for (j = 0; j <= (sample_size - num_taps); j++) {
		*output = 0;
		for (i = 0; i < num_taps; i++) {
			*output += input[i] * coeffs[i];
		}
		output++;
		input++;
	}
}

// Scalar FIR filter half
void scalar_vec_fir_half(int16_t *output, int16_t *input, const int16_t *const coeffs, const int32_t sample_size, const int32_t num_taps)
{
	int32_t i, j;

	for (j = 0; j <= (sample_size - num_taps); j++) {
		*output = 0;
		for (i = 0; i < num_taps; i++) {
			*output += input[i] * coeffs[i];
		}
		output++;
		input++;
	}
}

// Scalar FIR filter word
void scalar_vec_fir_word(int32_t *output, int32_t *input, const int32_t *const coeffs, const int32_t sample_size, const int32_t num_taps)
{
	int32_t i, j;

	for (j = 0; j <= (sample_size - num_taps); j++) {
		*output = 0;
		for (i = 0; i < num_taps; i++) {
			*output += input[i] * coeffs[i];
		}
		output++;
		input++;
	}
}
// Scalar FIR filter unsigned byte
void scalar_vec_fir_ubyte(uint8_t *output, uint8_t *input, const uint8_t *const coeffs, const int32_t sample_size, const int32_t num_taps)
{
	int32_t i, j;

	for (j = 0; j <= (sample_size - num_taps); j++) {
		*output = 0;
		for (i = 0; i < num_taps; i++) {
			*output += input[i] * coeffs[i];
		}
		output++;
		input++;
	}
}

// Scalar FIR filter unsigned half
void scalar_vec_fir_uhalf(uint16_t *output, uint16_t *input, const uint16_t *const coeffs, const int32_t sample_size, const int32_t num_taps)
{
	int32_t i, j;

	for (j = 0; j <= (sample_size - num_taps); j++) {
		*output = 0;
		for (i = 0; i < num_taps; i++) {
			*output += input[i] * coeffs[i];
		}
		output++;
		input++;
	}
}

// Scalar FIR filter unsigned word
void scalar_vec_fir_uword(uint32_t *output, uint32_t *input, const uint32_t *const coeffs, const int32_t sample_size, const int32_t num_taps)
{
	int32_t i, j;

	for (j = 0; j <= (sample_size - num_taps); j++) {
		*output = 0;
		for (i = 0; i < num_taps; i++) {
			*output += input[i] * coeffs[i];
		}
		output++;
		input++;
	}
}
