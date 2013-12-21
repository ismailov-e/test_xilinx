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
VBXCOPYRIGHT( scalar_functions )

#include "demo.h"

#if TOUCHSCREEN
// This is our touch panel
extern touchscreen_t *pTouch;
#endif

void scalar_draw_char(unsigned char char_to_draw, int startx, int starty, pixel *buffer)
{
  pixel *char_buffer;
  int y,x;
  pixel *bg_pix;
  pixel *fg_pix;

  unsigned short temp; 

  if(char_to_draw < MIN_CHAR || char_to_draw >= MAX_CHAR)char_to_draw = ' ';
  
  char_buffer = (pixel *)(CHAR_BUFFER_PIXEL_DATA+((CHAR_WIDTH*sizeof(pixel)*CHAR_HEIGHT)*(char_to_draw-MIN_CHAR)));
  
  for(y = 0; y < CHAR_HEIGHT; y++){
	for(x = 0; x < CHAR_WIDTH; x++){
	  fg_pix = char_buffer+(y*CHAR_WIDTH+x);
	  bg_pix = buffer+((starty+y)*IMAGE_WIDTH+(startx+x));

	  temp = (255-(*bg_pix).r) * (*fg_pix).a;
	  temp += (*bg_pix).r * (256-((*fg_pix).a));
	  (*bg_pix).r = temp >> 8;
	  temp = (255-(*bg_pix).g) * (*fg_pix).a;
	  temp += (*bg_pix).g * (256-((*fg_pix).a));
	  (*bg_pix).g = temp >> 8;
	  temp = (255-(*bg_pix).b) * (*fg_pix).a;
	  temp += (*bg_pix).b * (256-((*fg_pix).a));
	  (*bg_pix).b = temp >> 8;
	}
  }
}

//Returns x posititon of end of string
int scalar_overlay_printf(char *print_string, int startx, int starty, int max_length, pixel *buffer)
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
	  scalar_draw_char(to_print, startx+(char_num*CHAR_WIDTH), starty, buffer);
	}
  }
  
  return startx+char_num*CHAR_WIDTH;
}

void scalar_draw_vblogo(int startx, int starty, pixel *buffer)
{
  pixel *logo_buffer;
  int y,x;
  pixel *bg_pix;
  pixel *fg_pix;

  unsigned short temp; 

  logo_buffer = (pixel *)VBLOGO_PIXEL_DATA;
  
  for(y = 0; y < VBLOGO_HEIGHT; y++){
	for(x = 0; x < VBLOGO_WIDTH; x++){
	  fg_pix = logo_buffer+(y*VBLOGO_WIDTH+x);
	  bg_pix = buffer+((starty+y)*IMAGE_WIDTH+(startx+x));

	  temp = (255-(*bg_pix).r) * (*fg_pix).a;
	  temp += (*bg_pix).r * (256-((*fg_pix).a));
	  (*bg_pix).r = temp >> 8;
	  temp = (255-(*bg_pix).g) * (*fg_pix).a;
	  temp += (*bg_pix).g * (256-((*fg_pix).a));
	  (*bg_pix).g = temp >> 8;
	  temp = (255-(*bg_pix).b) * (*fg_pix).a;
	  temp += (*bg_pix).b * (256-((*fg_pix).a));
	  (*bg_pix).b = temp >> 8;
	}
  }
}

int scalar_green_detect(pixel *input, int *avg_y, int *avg_x)
{
  int y,x;
  pixel *color;
  int greenness, line_y, line_x, line_greenness;
  int total_y, total_x, total_greenness;

  total_y       = 0;
  total_x       = 0;
  total_greenness = 0;

  for(y = 0; y < IMAGE_HEIGHT; y++){
	line_y = 0;
	line_x = 0;
	line_greenness = 0;
	for(x = 0; x < IMAGE_WIDTH; x++){
				color = input+y*IMAGE_WIDTH+x;
				greenness = color->r;
				greenness -= ((color->g + color->b)<<2);
				if(greenness > 100){
				line_greenness += greenness;
				line_y += y*greenness;
				line_x += x*greenness;
	  }
	}
	total_greenness += line_greenness >> GREENNESS_SCALING_PER_LINE;
	total_y += line_y >> GREENNESS_SCALING_PER_LINE;
	total_x += line_x >> GREENNESS_SCALING_PER_LINE;

#if TOUCHSCREEN
	if (touchscreen_get_pen(pTouch)) {
	  return -1;
	}
#endif
  }

  *avg_y = total_y;
  *avg_x = total_x;
  return total_greenness;
}

