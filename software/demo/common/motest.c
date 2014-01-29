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
VBXCOPYRIGHT( motest )

#include "demo.h"
#include <stdlib.h>
#include <math.h>

// For INT_MAX
#include <limits.h>

#if TOUCHSCREEN
// This is our touch panel
extern touchscreen_t *pTouch;
#endif

static inline void setPixel( int x, int y, pixel *output_buffer, pixel color, const int image_pitch )
{
	output_buffer[ y*image_pitch + x ] = color;
}

void scalar_draw_line( int x0, int y0, int x1, int y1, pixel color, pixel *output_buffer, const int image_pitch )
{
	// Taken from pseudocode in Wikipedia's writeup on
	// Bresenham's line drawing algorithm
	int dy, dx, sx, sy;
	int err, e2;

	dx = abs(x1-x0);
	dy = abs(y1-y0);

	if( x0 < x1 ){
		sx = 1;
	} else {
		sx = -1;
	}

	if( y0 < y1 ){
		sy = 1;
	} else {
		sy = -1;
	}

	err = dx - dy;
	do {
		setPixel( x0, y0, output_buffer, color, image_pitch );
		if( x0 == x1 && y0 == y1 )
			break;
		e2 = 2*err;
		if( e2 > -dy ) {
			err -= dy;
			x0  += sx;
		}
		if( e2 < dx ) {
			err += dx;
			y0  += sy;
		}
	} while(1);
}

//Try following block around.  Give warning, then follow for a couple seconds
#define MOTEST_BLOCK_WIDTH   64
#define MOTEST_BLOCK_HEIGHT  64
#define MOTEST_BLOCK_SIZE    ((MOTEST_BLOCK_HEIGHT)*(MOTEST_BLOCK_WIDTH))
#define MOTEST_SEARCH_WIDTH  64
#define MOTEST_SEARCH_HEIGHT 64
#define MOTEST_SEARCH_SIZE   ((MOTEST_SEARCH_HEIGHT)*(MOTEST_SEARCH_WIDTH))
#define MOTEST_BUFFER_WIDTH  ((MOTEST_BLOCK_WIDTH)+(MOTEST_SEARCH_WIDTH))
#define MOTEST_BUFFER_HEIGHT ((MOTEST_BLOCK_HEIGHT)+(MOTEST_SEARCH_HEIGHT))
#define MOTEST_BUFFER_SIZE   ((MOTEST_BUFFER_WIDTH)*(MOTEST_BUFFER_HEIGHT))

//typedef unsigned short luma_type;

static luma_type *last_luma = NULL;
static int motest_x = 0;
static int motest_y = 0;

void draw_motest(pixel *input_buffer, int motest_x, int motest_y, const int image_pitch)
{
	int y, x;
	pixel color;

	for(x = motest_x; x < motest_x+MOTEST_BLOCK_WIDTH; x++){
		for(y = motest_y; y < motest_y+MOTEST_BLOCK_HEIGHT; y+=MOTEST_BLOCK_HEIGHT-1){
			color = input_buffer[y*image_pitch+x];
			color.r = 255 - color.r;
			color.g = 255 - color.g;
			color.b = 255 - color.b;
			input_buffer[y*image_pitch+x] = color;
		}
	}

	for(y = motest_y; y < motest_y+MOTEST_BLOCK_HEIGHT; y++){
		for(x = motest_x; x < motest_x+MOTEST_BLOCK_WIDTH; x+=MOTEST_BLOCK_WIDTH-1){
			color = input_buffer[y*image_pitch+x];
			color.r = 255 - color.r;
			color.g = 255 - color.g;
			color.b = 255 - color.b;
			input_buffer[y*image_pitch+x] = color;
		}
	}
}

void scalar_rectangle_to_luma(pixel *input_buffer, luma_type *luma_buffer, int startx, int starty, int width, int height, const int image_pitch)
{
	int y,x;
	pixel color;

	for(y = 0; y < height; y++){
		for(x = 0; x < width; x++){
			color = input_buffer[(y+starty)*image_pitch+(x+startx)];
			luma_buffer[y*width+x] = (66*(luma_type)(color.r) + 129*(luma_type)(color.g) + 25*(luma_type)(color.b)) >> 8;
		}
	}
}

