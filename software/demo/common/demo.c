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
VBXCOPYRIGHT( demo )

#include "demo.h"
#include "repulse.h"
#include "vbw_mtx_sobel.h"
#include "scalar_mtx_sobel.h"
#include "vbw_mtx_median_argb32.h"
#include "scalar_mtx_median_argb32.h"

void demo_title(char *board, const int image_width, const int image_height)
{
	printf("VectorBlox1 MXP %s demo loaded\n", board);
	printf("Screen Resolution = %ux%u\n", image_width, image_height);
}

float time_to_ms(vbx_timestamp_t time)
{
	return ((float)(time))/((float)vbx_timestamp_freq())*1000.0;
}

void draw_vblogo(pixel *bg, int vector)
{
	if (vector) {
		vector_draw_alpha(X_MARGIN, Y_MARGIN, bg, (pixel *)VBLOGO_PIXEL_DATA, VBLOGO_WIDTH, VBLOGO_HEIGHT);
	}
	else {
		scalar_draw_vblogo(X_MARGIN, Y_MARGIN, bg);
	}
}

//Returns x posititon of end of string
int overlay_printf(char *print_string, int startx, int starty, int max_length, pixel *buffer, int vector_overlay)
{
	if (vector_overlay) {
		return vector_overlay_printf(print_string, startx, starty, max_length, buffer);
	}
	else {
		return scalar_overlay_printf(print_string, startx, starty, max_length, buffer);
	}
}

void update_time(float *processing_ms, float *total_ms, int local_mode, int cycles, vbx_timestamp_t frame_time, vbx_timestamp_t wait_time)
{
	if (!(local_mode%2) || local_mode==MODE_VECTOR_MANDEL || !(cycles%32)) {
		*processing_ms = time_to_ms(frame_time-wait_time);
		if (local_mode==MODE_VECTOR_REPULSION) {
			total_ms[local_mode] = time_to_ms(frame_time/ITERS_PER_UPDATE);
		}else if (local_mode==MODE_SCALAR_REPULSION) {
			total_ms[local_mode] = time_to_ms(frame_time/SCALAR_ITERS_PER_UPDATE);
		}else{
			total_ms[local_mode] = time_to_ms(frame_time);
		}
	}
}

void display_title(demo_t *pDemo, char *strbuff_title, int local_mode, int uses_video_in, int vector_overlay, const int image_height)
{
	if (local_mode != MODE_PASSTHRU) {
		pixel *overlay_buffer = (uses_video_in) ?
			(pixel *)pDemo->buffer[BUFFER_PROCESSING] :
			(pixel *)pDemo->buffer[BUFFER_READING];
		overlay_printf(strbuff_title, X_MARGIN,
				image_height-Y_MARGIN-CHAR_HEIGHT,
				MAX_STRING_LENGTH, overlay_buffer, vector_overlay);
	}
}

void display_logo(demo_t *pDemo, int uses_video_in, int vector_overlay)
{
	pixel *overlay_buffer = (uses_video_in) ?
		(pixel *)pDemo->buffer[BUFFER_PROCESSING] :
			(pixel *)pDemo->buffer[BUFFER_READING];
		draw_vblogo(overlay_buffer, vector_overlay);
}

int show_fps(int mode)
{
	if(mode == MODE_SCALAR_FACE_DETECT || mode == MODE_VECTOR_FACE_DETECT ||
	   mode == MODE_SCALAR_EDGE_DETECT || mode == MODE_VECTOR_EDGE_DETECT ){
		return 1;
	}

	return 0;
}

