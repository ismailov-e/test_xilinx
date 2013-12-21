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


#include "vbx_copyright.h"
VBXCOPYRIGHT( vector_functions )

#include "demo.h"

#include "vbw_vec_rev.h"

#if TOUCHSCREEN
	// This is our touch panel
	extern touchscreen_t *pTouch;
#define CHECK_TOUCHSCREEN() \
		if( TOUCH_INTERRUPTS_VBX && touchscreen_get_pen(pTouch) ) { \
			vbx_sync(); \
			vbx_sp_free(); \
			return -1; \
		}
#endif

	typedef vbx_uword_t* vptr_uword;
	typedef vbx_uhalf_t* vptr_uhalf;
	typedef vbx_ubyte_t* vptr_ubyte;
	typedef vbx_word_t* vptr_word;
	typedef vbx_half_t* vptr_half;
	typedef vbx_byte_t* vptr_byte;

#ifdef SYSTEM_DE4
#define FORCE_ALIGNED_DMA 0
#else
#define FORCE_ALIGNED_DMA 1
#endif

	//Not double buffered, could be faster
void vector_draw_alpha(int startx, int starty, pixel *bg, pixel *fg, int size_x, int size_y)
{
	int y,j;
	pixel *fg_buffer, *bg_buffer;
	vbx_uword_t *v_fg, *v_bg, *v_color, *v_temp, *v_alpha, *v_alpha_not;

	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	const int scratchpad_size = this_mxp->scratchpad_size;

	int lines_per_pass = scratchpad_size/(size_x*sizeof(pixel)*6);
	if(lines_per_pass > size_y){
		lines_per_pass = size_y;
	}
	int pass_size_bytes = lines_per_pass*size_x*sizeof(pixel);

	v_fg        = (vbx_uword_t *)vbx_sp_malloc(pass_size_bytes);
	v_bg        = (vbx_uword_t *)vbx_sp_malloc(pass_size_bytes);
	v_color     = (vbx_uword_t *)vbx_sp_malloc(pass_size_bytes);
	v_temp      = (vbx_uword_t *)vbx_sp_malloc(pass_size_bytes);
	v_alpha     = (vbx_uword_t *)vbx_sp_malloc(pass_size_bytes);
	v_alpha_not = (vbx_uword_t *)vbx_sp_malloc(pass_size_bytes);

	for(y = 0; y < size_y; y += lines_per_pass){
		if(y + lines_per_pass > size_y){
			lines_per_pass = size_y - y;
		}
		bg_buffer = bg+(((starty+y)*IMAGE_WIDTH)+startx);
		fg_buffer = fg+(y*size_x);
#if FORCE_ALIGNED_DMA
		vbx_dma_to_vector_aligned(v_fg, fg_buffer, pass_size_bytes);
#else
		vbx_dma_to_vector(v_fg, fg_buffer, pass_size_bytes);
#endif
		for(j = 0; j < lines_per_pass; j++){
#if FORCE_ALIGNED_DMA
			vbx_dma_to_vector_aligned(v_bg+(j*size_x), bg_buffer+(j*IMAGE_WIDTH), size_x*sizeof(pixel));
#else
			vbx_dma_to_vector(v_bg+(j*size_x), bg_buffer+(j*IMAGE_WIDTH), size_x*sizeof(pixel));
#endif
		}

		vbx_set_vl(lines_per_pass*size_x);

		vbx(SVWU, VSHR,  v_alpha,     24,  v_fg);
		vbx(SVWU, VSUB,  v_alpha_not, 256, v_alpha);

		//Now v_fg used as output
		vbx(SVWU, VAND,  v_color, 0xFF,    v_bg);
		vbx(VVWU, VMUL,  v_temp,  v_color, v_alpha_not);
		vbx(SVWU, VSUB,  v_color, 0xFF,    v_color);
		vbx(VVWU, VMUL,  v_color, v_color, v_alpha);
		vbx(VVWU, VADD,  v_color, v_color, v_temp);
		vbx(SVWU, VSHR,  v_fg,    8,       v_color);

		vbx(SVWU, VAND,  v_color, 0xFF,    (vbx_uword_t*)(((vbx_ubyte_t *)v_bg)+1));
		vbx(VVWU, VMUL,  v_temp,  v_color, v_alpha_not);
		vbx(SVWU, VSUB,  v_color, 0xFF,    v_color);
		vbx(VVWU, VMUL,  v_color, v_color, v_alpha);
		vbx(VVWU, VADD,  v_color, v_color, v_temp);
		vbx(SVWU, VAND,  v_color, 0xFF00,  v_color);
		vbx(VVWU, VOR,   v_fg,    v_fg,    v_color);

		vbx(SVWU, VAND,  v_color, 0xFF00,   (vbx_uword_t*)(((vbx_ubyte_t *)v_bg)+1));
		vbx(VVWU, VMUL,  v_temp,  v_color,  v_alpha_not);
		vbx(SVWU, VSUB,  v_color, 0xFF00,   v_color);
		vbx(VVWU, VMUL,  v_color, v_color,  v_alpha);
		vbx(VVWU, VADD,  v_color, v_color,  v_temp);
		vbx(SVWU, VAND,  v_color, 0xFF0000, v_color);
		vbx(VVWU, VOR,   v_fg,    v_fg,     v_color);

		for(j = 0; j < lines_per_pass; j++){
#if FORCE_ALIGNED_DMA
			vbx_dma_to_host_aligned(bg_buffer+(j*IMAGE_WIDTH), v_fg+(j*size_x), size_x*sizeof(pixel));
#else
			vbx_dma_to_host(bg_buffer+(j*IMAGE_WIDTH), v_fg+(j*size_x), size_x*sizeof(pixel));
#endif
		}
		vbx_sync();
	}

	vbx_sp_free();
}