void scalar_invert_image(pixel *image, const int image_width, const int image_height, const int image_pitch)
{
  int y,x,index;

  for(y = 0; y < image_height; y++){
	for(x = 0; x < image_width; x++){
	  index = y*image_pitch+x;
	  image[index].r = 0-image[index].r;
	  image[index].g = 0-image[index].g;
	  image[index].b = 0-image[index].b;
	}
  }

  //Should flush cache here
}

//Attempted to use cache blocking here; not really helpful with direct mapped cache
#define BLOCK_SIZE 800

int scalar_edge_detect(pixel *input, pixel *output)
{
  int y,x,j,i;
  int y_block,x_block,y_max,x_max;
  short gradient_x,gradient_y;
  pixel color;
  short luma;
  short filter_x[FILTER_HEIGHT][FILTER_WIDTH] = FILTER_COEFFICIENTS_X;
  short filter_y[FILTER_HEIGHT][FILTER_WIDTH] = FILTER_COEFFICIENTS_Y;

  color.a = 0;//Otherwise compiler warns

	for(y_block = 0; y_block < IMAGE_HEIGHT-FILTER_HEIGHT; y_block+=BLOCK_SIZE){
		y_max = y_block + BLOCK_SIZE;
		if(y_max > IMAGE_HEIGHT-FILTER_HEIGHT){
			y_max = IMAGE_HEIGHT-FILTER_HEIGHT;
		}
		for(x_block = 0; x_block < IMAGE_WIDTH-FILTER_WIDTH; x_block+=BLOCK_SIZE){
			x_max = x_block + BLOCK_SIZE;
			if(x_max > IMAGE_WIDTH-FILTER_WIDTH){
				x_max = IMAGE_WIDTH-FILTER_WIDTH;
			}
			for(y = y_block; y < y_max; y++){
				for(x = x_block; x < x_max; x++){
					gradient_x = 0;
					gradient_y = 0;
					for(j = 0; j < FILTER_HEIGHT; j++){
						for(i = 0; i < FILTER_WIDTH; i++){
							color = input[(y+j)*IMAGE_WIDTH+x+i];

//						luma = color.r + color.g + color.b; // Not correct, approximate
							luma = (66*color.r + 129*color.g + 25*color.b) >> 8; // 601 conversions.

							gradient_x += luma*filter_x[j][i];
							gradient_y += luma*filter_y[j][i];
						}
					}

					luma = (abs(gradient_x)+abs(gradient_y))>>RENORM_AMOUNT;

					color.r = luma;
					color.g = luma;
					color.b = luma;
					color.a = 0;

					output[y*IMAGE_WIDTH+x] = color;
				}

#if TOUCHSCREEN
				if (touchscreen_get_pen(pTouch)) {
					return -1;
				}
#endif
			}
		}
	}

  //Blank out the rightmost pixels and bottommost pixels
  color.r = 0;
  color.g = 0;
  color.b = 0;
  for(y = 0; y < IMAGE_HEIGHT; y++){
	for(x = IMAGE_WIDTH-FILTER_WIDTH; x < IMAGE_WIDTH; x++){
	  output[y*IMAGE_WIDTH+x] = color;
	}
  }
  for(y = IMAGE_HEIGHT-FILTER_HEIGHT; y < IMAGE_HEIGHT; y++){
	for(x = 0; x < IMAGE_WIDTH; x++){
	  output[y*IMAGE_WIDTH+x] = color;
	}
  }

  return 0;
}

