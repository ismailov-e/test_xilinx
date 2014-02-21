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


#ifndef __DEMO_H
#define __DEMO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "pixel.h"
#include "haar.h"

#if SYSTEM_VEEK
#include "../common/demo_t.h"
#include "../veek/board.h"
#elif SYSTEM_DE4
#include "../common/demo_t.h"
#include "../de4_dvi/board.h"
#elif SYSTEM_DE2_115
#include "../common/demo_t.h"
#include "../de2_115/board.h"
#elif SYSTEM_ZEDBOARD
#include "../zedboard/demo_t.h"
#include "../zedboard/board.h"
#elif SYSTEM_ZEDBOARD_IMAGEON
#include "../zedboard_imageon/demo_t.h"
#include "../zedboard_imageon/board.h"
#endif

demo_t demo;

//FIXME assumes MXP declared as 'VBX1'
//fixed point divide @ custom0
//fixed point sqrt   @ custom1
//particle repulsion @ custom3
#if VBX1_VCI_LANES 
#define USE_CUSTOM_DIVIDE 1
#define USE_CUSTOM_SQRT   1
#define USE_CUSTOM_FULL   1
#else
#define USE_CUSTOM_DIVIDE 0
#define USE_CUSTOM_SQRT   0
#define USE_CUSTOM_FULL   0
#endif

// Scalar/vector modes for a given algorithm should be numbered consecutively
// with the scalar version coming first. (Arrays are indexed using these mode
// numbers.)
#define NUM_MODES              16
#define MODE_PASSTHRU           0
#define MODE_PASSTHRU2          1
#define MODE_SCALAR_FACE_DETECT 2
#define MODE_VECTOR_FACE_DETECT 3
#define MODE_SCALAR_EDGE_DETECT 4
#define MODE_VECTOR_EDGE_DETECT 5
#define MODE_SCALAR_MOTEST      6
#define MODE_VECTOR_MOTEST      7
#define MODE_SCALAR_MANDEL      8
#define MODE_VECTOR_MANDEL      9
#define MODE_SCALAR_REPULSION   10
#define MODE_VECTOR_REPULSION   11
#define MODE_SCALAR_MULTI       12
#define MODE_VECTOR_MULTI       13
#define MODE_SCALAR_SPLIT       14
#define MODE_VECTOR_SPLIT       15

#define IMAGE_COLOR_DEPTH 32

//Video buffers and numbers
#define VIDEO_BUFFERS        5
#define BUFFER_READING       0
#define BUFFER_PROCESSING    1
#define BUFFER_READY         2
#define BUFFER_TRANSFERRING  3
#define BUFFER_NEXT_TRANSFER 4

//Filter coefficients
//#define SOBEL_BRUTE_FORCE
#define SOBEL_NO_LOOP
#define FILTER_3X3
#ifdef FILTER_3X3
#define FILTER_COEFFICIENTS_X {{-1,0,1},{-2,0,2},{-1,0,1}}
#define FILTER_COEFFICIENTS_Y {{-1,-2,-1},{0,0,0},{1,2,1}}
#define FILTER_WIDTH  3
#define FILTER_HEIGHT 3
#define FILTER_SIZE (FILTER_WIDTH*FILTER_HEIGHT)
#define RENORM_AMOUNT 0//FIXME was 2
#else
#define FILTER_COEFFICIENTS_X {{-1,-2,0,2,1},{-4,-8,0,8,4},{-6,-12,0,12,6},{-4,-8,0,8,4},{-1,-2,0,2,1}}
#define FILTER_COEFFICIENTS_Y {{-1,-4,-6,-4,-1},{-2,-8,-12,-8,-2},{0,0,0,0,0},{2,8,12,8,2},{1,4,6,4,1}}
#define FILTER_WIDTH  5
#define FILTER_HEIGHT 5
#define FILTER_SIZE (FILTER_WIDTH*FILTER_HEIGHT)
#define RENORM_AMOUNT 6
#endif

//To avoid overflow in the greennes detect algorithm
#define GREENNESS_SCALING_PER_LINE 5

//In demo.c
#define DISPLAY_FPS
void draw_logo(pixel *buffer, int vector);
void draw_vblogo(pixel *bg, int vector);
void display_logo(demo_t *pDemo, int uses_video_in, int vector_overlay);
float time_to_ms(vbx_timestamp_t time);

//In scalar_functions.c
void scalar_draw_char(unsigned char char_to_draw, int startx, int starty, pixel *buffer);
int scalar_overlay_printf(char *print_string, int startx, int starty, int max_length, pixel *buffer);
void scalar_draw_vblogo(int startx, int starty, pixel *buffer);
int scalar_green_detect(pixel *input, int *avg_y, int *avg_x);
void scalar_invert_image(pixel *image, const int image_width, const int image_height, const int image_pitch);
int scalar_edge_detect(pixel *input, pixel *output);
void scalar_to_luma(pixel *input, short *output);
int scalar_edge_detect_luma(short *input, pixel *output);
int scalar_edge_detect_luma_3x3(short *input, pixel *output);

