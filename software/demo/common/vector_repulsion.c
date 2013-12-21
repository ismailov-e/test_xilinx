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
VBXCOPYRIGHT( vector_repulsion )

#include <stdint.h>
#include "repulse.h"

particle_t        particles;
particle_block_t  particles_block;
particle_block_t  particles_block_0;
particle_block_t  particles_block_1;
particle_block_t  db[2];

int g_custom_divide_offs;
int g_custom_sqrt_offs;
int g_full_ci_offs;

int vci_init_done = 0;

void vector_particle_vci_init()
{
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	int vci_lanes = this_mxp->vci_lanes;
	int word_frac_bits = this_mxp->fxp_word_frac_bits;

	g_custom_divide_offs = (32+1+word_frac_bits)*vci_lanes;

	g_custom_sqrt_offs = 16*vci_lanes;

#if DSPBA_FLOATING
		g_full_ci_offs = (70+word_frac_bits)/2;
#else
#if __NIOS2__
		g_full_ci_offs = (62+word_frac_bits)/2;
#else
		g_full_ci_offs = (94)/2;
#endif
#endif
	vci_init_done = 1;
}

//keeps 8*num_particles*sizof(vbx_word_t)
void vector_particle_init(particle_t *particles, const int num_particles)
{
	vbx_word_t *v_tmp  = (vbx_word_t *) vbx_sp_malloc( 9*num_particles * sizeof(vbx_word_t) );

	//keep in same order
	particles->v_Px   = v_tmp+0*num_particles;
	particles->v_Py   = v_tmp+1*num_particles;
	particles->v_size = v_tmp+2*num_particles;
	particles->v_Qx   = v_tmp+3*num_particles;
	particles->v_Qy   = v_tmp+4*num_particles;
	particles->v_gm   = v_tmp+5*num_particles;
	particles->v_Vx   = v_tmp+6*num_particles;
	particles->v_Vy   = v_tmp+7*num_particles;
	particles->v_inv_size = v_tmp+8*num_particles;

}

void vector_particle_block_init(particle_block_t *particles_block, const int num_particles)
{
	vbx_word_t *v_tmp  = (vbx_word_t *) vbx_sp_malloc( 3*num_particles * sizeof(vbx_word_t) );

	particles_block->v_Px   = v_tmp+0*num_particles;
	particles_block->v_Py   = v_tmp+1*num_particles;
	particles_block->v_size = v_tmp+2*num_particles;
}

void vector_particle_block_init_db(particle_block_t *double_buffer, const int num_particles)
{
	vbx_word_t *v_tmp  = (vbx_word_t *) vbx_sp_malloc( 2*3*num_particles * sizeof(vbx_word_t) );

	double_buffer[0].v_Px   = v_tmp+0*num_particles;
	double_buffer[0].v_Py   = v_tmp+1*num_particles;
	double_buffer[0].v_size = v_tmp+2*num_particles;
	double_buffer[1].v_Px   = v_tmp+3*num_particles;
	double_buffer[1].v_Py   = v_tmp+4*num_particles;
	double_buffer[1].v_size = v_tmp+5*num_particles;
}

void vector_particle_load(particle_t *particles, const int num_particles, const int block_num)
{
	int offset = num_particles*block_num;
	vbx_dma_to_vector( particles->v_gm,       particles->gm+offset,       num_particles*sizeof(vbx_word_t));
	vbx_dma_to_vector( particles->v_inv_size, particles->inv_size+offset, num_particles*sizeof(vbx_word_t));
	vbx_dma_to_vector( particles->v_size,     particles->size+offset,     num_particles*sizeof(vbx_word_t));
	vbx_dma_to_vector( particles->v_Px,       particles->Px+offset,       num_particles*sizeof(vbx_word_t));
	vbx_dma_to_vector( particles->v_Py,       particles->Py+offset,       num_particles*sizeof(vbx_word_t));
	vbx_dma_to_vector( particles->v_Vx,       particles->Vx+offset,       num_particles*sizeof(vbx_word_t));
	vbx_dma_to_vector( particles->v_Vy,       particles->Vy+offset,       num_particles*sizeof(vbx_word_t));
}