void vector_rectangle_to_luma(
	pixel *input_buffer,
	vbx_uhalf_t *v_luma_buffer, vbx_uhalf_t *v_row_temp, vbx_uword_t *v_row,
	int startx, int starty, int width, int height, const int image_pitch )
{
	int y;
	vbx_uhalf_t *v_luma;

	vbx_set_vl(width);

	for(y = 0; y < height; y++){
		v_luma = v_luma_buffer+(y*width);
		vbx_dma_to_vector(v_row, input_buffer+((y+starty)*image_pitch)+startx, width*sizeof(vbx_uword_t));

		//Move the b component into v_luma
		vbx(SVWHU, VAND, v_luma, 0xFF, v_row);
		vbx(SVHU,  VMUL, v_luma, 25,   v_luma);

		//Move g into v_row_temp and add it to v_luma
		vbx(SVWHU, VAND, v_row_temp, 0xFF,  (vbx_uword_t*)(((vbx_ubyte_t*)v_row)+1));
		vbx(SVHU,  VMUL, v_row_temp, 129,    v_row_temp);
		vbx(VVHU,  VADD, v_luma,     v_luma, v_row_temp);

		//Move r into v_row_temp and add it to v_luma
		vbx(SVWHU, VAND, v_row_temp, 0xFF,  (vbx_uword_t*)(((vbx_ubyte_t*)v_row)+2));
		vbx(SVHU,  VMUL, v_row_temp, 66,     v_row_temp);
		vbx(VVHU,  VADD, v_luma,     v_luma, v_row_temp);

		//divide by 2^8
		vbx(SVHU,  VSHR, v_luma, 8,  v_luma);
	}
}

void init_scalar_motest(pixel *input_buffer, luma_type **last_luma, int *motest_x, int *motest_y, int x, int y, const int image_pitch)
{
	if(*last_luma == NULL){
		*last_luma = malloc(MOTEST_BLOCK_SIZE*sizeof(luma_type));
	}
	*motest_x = x-(MOTEST_BLOCK_WIDTH/2);
	*motest_y = y-(MOTEST_BLOCK_HEIGHT/2);

	scalar_rectangle_to_luma(input_buffer, *last_luma, *motest_x, *motest_y, MOTEST_BLOCK_WIDTH, MOTEST_BLOCK_HEIGHT, image_pitch);
}

void init_vector_motest(pixel *input_buffer, luma_type **last_luma, int *motest_x, int *motest_y, int x, int y, const int image_pitch)
{
	vbx_uhalf_t *v_last_luma;
	vbx_uhalf_t *v_row_temp;
	vbx_uword_t *v_row;

	if(*last_luma == NULL){
		*last_luma = malloc(MOTEST_BLOCK_SIZE*sizeof(luma_type));
	}
	*motest_x = x-(MOTEST_BLOCK_WIDTH/2);
	*motest_y = y-(MOTEST_BLOCK_HEIGHT/2);


	v_last_luma   = vbx_sp_malloc(MOTEST_BLOCK_SIZE*sizeof(vbx_uhalf_t));
	v_row_temp    = vbx_sp_malloc(MOTEST_BLOCK_WIDTH*sizeof(vbx_uhalf_t));
	v_row         = vbx_sp_malloc(MOTEST_BLOCK_WIDTH*sizeof(vbx_uword_t));

	vector_rectangle_to_luma(input_buffer, v_last_luma, v_row_temp, v_row, *motest_x, *motest_y, MOTEST_BLOCK_WIDTH, MOTEST_BLOCK_HEIGHT, image_pitch);

	vbx_dma_to_host(*last_luma, v_last_luma, MOTEST_BLOCK_SIZE*sizeof(luma_type));

	vbx_sp_free();
}