int display_ms(demo_t *pDemo, char *strbuff_title, char *strbuff, int local_mode, float time, int x_string_loc, int uses_video_in, int vector_overlay, const int image_height)
{
	pixel *overlay_buffer = (uses_video_in) ?
		(pixel *)pDemo->buffer[BUFFER_PROCESSING] :
		(pixel *)pDemo->buffer[BUFFER_READING];
	x_string_loc = overlay_printf(strbuff_title, X_MARGIN,
			image_height-Y_MARGIN-CHAR_HEIGHT,
			MAX_STRING_LENGTH, overlay_buffer, vector_overlay);
	if(show_fps(local_mode)){
		snprintf(strbuff, MAX_STRING_LENGTH, "%5.*fms %5.*ffps",
				(local_mode == MODE_SCALAR_MANDEL || local_mode == MODE_VECTOR_MANDEL)? 0: 1,
				time,
				(local_mode == MODE_SCALAR_MANDEL || local_mode == MODE_VECTOR_MANDEL)? 2: 1,
				1000.0/time);
	} else {
		snprintf(strbuff, MAX_STRING_LENGTH, "%5.*fms",
				(local_mode == MODE_SCALAR_MANDEL || local_mode == MODE_VECTOR_MANDEL)? 0: 1,
				time);
	}
	x_string_loc = overlay_printf(strbuff, x_string_loc,
			image_height-Y_MARGIN-CHAR_HEIGHT,
			MAX_STRING_LENGTH, overlay_buffer, vector_overlay);
	return x_string_loc;
}

int display_speedup(demo_t *pDemo, char *strbuff, int x_string_loc, float vector_time, float scalar_time, int uses_video_in, int uses_vector, int vector_overlay, const int image_height)
{
	pixel *overlay_buffer = (uses_video_in) ?
		(pixel *)pDemo->buffer[BUFFER_PROCESSING] :
		(pixel *)pDemo->buffer[BUFFER_READING];
	// compare MXP vs scalar CPU processing
	if ( uses_vector && (scalar_time != 0.0) ) {
		snprintf(strbuff, MAX_STRING_LENGTH, "%.1fx", scalar_time/vector_time);
		x_string_loc = overlay_printf(strbuff, x_string_loc,
				image_height-Y_MARGIN-CHAR_HEIGHT,
				MAX_STRING_LENGTH, overlay_buffer, vector_overlay);
	}
	return x_string_loc;
}

void console_title(char *strbuff_title, int local_mode)
{
	if (local_mode != MODE_PASSTHRU) {
		printf( "SWITCH: %s\n", strbuff_title);
	}
}

void console_ms(char *strbuff_title, int local_mode, int cycles, float time)
{
	if (((local_mode == MODE_SCALAR_MANDEL) || (local_mode == MODE_VECTOR_MANDEL)) ||
			(cycles % 32 == 0)) {
		if(show_fps(local_mode)){
			printf( "%s %.*fms %.*ffps frame=%d\n", strbuff_title,
				(local_mode == MODE_SCALAR_MANDEL || local_mode == MODE_VECTOR_MANDEL)? 0: 1,
				time,
				(local_mode == MODE_SCALAR_MANDEL || local_mode == MODE_VECTOR_MANDEL)? 2: 1,
				1000.0/time,
				cycles);
		}else{
			printf( "%s %.*fms frame=%d\n", strbuff_title,
				(local_mode == MODE_SCALAR_MANDEL || local_mode == MODE_VECTOR_MANDEL)? 0: 1,
				time,
				cycles);
		}
	}
}

void console_speedup(int local_mode, float vector_time, float scalar_time, int uses_vector, int cycles)
{
	// compare MXP vs Scalar CPU processing
	if ( uses_vector && (scalar_time != 0.0) && (local_mode == MODE_VECTOR_MANDEL || (cycles % 32 == 0))) {
		printf(" %.1fx", scalar_time/vector_time);
		printf("\n");
	}
}