void vector_particle_store(particle_t *particles, const int num_particles, const int block_num)
{
	int offset = num_particles*block_num;
	vbx_dma_to_host( particles->Qx+offset, particles->v_Qx, num_particles*sizeof(vbx_word_t));
	vbx_dma_to_host( particles->Qy+offset, particles->v_Qy, num_particles*sizeof(vbx_word_t));
	vbx_dma_to_host( particles->Vx+offset, particles->v_Vx, num_particles*sizeof(vbx_word_t));
	vbx_dma_to_host( particles->Vy+offset, particles->v_Vy, num_particles*sizeof(vbx_word_t));
}

void vector_particle_block_load(particle_block_t *particles_block, particle_t *particles, const int block_size, const int block_num)
{
	int block_offset = block_size*block_num;

	// FIXME
	// This can be replaced by an interleaved 2D DMA call which allows computation to start before DMA finishes.
	// Suggest keeping this version, and adding a 2D DMA version, then comparing performance.
	vbx_dma_to_vector( particles_block->v_Px,   particles->Px+block_offset, block_size*sizeof(vbx_word_t));
	vbx_dma_to_vector( particles_block->v_Py,   particles->Py+block_offset, block_size*sizeof(vbx_word_t));
	vbx_dma_to_vector( particles_block->v_size, particles->size+block_offset, block_size*sizeof(vbx_word_t));
}

static inline void vector_force_calc_full_hw(vbx_word_t *v_fx, vbx_word_t *v_fy, int j, int num_particles, int use_loaded_block, int current)
{
	//Load in parameters for current particle
	vbx_2D(VVW, VCUSTOM3, v_fx+j, particles.v_Px+j, particles.v_Py+j);

	if(!use_loaded_block){
		//Actual computation
		vbx_3D(VVW, VCUSTOM3, v_fx+j, particles.v_Px, particles.v_Py);
	}else{
		vbx_3D(VVW, VCUSTOM3, v_fx+j, db[current].v_Px, db[current].v_Py);
	}

}

static inline void vector_force_calc(vbx_word_t *v_fx, vbx_word_t *v_fy, int j, int num_particles, int hw_div, int hw_sqrt, int use_loaded_block, int current)
{
	vbx_sp_push();
	int num_vectors;
	num_vectors = 9;

	vbx_word_t *v_tmp = (vbx_word_t*)vbx_sp_malloc(sizeof(vbx_word_t)*num_particles*num_vectors);
	vbx_word_t *v_t_sub   = v_tmp + 0*num_particles;
	vbx_word_t *v_y       = v_tmp + 1*num_particles;
	vbx_word_t *v_x       = v_tmp + 2*num_particles;
	vbx_word_t *v_mm      = v_tmp + 3*num_particles;
	vbx_word_t *v_dx      = v_tmp + 4*num_particles;
	vbx_word_t *v_dy      = v_tmp + 5*num_particles;
	vbx_word_t *v_dist    = v_tmp + 6*num_particles;
	vbx_word_t *v_dist2   = v_tmp + 7*num_particles;
	vbx_word_t *v_rdist   = v_tmp + 8*num_particles;

	vbx_word_t *v_1 = v_mm;

	fxp_t px    = particles.v_Px[j];
	fxp_t py    = particles.v_Py[j];

  //get x and y distances from our current particle to every other
  // (vector)v_Px - (scalar)px
  // (vector)v_Py - (scalar)py
	if(!use_loaded_block){
		vbw_fix16_sub_s(v_dx, px, particles.v_Px);
		vbw_fix16_sub_s(v_dy, py, particles.v_Py);
	}else{
		vbw_fix16_sub_s(v_dx, px, db[current].v_Px);
		vbw_fix16_sub_s(v_dy, py, db[current].v_Py);
	}
  //use sqrt(abs_dx**2 + abs_dy**2) to get distance
	vbw_fix16_mul( v_y, v_dy, v_dy);
	vbw_fix16_mul( v_x, v_dx, v_dx);
	vbw_fix16_add( v_dist2, v_x, v_y);
	if(hw_sqrt){
		vbw_fix16_sqrt_hw(v_dist, v_dist2, num_particles, g_custom_sqrt_offs );
	} else {
		vbw_fix16_sqrt(v_dist, v_dist2, num_particles );

	}

  // reciprocal of distance used later on
	vbx(SVW, VMOV, v_1, fix16_from_int(1), 0); //generate vector of '1's
	if(hw_div){
	  vbw_fix16_div_hw( v_rdist, v_1, v_dist, num_particles, g_custom_divide_offs );// 1/dist
	} else {
		vbw_fix16_div( v_rdist, v_1, v_dist, num_particles );// 1/dist
	}

  //get repulsion force
  if(!use_loaded_block){
	vbw_fix16_mul_s(v_mm, particles.v_gm[j], particles.v_size); //our particle* vector of particle sizes
  }else{
	vbw_fix16_mul_s(v_mm, particles.v_gm[j], db[current].v_size); //our particle* vector of particle sizes
  }

  //(particle*vector of particles**3) / distance**3
	vbw_fix16_mul(v_mm, v_mm,    v_rdist);
	vbw_fix16_mul(v_mm, v_mm,    v_rdist);
	vbw_fix16_mul(v_mm, v_mm,    v_rdist);

	//if dist < minDist, set repulsion to 0 to avoid weird behaviors.
	vbx(SVW, VSUB,     v_t_sub, minDist, v_dist);
	vbx(SVW, VCMV_GTZ, v_mm,    0,       v_t_sub);
	//If squaring overflows occurred, don't use.
	//Note that we add these together before sqrting, but sqrt takes an usigned number,
	//and two signed positive numbers added together won't overflow as unsigned.
	vbx(SVW, VCMV_LTZ, v_mm, 0, v_x);
	vbx(SVW, VCMV_LTZ, v_mm, 0, v_y);

	vbx_acc(VVW, VMULFXP, v_fx+j, v_mm, v_dx);
	vbx_acc(VVW, VMULFXP, v_fy+j, v_mm, v_dy);

	vbx_sp_pop();
}

