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
VBXCOPYRIGHT( vector_haar_detect )

#include "demo.h"
#include "haar_detect.h"
#include "sqrtLUT.h"

int stage_count[22];
int prev_frame = 999;

void vector_row_to_integrals(vptr_uhalf v_luma_short, vptr_uword v_luma, vptr_uword v_luma2, vptr_uword v_prev_int, vptr_uword v_prev_sq, vptr_uword v_int, vptr_uword v_sq, int num ,int width)
{
	int i,j,index;
	int slice = 1;

	vptr_uword v_temp, v_temp2;
	v_temp  = v_int;
	v_temp2 = v_sq;

	//Move in greyscale values 
	vbx_set_vl(width*num);

	vbx(VVHWU, VMOV, v_luma, v_luma_short, 0 );
	//Create squared version of greyscale image
	vbx(VVWU, VMULLO, v_luma2, v_luma, v_luma );

	//Move first positon of luma and squared luma values into integral and square rows
	vbx_set_vl(1);
	vbx_set_2D(num*slice , sizeof(vbx_uword_t)*width/slice, sizeof(vbx_uword_t)*width/slice, sizeof(vbx_uword_t)*width/slice); 
	vbx_2D(VVWU, VMOV, v_int, v_luma , 0 );
	vbx_2D(VVWU, VMOV, v_sq, v_luma2 , 0 );

	//Split rows up to make for longer 2D op
	for( i=0; i<width/slice-1; i++){
		vbx_set_vl(1);
		vbx_set_2D(num*slice , sizeof(vbx_uword_t)*width/slice, sizeof(vbx_uword_t)*width/slice, sizeof(vbx_uword_t)*width/slice); 
		vbx_2D(VVWU, VADD, v_int+i+1, v_int+i,  v_luma+i+1 );
		vbx_2D(VVWU, VADD,  v_sq+i+1,  v_sq+i, v_luma2+i+1 );
	}
	
	//Combine the previous split rows to get summed row primitives
	for(i=1;i<slice;i++){
		for(j=0;j<num;j++){
			index = width*j + width*i/slice;
			vbx_sync();
			vbx_set_vl(width/slice);
			vbx(SVWU, VADD, v_int+index, v_int[index-1], v_int+index );
			vbx(SVWU, VADD, v_sq+index, v_sq[index-1], v_sq+index );
		}
	}

	//Add row primitives to compose integral image, save last row for next batch
	vbx_set_vl(width);
	vbx(VVWU, VADD, v_int, v_int, v_prev_int );
	vbx(VVWU, VADD, v_sq, v_sq, v_prev_sq );
	for(i=1;i<num;i++){
		vbx(VVWU, VADD, v_int+width*i, v_int+width*i, v_int+width*(i-1) );
		vbx(VVWU, VADD, v_sq+width*i, v_sq+width*i, v_sq+width*(i-1) );
	}
	vbx(VVWU, VMOV, v_prev_int, v_int+width*(num-1), 0 );
	vbx(VVWU, VMOV, v_prev_sq,  v_sq +width*(num-1), 0 );
}

void vector_gen_integrals(short *input, int *integral, int *squared, int width, int height, short window)
{
	vptr_uword v_prev, v_prev2, v_int, v_in, v_in2, v_sq;
	int num_rows = 3200/width;
	if (num_rows > (window+1)) num_rows=(window+1);
	num_rows=1;

	vptr_uhalf v_short = (vptr_uhalf)vbx_sp_malloc(num_rows*width*sizeof(vbx_uhalf_t));
	v_in    = (vptr_uword)vbx_sp_malloc(num_rows*width*sizeof(vbx_uword_t));
	v_in2   = (vptr_uword)vbx_sp_malloc(num_rows*width*sizeof(vbx_uword_t));
	v_int   = (vptr_uword)vbx_sp_malloc(num_rows*width*sizeof(vbx_uword_t));
	v_sq    = (vptr_uword)vbx_sp_malloc(num_rows*width*sizeof(vbx_uword_t));
	v_prev  = (vptr_uword)vbx_sp_malloc(       1*width*sizeof(vbx_uword_t));
	v_prev2 = (vptr_uword)vbx_sp_malloc(       1*width*sizeof(vbx_uword_t));

	if(v_prev==NULL || v_prev2==NULL || v_in2==NULL || v_in==NULL || v_int==NULL || v_sq==NULL){
		printf("Scratchpad not large enough; need to partition test\n");
		exit(-1);
	}

	vbx_set_vl(width);
	vbx(SVWU, VMOV, v_prev, 0, 0 );
	vbx(SVWU, VMOV, v_prev2, 0, 0 );

	int y;
	for(y = 0; y < height-num_rows; y=y+num_rows){

	  vbx_dma_to_vector(v_short, input+y*width, num_rows*width*sizeof(vbx_uhalf_t));
	  vector_row_to_integrals( v_short, v_in, v_in2, v_prev, v_prev2, v_int, v_sq, num_rows, width);
	 	  vbx_dma_to_host(  integral+y*width, v_int, num_rows*width*sizeof(vbx_uword_t));
		  vbx_dma_to_host(  squared+y*width,  v_sq,  num_rows*width*sizeof(vbx_uword_t));
	}
	vbx_sync();
	vbx_sp_free();
}

