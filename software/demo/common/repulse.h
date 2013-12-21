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


#ifndef __PARTICLES_H
#define __PARTICLES_H

#include <stdint.h>
#include "fix16.h"
#include "vbw_fix16.h"
#include "draw.h"

#define DSPBA_FLOATING   0 //using free running w/fifo instead of clock enable
#define USE_BLOCK 0

#define NUM_PARTICLES 512   
#define BORDER  8

#define ITERS_PER_UPDATE 12
#define SCALAR_ITERS_PER_UPDATE 1   
#define LISSAJOUS_UPDATE_CYCLES ITERS_PER_UPDATE // changes gravity refresh

#define FPS  2 

#define DRAW_PARTICLES 1
#define USE_DIAMOND 0
#define USE_BLACK 0 //Turn on for black background (slower)
#define USE_ALPHA 0 //Turn off for faster particle sim
#define WINDOW_SIZE 4 //Bigger camera 'pass-through' windows

typedef struct {
	// main memory version of dat
	fxp_t *Px; // position, src
	fxp_t *Py;
	fxp_t *Qx; // position, dst
	fxp_t *Qy;
	fxp_t *Vx; // velocity
	fxp_t *Vy;
	fxp_t *size;
	fxp_t *inv_size;
	fxp_t *gm;

	// scratchpad version of data
	vbx_word_t *v_Px; // position, src
	vbx_word_t *v_Py;
	vbx_word_t *v_Qx; // position, dst
	vbx_word_t *v_Qy;
	vbx_word_t *v_Vx; // velocity
	vbx_word_t *v_Vy;
	vbx_word_t *v_inv_size;
	vbx_word_t *v_size;
	vbx_word_t *v_gm;
} particle_t;

typedef struct {
	vbx_word_t *v_Px; // position, src
	vbx_word_t *v_Py;
	vbx_word_t *v_size;
} particle_block_t;

//---------------- variables for score keeping and physics -- declared in particles.c
extern particle_t    particles;
extern volatile int _init_flag;

extern fxp_t dt;
extern fxp_t gravityX;
extern fxp_t gravityY;

extern fxp_t wallForce;
extern fxp_t wallEpsilon;
extern fxp_t wallReflect;
extern fxp_t frictionForce;
extern fxp_t minEpsilon;

extern fxp_t collisionEpsilon_min;
extern fxp_t collisionEpsilon_max;

extern fxp_t collisionForce;
extern fxp_t repulsionForce;

extern fxp_t minPx;
extern fxp_t minPy;
extern fxp_t maxPx;
extern fxp_t maxPy;

extern fxp_t minDist;

//----------------

//Shared functions - particles.c
void particle_free(particle_t *p_particles);
void particle_malloc(particle_t *p_particles);
void particle_init(particle_t *p_particles, const int image_width, const int image_height);
void particle_copy(particle_t *p_source, particle_t *p_dest);

// This is our touch panel
#if TOUCHSCREEN
extern touchscreen_t *pTouch;
#endif
//scalar functions -- scalar_particles.c
int force_calc(fxp_t *pfx, fxp_t *pfy, int i, int j);
void boundsCheck( fxp_t *pP, fxp_t *pV, fxp_t dist, fxp_t newP, int posNeg);
void update();
int scalar_repulsion_demo(pixel *buffer, int gravity_x, int gravity_y, const int image_width, const int image_height);

//vector functions -- vector_particles.c 
void vector_update(int hw_full, int hw_div, int hw_sqrt, int block_size, int block_num, int block_max);
int vector_repulsion_demo(pixel *buffer, int gravity_x, int gravity_y, const int image_width, const int image_height);

#endif // __PARTICLES_H 