int scalar_motest(pixel *input_buffer, luma_type **last_luma, int *motest_x, int *motest_y, int start_x, int start_y, int reset, const int image_width, const int image_height, const int image_pitch)
{
	int y, x, starty, startx;
	int j, i;
	unsigned int sad, sad_min, y_min, x_min;
	static luma_type *search_luma = NULL;
	pixel color;

	if(*last_luma == NULL || reset){
		init_scalar_motest(input_buffer, last_luma, motest_x, motest_y, start_x, start_y, image_pitch);
	}

	if(search_luma == NULL){
		search_luma = malloc(MOTEST_BUFFER_SIZE*sizeof(luma_type));
	}

	startx = *motest_x-(MOTEST_SEARCH_WIDTH/2);
	starty = *motest_y-(MOTEST_SEARCH_HEIGHT/2);
	if(startx < 0){
		startx = 0;
	}
	if(startx > image_width-MOTEST_BUFFER_WIDTH){
		startx = image_width-MOTEST_BUFFER_WIDTH;
	}
	if(starty < 0){
		starty = 0;
	}
	if(starty > image_height-MOTEST_BUFFER_HEIGHT){
		starty = image_height-MOTEST_BUFFER_HEIGHT;
	}

	scalar_rectangle_to_luma(input_buffer, search_luma, startx, starty, MOTEST_BUFFER_WIDTH, MOTEST_BUFFER_HEIGHT, image_pitch);

	sad_min = INT_MAX;
	y_min = *motest_y;
	x_min = *motest_x;

	for(y = 0; y < MOTEST_SEARCH_HEIGHT; y++){
		for(x = 0; x < MOTEST_SEARCH_WIDTH; x++){
			sad = 0;
			for(j = 0; j < MOTEST_BLOCK_HEIGHT; j++){
				for(i = 0; i < MOTEST_BLOCK_WIDTH; i++){
					sad += abs((*last_luma)[j*MOTEST_BLOCK_WIDTH+i] - search_luma[((y+j)*(MOTEST_BLOCK_WIDTH+MOTEST_SEARCH_WIDTH))+(x+i)]);
				}
			}
			if(sad < sad_min){
				sad_min = sad;
				x_min = x+startx;
				y_min = y+starty;
			} else if(sad == sad_min) {
				if((abs(x              - MOTEST_SEARCH_WIDTH/2) + abs(y              - MOTEST_SEARCH_HEIGHT/2)) <
					 (abs((x_min-startx) - MOTEST_SEARCH_WIDTH/2) + abs((y_min-starty) - MOTEST_SEARCH_HEIGHT/2))){
					x_min = x+startx;
					y_min = y+starty;
				}
			}
		}

#if TOUCHSCREEN
		if (touchscreen_get_pen(pTouch)) {
			return -1;
		}
#endif
	}

	color.r = 0;
	color.g = 255;
	color.b = 0;
	color.a = 0;
	scalar_draw_line(*motest_x+(MOTEST_BLOCK_WIDTH/2), *motest_y+(MOTEST_BLOCK_HEIGHT/2), x_min+(MOTEST_BLOCK_WIDTH/2), y_min+(MOTEST_BLOCK_HEIGHT/2), color, input_buffer, image_pitch);

	*motest_y = y_min;
	*motest_x = x_min;

	for(y = 0; y < MOTEST_BLOCK_HEIGHT; y++){
		for(x = 0; x < MOTEST_BLOCK_WIDTH; x++){
			(*last_luma)[y*MOTEST_BLOCK_WIDTH+x] = search_luma[((y+y_min-starty)*MOTEST_BUFFER_WIDTH)+(x+x_min-startx)];
		}
	}

	draw_motest(input_buffer, *motest_x, *motest_y, image_pitch);
	//simple hack to draw thicker
	draw_motest(input_buffer, *motest_x+1, *motest_y+1, image_pitch);

	return 0;
}