void vector_row_haar_2D( vptr_word v_int, vptr_word v_tmp, int win, int width, int vector_2D, int* row_var, int* row_pass, stage *cascade, short max_stage)
{
	rect *prect1;
	rect *prect2;
	rect *prect3;
	int stage, i, v, var; 
	int inv = fix16_from_float(1.0/(win*win));
	int accumulated; 


	vptr_word v_sq_0, v_sq_end, v_out, v_var2, v_thr, v_feat, v_add, v_stage, v_pass, v_final,v_accum;
	vptr_half v_a, v_b, v_c, v_d, v_e, v_f;
	vptr_word v_aw, v_bw, v_cw, v_dw;
	v_sq_0  = v_tmp +0*width*vector_2D;  //Holds first row of squared integral image 
	v_sq_end= v_tmp +1*width*vector_2D;  //Holds last row of squared integral image 
	v_out   = v_tmp +2*width*vector_2D;  //Holds values to be DMAed out (var & pass)
	v_var2  = v_tmp +3*width*vector_2D;  //Holds variance*win^2
	v_thr   = v_tmp +4*width*vector_2D;  //Holds variance*win^2*feature threshold 
	v_feat  = v_tmp +5*width*vector_2D;  //Holds sum of rectangles in feature
	v_add   = v_tmp +6*width*vector_2D;  //Holds pass or fail values to be added to stage sum
	v_stage = v_tmp +7*width*vector_2D;  //Holds sum of features in a stages
	v_pass  = v_tmp +8*width*vector_2D;  //Holds binary values if passed current stage
	v_final = v_tmp +9*width*vector_2D;  //Holds binary value if passed all stages
	v_accum = v_tmp +10*width*vector_2D; //Holds accumulated binary values if stages have been passed, used to exit early
	v_a = (vptr_half)(v_tmp +11*width*vector_2D); //Temporary registers 11-24
	v_b = (vptr_half)(v_tmp +12*width*vector_2D); 
	v_c = (vptr_half)(v_tmp +13*width*vector_2D); 
	v_d = (vptr_half)(v_tmp +14*width*vector_2D); 
	v_e = (vptr_half)(v_tmp +15*width*vector_2D); 
	v_f = (vptr_half)(v_tmp +16*width*vector_2D); 
	v_aw = (vptr_word)v_a;
	v_bw = (vptr_word)v_b;
	v_cw = (vptr_word)v_c;
	v_dw = (vptr_word)v_d;

	short vector = width-win;
	vbx_set_vl(vector);
	vbx_set_2D(vector_2D, width*sizeof(vbx_word_t), width*sizeof(vbx_word_t), width*sizeof(vbx_word_t)); 
	//Zero components
	vbx_2D(SVW, VMOV,   v_out,  0, 0);
	vbx_2D(SVW, VMOV,   v_final, 1, 0);

	vbx_2D(SVW, VMOV,   v_var2, 0, 0);
	vbx_2D(SVW, VMOV,   v_add, 0, 0);
	
	//Compute Variance
	vbx_2D(VVW, VSUB,   v_aw, v_int+win,  v_int );// b-a
	vbx_2D(VVW, VSUB,   v_bw, v_int+win*width+win, v_int+win*width);// c-d
	vbx_2D(VVW, VSUB,   v_bw, v_bw,     v_aw ); //c-d-b+a

	vbx_2D(SVW, VMULFXP,   v_bw, inv,  v_bw );
	
	vbx_2D(VVW, VMULLO, v_bw, v_bw,     v_bw );//mean squared

	vbx_2D(VVW, VSUB,   v_cw, v_sq_0+win,    v_sq_0   );
	vbx_2D(VVW, VSUB,   v_dw, v_sq_end+win,   v_sq_end  );
	vbx_2D(VVW, VSUB,   v_dw, v_dw,     v_cw );

	vbx_2D(SVW, VMULFXP,   v_dw, inv,  v_dw );

	vbx_2D(VVW, VSUB  , v_dw, v_dw,      v_bw ); //var-mean^2
	

	//Send variance out to row_var 

#if 1
	//var2 < 6000 var > 0
	vbx_2D(SVW, VSUB,     v_cw, 6000,   v_dw ); 
	vbx_2D(SVW, VCMV_LEZ, v_dw, 5999,   v_cw ); 
	vbx_2D(SVW, VCMV_LEZ, v_dw, 0,   v_dw ); 
#endif

	vbx_sync();
#if defined(SYSTEM_ZEDBOARD) || defined(SYSTEM_ZEDBOARD_IMAGEON)
	// On Zynq, can't cache scratchpad accesses without modifying the default
	// MMU translation table; also can't support bursts with AXI4-Lite
	// interface.
	vbx_word_t *v_tmp_cached = v_dw;
	vbx_word_t *v_var_cached = v_var2;
#else
	vbx_word_t *v_tmp_cached = vbx_remap_cached(v_dw, width*vector_2D*sizeof(vbx_word_t));
	vbx_word_t *v_var_cached = vbx_remap_cached(v_var2,    width*vector_2D*sizeof(vbx_word_t));
#endif
	for(v=0;v<(vector_2D);v++){
		for(i=0;i<(vector);i++){
			var = (v_tmp_cached[v*width +i]);
#if 1
			v_var_cached[v*width +i] = sqrtLUT[var];
#else
			if (var < 6000 && var > 0){
				v_var_cached[v*width +i] = sqrtLUT[var];
			}else{
				v_var_cached[v*width +i] = 78;
			}
#endif
		}
	}
#if !(defined(SYSTEM_ZEDBOARD) || defined(SYSTEM_ZEDBOARD_IMAGEON))
	vbx_dcache_flush((void *)v_tmp_cached, width*vector_2D*sizeof(vbx_word_t));
	vbx_dcache_flush((void *)v_var_cached, width*vector_2D*sizeof(vbx_word_t));
#endif
	//Multiply var by win*win, used for feature thresholding
	vbx_2D(SVW, VMULLO,  v_var2, win*win, v_var2 );
		
	//Run through stages
	//FIXME here we must split vector up
	//break into sections of 16
		for(stage=0; stage < max_stage; stage++){
			
			//Zero out temporary binary stage pass
			vbx_2D(SVW, VMOV,     v_pass,         0,             0 );
			//Zero out stage sumation
			vbx_2D(SVW, VMOV,     v_stage,        0,             0 );

			short *pthresh = cascade[stage].thresh;
			short *pfail   = cascade[stage].fail;
			short *ppass   = cascade[stage].pass;

			for(i=0; i< cascade[stage].size; i++){
				//get features threshold value
				vbx_2D(SVW, VMULLO,   v_thr,  (int)*pthresh++,  v_var2  );
				//Initalize values to be added to default fail value
				vbx_2D(SVW, VMOV,     v_add,  (int)*pfail++,           0);
				//Initalize the sum of the feature to be 0, before adding rectangles
				vbx_2D(SVW, VMOV,     v_feat, 0,                    0);

				const unsigned char endj= cascade[stage].num[i];
				const short idx = cascade[stage].start[i];
				prect1        = &cascade[stage].rects[ idx ];
				prect2        = &cascade[stage].rects[ idx+1 ];
				prect3        = &cascade[stage].rects[ idx+2 ];

				if( endj == 2 ) {
#if 0
					const vbx_word_t *v_a1 = v_int +width*prect1->y + prect1->x;
					const vbx_word_t *v_b1 = v_int +width*prect1->y + prect1->w;
					const vbx_word_t *v_d1 = v_int +width*prect1->h + prect1->x;
					const vbx_word_t *v_c1 = v_int +width*prect1->h + prect1->w;
					const vbx_word_t *v_a2 = v_int +width*prect2->y + prect2->x;
					const vbx_word_t *v_b2 = v_int +width*prect2->y + prect2->w;
					const vbx_word_t *v_d2 = v_int +width*prect2->h + prect2->x;
					const vbx_word_t *v_c2 = v_int +width*prect2->h + prect2->w;
#else
					vbx_word_t *v_a1 = v_int +width*prect1->y + prect1->x;
					vbx_word_t *v_b1 = v_int +width*prect1->y + prect1->w;
					vbx_word_t *v_d1 = v_int +width*prect1->h + prect1->x;
					vbx_word_t *v_c1 = v_int +width*prect1->h + prect1->w;
					vbx_word_t *v_a2 = v_int +width*prect2->y + prect2->x;
					vbx_word_t *v_b2 = v_int +width*prect2->y + prect2->w;
					vbx_word_t *v_d2 = v_int +width*prect2->h + prect2->x;
					vbx_word_t *v_c2 = v_int +width*prect2->h + prect2->w;
#endif

					vbx_2D(VVWH, VSUB,   v_a, v_b1, v_a1);// b-a
					vbx_2D(VVWH, VSUB,   v_c, v_b2, v_a2);// b-a
					vbx_2D(VVWH, VSUB,   v_b, v_c1, v_d1);// c-d
					vbx_2D(VVWH, VSUB,   v_d, v_c2, v_d2);// c-d

					vbx_2D(VVH, VSUB,    v_b, v_b,           v_a ); //c-d-b+a
					vbx_2D(VVH, VSUB,    v_d, v_d,           v_c ); //c-d-b+a
					vbx_2D(SVH, VMULLO,  v_a, (int)prect1->value,  v_b ); //total * feature weight
					vbx_2D(SVH, VMULLO,  v_c, (int)prect2->value,  v_d ); //total * feature weight
					vbx_2D(VVHW, VADD,   (vptr_word)v_d,    v_c,             v_a ); //add to feature total
					vbx_2D(VVW,  VADD,   v_feat, v_feat,          (vptr_word)v_d ); //add to feature total

				}
				if( endj == 3 ) {
#if 0
					const vbx_word_t *v_a1 = v_int +width*prect1->y + prect1->x;
					const vbx_word_t *v_b1 = v_int +width*prect1->y + prect1->w;
					const vbx_word_t *v_d1 = v_int +width*prect1->h + prect1->x;
					const vbx_word_t *v_c1 = v_int +width*prect1->h + prect1->w;
					const vbx_word_t *v_a2 = v_int +width*prect2->y + prect2->x;
					const vbx_word_t *v_b2 = v_int +width*prect2->y + prect2->w;
					const vbx_word_t *v_d2 = v_int +width*prect2->h + prect2->x;
					const vbx_word_t *v_c2 = v_int +width*prect2->h + prect2->w;
					const vbx_word_t *v_a3 = v_int +width*prect3->y + prect3->x;
					const vbx_word_t *v_b3 = v_int +width*prect3->y + prect3->w;
					const vbx_word_t *v_d3 = v_int +width*prect3->h + prect3->x;
					const vbx_word_t *v_c3 = v_int +width*prect3->h + prect3->w;
#else
					vbx_word_t *v_a1 = v_int +width*prect1->y + prect1->x;
					vbx_word_t *v_b1 = v_int +width*prect1->y + prect1->w;
					vbx_word_t *v_d1 = v_int +width*prect1->h + prect1->x;
					vbx_word_t *v_c1 = v_int +width*prect1->h + prect1->w;
					vbx_word_t *v_a2 = v_int +width*prect2->y + prect2->x;
					vbx_word_t *v_b2 = v_int +width*prect2->y + prect2->w;
					vbx_word_t *v_d2 = v_int +width*prect2->h + prect2->x;
					vbx_word_t *v_c2 = v_int +width*prect2->h + prect2->w;
					vbx_word_t *v_a3 = v_int +width*prect3->y + prect3->x;
					vbx_word_t *v_b3 = v_int +width*prect3->y + prect3->w;
					vbx_word_t *v_d3 = v_int +width*prect3->h + prect3->x;
					vbx_word_t *v_c3 = v_int +width*prect3->h + prect3->w;
#endif

					vbx_2D(VVWH, VSUB,    v_a, v_b1, v_a1);// b-a
					vbx_2D(VVWH, VSUB,    v_c, v_b2, v_a2);// b-a
					vbx_2D(VVWH, VSUB,    v_e, v_b3, v_a3);// b-a
					vbx_2D(VVWH, VSUB,    v_b, v_c1, v_d1);// c-d
					vbx_2D(VVWH, VSUB,    v_d, v_c2, v_d2);// c-d
					vbx_2D(VVWH, VSUB,    v_f, v_c3, v_d3);// c-d

					vbx_2D(VVH,  VSUB,    v_b, v_b,          v_a ); //c-d-b+a
					vbx_2D(VVH,  VSUB,    v_d, v_d,          v_c ); //c-d-b+a
					vbx_2D(VVH,  VSUB,    v_f, v_f,          v_e ); //c-d-b+a
					vbx_2D(SVH,  VMULLO,  v_a, (int)prect1->value, v_b ); //total * feature weight
					vbx_2D(SVH,  VMULLO,  v_c, (int)prect2->value, v_d ); //total * feature weight
					vbx_2D(SVH,  VMULLO,  v_e, (int)prect3->value, v_f ); //total * feature weight
					vbx_2D(VVH,  VADD,    v_d, v_a,          v_c ); //add to feature total
					vbx_2D(VVHW, VADD,    (vptr_word)v_f, v_e,          v_d ); //add to feature total
					vbx_2D(VVW,  VADD,    v_feat,  v_feat,   (vptr_word)v_f ); //add to feature total
				}

				//if feature is greater than threshold, switch add from default fail to pass values
				vbx_2D(SVW, VSHL,     v_feat,    12,         v_feat );
				vbx_2D(VVW, VSUB,     v_thr,    v_thr,       v_feat );
				vbx_2D(SVW, VCMV_GTZ, v_add, (int)*ppass++,   v_thr  );
				//add either pass or fail sum to running stage total
				vbx_2D(VVW, VADD,     v_stage,  v_stage,    v_add   );
			}

			//final stage result
			vbx_2D(SVW, VSUB,     v_stage, cascade[stage].value,       v_stage );
			vbx_2D(SVW, VCMV_LEZ, v_pass,         1,       v_stage );
			vbx_2D(SVW, VCMV_LEZ, v_final, 0, v_pass);

			//Exit early if entire group of rows has failed
			vbx_acc_2D( VVWU, VMOV, (vptr_uword)v_accum, (vptr_uword)v_final, 0);
			vbx_sync();
			accumulated = 0;
			for(i=0;i<vector_2D;i++){
				accumulated  = accumulated + v_accum[i*width];
			}
#if DEBUG
				if(! accumulated ){
					stage_count[stage] = stage_count[stage]+1;
					break;
				}else if (stage == max_stage-1){
					stage_count[stage] = stage_count[stage]+1;
				}
#else
				if(! accumulated ) break;
#endif
		}
		//Send out if stage passed to row_pass
		vbx_dma_to_host( row_pass, v_final , (width*vector_2D)*sizeof(vbx_word_t));
		vbx_sync();
}