int scalar_edge_detect_3x3(pixel *input, pixel *output)
{
  int y,x;
  int y_block,x_block,y_max,x_max;
  short gradient_x,gradient_y;
  pixel color;
  short luma;

  color.a = 0;//Otherwise compiler warns

	for(y_block = 0; y_block < IMAGE_HEIGHT-FILTER_HEIGHT; y_block+=BLOCK_SIZE){
		y_max = y_block + BLOCK_SIZE;
		if(y_max > IMAGE_HEIGHT-FILTER_HEIGHT){
			y_max = IMAGE_HEIGHT-FILTER_HEIGHT;
		}
		for(x_block = 0; x_block < IMAGE_WIDTH-FILTER_WIDTH; x_block+=BLOCK_SIZE){
			x_max = x_block + BLOCK_SIZE;
			if(x_max > IMAGE_WIDTH-FILTER_WIDTH){
				x_max = IMAGE_WIDTH-FILTER_WIDTH;
			}
			for(y = y_block; y < y_max; y++){
				for(x = x_block; x < x_max; x++){
					gradient_x = 0;
					gradient_y = 0;

					color = input[(y  )*IMAGE_WIDTH+x  ];
					luma = (66*color.r + 129*color.g + 25*color.b) >> 8; // 601 conversions.
					gradient_x = luma;
					gradient_y = luma;

					color = input[(y  )*IMAGE_WIDTH+x+1];
					luma = (66*color.r + 129*color.g + 25*color.b) >> 8; // 601 conversions.
					//gradient_x += luma;
					gradient_y += 2*luma;

					color = input[(y  )*IMAGE_WIDTH+x+2];
					luma = (66*color.r + 129*color.g + 25*color.b) >> 8; // 601 conversions.
					gradient_x -= luma;
					//gradient_y += luma;

					color = input[(y+1)*IMAGE_WIDTH+x  ];
					luma = (66*color.r + 129*color.g + 25*color.b) >> 8; // 601 conversions.
					gradient_x += 2*luma;
					//gradient_y += luma;

					color = input[(y+1)*IMAGE_WIDTH+x+1];
					luma = (66*color.r + 129*color.g + 25*color.b) >> 8; // 601 conversions.
					//gradient_x += luma;
					//gradient_y += luma;

					color = input[(y+1)*IMAGE_WIDTH+x+2];
					luma = (66*color.r + 129*color.g + 25*color.b) >> 8; // 601 conversions.
					gradient_x += -2*luma;
					//gradient_y += luma;

					color = input[(y+2)*IMAGE_WIDTH+x  ];
					luma = (66*color.r + 129*color.g + 25*color.b) >> 8; // 601 conversions.
					gradient_x += luma;
					gradient_y += -luma;

					color = input[(y+2)*IMAGE_WIDTH+x+1];
					luma = (66*color.r + 129*color.g + 25*color.b) >> 8; // 601 conversions.
					//gradient_x += luma;
					gradient_y += -2*luma;

					color = input[(y+2)*IMAGE_WIDTH+x+2];
					luma = (66*color.r + 129*color.g + 25*color.b) >> 8; // 601 conversions.
					gradient_x += -luma;
					gradient_y += -luma;


					luma = (abs(gradient_x)+abs(gradient_y))>>RENORM_AMOUNT;

					color.r = luma;
					color.g = luma;
					color.b = luma;
					color.a = 0;

					output[y*IMAGE_WIDTH+x] = color;
				}

#if TOUCHSCREEN
				if (touchscreen_get_pen(pTouch)) {
					return -1;
				}
#endif
			}
		}
	}

  //Blank out the rightmost pixels and bottommost pixels
  color.r = 0;
  color.g = 0;
  color.b = 0;
  for(y = 0; y < IMAGE_HEIGHT; y++){
	for(x = IMAGE_WIDTH-FILTER_WIDTH; x < IMAGE_WIDTH; x++){
	  output[y*IMAGE_WIDTH+x] = color;
	}
  }
  for(y = IMAGE_HEIGHT-FILTER_HEIGHT; y < IMAGE_HEIGHT; y++){
	for(x = 0; x < IMAGE_WIDTH; x++){
	  output[y*IMAGE_WIDTH+x] = color;
	}
  }

  return 0;
}

void scalar_to_luma(pixel *input, short *output)
{
  int y, x;
  pixel *color;
  for(y = 0; y < IMAGE_HEIGHT; y++){
	for(x = 0; x < IMAGE_WIDTH; x++){
	  color = input+y*IMAGE_WIDTH+x;
	  output[y*IMAGE_WIDTH+x] = (66*color->r + 129*color->g + 25*color->b) >> 8;
	}
  }
}