//In vector_functions.c
void vector_draw_alpha(int startx, int starty, pixel *bg, pixel *fg, int size_x, int size_y);
void vector_draw_char(unsigned char char_to_draw, int startx, int starty, pixel *buffer);
int vector_overlay_printf(char *print_string, int startx, int starty, int max_length, pixel *buffer);
void vector_invert_image(pixel *image, const int image_width, const int image_height, const int image_pitch);
void vector_brighten_image(pixel *image, unsigned char brighten_amount);
void vector_flip_image(pixel *input, pixel *output);
void vector_flip_vertical(pixel *input, pixel *output);
void vector_flip_vertical_simple(pixel *input, pixel *output);
int vector_green_detect(pixel *input, pixel *temp_buffer, int *avg_y, int *avg_x, int *x_weights);

//In mandel.c
int mandelbrot( pixel *buffer, int vector_mode );

//In hough.c
void init_hough(void);
int scalar_hough(pixel *edge_buffer, pixel *output_buffer);

//In motest.c
typedef unsigned short luma_type;
void init_scalar_motest(pixel *input_buffer, luma_type **last_luma, int *motest_x, int *motest_y, int x, int y, const int image_width);
int scalar_motest(pixel *input_buffer, luma_type **last_luma, int *motest_x, int *motest_y, int start_x, int start_y, int reset, const int image_width, const int image_height, const int image_pitch);
void init_vector_motest(pixel *input_buffer, luma_type **last_luma, int *motest_x, int *motest_y, int x, int y, const int image_width);
int vector_motest(pixel *input_buffer, luma_type **last_luma, int *motest_x, int *motest_y, int start_x, int start_y, int reset, const int image_width, const int image_height, const int image_pitch);

//In vector_haar_detect.c and scalar_haar_detect.c
int scalar_face_detect_luma(unsigned short *input, pixel *output, const int image_width, const int image_height, const int image_pitch);
int vector_face_detect(pixel *input,  const int image_width, const int image_height, const int image_pitch);

//In draw.c
void draw_square(int startx, int starty, int width, int height, pixel* color, pixel *output_buffer);

//In gravity.c
void lissajous( int *gravity_x, int *gravity_y, int cycles );


//In char_buffer.c
#define CHAR_BUFFER_WIDTH (16)
#define CHAR_BUFFER_HEIGHT (2090)
#define CHAR_BUFFER_BYTES_PER_PIXEL (4) /* 3:RGB, 4:RGBA */
extern const unsigned char CHAR_BUFFER_pixel_data[CHAR_BUFFER_WIDTH * CHAR_BUFFER_HEIGHT * CHAR_BUFFER_BYTES_PER_PIXEL + 1];
#define CHAR_BUFFER_PIXEL_DATA ((unsigned char*) CHAR_BUFFER_pixel_data)
//Char defines
#define MIN_CHAR ' '
#define NUM_CHARS 95
#define CHAR_HEIGHT ((CHAR_BUFFER_HEIGHT)/(NUM_CHARS))
#define CHAR_WIDTH  CHAR_BUFFER_WIDTH
#define MAX_CHAR ((MIN_CHAR)+(NUM_CHARS))

#define CHAR_SIZE_BYTES ((CHAR_HEIGHT)*(CHAR_WIDTH)*(CHAR_BUFFER_BYTES_PER_PIXEL))

#define MAX_STRING_LENGTH ((int)(((IMAGE_WIDTH)/(CHAR_WIDTH))+1))

//In vblogo.c
#define VBLOGO_WIDTH (184)
#define VBLOGO_HEIGHT (48)
#define VBLOGO_BYTES_PER_PIXEL (4) /* 3:RGB, 4:RGBA */
extern const unsigned char VBLOGO_pixel_data[VBLOGO_WIDTH * VBLOGO_HEIGHT * VBLOGO_BYTES_PER_PIXEL + 1];
#define VBLOGO_PIXEL_DATA ((unsigned char*) VBLOGO_pixel_data)

//board/platform specific functions
int application_mode(demo_t *pDemo, int local_mode);
int is_application(demo_t *pDemo, int local_mode);
void board_init();
vbx_timestamp_t frame_buffer_update(demo_t* pdemo,  int uses_video_in);

void init_platform();
void cleanup_platform();

int init_demo(demo_t *pDemo);
void loop_demo(demo_t *pDemo);
void cleanup_demo();

#define X_MARGIN 8
#define Y_MARGIN 8

#endif //__DEMO_H