void vector_get_img(short *idest, pixel *isrc, short bin, const int image_width, const int image_height, const int image_pitch)
{
	
	vptr_uword v_next, v_in, v_reduced;
	vptr_uhalf v_temp, v_out, v_luma;
	vptr_uword v_tmp_word;
	vptr_uhalf v_tmp_half;
	v_in       = (vptr_uword)vbx_sp_malloc(image_width*sizeof(vbx_uword_t));
	v_next     = (vptr_uword)vbx_sp_malloc(image_width*sizeof(vbx_uword_t));
	v_reduced  = (vptr_uword)vbx_sp_malloc(image_width/bin*sizeof(vbx_uword_t));
	v_temp     = (vptr_uhalf)vbx_sp_malloc(image_width/bin*sizeof(vbx_uhalf_t));
	v_luma     = (vptr_uhalf)vbx_sp_malloc(image_width/bin*sizeof(vbx_uhalf_t));
	v_out      = (vptr_uhalf)vbx_sp_malloc(image_width/bin*sizeof(vbx_uhalf_t));
	if (v_out == NULL) exit( -1);

	vbx_dma_to_vector(v_next, isrc+image_pitch, image_width*sizeof(vbx_uword_t));

	int y;
	for(y = 0; y < image_height/bin; y++){
	  // transfer in row of camera input
	  SWAP(v_next, v_in, v_tmp_word);
	  vbx_dma_to_vector(v_next, isrc+( bin*(y+1))*image_pitch, image_width*sizeof(vbx_uword_t));

	  // bin image: for IMAGE_WIDTH / bin times, transfer a pixel, move over bin pixels
	  vbx_set_vl(1);
	  vbx_set_2D(image_width/bin, sizeof(vbx_uword_t), bin*sizeof(vbx_uword_t),0);
	  vbx_2D(VVWU, VMOV, v_reduced, v_in, 0);

	  vbx_set_vl(image_width/bin);

		//Move the b component into v_luma
		vbx(SVWHU, VAND, v_temp, 0xFF,   v_reduced);
		vbx(SVHU,  VMUL, v_luma, 25,     v_temp);

		//Move g into v_temp and add it to v_luma
		vbx(SVWHU, VAND, v_temp, 0xFF,   (vptr_uword)(((vptr_ubyte)v_reduced)+1));
		vbx(SVHU,  VMUL, v_temp, 129,    v_temp);
		vbx(VVHU,  VADD, v_luma, v_luma, v_temp);

		//Move r into v_temp and add it to v_luma
		vbx(SVWHU, VAND, v_temp, 0xFF,   (vptr_uword)(((vptr_ubyte)v_reduced)+2));
		vbx(SVHU,  VMUL, v_temp, 66,     v_temp);
		vbx(VVHU,  VADD, v_luma, v_luma, v_temp);

		vbx(SVHU,  VSHR, v_luma, 8,      v_luma);

	  // transfer binned image out
	  SWAP(v_out, v_luma, v_tmp_half);
	  vbx_dma_to_host(idest+y*image_width/bin, v_out, image_width/bin*sizeof(vbx_uhalf_t));
	}

	vbx_sync();
	vbx_sp_free();
}