void vector_draw_char(unsigned char char_to_draw, int startx, int starty, pixel *buffer)
{
	pixel *char_buffer;

	if(char_to_draw < MIN_CHAR || char_to_draw >= MAX_CHAR){
		char_to_draw = ' ';
	}

	char_buffer = (pixel *)(CHAR_BUFFER_PIXEL_DATA+((CHAR_WIDTH*sizeof(pixel)*CHAR_HEIGHT)*(char_to_draw-MIN_CHAR)));

	vector_draw_alpha(startx, starty, buffer, char_buffer, CHAR_WIDTH, CHAR_HEIGHT);
}

//Returns x posititon of end of string
int vector_overlay_printf(char *print_string, int startx, int starty, int max_length, pixel *buffer)
{
	int done = 0;
	int char_num;
	unsigned char to_print;

	for(char_num = 0; char_num < max_length && !done; char_num++){
		to_print = (unsigned char)(print_string[char_num]);
		if((to_print == '\0') || (startx+((char_num+1)*CHAR_WIDTH) > IMAGE_WIDTH)){
			done = 1;
		}
		else {
			vector_draw_char(to_print, startx+(char_num*CHAR_WIDTH), starty, buffer);
		}
	}

	return startx+char_num*CHAR_WIDTH;
}

void vector_invert_image(pixel *image, const int image_width, const int image_height, const int image_pitch)
{
	vptr_uword v_to_vector, v_processing, v_to_host, temp;
	int y;

	v_to_vector  = (vptr_uword)vbx_sp_malloc(image_width*sizeof(pixel));
	v_processing = (vptr_uword)vbx_sp_malloc(image_width*sizeof(pixel));
	v_to_host    = (vptr_uword)vbx_sp_malloc(image_width*sizeof(pixel));

#if FORCE_ALIGNED_DMA
	vbx_dma_to_vector_aligned(v_to_vector, image, image_width*sizeof(pixel));
#else
	vbx_dma_to_vector(v_to_vector, image, image_width*sizeof(pixel));
#endif

	vbx_set_vl(image_width*sizeof(pixel));

	for(y = 0; y < image_height; y++){
		temp         = v_to_host;
		v_to_host    = v_processing;
		v_processing = v_to_vector;
		v_to_vector  = temp;

		if(y < IMAGE_HEIGHT-1){
#if FORCE_ALIGNED_DMA
			vbx_dma_to_vector_aligned(v_to_vector, image+(y+1)*image_pitch, image_width*sizeof(pixel));
#else
			vbx_dma_to_vector(v_to_vector, image+(y+1)*image_pitch, image_width*sizeof(pixel));
#endif
		}

		vbx(SVBU, VSUB, (vbx_ubyte_t*)v_processing, 255, (vbx_ubyte_t*)v_processing);

#if FORCE_ALIGNED_DMA
		vbx_dma_to_host_aligned(image+y*image_pitch, v_processing, image_width*sizeof(pixel));
#else
		vbx_dma_to_host(image+y*image_pitch, v_processing, image_width*sizeof(pixel));
#endif
	}

	vbx_sync();
	vbx_sp_free();
}