void application_title(char *scalar_cpu, char *strbuff_title, int vector_lanes, int vci_lanes, int mode)
{
	switch (mode) {

		case MODE_SCALAR_SPLIT:
			snprintf(strbuff_title, MAX_STRING_LENGTH, "%s Split:", scalar_cpu);
			break;

		case MODE_VECTOR_SPLIT:
			snprintf(strbuff_title, MAX_STRING_LENGTH, "MXP V%d Split:", vector_lanes);
			break;

		case MODE_SCALAR_MULTI:
			snprintf(strbuff_title, MAX_STRING_LENGTH, "%s Multi:", scalar_cpu);
			break;

		case MODE_VECTOR_MULTI:
			snprintf(strbuff_title, MAX_STRING_LENGTH, "MXP V%d Multi:", vector_lanes);
			break;

		case MODE_SCALAR_FACE_DETECT:
			snprintf(strbuff_title, MAX_STRING_LENGTH, "%s Haar Detect:", scalar_cpu);
			break;

		case MODE_VECTOR_FACE_DETECT:
			snprintf(strbuff_title, MAX_STRING_LENGTH, "MXP V%d Haar Detect:", vector_lanes);
			break;

		case MODE_SCALAR_EDGE_DETECT:
			snprintf(strbuff_title, MAX_STRING_LENGTH, "%s Edge Detect:", scalar_cpu);
			break;

		case MODE_VECTOR_EDGE_DETECT:
			snprintf(strbuff_title, MAX_STRING_LENGTH, "MXP V%d Edge Detect:", vector_lanes);
			break;

		case MODE_SCALAR_MOTEST:
			snprintf(strbuff_title, MAX_STRING_LENGTH, "%s Motion Estimation:", scalar_cpu);
			break;

		case MODE_VECTOR_MOTEST:
			snprintf(strbuff_title, MAX_STRING_LENGTH, "MXP V%d Motion Estimation:", vector_lanes);
			break;

		case MODE_SCALAR_MANDEL:
			snprintf(strbuff_title, MAX_STRING_LENGTH, "%s Mandelbrot:", scalar_cpu);
			break;

		case MODE_VECTOR_MANDEL:
			snprintf(strbuff_title, MAX_STRING_LENGTH, "MXP V%d Mandelbrot:", vector_lanes);
			break;

		case MODE_VECTOR_REPULSION:
			if (vci_lanes > 0) {
				snprintf(strbuff_title, MAX_STRING_LENGTH, "MXP V%d C%d Particles:", vector_lanes, vci_lanes);
			} else {
				snprintf(strbuff_title, MAX_STRING_LENGTH, "MXP V%d Particles:", vector_lanes);
			}
			break;

		case MODE_SCALAR_REPULSION:
			snprintf(strbuff_title, MAX_STRING_LENGTH, "%s Particles:", scalar_cpu);
			break;

		default:
			snprintf(strbuff_title, MAX_STRING_LENGTH, " ");
			break;
	}
}

void application_init(demo_t *pDemo, int mode, int *switch_buffers_enable, int *uses_vector)
{

	if(mode == MODE_SCALAR_MANDEL || mode == MODE_VECTOR_MANDEL){
		*switch_buffers_enable = 0;
	}else{
		*switch_buffers_enable = 1;
	}
	if(mode%2){
		*uses_vector = 1;
	}else{
		*uses_vector = 0;
	}

}