int vector_motest(pixel *input_buffer, luma_type **last_luma, int *motest_x, int *motest_y, int start_x, int start_y, int reset, const int image_width, const int image_height, const int image_pitch)
{
	int y, x, starty, startx;
	unsigned int sad, sad_min, y_min, x_min;
	vbx_uhalf_t *v_search_luma, *v_last_luma;
	vbx_uhalf_t *v_row_temp;
	vbx_uword_t *v_row;
	vbx_uword_t *v_sad;
	pixel color;

	if(*last_luma == NULL || reset){
		init_vector_motest(input_buffer, last_luma, motest_x, motest_y, start_x, start_y, image_pitch);
	}

	v_search_luma = vbx_sp_malloc( MOTEST_BUFFER_SIZE  * sizeof(vbx_uhalf_t) );
	v_last_luma   = vbx_sp_malloc( MOTEST_BLOCK_SIZE   * sizeof(vbx_uhalf_t) );
	v_row_temp    = vbx_sp_malloc( MOTEST_BUFFER_WIDTH * sizeof(vbx_uhalf_t) );
	v_row         = vbx_sp_malloc( MOTEST_BUFFER_WIDTH * sizeof(vbx_uword_t) );
	v_sad         = vbx_sp_malloc( MOTEST_SEARCH_SIZE  * sizeof(vbx_uword_t) );

	if(v_sad == NULL){
		printf("Not enough scratchpad for motest\n");
		while(1);
	}

	startx = *motest_x-(MOTEST_SEARCH_WIDTH/2);
	starty = *motest_y-(MOTEST_SEARCH_HEIGHT/2);
	if(startx < 0){
		startx = 0;
	}
	if(startx > image_width-MOTEST_BUFFER_WIDTH){
		startx = image_width-MOTEST_BUFFER_WIDTH;
	}
	if(starty < 0){
		starty = 0;
	}
	if(starty > image_height-MOTEST_BUFFER_HEIGHT){
		starty = image_height-MOTEST_BUFFER_HEIGHT;
	}

	vector_rectangle_to_luma(input_buffer, v_search_luma, v_row_temp, v_row, startx, starty, MOTEST_BUFFER_WIDTH, MOTEST_BUFFER_HEIGHT, image_pitch);
	vbx_dma_to_vector(v_last_luma, *last_luma, MOTEST_BLOCK_SIZE*sizeof(vbx_uhalf_t));

	//Vector compute sad here

	vbx_set_2D(MOTEST_BLOCK_HEIGHT, sizeof(vbx_uword_t), MOTEST_BUFFER_WIDTH*sizeof(vbx_uhalf_t), MOTEST_BLOCK_WIDTH*sizeof(vbx_uhalf_t));

	for(y = 0; y < MOTEST_SEARCH_HEIGHT; y++){
		for(x = 0; x < MOTEST_SEARCH_WIDTH; x++){
			vbx_set_vl(MOTEST_BLOCK_WIDTH);
			vbx_acc_2D(VVHWU, VABSDIFF, v_row, v_search_luma+(y*MOTEST_BUFFER_WIDTH)+x, v_last_luma);
			vbx_set_vl(MOTEST_BLOCK_HEIGHT/2);
			vbx_acc(VVWU, VADD, v_sad+(y*MOTEST_SEARCH_WIDTH)+x, v_row, v_row+MOTEST_BLOCK_HEIGHT/2);
		}

#if TOUCHSCREEN
#ifdef TOUCH_INTERRUPTS_VBX
		if (touchscreen_get_pen(pTouch)) {
			vbx_sp_free();
			return -1;
		}
#endif
#endif
	}

	vbx_sync();

	sad_min = INT_MAX;
	y_min = *motest_y;
	x_min = *motest_x;

	for(y = 0; y < MOTEST_SEARCH_HEIGHT; y++){
		for(x = 0; x < MOTEST_SEARCH_WIDTH; x++){
			sad = v_sad[y*MOTEST_SEARCH_WIDTH+x];
			if(sad < sad_min){
				sad_min = sad;
				x_min = x+startx;
				y_min = y+starty;
			} else if(sad == sad_min) {
				if( (abs( x             - MOTEST_SEARCH_WIDTH/2) + abs( y             - MOTEST_SEARCH_HEIGHT/2)) <
				    (abs((x_min-startx) - MOTEST_SEARCH_WIDTH/2) + abs((y_min-starty) - MOTEST_SEARCH_HEIGHT/2))) {
					x_min = x+startx;
					y_min = y+starty;
				}
			}
		}
	}

	color.r = 0;
	color.g = 255;
	color.b = 0;
	color.a = 0;
	scalar_draw_line(*motest_x+(MOTEST_BLOCK_WIDTH/2), *motest_y+(MOTEST_BLOCK_HEIGHT/2), x_min+(MOTEST_BLOCK_WIDTH/2), y_min+(MOTEST_BLOCK_HEIGHT/2), color, input_buffer, image_pitch);

	*motest_y = y_min;
	*motest_x = x_min;

	vbx_set_vl(MOTEST_BLOCK_WIDTH);
	for(y = 0; y < MOTEST_BLOCK_HEIGHT; y++){
		vbx(VVHU, VMOV, v_last_luma+(y*MOTEST_BLOCK_WIDTH), v_search_luma+((y+y_min-starty)*MOTEST_BUFFER_WIDTH)+(x_min-startx), 0);
	}
	vbx_dma_to_host(*last_luma, v_last_luma, MOTEST_BLOCK_SIZE*sizeof(luma_type));

	draw_motest(input_buffer, *motest_x, *motest_y, image_pitch);
	//simple hack to draw thicker
	draw_motest(input_buffer, *motest_x+1, *motest_y+1, image_pitch);

	vbx_sp_free();
	return 0;
}
