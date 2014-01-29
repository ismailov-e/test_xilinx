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


#include "demo.h"
#include <stdio.h>
#include <math.h>
#include "draw.h"
//#include "adventure2.h"

#if DEBUG
extern int stage_count[22];
extern int prev_frame = 999;
#endif

#define SCALE_FACTOR ((int) 1000.0 * 1.25) 
#define INITIAL_ZOOM  ((int) 1000.0 * 8)
#define BIN 4 
#define Y_STEP 1 
#define MIN_NEIGHBORS 3
#define USE_2D 1
#define VECTOR_2D 2 

#define SWAP(x1,x2,tmp) do { tmp=x1; x1=x2; x2=tmp; } while(0)
typedef vbx_uword_t* vptr_uword;
typedef vbx_uhalf_t* vptr_uhalf;
typedef vbx_ubyte_t* vptr_ubyte;
typedef vbx_word_t* vptr_word;
typedef vbx_half_t* vptr_half;
typedef vbx_byte_t* vptr_byte;

void vector_row_to_integrals(vptr_uhalf v_luma_short, vptr_uword v_luma, vptr_uword v_luma2, vptr_uword v_prev_int, vptr_uword v_prev_sq, vptr_uword v_int, vptr_uword v_sq, int num ,int width);

void vector_gen_integrals(short *input, int *integral, int *squared, int width, int height, short window);

void vector_row_haar_2D( vptr_word v_int, vptr_word v_tmp, int win, int width, int vector_2D, int* row_var, int* row_pass, stage *cascade, short max_stage);

void vector_get_img(short *idest, pixel *isrc, short bin, const int image_width, const int image_height, const int image_pitch);

void vector_BLIP(short* img, short height, short width, short* scaled_img, short scaled_height, short scaled_width, short value);

//get a list of features that pass the stages of the haar filter
feat* vector_get_haar_features_image_scaling_2D( stage *cascade, short* img, feat* features, int min_scale, int scale_inc, short reduce, short width , short height, short window, short max_stage);

int vector_face_detect(pixel *input, const int image_width, const int image_height, const int image_pitch);

//generate both the integral image (sum area table) and squared integral image - significanlty reducing loads
void gen_integrals( unsigned short* img, unsigned int* iImg, unsigned int* iiImg, short width, short height);

//calculate the variance of a given window
int get_variance( unsigned int* iImg, unsigned int* iiImg, int x0, int y0, short win, short width);

//sum all weighted rectangular sections of a given feature
int sum_feature( rect* feature, int start, int num_features, unsigned int* iImg, int x0, int y0, short width );

//each feature either passes or fails, adding a value to the stage's total
//a binary value is returned, depending if the stage's total is greater than the stage's threshold
int pass_stage( stage stage, unsigned int* iImg, int x, int y, int var, int win, short width );

//dynamically add features to the feature set -- implemented as a linked list
feat* append_feature(feat* features, int x0, int y0, int w0);

//free all features that had been dynamically allocated
void free_features( feat* features );

//check if two features overlap, indicating they may point to the same object
int overlapped_features( int ax, int ay, int aw , int bx, int by, int bw );

//merge overlapping features, producing a reduced feature list where overlapped features are averaged together
feat* merge_features(feat* raw, feat* merged);

//scales image using bilinear interpolation, to the given percentage
void scalar_BLIP(unsigned short* img, short height, short width, unsigned short* scaled_img, short scaled_height, short scaled_width, float percent);

//get a list of features that pass the stages of the haar filter
feat* scalar_get_haar_features_image_scale( stage *cascade, unsigned short* img, int min_scale, int scale_inc, feat* features, short width, short height, short window, short max_stage );

//find and display the features found in an image using a haar cascade
int scalar_face_detect_luma(unsigned short *input, pixel *output, const int image_width, const int image_height, const int image_pitch);