void vector_BLIP(short* img, short height, short width, short* scaled_img, short scaled_height, short scaled_width, short value)
{
	int y, i, scale, y_scaled;
	
	vptr_uhalf v_x =      (vptr_uhalf)vbx_sp_malloc((value+1)*width*sizeof(vbx_uhalf_t));
	vptr_uhalf v_x_next = (vptr_uhalf)vbx_sp_malloc((value+1)*width*sizeof(vbx_uhalf_t));
	vptr_uhalf v_out =    (vptr_uhalf)vbx_sp_malloc(scaled_width*sizeof(vbx_uhalf_t));
	vptr_uhalf v_out_next =    (vptr_uhalf)vbx_sp_malloc(scaled_width*sizeof(vbx_uhalf_t));
	vptr_uhalf v_x0, v_x1, v_temp;


	vptr_uhalf v_coeff_a = (vptr_uhalf)vbx_sp_malloc(value         *sizeof(vbx_uhalf_t));
	vptr_uhalf v_coeff_b = (vptr_uhalf)vbx_sp_malloc(value         *sizeof(vbx_uhalf_t));

	vptr_uword v_a = (vptr_uword)vbx_sp_malloc(scaled_width*sizeof(vbx_uword_t));
	vptr_uword v_b = (vptr_uword)vbx_sp_malloc(scaled_width*sizeof(vbx_uword_t));
	vptr_uword v_c = (vptr_uword)vbx_sp_malloc(scaled_width*sizeof(vbx_uword_t));
	vptr_uword v_d = (vptr_uword)vbx_sp_malloc(scaled_width*sizeof(vbx_uword_t));

	if (v_c==NULL || v_d == NULL) printf("In vector_BLIP : not enought space in scratch!\n");
	
	//scale = 64;
	scale = 128;
	for(i=0;i<value;i++){
		v_coeff_a[i]=scale-i*scale/value;
		v_coeff_b[i]=i*scale/value;
	}
	y_scaled=0;
	vbx_dma_to_vector(v_x_next, img,  (value+1)*width*sizeof(vbx_uhalf_t));
	for(y=0;y<height-1;y++){
		if(y%(value+1) == 0){
			SWAP(v_x_next,v_x, v_temp);
			vbx_dma_to_vector(v_x_next, img+width*(y+(value+1)),     (value+1)*width*sizeof(vbx_uhalf_t));
		}
		if(y%(value+1) != value){
			v_x0 = v_x + width*(y%(value+1));
			v_x1 = v_x0 + width;

			vbx_set_vl(value);
			vbx_set_2D(width/(value+1), value*sizeof(vbx_uword_t), (value+1)*sizeof(vbx_uhalf_t), 0);
			vbx_2D(VVHWU, VMULLO, v_a,   v_x0,    v_coeff_a); //*scaled
			vbx_2D(VVHWU, VMULLO, v_b,   v_x0+1,  v_coeff_b);
			vbx_2D(VVHWU, VMULLO, v_c,   v_x1,    v_coeff_a);
			vbx_2D(VVHWU, VMULLO, v_d,   v_x1+1,  v_coeff_b);


			vbx_set_vl(scaled_width);
			vbx(VVWU, VADD,   v_a,   v_a,   v_b);
			vbx(VVWU, VADD,   v_c,   v_c,   v_d);

			vbx(SVWU,  VMULLO, v_a,   scale-(y%(value+1))*scale/value, v_a); //*scaled
			vbx(SVWU,  VMULLO, v_c,   (y%(value+1))*scale/value, v_c);
			vbx(VVWU,  VADD,   v_a,   v_a,     v_c);
			//vbx(SVWU,  VSHR,   v_a,   12,      v_a); //scale == 64 == 2^6, multiplied scaled numbers, need to shift back 12
			vbx(SVWU,  VSHR,   v_a,   14,      v_a); //scale == 64 == 2^6, multiplied scaled numbers, need to shift back 12
			vbx(VVWHU, VMOV,   v_out, v_a,      0); 

			SWAP(v_out_next, v_out, v_temp);
			vbx_dma_to_host(scaled_img+scaled_width*y_scaled, v_out_next, scaled_width*sizeof(vbx_uhalf_t));
			y_scaled++;
		}
	}
	vbx_sync();
	vbx_sp_free();
}