int application_run(demo_t *pDemo, int local_mode, int cycles, int *pgravity_x, int *pgravity_y, vbx_timestamp_t* frame_time, const int image_width, const int image_height)
{
	static int motest_count = 0;
	static int mo_x1;
	static int mo_y1;
	static luma_type *last_luma1 = NULL;
	static int mo_x2;
	static int mo_y2;
	static luma_type *last_luma2 = NULL;

	int reset = 0;
	if(!(motest_count%400)){
		reset = 1;
	}

	int frame_status = 0;
	vbx_timestamp_t time_start, time_stop;

	vbx_timestamp_start();
	time_start = vbx_timestamp();

	switch(local_mode){

		case MODE_SCALAR_SPLIT:
			//full screen
			if (!(cycles%LISSAJOUS_UPDATE_CYCLES)){
				lissajous( pgravity_x, pgravity_y, cycles);
			}
			scalar_repulsion_demo((pixel *)pDemo->buffer[BUFFER_PROCESSING], *pgravity_x, *pgravity_y, image_width, image_height);
			vector_draw_screen((pixel *)pDemo->buffer[BUFFER_PROCESSING], NUM_PARTICLES, 0, 0, 1, image_width, image_height, image_width);

			//right
			scalar_rgb2luma( pDemo->short_buffer, (pixel *)pDemo->buffer[BUFFER_PROCESSING]+image_width/2, image_width/2, image_height, image_width);
			scalar_sobel_argb32_3x3((pixel *)pDemo->buffer[BUFFER_PROCESSING]+image_width/2, pDemo->short_buffer, image_width/2, image_height, image_width, 0);

			time_stop = vbx_timestamp();
			frame_status = 0;
			break;

		case MODE_VECTOR_SPLIT:
			//full-screen
			if (!(cycles%LISSAJOUS_UPDATE_CYCLES)){
				lissajous( pgravity_x, pgravity_y, cycles);
			}
			vector_repulsion_demo((pixel *)pDemo->buffer[BUFFER_PROCESSING], *pgravity_x, *pgravity_y, image_width, image_height);
			vector_draw_screen((pixel *)pDemo->buffer[BUFFER_PROCESSING], NUM_PARTICLES, 0, 0, 1, image_width, image_height, image_width);

			//right
			vbw_sobel_argb32_3x3((unsigned *)pDemo->buffer[BUFFER_PROCESSING]+image_width/2, (unsigned *)pDemo->buffer[BUFFER_PROCESSING]+image_width/2, image_width/2, image_height, image_width, 0);

			time_stop = vbx_timestamp();
			frame_status = 0;
			break;

		case MODE_SCALAR_MULTI:
			//full screen
			if (!(cycles%LISSAJOUS_UPDATE_CYCLES)){
				lissajous( pgravity_x, pgravity_y, cycles);
			}
			scalar_repulsion_demo((pixel *)pDemo->buffer[BUFFER_PROCESSING], *pgravity_x, *pgravity_y, image_width, image_height);
			vector_draw_screen((pixel *)pDemo->buffer[BUFFER_PROCESSING], NUM_PARTICLES, 0, 0, 0, image_width, image_height, image_width);

			//top-left
			scalar_rgb2luma( pDemo->short_buffer, (pixel *)pDemo->buffer[BUFFER_PROCESSING], image_width/2, image_height/2, image_width);
			scalar_sobel_argb32_3x3((pixel *)pDemo->buffer[BUFFER_PROCESSING], pDemo->short_buffer, image_width/2, image_height/2, image_width, 0);

			//top-right
			scalar_motest((pixel *)pDemo->buffer[BUFFER_PROCESSING]+image_width/2, &last_luma1, &mo_x1, &mo_y1, image_width/8*1, image_height/4, reset, image_width/2, image_height/2, image_width);
			scalar_motest((pixel *)pDemo->buffer[BUFFER_PROCESSING]+image_width/2, &last_luma2, &mo_x2, &mo_y2, image_width/8*3, image_height/4, reset, image_width/2, image_height/2, image_width);

			//bottom-left
			//scalar_mtx_median_argb32((pixel *)pDemo->buffer[BUFFER_PROCESSING]+image_width*image_height/2+image_width/4, 5, 5, image_height/2, image_width/4, image_width);

			//bottom-right
			scalar_invert_image((pixel *)pDemo->buffer[BUFFER_PROCESSING]+image_width*image_height/2+image_width/2, image_width/2, image_height/2, image_width);

			time_stop = vbx_timestamp();
			frame_status = 0;
			motest_count++;
			break;

		case MODE_VECTOR_MULTI:
			//full-screen
			if (!(cycles%LISSAJOUS_UPDATE_CYCLES)){
				lissajous( pgravity_x, pgravity_y, cycles);
			}
			vector_repulsion_demo((pixel *)pDemo->buffer[BUFFER_PROCESSING], *pgravity_x, *pgravity_y, image_width, image_height);
			vector_draw_screen((pixel *)pDemo->buffer[BUFFER_PROCESSING], NUM_PARTICLES, 0, 0, 0, image_width, image_height, image_width);

			//top-left
			vbw_sobel_argb32_3x3((unsigned *)pDemo->buffer[BUFFER_PROCESSING], (unsigned *)pDemo->buffer[BUFFER_PROCESSING], image_width/2, image_height/2, image_width, 0);

			//top-right
			vector_motest((pixel *)pDemo->buffer[BUFFER_PROCESSING]+image_width/2, &last_luma1, &mo_x1, &mo_y1, image_width/8*1, image_height/4, reset, image_width/2, image_height/2, image_width);
			vector_motest((pixel *)pDemo->buffer[BUFFER_PROCESSING]+image_width/2, &last_luma2, &mo_x2, &mo_y2, image_width/8*3, image_height/4, reset, image_width/2, image_height/2, image_width);

			//bottom-left
			//vbw_mtx_median_argb32((unsigned *)pDemo->buffer[BUFFER_PROCESSING]+image_width*image_height/2+image_width/4, 5, 5, image_height/2, image_width/4, image_width);

			//bottom-right
			vector_invert_image((pixel *)pDemo->buffer[BUFFER_PROCESSING]+image_width*image_height/2+image_width/2, image_width/2, image_height/2, image_width);

			time_stop = vbx_timestamp();
			frame_status = 0;
			motest_count++;
			break;

		case MODE_SCALAR_EDGE_DETECT:
			scalar_rgb2luma( pDemo->short_buffer, (pixel *)pDemo->buffer[BUFFER_PROCESSING], image_width, image_height, image_width);
			scalar_sobel_argb32_3x3((pixel *)pDemo->buffer[BUFFER_PROCESSING], pDemo->short_buffer, image_width, image_height, image_width, 0);
			frame_status = 0;
			time_stop = vbx_timestamp();
			break;

		case MODE_VECTOR_EDGE_DETECT:
			frame_status = vbw_sobel_argb32_3x3((unsigned *)pDemo->buffer[BUFFER_PROCESSING], (unsigned *)pDemo->buffer[BUFFER_PROCESSING], image_width, image_height, image_width, 0);
			time_stop = vbx_timestamp();
			break;

		case MODE_SCALAR_MOTEST:
			//frame_status = scalar_motest((pixel *)pDemo->buffer[BUFFER_PROCESSING], image_width, image_height, image_width);
			scalar_motest((pixel *)pDemo->buffer[BUFFER_PROCESSING], &last_luma1, &mo_x1, &mo_y1, image_width/4*1, image_height/2, reset, image_width, image_height, image_width);
			scalar_motest((pixel *)pDemo->buffer[BUFFER_PROCESSING], &last_luma2, &mo_x2, &mo_y2, image_width/4*3, image_height/2, reset, image_width, image_height, image_width);
			frame_status = 0;
			time_stop = vbx_timestamp();
			motest_count++;
			break;

		case MODE_VECTOR_MOTEST:
			//frame_status = vector_motest((pixel *)pDemo->buffer[BUFFER_PROCESSING], image_width, image_height, image_width);
			vector_motest((pixel *)pDemo->buffer[BUFFER_PROCESSING], &last_luma1, &mo_x1, &mo_y1, image_width/4*1, image_height/2, reset, image_width, image_height, image_width);
			vector_motest((pixel *)pDemo->buffer[BUFFER_PROCESSING], &last_luma2, &mo_x2, &mo_y2, image_width/4*3, image_height/2, reset, image_width, image_height, image_width);
			frame_status = 0;
			time_stop = vbx_timestamp();
			motest_count++;
			break;

		case MODE_SCALAR_MANDEL:
			frame_status = mandelbrot((pixel *)pDemo->buffer[BUFFER_READING], 0);
			time_stop = vbx_timestamp();
			break;

		case MODE_VECTOR_MANDEL:
			frame_status = mandelbrot((pixel *)pDemo->buffer[BUFFER_READING], 1);
			time_stop = vbx_timestamp();
			break;

		case MODE_SCALAR_REPULSION:
			if (!(cycles%LISSAJOUS_UPDATE_CYCLES)){
				lissajous( pgravity_x, pgravity_y, cycles++);
			}
			frame_status = scalar_repulsion_demo((pixel *)pDemo->buffer[BUFFER_PROCESSING], *pgravity_x, *pgravity_y, image_width, image_height);
			time_stop = vbx_timestamp();
			vector_draw_screen((pixel *)pDemo->buffer[BUFFER_PROCESSING], NUM_PARTICLES, 0, 0, 1, image_width, image_height, image_width);
			break;

		case MODE_VECTOR_REPULSION:
			if (!(cycles%LISSAJOUS_UPDATE_CYCLES)){
				lissajous( pgravity_x, pgravity_y, cycles);
			}
			frame_status = vector_repulsion_demo((pixel *)pDemo->buffer[BUFFER_PROCESSING], *pgravity_x, *pgravity_y, image_width, image_height);
			time_stop = vbx_timestamp();
			vector_draw_screen((pixel *)pDemo->buffer[BUFFER_PROCESSING], NUM_PARTICLES, 0, 0, 1, image_width, image_height, image_width);
			break;

		case MODE_SCALAR_FACE_DETECT:
			scalar_rgb2luma( pDemo->short_buffer, (pixel *)pDemo->buffer[BUFFER_PROCESSING], image_width, image_height, image_width);
			frame_status = scalar_face_detect_luma(pDemo->short_buffer, (pixel *)pDemo->buffer[BUFFER_PROCESSING], image_width, image_height, image_width);
			time_stop = vbx_timestamp();
			break;

		case MODE_VECTOR_FACE_DETECT:
			frame_status = vector_face_detect((pixel *)pDemo->buffer[BUFFER_PROCESSING], image_width, image_height, image_width);
			time_stop = vbx_timestamp();
			break;


		default:
			time_stop = vbx_timestamp();
			break;
	}

	*frame_time = (time_stop - time_start);

	return frame_status;

}