void vector_brighten_image(pixel *image, unsigned char brighten_amount)
{
	vptr_uword v_to_vector, v_processing, v_to_host, temp;
	int y;

	v_to_vector  = (vptr_uword)vbx_sp_malloc(IMAGE_WIDTH*sizeof(pixel));
	v_processing = (vptr_uword)vbx_sp_malloc(IMAGE_WIDTH*sizeof(pixel));
	v_to_host    = (vptr_uword)vbx_sp_malloc(IMAGE_WIDTH*sizeof(pixel));

#if FORCE_ALIGNED_DMA
	vbx_dma_to_vector_aligned(v_to_vector, image, IMAGE_WIDTH*sizeof(pixel));
#else
	vbx_dma_to_vector(v_to_vector, image, IMAGE_WIDTH*sizeof(pixel));
#endif

	vbx_set_vl(IMAGE_WIDTH*4);

	for(y = 0; y < IMAGE_HEIGHT; y++){
		temp         = v_to_host;
		v_to_host    = v_processing;
		v_processing = v_to_vector;
		v_to_vector  = temp;

		if(y < IMAGE_HEIGHT-1){
#if FORCE_ALIGNED_DMA
			vbx_dma_to_vector_aligned(v_to_vector, image+(y+1)*IMAGE_WIDTH, IMAGE_WIDTH*sizeof(pixel));
#else
			vbx_dma_to_vector(v_to_vector, image+(y+1)*IMAGE_WIDTH, IMAGE_WIDTH*sizeof(pixel));
#endif
		}

		vbx(SVBU, VADD,     (vbx_ubyte_t*)v_processing, brighten_amount, (vbx_ubyte_t*)v_processing);
		vbx(SVBU, VCMV_LTZ, (vbx_ubyte_t*)v_processing, 255,             (vbx_ubyte_t*)v_processing);

#if FORCE_ALIGNED_DMA
		vbx_dma_to_host_aligned(image+y*IMAGE_WIDTH, v_processing, IMAGE_WIDTH*sizeof(pixel));
#else
		vbx_dma_to_host(image+y*IMAGE_WIDTH, v_processing, IMAGE_WIDTH*sizeof(pixel));
#endif
	}

	vbx_sync();
	vbx_sp_free();
}

void vector_flip_image(pixel *input, pixel *output)
{
	int y;
	int w = IMAGE_WIDTH*sizeof(pixel);
#if 0 //full horizontal flip 
	for(y = 0; y < IMAGE_HEIGHT/2; y++){
#if FORCE_ALIGNED_DMA
		vbx_dma_to_vector_aligned(0, input+    y*IMAGE_WIDTH, w);
		vbx_dma_to_vector_aligned(w, input+(h-y)*IMAGE_WIDTH, w);
		vbx_dma_to_host_aligned(output+(h-y)*IMAGE_WIDTH, 0, w);
		vbx_dma_to_host_aligned(output+    y*IMAGE_WIDTH, (vptr_ubyte)w, w);
#else
		vbx_dma_to_vector(0, input+    y*IMAGE_WIDTH, w);
		vbx_dma_to_vector(w, input+(h-y)*IMAGE_WIDTH, w);
		vbx_dma_to_host(output+(h-y)*IMAGE_WIDTH, 0, w);
		vbx_dma_to_host(output+    y*IMAGE_WIDTH, (vptr_ubyte)w, w);
#endif
	}
#elif 0 //horizontal mirror
	for(y = 0; y < IMAGE_HEIGHT/2; y++){
#if FORCE_ALIGNED_DMA
		vbx_dma_to_vector_aligned(0, input+    y*IMAGE_WIDTH, w);
		vbx_dma_to_host_aligned(output+(h-y)*IMAGE_WIDTH, 0, w);
#else
		vbx_dma_to_vector(0, input+    y*IMAGE_WIDTH, w);
		vbx_dma_to_host(output+(h-y)*IMAGE_WIDTH, 0, w);
#endif
	}
#elif 0 //full vertical flip
	vbx_set_vl( 1 );
	vbx_set_2D( IMAGE_WIDTH, 4, -4, 0);
	for(y = 0; y < IMAGE_HEIGHT; y++){
#if FORCE_ALIGNED_DMA
		vbx_dma_to_vector_aligned(0, input+y*IMAGE_WIDTH, w);
		vbx_2D(VVW, VMOV, w, w-4, 0 );
		vbx_dma_to_host_aligned(output+y*IMAGE_WIDTH, (vptr_ubyte)w, w);
#else
		vbx_dma_to_vector(0, input+y*IMAGE_WIDTH, w);
		vbx_2D(VVW, VMOV, w, w-4, 0 );
		vbx_dma_to_host(output+y*IMAGE_WIDTH, (vptr_ubyte)w, w);
#endif
	}
#else //vertical mirror
	vbx_set_vl( 1 );
	vbx_set_2D( IMAGE_WIDTH/2, 4, -4, 0);
	for(y = 0; y < IMAGE_HEIGHT; y++){
#if FORCE_ALIGNED_DMA
		vbx_dma_to_vector_aligned(0, input+y*IMAGE_WIDTH, w/2);
		vbx_2D(VVW, VMOV, (vbx_word_t*)w, (vbx_word_t*)(w/2-4), 0 );
		vbx_dma_to_host_aligned(output+y*IMAGE_WIDTH+IMAGE_WIDTH/2, (vptr_ubyte)w, w/2);
#else
		vbx_dma_to_vector(0, input+y*IMAGE_WIDTH, w/2);
		vbx_2D(VVW, VMOV, (vbx_word_t*)w, (vbx_word_t*)(w/2-4), 0 );
		vbx_dma_to_host(output+y*IMAGE_WIDTH+IMAGE_WIDTH/2, (vptr_ubyte)w, w/2);
#endif
	}
#endif
	vbx_sync();
}

