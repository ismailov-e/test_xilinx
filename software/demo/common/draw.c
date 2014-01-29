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
VBXCOPYRIGHT( draw )

#include "draw.h"

void vector_erase_screen(pixel *buffer, vbx_word_t *v_screen, const int image_width, const int image_height, const int image_pitch)
{
	int y;
	//draw screen black
	vbx_set_vl(image_width);
	vbx(SVW,VMOV, v_screen, 0, 0); 
	for(y=0; y<image_height; y++){
		vbx_dma_to_host(buffer+y*image_pitch, v_screen, image_width*sizeof(pixel));
	} 
}

void vector_erase_screen_alpha(pixel *buffer, vbx_word_t *v_screen, const int image_width, const int image_height, const int image_pitch)
{
	int y;
	//draw screen black
	vbx_set_vl( image_width );
	for(y=0; y<image_height; y++){ 
		vbx_dma_to_vector(v_screen, buffer+y*image_pitch, image_width*sizeof(pixel)); 
		vbx(SVW, VCMV_GTZ, v_screen, 0, v_screen);
		vbx_dma_to_host(buffer+y*image_pitch, v_screen, image_width*sizeof(pixel)); 
	} 
}

void vector_draw_point_diamond(pixel *buffer, vbx_word_t *v_screen, int x, int y, int size, const int image_pitch)
{

	int j;
	int offset;
	offset = x-size+ (y-size)*image_pitch; 

	for( j=0; j<(size*2+1); j++ ) {
		if( j<size) {
			vbx_dma_to_host(
					buffer+offset+j*image_pitch+(size-j),
					v_screen,
					(j*2+1)*sizeof(pixel) );
		} else {
			vbx_dma_to_host(
					buffer+offset+j*image_pitch+(j-size),
					v_screen,
					((size*2-j)*2+1)*sizeof(pixel) );
		} 
	}
}

void vector_draw_point_alpha_diamond(pixel *buffer, vbx_word_t *v_screen, int x, int y, int size, const int image_pitch)
{
	int j, i;
	int offset;
	offset = x + y*image_pitch; 

	for( j=0; j<(size*2+1); j++ ) {
		if( j<size ) {
			for(i=0;i<j*2+1;i++){
				buffer[offset+(j-size)*image_pitch+(size-j)+(i-size)].a = 0xFF;

			}
		} else {
			for(i=0;i<((size*2-j)*2+1);i++){
				buffer[offset+(j-size)*image_pitch+(j-size)+(i-size)].a = 0xFF;

			}
		} 
	}
}

void vector_draw_point(pixel *buffer, vbx_word_t *v_screen, int x, int y, int size, const int image_pitch)
{
	int j;
	int offset;
	offset = x + y*image_pitch; 
	for( j=0; j<size*2+1; j++ ) {
		vbx_dma_to_host(
				buffer+offset+(j-size)*image_pitch+(-size),
				v_screen,
				(size*2+1)*sizeof(pixel) );
	}
}

void vector_draw_point_alpha(pixel *buffer, vbx_word_t *v_screen, int x, int y, int size, const int image_pitch)
{
	int j, i;
	int offset;
	offset = x + y*image_pitch; 
	for( j=0; j<size*2+1; j++ ) {
		for( i=0; i<size*2+1; i++ ) {
			buffer[offset+(j-size)*image_pitch+(i-size)].a =0xFF; 
		}
	}
}


void vector_draw_screen(pixel *cbuffer, const int num_particles, const int use_diamond, const int use_alpha, const int use_black, const int image_width, const int image_height, const int image_pitch)
{

	int y, x, i;
	int size;
	unsigned int color;
	vbx_word_t * v_screen;

	vbx_sp_push();
    if(use_alpha || use_black){
        v_screen = (vbx_word_t *) vbx_sp_malloc( image_width * sizeof(vbx_word_t) );
    }else{
        v_screen = (vbx_word_t *) vbx_sp_malloc( 100 * sizeof(vbx_word_t) );
    }
	pixel *buffer = (pixel *)vbx_remap_uncached( cbuffer );

    if(use_black && !use_alpha){
        vector_erase_screen(buffer, v_screen, image_width, image_height, image_pitch);
    }

	color = 0x0000FFFF;
	//draw new pixels
	int max_size = 4*2;
	vbx_set_vl(max_size*2+1);
	for(i=num_particles-1; i>=0; i--){
		x = particles.Px[i] >> 16;
		y = particles.Py[i] >> 16;
		size = particles.size[i]>>16;

		if( size>=9 ){
			color = 0x00FFFFFF - i;
			vbx(SVW, VMOV, v_screen, color, 0); 
			size = 4;
		}else if( size>=2 ){
			color = 0x0000FFF0 - i*0x1;
			vbx(SVW, VMOV, v_screen, color, 0); 
		}else {
			color = 0x00FFFF00 - i*0x100;
			vbx(SVW, VMOV, v_screen, color, 0); 
		}

        if(use_alpha){
            if(use_diamond){
                vector_draw_point_alpha_diamond( buffer, v_screen, x, y, size, image_pitch );
            }else{
                vector_draw_point_alpha( buffer, v_screen, x, y, size*2, image_pitch );
            }
        }else{
            if(use_diamond){
                vector_draw_point_diamond( buffer, v_screen, x, y, size, image_pitch );
            }else{
                vector_draw_point( buffer, v_screen, x, y, size*2, image_pitch );
            }
        }
    }

    if(use_alpha){
        vector_erase_screen_alpha(buffer, v_screen, image_width, image_height, image_pitch);
    }

	vbx_sp_pop();
}

//draw a rectangle of given size, in a given color, on the output image
void draw_rectangle(int startx, int starty, int width, int height, pixel* color, pixel *output_buffer, const int image_width, const int image_height, const int image_pitch)
{
	int endy = starty + height;
	int endx = startx + width;
	int x,y;

	if(startx <= 0){
		startx = 1;
	}
	if(starty <= 0){
		starty = 1;
	}
	if(endy >= image_height-1){
		endy = image_height-2;
	}
	if(endx >= image_width-1){
		endx = image_width-2;
	}

	for(y = starty; y < endy; y++){
	output_buffer[y*image_pitch+startx+1] = *color;
	output_buffer[y*image_pitch+startx] = *color;
	output_buffer[y*image_pitch+endx+1] = *color;
	output_buffer[y*image_pitch+endx] = *color;
	}

	for(x = startx; x < endx; x++){
		output_buffer[starty*image_pitch+x] = *color;
		output_buffer[(starty+1)*image_pitch+x] = *color;
		output_buffer[endy*image_pitch+x] = *color;
		output_buffer[(endy+1)*image_pitch+x] = *color;
	}
}

//draw a given set of haar features as rectangles on the output image
void draw_features( feat* feature, pixel* color, pixel* output, const int image_width, const int image_height, const int image_pitch)
{
	feat* current;

	current = feature;
	while(current){
		draw_rectangle(current->x, current->y, current->w, current->w, color, output, image_width, image_height, image_pitch);
		current = current->next;
	}
}