feat* vector_get_haar_features_image_scaling_2D( stage *cascade, short* img, feat* features, int min_scale, int scale_inc, short reduce, short width , short height, short window, short max_stage)
{
	int x, y, v;
	int sx, sy, sw;
	int x_max, y_max;

	short orig_width, orig_height;
	short *tmp;

	int* iImg = (int*)vbx_shared_malloc(width*height*sizeof(int));
	int* iiImg = (int*)vbx_shared_malloc(width*height*sizeof(int));
	short* rimg = (short*)vbx_shared_malloc( width * height * sizeof(short) );

	int ystep = Y_STEP;
	int vector_2D = VECTOR_2D;
	int* row_variance = (int*)vbx_shared_malloc(width*vector_2D*sizeof(int));
	int* row_pass =     (int*)vbx_shared_malloc(width*vector_2D*sizeof(int));
	
	if(row_pass == NULL){
		printf("Error allocating integral images!\n");
		return NULL;
	}

	vptr_uword v_integral, v_temp;

	float scaled =1.0;
	while( width >= window +4 && height >= window +1 +vector_2D){
		x_max = width-window;
		y_max = height-(window +1 +(vector_2D-1)*ystep);

		if(scaled*1000*reduce >= min_scale){

			vector_gen_integrals(img, iImg, iiImg, width, height, window); 
			v_integral = (vptr_uword)vbx_sp_malloc((window +1 +(vector_2D-1)*ystep)*width*sizeof(vbx_uword_t));
			v_temp     = (vptr_uword)vbx_sp_malloc(24*vector_2D*width*sizeof(vbx_uword_t));
			if (v_temp==NULL || v_integral == NULL) printf("In getHaarVector : not enought space in scratch!\n");

			//initiate row
			// total required = window + vector_2D*ystep
			// every loop bring in vector_2D*ystep
			vbx_dma_to_vector(v_integral +vector_2D*ystep*width, iImg, (window +1 -ystep)*width*sizeof(vbx_uword_t));

			for(y=0; y<y_max; y=y+vector_2D*ystep){
				//move all rows to take on the value of rows'ystep' above ie 0->1 1->2 ..
				vbx_set_vl( (window +1 -ystep)*width ); //everything but first row shifts up
				vbx(VVW, VMOV, (vptr_word)v_integral, (vptr_word)v_integral +vector_2D*ystep*width, 0 );
				vbx_dma_to_vector(v_integral +(window +1 -ystep)*width,  iImg+(y+(window +1 -ystep))*width, vector_2D*ystep*width*sizeof(vbx_uword_t));

				//bring in top and bottom rows of squared integral, required for calculating the variance
				vbx_dma_to_vector(v_temp+0*width*vector_2D,     iiImg +(y+     0)*width, width*vector_2D*sizeof(vbx_uword_t));
				vbx_dma_to_vector(v_temp+1+width*vector_2D,     iiImg +(y+window)*width, width*vector_2D*sizeof(vbx_uword_t));
				
				vector_row_haar_2D((vbx_word_t*)v_integral, (vbx_word_t*)v_temp, window, width, vector_2D, row_variance, row_pass, cascade, max_stage); 

				for(v=0; v<vector_2D; v++){
					for(x=0; x<x_max; x++){
						if( row_pass[x+ v*width] ){
							sx = (int)(scaled*reduce*x);
							sy = (int)(scaled*reduce*(y +v*ystep));
							sw = (int)(scaled*reduce*window);
							features = append_feature(features, sx, sy, sw);
						}
					}
				}

			}
			vbx_sync();
			vbx_sp_free();
		}
		//reduce image
		SWAP(img,rimg,tmp);
		orig_width = width; 
		orig_height = height;
		short f;
		if(scale_inc == 2000){
			f=1;
		}else if(scale_inc == 1500){
			f=2;
		}else if(scale_inc == 1333){
			f=3;
		}else if(scale_inc == 1250){
			f=4;
		}else if(scale_inc == 1200){
			f=5;
		}else if(scale_inc == 1125){
			f=8;
		}else if(scale_inc == 1100){
			f=10;
		}else{
			printf("Not a valid scaling factor!\n");
			exit(-1);
		}

		width = width*f/(f+1);
		//printf("width %d\n", width);
		height= height*f/(f+1);
		if (height>=window && width >=window){
            vector_BLIP(rimg, orig_height, orig_width, img, height, width, f);
        }
		//increase scaled
		scaled = scaled*scale_inc/1000;
	}

	//vbx_shared_free(reduced_input);
	vbx_shared_free(iImg);
	vbx_shared_free(iiImg);
	vbx_shared_free(rimg);
	vbx_shared_free(img);
	vbx_shared_free(row_variance);
	vbx_shared_free(row_pass);

	return features;
}	