// mirror image (i.e. flip image over vertical axis)
void vector_flip_vertical_simple(pixel *input, pixel *output)
{
	int y;

	int w = IMAGE_WIDTH*sizeof(pixel);

	vbx_set_vl( 1 );
	vbx_set_2D( IMAGE_WIDTH, 4, -4, 0);
	for(y = 0; y < IMAGE_HEIGHT; y++){
#if FORCE_ALIGNED_DMA
		vbx_dma_to_vector_aligned(0, input+y*IMAGE_WIDTH, w);
		vbx_2D(VVW, VMOV, (vbx_word_t*)w, (vbx_word_t*)(w-4), 0 );
		vbx_dma_to_host_aligned(output+y*IMAGE_WIDTH, (vptr_ubyte)w, w);
#else
		vbx_dma_to_vector(0, input+y*IMAGE_WIDTH, w);
		vbx_2D(VVW, VMOV, (vbx_word_t*)w, (vbx_word_t*)(w-4), 0 );
		vbx_dma_to_host(output+y*IMAGE_WIDTH, (vptr_ubyte)w, w);
#endif
	}
}

// mirror image (i.e. flip image over vertical axis)
// using vbw_vec_rev() vbxware library function.
// Assumes two entire scan lines will fit in scratchpad.
// Assumes sizeof(pixel) = sizeof(vbx_word_t).
// On DE4 V32 @ 188MHz this is about 70% faster than
// vector_flip_vertical_simple() on a 1080p frame (8-10ms/frame).
// On DE4 V16 @ 200MHz, it's about 40% faster (10-12ms/frame).
void vector_flip_vertical(pixel *input, pixel *output)
{
	int y;
	int line_bytes = IMAGE_WIDTH*sizeof(pixel);
	vbx_word_t *tmp_line;
	vbx_word_t *reversed_line;

	vbx_sp_push();
	tmp_line = vbx_sp_malloc(line_bytes);

	for(y = 0; y < IMAGE_HEIGHT; y++){
		vbx_dma_to_vector(tmp_line, input+y*IMAGE_WIDTH, line_bytes);
		// vector_reverse function call allocates space for output vector,
		// so must push current scratch pointer in order to later deallocate
		// the output vector.
		vbx_sp_push();
		reversed_line = vbw_vec_reverse_word(tmp_line, IMAGE_WIDTH);
		vbx_dma_to_host(output+y*IMAGE_WIDTH, reversed_line, line_bytes);
		vbx_sp_pop();
	}
	vbx_sp_pop();
	vbx_sync();
}