void loop_demo(demo_t *pDemo)
{
	//string containing timing info
	char strbuff[MAX_STRING_LENGTH];
	//string containing current application title
	char strbuff_title[MAX_STRING_LENGTH];
	//x-offset used when writing components of overlay
	int x_string_loc = 0;

	int current_mode, next_mode;
	int cycles = 0;

	vbx_timestamp_t wait_time = 0, frame_time;
	int frame_status;
	float processing_ms, wait_ms, total_ms[2*NUM_MODES] = {0.0};


	int uses_video_in = 1;
	int uses_vector = 1;
	int vector_overlay = 0;

	int gravity_x = 0;
	int gravity_y = 0;

	vbx_timestamp_start();

	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	const int vector_lanes = this_mxp->vector_lanes;
	const int vci_lanes = (this_mxp->vci_enabled) ? this_mxp->vci_lanes : 0;
	const int image_width = IMAGE_WIDTH;
	const int image_height = IMAGE_HEIGHT;

	// print demo title
	demo_title(BOARD, IMAGE_WIDTH, IMAGE_HEIGHT);
	printf("Starting main loop\n");

	// immediately jump into ...
	next_mode = MODE_VECTOR_REPULSION;
	current_mode     = -1;

	while(1) {

		// update application info
		if (current_mode != next_mode) {
			current_mode = next_mode;

			application_init(pDemo, current_mode, &uses_video_in, &uses_vector);
			application_title(SCALAR_CPU, strbuff_title, vector_lanes, vci_lanes, current_mode);
			display_title(pDemo, strbuff_title, current_mode, uses_video_in, vector_overlay, image_height);
			console_title(strbuff_title, current_mode);
		}

		// process frame here
		frame_status = application_run(pDemo, current_mode, cycles, &gravity_x, &gravity_y, &frame_time, image_width, image_height);
		cycles++;

		// display logo and timing info
		if (current_mode != MODE_PASSTHRU && frame_status != -1) {
			display_logo(pDemo, uses_video_in, vector_overlay);

			update_time(&processing_ms, total_ms, current_mode, cycles, frame_time, wait_time);

			x_string_loc = display_ms(pDemo, strbuff_title, strbuff, current_mode, total_ms[current_mode],  x_string_loc, uses_video_in, vector_overlay, image_height);
			console_ms(strbuff_title, current_mode, cycles, total_ms[current_mode]);

			display_speedup(pDemo, strbuff, x_string_loc, total_ms[current_mode], total_ms[current_mode-1], uses_video_in, uses_vector, vector_overlay, image_height);
			console_speedup(current_mode, total_ms[current_mode], total_ms[current_mode-1], uses_vector, cycles);
		}

		// flush data cache, swap frame buffers, and check for new mode
		vbx_dcache_flush_all();
		wait_time = frame_buffer_update(pDemo, uses_video_in);
		wait_ms = time_to_ms(wait_time);

		next_mode = application_mode(pDemo, current_mode);
	}
}