int vector_face_detect(pixel *input, const int image_width, const int image_height, const int image_pitch)
{

#if DEBUG
	{
		int i;
		for(i=0; i<22; i++){
			stage_count[i]=0;
		}
	}
#endif

	pixel *color =(pixel*)malloc(sizeof(pixel));
	feat* features = NULL; 
	feat* merged = NULL; 

	short* img =(short*)vbx_shared_malloc( image_width/BIN * image_height/BIN * sizeof(short) ); //freed in vector_get_haar_features_image_scaling_2D

	vector_get_img( img, input, BIN, image_width, image_height, image_pitch);

	features = vector_get_haar_features_image_scaling_2D(face_alt, img, features, INITIAL_ZOOM, SCALE_FACTOR, BIN, image_width/BIN, image_height/BIN, 20, 22);
	//features = vector_get_haar_features_image_scaling_2D(eye, img, features, INITIAL_ZOOM, SCALE_FACTOR, BIN, IMAGE_WIDTH/BIN, IMAGE_HEIGHT/BIN, 40, 20);

	merged = merge_features( features, merged);

	if(merged != NULL){
	  color->r = 0;color->b = 0;color->g = 255;
	  draw_features( merged , color, input, image_width, image_height, image_pitch);

	  free_features( features );
	  free_features( merged );
	}else if(features != NULL){

#if DEBUG
	  color->r = 0;color->b = 0;color->g = 75;
	//  draw_features( features , color, input, image_width, image_height, image_pitch);
#endif
	  free_features( features );

	}

	free(color);

#if DEBUG
	{
		int i;
		int total = 0;
		int running_total=0;

		for(i=0; i<22; i++){
			total = total + stage_count[i];
		}
		for(i=0; i<22; i++){
			running_total = running_total + stage_count[i];
			printf("%2.1f\t",100.0*running_total/total);
		}
		printf("\n");
	}
#endif

	return 0;
}