int scalar_edge_detect_luma(short *input, pixel *output)
{
  int y,x,j,i;
  int y_block,x_block,y_max,x_max;
  short gradient_x,gradient_y;
  pixel *color;
  short luma;
  short filter_x[FILTER_HEIGHT][FILTER_WIDTH] = FILTER_COEFFICIENTS_X;
  short filter_y[FILTER_HEIGHT][FILTER_WIDTH] = FILTER_COEFFICIENTS_Y;

	for(y_block = 0; y_block < IMAGE_HEIGHT-FILTER_HEIGHT; y_block+=BLOCK_SIZE){
		y_max = y_block + BLOCK_SIZE;
		if(y_max > IMAGE_HEIGHT-FILTER_HEIGHT){
			y_max = IMAGE_HEIGHT-FILTER_HEIGHT;
		}
		for(x_block = 0; x_block < IMAGE_WIDTH-FILTER_WIDTH; x_block+=BLOCK_SIZE){
			x_max = x_block + BLOCK_SIZE;
			if(x_max > IMAGE_WIDTH-FILTER_WIDTH){
				x_max = IMAGE_WIDTH-FILTER_WIDTH;
			}
			for(y = y_block; y < y_max; y++){
				for(x = x_block; x < x_max; x++){
					gradient_x = 0;
					gradient_y = 0;
					for(j = 0; j < FILTER_HEIGHT; j++){
						for(i = 0; i < FILTER_WIDTH; i++){
							luma = input[(y+j)*IMAGE_WIDTH+x+i];

							gradient_x += luma*filter_x[j][i];
							gradient_y += luma*filter_y[j][i];
						}
					}

					luma = (abs(gradient_x)+abs(gradient_y))>>RENORM_AMOUNT;

					if(luma > 255){luma = 255;}

					color = output+y*IMAGE_WIDTH+x;

					color->r = luma;
					color->g = luma;
					color->b = luma;
					color->a = 0;
				}

#if TOUCHSCREEN
				if (touchscreen_get_pen(pTouch)) {
					return -1;
				}
#endif
			}
		}
	}

  //Blank out the rightmost pixels and bottommost pixels
  for(y = 0; y < IMAGE_HEIGHT; y++){
	for(x = IMAGE_WIDTH-FILTER_WIDTH; x < IMAGE_WIDTH; x++){
	  color = output+y*IMAGE_WIDTH+x;
	  color->r = 0;
	  color->g = 0;
	  color->b = 0;
	  color->a = 0;
	}
  }
  for(y = IMAGE_HEIGHT-FILTER_HEIGHT; y < IMAGE_HEIGHT; y++){
	for(x = 0; x < IMAGE_WIDTH; x++){
	  color = output+y*IMAGE_WIDTH+x;
	  color->r = 0;
	  color->g = 0;
	  color->b = 0;
	  color->a = 0;
	}
  }

  return 0;
}


int scalar_edge_detect_luma_3x3(short *input, pixel *output)
{
	int y,x;
	int gradient_x, gradient_y;
	pixel *color;
	int luma;
	short *r0, *r1, *r2;

	int r00, r01, r02;
	int r10, r11, r12;
	int r20, r21, r22;

	for( y = 0; y < IMAGE_HEIGHT-FILTER_HEIGHT; y++ ) {

		r0 = input+(y  )*IMAGE_WIDTH;
		r1 = input+(y+1)*IMAGE_WIDTH;
		r2 = input+(y+2)*IMAGE_WIDTH;

		r00 = r0[0]; r01 = r0[1]; r02 = r0[2];
		r10 = r1[0]; r11 = r1[1]; r12 = r1[2];
		r20 = r2[0]; r21 = r2[1]; r22 = r2[2];

		for( x = 0; x < IMAGE_WIDTH-FILTER_WIDTH; x++ ) {

			gradient_x = gradient_y = 0;

			r0 = input+(y  )*IMAGE_WIDTH+x;
			r1 = input+(y+1)*IMAGE_WIDTH+x;
			r2 = input+(y+2)*IMAGE_WIDTH+x;

			gradient_x +=  1*r00; gradient_y +=  1*r00;
			gradient_x +=  0*r01; gradient_y +=  2*r01;
			gradient_x += -1*r02; gradient_y +=  1*r02;

			gradient_x +=  2*r10; gradient_y +=  0*r10;
			gradient_x +=  0*r11; gradient_y +=  0*r11;
			gradient_x += -2*r12; gradient_y +=  0*r12;

			gradient_x +=  1*r20; gradient_y += -1*r20;
			gradient_x +=  0*r21; gradient_y += -2*r21;
			gradient_x += -1*r22; gradient_y += -1*r22;

			luma = (abs(gradient_x)+abs(gradient_y))>>RENORM_AMOUNT;

			if(luma > 255){luma = 255;}

			color = output+y*IMAGE_WIDTH+x;

			color->r = luma;
			color->g = luma;
			color->b = luma;
			color->a = 0;

			r00 = r01;
			r01 = r02;
			r02 = r0[3];

			r10 = r11;
			r11 = r12;
			r12 = r1[3];

			r20 = r21;
			r21 = r22;
			r22 = r2[3];

		}

#if TOUCHSCREEN
		if (touchscreen_get_pen(pTouch)) {
			return -1;
		}
#endif
	}

	//Blank out the rightmost pixels and bottommost pixels
	for(y = 0; y < IMAGE_HEIGHT; y++) {
		for(x = IMAGE_WIDTH-FILTER_WIDTH; x < IMAGE_WIDTH; x++) {
			color = output+y*IMAGE_WIDTH+x;
			color->r = 0;
			color->g = 0;
			color->b = 0;
			color->a = 0;
		}
	}
	for(y = IMAGE_HEIGHT-FILTER_HEIGHT; y < IMAGE_HEIGHT; y++) {
		for(x = 0; x < IMAGE_WIDTH; x++) {
			color = output+y*IMAGE_WIDTH+x;
			color->r = 0;
			color->g = 0;
			color->b = 0;
			color->a = 0;
		}
	}

	return 0;
}