static inline void vector_boundsCheck2( vbx_word_t *v_p, vbx_word_t *v_v, vbx_word_t *v_inv_size, fxp_t min, fxp_t max, vbx_word_t *v_tmp, int num_particles)
{
	vbx_word_t *v_t0 = v_tmp+0*num_particles;
	vbx_word_t *v_t1 = v_tmp+1*num_particles;
	vbx_word_t *v_t2 = v_tmp+2*num_particles;
	vbx_word_t *v_t3 = v_tmp+3*num_particles;

	//Zero t3, our wallforce vector
	vbx(SVW, VMOV,     v_t3, 0,    0);

	//If < min+epsilon, add wallforce*((min+epsilon)-p) into t3
	vbw_fix16_sub_s(v_t0, min+wallEpsilon, v_p);
	vbw_fix16_mul_s(v_t1, wallForce,       v_t0);
	vbx(VVW, VCMV_GTZ, v_t3, v_t1, v_t0);

	//If < min, move in min+(min-p) and reverse velocity
	vbw_fix16_sub_s(v_t0,   min,         v_p);
	vbw_fix16_mul_s(v_t1,   wallReflect, v_v);
	vbw_fix16_add_s(v_t2,   min,         v_t0);
	vbx(VVW, VCMV_GTZ, v_p, v_t2,        v_t0);
	vbx(VVW, VCMV_GTZ, v_v, v_t1,        v_t0);

	//If > max-epsilon, add wallforce*((max-epsilon)-p) into t3
	vbw_fix16_sub_s(v_t0, max-wallEpsilon, v_p);
	vbw_fix16_mul_s(v_t1, wallForce,       v_t0);
	vbx(VVW, VCMV_LTZ, v_t3, v_t1, v_t0);

	//If > max, move in max-(p-max) and reverse velocity
	vbw_fix16_sub_s(v_t0,   max,         v_p);
	vbw_fix16_mul_s(v_t1,   wallReflect, v_v);
	vbw_fix16_add_s(v_t2,   max,         v_t0);
	vbx(VVW, VCMV_LTZ, v_p, v_t2,        v_t0);
	vbx(VVW, VCMV_LTZ, v_v, v_t1,        v_t0);

	//divide t3 by size to get force, add into velocity
	vbw_fix16_mul(v_t3, v_t3, v_inv_size);
	vbw_fix16_add(v_v,  v_t3, v_v);

	//Final check because crazy high velocities can cause reflections out of bounds
	vbw_fix16_sub_s(v_t0,   min, v_p);
	vbx(SVW, VCMV_GTZ, v_p, min, v_t0);
	vbw_fix16_sub_s(v_t0,   max, v_p);
	vbx(SVW, VCMV_LTZ, v_p, max, v_t0);
}


