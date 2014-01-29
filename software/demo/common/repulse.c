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
VBXCOPYRIGHT( repulse )

#include <stdint.h>
#include "repulse.h"

#if !X86
#define FREE vbx_shared_free
#define MALLOC vbx_shared_malloc
#else
#define FREE free
#define MALLOC malloc
#endif

particle_t    particles = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};
volatile int _init_flag = 0;

fxp_t dt;
fxp_t gravityX;
fxp_t gravityY;

fxp_t wallForce;
fxp_t wallEpsilon;
fxp_t wallReflect;
fxp_t frictionForce;
fxp_t minEpsilon;

fxp_t collisionEpsilon_min;
fxp_t collisionEpsilon_max;

fxp_t collisionForce;
fxp_t repulsionForce;

fxp_t minPx;
fxp_t minPy;
fxp_t maxPx;
fxp_t maxPy;

fxp_t minDist;

void particle_free(particle_t *p_particles)
{
	FREE(p_particles->Px);   
	FREE(p_particles->Py);
	FREE(p_particles->Qx);
	FREE(p_particles->Qy);
	FREE(p_particles->Vx);
	FREE(p_particles->Vy); 
	FREE(p_particles->size);
	FREE(p_particles->inv_size);
	FREE(p_particles->gm);
}

void particle_malloc(particle_t *p_particles){

	// allocate the memory needed; if there assume it is already allocated
	if(p_particles->Px == NULL){
		p_particles->Px   = (fxp_t *) MALLOC( NUM_PARTICLES * sizeof(fxp_t) );
		p_particles->Py   = (fxp_t *) MALLOC( NUM_PARTICLES * sizeof(fxp_t) );
		p_particles->Qx   = (fxp_t *) MALLOC( NUM_PARTICLES * sizeof(fxp_t) );
		p_particles->Qy   = (fxp_t *) MALLOC( NUM_PARTICLES * sizeof(fxp_t) );
		p_particles->Vx   = (fxp_t *) MALLOC( NUM_PARTICLES * sizeof(fxp_t) );
		p_particles->Vy   = (fxp_t *) MALLOC( NUM_PARTICLES * sizeof(fxp_t) );
		p_particles->size = (fxp_t *) MALLOC( NUM_PARTICLES * sizeof(fxp_t) );
		p_particles->inv_size = (fxp_t *) MALLOC( NUM_PARTICLES * sizeof(fxp_t) );
		p_particles->gm = (fxp_t *) MALLOC( NUM_PARTICLES * sizeof(fxp_t) );
	}
}
#undef FREE
#undef MALLOC

void particle_init(particle_t *p_particles, const int image_width, const int image_height)
{
    dt       = fix16_from_float(((float)(1./FPS)));
    gravityX = fix16_from_float(0.0*9.8);
    gravityY = fix16_from_float(2.0*9.8);

    wallForce     = fix16_from_float(1.0/8192.0);
    wallEpsilon   = fix16_from_float(48.0);
    wallReflect   = fix16_from_float(-1.1);
    frictionForce = fix16_from_float(0.997);
    minEpsilon    = fix16_from_float(0.1); 

    collisionEpsilon_min      = fix16_from_float(16.0);
    collisionEpsilon_max      = fix16_from_float(100.0);

    collisionForce            = fix16_from_float(0.45);
    repulsionForce            = fix16_from_float(4.0);

    minPx = fix16_from_int(BORDER);
    minPy = fix16_from_int(BORDER);
    maxPx = fix16_from_int(image_width-1-BORDER);
    maxPy = fix16_from_int(image_height-1-BORDER);

    minDist = fix16_from_float(1.0);

	particle_malloc(p_particles); //only mallocs if needed

	// initialize particles with random values
	srand(0);
	int i;
	for( i=0; i < NUM_PARTICLES; i++ ) {
		p_particles->Px[i]   = (BORDER+(rand()%(image_width-(BORDER*2))))<<16;
		p_particles->Py[i]   = (BORDER+(rand()%(image_height-(BORDER*2))))<<16;

		p_particles->Vx[i]   = 0;
		p_particles->Vy[i]   = 0;

		if(i==0){
			p_particles->size[i] = fix16_from_float(16.0);
		}else if(i%5 ){
			p_particles->size[i] = fix16_from_float(1.0);
		}else{
			p_particles->size[i] = fix16_from_float(2.0);
		}

		p_particles->inv_size[i] = fix16_div( fix16_from_float(1.0), p_particles->size[i] );
		p_particles->gm[i] = fix16_mul( repulsionForce, p_particles->size[i] );
	}
}

void particle_copy(particle_t *p_source, particle_t *p_dest)
{
	particle_malloc(p_dest); //in case not initialized

	int i;
	for(i = 0; i < NUM_PARTICLES; i++){
		p_dest->Px[i]   = p_source->Px[i];
		p_dest->Py[i]   = p_source->Py[i];
		p_dest->Qx[i]   = p_source->Qx[i];
		p_dest->Qy[i]   = p_source->Qy[i];
		p_dest->Vx[i]   = p_source->Vx[i];
		p_dest->Vy[i]   = p_source->Vy[i];
		p_dest->size[i] = p_source->size[i];
	}
}
