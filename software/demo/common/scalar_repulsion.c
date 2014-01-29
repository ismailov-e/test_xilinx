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
VBXCOPYRIGHT( scalar_repulsion )

#include <stdint.h>
#include "repulse.h"

int force_calc(fxp_t *pfx, fxp_t *pfy, int i, int j)
{
	*pfx = *pfy = 0;

	fxp_t dx   = fix16_sub( particles.Px[j], particles.Px[i] );
	fxp_t dy   = fix16_sub( particles.Py[j], particles.Py[i] );

	fxp_t dist2, dist, rdist;

	fxp_t dx2 = fix16_mul(dx, dx);
	fxp_t dy2 = fix16_mul(dy, dy);
	dist2 = fix16_add(dx2, dy2);
	if(dx2 < 0 || dy2 < 0){
		return  0;
	}
	dist  = fix16_sqrt(dist2);
	if(dist < minDist){
		return 0;
	}

	rdist = fix16_div( fix16_from_float(1.0), dist );
	fxp_t gmm = fix16_mul(particles.gm[j], particles.size[i]);
	fxp_t gmm_rdist3 = fix16_mul(rdist, fix16_mul(rdist, fix16_mul(rdist, gmm)));


	*pfx = fix16_mul(dx, gmm_rdist3);
	*pfy = fix16_mul(dy, gmm_rdist3);
	return 0;
}

void boundsCheck2( fxp_t *pP, fxp_t *pV, fxp_t *pinv_size, fxp_t min, fxp_t max)
{
	//Zero force, our wallforce vector
	fxp_t force, tmp;
	force = 0;

	//If < min+epsilon, add wallforce*((min+epsilon)-p) into force
	tmp = fix16_sub(min+wallEpsilon, *pP);
	if(tmp > 0){
		force = fix16_mul(wallForce, tmp);
	}

	//If < min, move in min+(min-p) and reverse velocity
	tmp = fix16_sub(min,         *pP);
	if(min > *pP){
		*pP = fix16_add(min,         tmp);
		*pV = fix16_mul(wallReflect, *pV);
	}


	//If > max-epsilon, add wallforce*((max-epsilon)-p) into force
	tmp = fix16_sub(max-wallEpsilon, *pP);
	if(tmp < 0){
		force = fix16_mul(wallForce,       tmp);
	}

	//If > max, move in max-(p-max) and reverse velocity
	tmp = fix16_sub(max,         *pP);
	if(max < *pP){
		*pP=fix16_add(max,         tmp);
		*pV=fix16_mul(wallReflect, *pV);
	}

	//divide force by size to get force, add into velocity
	force = fix16_mul(force, *pinv_size);
	*pV = fix16_add(force, *pV);

	//Final check because crazy high velocities can cause reflections out of bounds
	if(min > *pP){
		*pP = min; 
	}
	if(max < *pP){
		*pP = max; 
	}
}

void update()
{
	int i,j;
	fxp_t fx, dfx;
	fxp_t fy, dfy;

	for( j=0; j < NUM_PARTICLES; j++ ) {
		// compute net force on particle j
		fx = fy = 0;

		// by summing all forces contributed by particles i
		for( i=0; i < NUM_PARTICLES; i++ ) {
			if( i==j ) continue;

			force_calc( &dfx, &dfy, i, j);
			// do force-based force adjustment
			fx = fix16_add( fx, dfx );
			fy = fix16_add( fy, dfy );
		}

		// compensate force by mass of particle
		fxp_t size = particles.size[j];
		size = fix16_mul( size, fix16_mul(size, size) );
		fx = fix16_div( fx, size );
		fy = fix16_div( fy, size );


		fx = fix16_add( fx, gravityX );
		fy = fix16_add( fy, gravityY );
		fx = fix16_mul( fx, dt );
		fy = fix16_mul( fy, dt );

		// update the velocity vectors for particle j
		fxp_t vx = fix16_mul( particles.Vx[j], frictionForce );
		fxp_t vy = fix16_mul( particles.Vy[j], frictionForce );
		particles.Vx[j] = fix16_add( vx, fx );
		particles.Vy[j] = fix16_add( vy, fy );

		// compute the new position vectors for particle j
		particles.Qx[j] = fix16_add( particles.Px[j] , fix16_mul(particles.Vx[j],dt) );
		particles.Qy[j] = fix16_add( particles.Py[j] , fix16_mul(particles.Vy[j],dt) );
	}

#if !SKIP_BOUNDS_CHECK
	// test for out-of-bounds and wall reflections
	for( j=0; j < NUM_PARTICLES; j++ ) {
		fxp_t *pPx = particles.Qx+j;
		fxp_t *pPy = particles.Qy+j;
		fxp_t *pVx = particles.Vx+j;
		fxp_t *pVy = particles.Vy+j;
		fxp_t *pinv = particles.inv_size+j;

		boundsCheck2( pPx, pVx, pinv, minPx, maxPx );
		boundsCheck2( pPy, pVy, pinv, minPy, maxPy );
	}
#endif

	// swap P and Q (input and output buffers)
	{ fxp_t *px = particles.Px; particles.Px = particles.Qx ; particles.Qx = px; }
	{ fxp_t *py = particles.Py; particles.Py = particles.Qy ; particles.Qy = py; }


}

void particles_remap_cached(particle_t *p_particles)
{
	p_particles->Px   = (fxp_t *)vbx_remap_cached( p_particles->Px , 1); 
	p_particles->Py   = (fxp_t *)vbx_remap_cached( p_particles->Py , 1); 
	p_particles->Qx   = (fxp_t *)vbx_remap_cached( p_particles->Qx , 1); 
	p_particles->Qy   = (fxp_t *)vbx_remap_cached( p_particles->Qy , 1); 
	p_particles->Vx   = (fxp_t *)vbx_remap_cached( p_particles->Vx , 1); 
	p_particles->Vy   = (fxp_t *)vbx_remap_cached( p_particles->Vy , 1); 
	p_particles->size = (fxp_t *)vbx_remap_cached( p_particles->size, 1);
	p_particles->inv_size = (fxp_t *)vbx_remap_cached( p_particles->inv_size, 1); 
	p_particles->gm   = (fxp_t *)vbx_remap_cached( p_particles->gm, 1);  
}


int scalar_repulsion_demo(pixel *buffer, int gravity_x, int gravity_y, const int image_width, const int image_height)
{

#if !X86
	if(!_init_flag){
		particle_init(&particles, image_width, image_height);
		_init_flag++;
	}
#endif
	particles_remap_cached(&particles);

	gravityX = gravity_x;
	gravityY = gravity_y;

	int iter;
	for(iter = 0; iter < SCALAR_ITERS_PER_UPDATE; iter++){
		update();
	}

	return 0;
}