void vector_update_force_calc(vbx_word_t *v_fx, vbx_word_t *v_fy, vbx_word_t *v_fx_tmp, vbx_word_t *v_fy_tmp, int num_particles, int hw_full, int hw_div, int hw_sqrt, int block_size, int block_num, int block_max)
{
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	int vci_lanes = this_mxp->vci_lanes;

	// by summing all forces contributed by particles i
	//set the 2D and 3D instructions, first pass using current block of data
	vbx_set_vl(num_particles);
	if(hw_full){
		vbx_set_3D((num_particles/vci_lanes)+g_full_ci_offs,
							 0,
							 vci_lanes*sizeof(vbx_word_t),
							 vci_lanes*sizeof(vbx_word_t));
		vbx_set_2D(2,
							 (v_fy-v_fx)*sizeof(vbx_word_t),
							 (particles.v_size-particles.v_Px)*sizeof(vbx_word_t),
							 (particles.v_gm-particles.v_Py)*sizeof(vbx_word_t));
	}

	int block;
	int j;
	int current = 0;
	int use_loaded_block = 0;

#define VBX_FORCE_CALC(v_x, v_y) \
	if(hw_full) { \
		vbx_set_vl(vci_lanes);\
	}\
	for(j=0; j<num_particles; j++ ) { \
		if(hw_full) { \
			vector_force_calc_full_hw( v_x, v_y, j, num_particles, use_loaded_block, current); \
		}else{ \
			vector_force_calc( v_x, v_y, j, num_particles, hw_div, hw_sqrt, use_loaded_block, current ); \
		} \
	} \
	if(hw_full) { \
		vbx_set_vl(num_particles);\
	}\

	if(!USE_BLOCK){
		VBX_FORCE_CALC( v_fx, v_fy );
	} else {
		vector_particle_block_load(&(db[!current]), &particles, num_particles, (1+0+block_num)%block_max);
		VBX_FORCE_CALC( v_fx, v_fy );
		current = !current;

		use_loaded_block = 1;
		if(hw_full){
		vbx_set_2D(2,
				 (v_fy_tmp-v_fx_tmp)*sizeof(vbx_word_t),
				 (db[!current].v_size-db[!current].v_Px)*sizeof(vbx_word_t),
				 (particles.v_gm-particles.v_Py)*sizeof(vbx_word_t));
		}

		for(block=1; block<block_max; block++){
			if(block<block_max-1){
				vector_particle_block_load(&(db[!current]), &particles, num_particles, (1+block+block_num)%block_max);
			}
			VBX_FORCE_CALC( v_fx_tmp, v_fy_tmp );
			vbx(VVW, VADD, v_fx, v_fx, v_fx_tmp);
			vbx(VVW, VADD, v_fy, v_fy, v_fy_tmp);
			current = !current;
		}
	}
}

void vector_update(int hw_full, int hw_div, int hw_sqrt, int block_size, int block_num, int block_max)
{

	int num_particles = block_size;
	int num_vectors = 6;
	vbx_sp_push();
	vbx_word_t *v_src = (vbx_word_t *)vbx_sp_malloc((num_vectors*num_particles)*sizeof(vbx_word_t));

	vbx_word_t *v_x     = v_src + 0*num_particles; //before check
	vbx_word_t *v_y     = v_src + 1*num_particles; //before check
	vbx_word_t *v_fx    = v_src + 2*num_particles; //before check
	vbx_word_t *v_fy    = v_src + 3*num_particles; //before check
	vbx_word_t *v_fx_tmp= v_src + 4*num_particles; //before check
	vbx_word_t *v_fy_tmp= v_src + 5*num_particles; //before check

	vbx_word_t *v_t_mul = v_y;
	vbx_word_t *v_check2 = v_x;

	// compute net force on each particle
	vbx_set_vl(num_particles);
	vbx(SVW, VMOV, v_fx, 0, 0 );
	vbx(SVW, VMOV, v_fy, 0, 0 );

	//vector_update_force_calc();
	vector_update_force_calc(v_fx, v_fy, v_fx_tmp, v_fy_tmp, num_particles, hw_full, hw_div, hw_sqrt, block_size, block_num, block_max);

	vbw_fix16_mul(v_t_mul, particles.v_inv_size, particles.v_inv_size);
	vbw_fix16_mul(v_t_mul, v_t_mul, particles.v_inv_size);

	vbw_fix16_mul(v_x, v_fx, v_t_mul);
	vbw_fix16_mul(v_y, v_fy, v_t_mul);

	vbw_fix16_add_s(v_fx, gravityX, v_x);
	vbw_fix16_add_s(v_fy, gravityY, v_y);
	vbw_fix16_mul_s(v_fx, dt, v_fx);
	vbw_fix16_mul_s(v_fy, dt, v_fy);

	vbw_fix16_mul_s(particles.v_Vx, frictionForce, particles.v_Vx);
	vbw_fix16_mul_s(particles.v_Vy, frictionForce, particles.v_Vy);
	vbw_fix16_add(particles.v_Vx, particles.v_Vx, v_fx);
	vbw_fix16_add(particles.v_Vy, particles.v_Vy, v_fy);

	vbw_fix16_mul_s(v_fx, dt, particles.v_Vx);
	vbw_fix16_mul_s(v_fy, dt, particles.v_Vy);

	vbw_fix16_add(particles.v_Qx, v_fx, particles.v_Px);
	vbw_fix16_add(particles.v_Qy, v_fy, particles.v_Py);

	//-----------------bounds check --------------------

#if !SKIP_BOUNDS_CHECK
	// test for out-of-bounds and wall reflections
	vector_boundsCheck2( particles.v_Qx, particles.v_Vx, particles.v_inv_size, minPx, maxPx, v_check2, num_particles );
	vector_boundsCheck2( particles.v_Qy, particles.v_Vy, particles.v_inv_size, minPy, maxPy, v_check2, num_particles );
#endif //!SKIP_BOUNDS_CHECK


#if USE_BLOCK
	vector_particle_store(&particles, num_particles, block_num);
#else
	// swap P and Q (input and output buffers)
	vbx_word_t* v_temp;

	v_temp = particles.v_Px;
	particles.v_Px = particles.v_Qx;
	particles.v_Qx = v_temp;

	v_temp = particles.v_Py;
	particles.v_Py = particles.v_Qy;
	particles.v_Qy = v_temp;
#endif

	vbx_sp_pop();

}

int vector_repulsion_demo(pixel *buffer, int gravity_x, int gravity_y, const int image_width, const int image_height)
{
	if(!_init_flag){
		particle_init(&particles, image_width, image_height);
		_init_flag++;
	}

	if(!vci_init_done){
		vector_particle_vci_init();
	}

	gravityX = gravity_x;
	gravityY = gravity_y;

	vbx_sp_push();
	int iter, i, block_max;

	if(!USE_BLOCK){
		block_max = 1;
	}else{
		block_max = 2;
	}

	int num_particles = NUM_PARTICLES/block_max;
	vector_particle_init(&particles, num_particles);

	if(!USE_BLOCK){
		vector_particle_load(&particles, num_particles, 0);
	}else{
		vector_particle_block_init_db(db, num_particles);
	}

	for(iter = 0; iter < ITERS_PER_UPDATE; iter++){
		for( i=0; i<block_max; i++){

			if(USE_BLOCK){
				vector_particle_load(&particles, num_particles, i);
			}
			//vector_update(hw_full, hw_div, hw_sqrt, num_particles, i,  block_max);
			vector_update(g_custom_divide_offs, g_custom_sqrt_offs, g_full_ci_offs, num_particles, i,  block_max);
		}

		if(USE_BLOCK){
			fxp_t* temp;
			temp = particles.Px;
			particles.Px = particles.Qx;
			particles.Qx = temp;
			temp = particles.Py;
			particles.Py = particles.Qy;
			particles.Qy = temp;
		}
	}

	if(!USE_BLOCK){
		vbx_dma_to_host( particles.Px, particles.v_Px, num_particles*sizeof(vbx_word_t));
		vbx_dma_to_host( particles.Py, particles.v_Py, num_particles*sizeof(vbx_word_t));
		vbx_dma_to_host( particles.Vx, particles.v_Vx, num_particles*sizeof(vbx_word_t));
		vbx_dma_to_host( particles.Vy, particles.v_Vy, num_particles*sizeof(vbx_word_t));
	}

	vbx_sync();
	vbx_sp_pop();

	return 0;
}

