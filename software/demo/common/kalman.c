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
VBXCOPYRIGHT( kalman )

#include "demo.h"
#include <stdio.h>

feat_kalman kal_X;
feat_kalman kal_X2;
float kal_P[6][6]= { {1000., 0, 0, 0, 0, 0},
					 {0, 1000., 0, 0, 0, 0},
					 {0, 0, 1000., 0, 0, 0},
					 {0, 0, 0, 1000., 0, 0},
					 {0, 0, 0, 0, 1000., 0},
					 {0, 0, 0, 0, 0, 1000.}};

float kal_P2[6][6]= { {1000., 0, 0, 0, 0, 0},
					  {0, 1000., 0, 0, 0, 0},
					  {0, 0, 1000., 0, 0, 0},
					  {0, 0, 0, 1000., 0, 0},
					  {0, 0, 0, 0, 1000., 0},
					  {0, 0, 0, 0, 0, 1000.}};

void draw_largest_kalman(feat *merged, pixel *color, pixel *output)
{
	feat* current;
	feat* max;
	int max_width = -1;

	if (merged == NULL)return;

	current = merged;
	max = current;

	while( current->next != NULL){
		if( current->w > max_width) {
			max_width = current->w;
			max = current;
		}
		current = current->next;
	}

	feat_kalman kal_feat;
	kalman_filter(max, &kal_feat, 0);
	draw_square(kal_feat.x, kal_feat.y, kal_feat.z, kal_feat.z, color, output);
}

void draw_previous_kalman(pixel *color, pixel *output)
{
	draw_square(kal_X.x, kal_X.y, kal_X.z, kal_X.z, color, output);
}

void reset_kalman(feat_kalman *kalman, int num)
{
	kalman->dx = 0;
	kalman->dy = 0;
	kalman->dz = 0;

	kalman->x = 0;
	kalman->y = 0;
	kalman->z = 0;

	float (*pkal_P)[6][6];
	if (!num){
		pkal_P = &kal_P;
	} else {
		pkal_P = &kal_P2;
	}

	int i,j;
	for(j=0;j<6;j++){
		for(i=0;i<6;i++){
			if(i==j) (*pkal_P)[j][i] = 1000.;
			else (*pkal_P)[j][i] = 0;
		}
	}
}

void kalman_filter( feat *measured, feat_kalman *kalman, int num )
{
	float s11, s22, s33;
	float kx, ky, kz, kdx, kdy, kdz;

	feat_kalman *pkal_X;
	float (*pkal_P)[6][6];
	if (!num) {
		pkal_X = kalman;
		pkal_P = &kal_P;
	} else {
		pkal_X = kalman;
		pkal_P = &kal_P2;
	}

	//bigger R -> more measurement error
	//bigger Q -> more prediction error
	// small Q + big R -> rely on prediction, more smooth
	// big Q + small R -> rely on measurement, less lag
	float Rx = 0.1;
	float Ry = 0.1;
	float Rz = 1.0;
	float Qx = 1.0;
	float Qy = 1.0;
	float Qz = 0.1;

	/* prediction
	 * x = (F * x) + u
	 * P = F * P * F.transpose() + Q
	 */

#if 0
	// x = (F * x) + u
	kal_X.x = kal_X.x + kal_X.dx;
	kal_X.y = kal_X.y + kal_X.dy;
	kal_X.z = kal_X.z + kal_X.dz;

	// P = F * P * F.transpose()
	// add quadrant 1 to quadrant 0
	kal_P[0][0] = kal_P[0][0] + kal_P[0][3];
	kal_P[1][1] = kal_P[1][1] + kal_P[1][4];
	kal_P[2][2] = kal_P[2][2] + kal_P[2][5];
	kal_P[3][0] = kal_P[3][0] + kal_P[3][3];
	kal_P[4][1] = kal_P[4][1] + kal_P[4][4];
	kal_P[5][2] = kal_P[5][2] + kal_P[5][5];

	// add bottom quadrants to top quadrants
	kal_P[0][0] = kal_P[0][0] + kal_P[3][0];
	kal_P[1][1] = kal_P[1][1] + kal_P[4][1];
	kal_P[2][2] = kal_P[2][2] + kal_P[5][2];
	kal_P[0][3] = kal_P[0][3] + kal_P[3][3];
	kal_P[1][4] = kal_P[1][4] + kal_P[4][4];
	kal_P[2][5] = kal_P[2][5] + kal_P[5][5];

	kal_P[0][0] = kal_P[0][0] + Qx;
	kal_P[1][1] = kal_P[1][1] + Qy;
	kal_P[2][2] = kal_P[2][2] + Qz;
	kal_P[3][3] = kal_P[3][3] + Qx*Qx;
	kal_P[4][4] = kal_P[4][4] + Qy*Qy;
	kal_P[5][5] = kal_P[5][5] + Qz*Qz;


	/*
	 * update step
	 *
	 * Z = measured.T
	 * y = Z - (H * x)
	 * S = H * P * H.T + R
	 * K = P * H.T * S.I
	 * x = x + (K * y)
	 * P = (I - (K * H)) * P
	 *
	 */

	// y = Z - (H * x)
	feat_kalman Y;
	Y.x = measured->x - kal_X.x;
	Y.y = measured->y - kal_X.y;
	Y.z = measured->w - kal_X.z;

	// S = H * P * H.T + R

	s11 = kal_P[0][0] + Rx;
	s22 = kal_P[1][1] + Ry;
	s33 = kal_P[2][2] + Rz;

	// K = P * H.T * S.I
	kx  = kal_P[0][0] / s11;
	ky  = kal_P[1][1] / s22;
	kz  = kal_P[2][2] / s33;
	kdx = kal_P[0][3] / s11;
	kdy = kal_P[1][4] / s22;
	kdz = kal_P[2][5] / s33;

	// x = x + (K * y)
	kal_X.x  = kal_X.x  + kx * Y.x;
	kal_X.y  = kal_X.y  + ky * Y.y;
	kal_X.z  = kal_X.z  + kz * Y.z;
	kal_X.dx = kal_X.dx + kdx * Y.x;
	kal_X.dy = kal_X.dy + kdy * Y.y;
	kal_X.dz = kal_X.dz + kdz * Y.z;

	// P = (I - (K * H)) * P
	kal_P[3][3] = ( (0-kdx) * kal_P[0][3] ) + ( kal_P[3][3] );
	kal_P[4][4] = ( (0-kdy) * kal_P[1][4] ) + ( kal_P[4][4] );
	kal_P[5][5] = ( (0-kdz) * kal_P[2][5] ) + ( kal_P[5][5] );

	kal_P[3][0] = ( (0-kdx) * kal_P[0][0] ) + ( kal_P[3][0] );
	kal_P[4][1] = ( (0-kdy) * kal_P[1][1] ) + ( kal_P[4][1] );
	kal_P[5][2] = ( (0-kdz) * kal_P[2][2] ) + ( kal_P[5][2] );

	kal_P[0][0] = ( (1-kx) * kal_P[0][0] );
	kal_P[1][1] = ( (1-ky) * kal_P[1][1] );
	kal_P[2][2] = ( (1-kz) * kal_P[2][2] );

	kal_P[0][3] = ( (1-kx) * kal_P[0][3] );
	kal_P[1][4] = ( (1-ky) * kal_P[1][4] );
	kal_P[2][5] = ( (1-kz) * kal_P[2][5] );

	kalman->x  = kal_X.x;
	kalman->y  = kal_X.y;
	kalman->w  = kal_X.z;

#if 0
	printf("\n");
	printf("%3.2f + ", kal_X.x);
	printf("%3.2f\t", kal_X.dx);
	printf("%3.2f + ", kal_X.y);
	printf("%3.2f\t", kal_X.dy);
	printf("%3.2f + ", kal_X.z);
	printf("%3.2f\n", kal_X.dz);
	printf("\n");
#endif
#else
	// x = (F * x) + u
	(*pkal_X).x = (*pkal_X).x + (*pkal_X).dx;
	(*pkal_X).y = (*pkal_X).y + (*pkal_X).dy;
	(*pkal_X).z = (*pkal_X).z + (*pkal_X).dz;

	// P = F * P * F.transpose()
	// add quadrant 1 to quadrant 0
	(*pkal_P)[0][0] = (*pkal_P)[0][0] + (*pkal_P)[0][3];
	(*pkal_P)[1][1] = (*pkal_P)[1][1] + (*pkal_P)[1][4];
	(*pkal_P)[2][2] = (*pkal_P)[2][2] + (*pkal_P)[2][5];
	(*pkal_P)[3][0] = (*pkal_P)[3][0] + (*pkal_P)[3][3];
	(*pkal_P)[4][1] = (*pkal_P)[4][1] + (*pkal_P)[4][4];
	(*pkal_P)[5][2] = (*pkal_P)[5][2] + (*pkal_P)[5][5];

	// add bottom quadrants to top quadrants
	(*pkal_P)[0][0] = (*pkal_P)[0][0] + (*pkal_P)[3][0];
	(*pkal_P)[1][1] = (*pkal_P)[1][1] + (*pkal_P)[4][1];
	(*pkal_P)[2][2] = (*pkal_P)[2][2] + (*pkal_P)[5][2];
	(*pkal_P)[0][3] = (*pkal_P)[0][3] + (*pkal_P)[3][3];
	(*pkal_P)[1][4] = (*pkal_P)[1][4] + (*pkal_P)[4][4];
	(*pkal_P)[2][5] = (*pkal_P)[2][5] + (*pkal_P)[5][5];

	(*pkal_P)[0][0] = (*pkal_P)[0][0] + Qx;
	(*pkal_P)[1][1] = (*pkal_P)[1][1] + Qy;
	(*pkal_P)[2][2] = (*pkal_P)[2][2] + Qz;
	(*pkal_P)[3][3] = (*pkal_P)[3][3] + Qx*Qx;
	(*pkal_P)[4][4] = (*pkal_P)[4][4] + Qy*Qy;
	(*pkal_P)[5][5] = (*pkal_P)[5][5] + Qz*Qz;


	/*
	 * update step
	 *
	 * Z = measured.T
	 * y = Z - (H * x)
	 * S = H * P * H.T + R
	 * K = P * H.T * S.I
	 * x = x + (K * y)
	 * P = (I - (K * H)) * P
	 *
	 */

	// y = Z - (H * x)
	feat_kalman Y;
	Y.x = measured->x - (*pkal_X).x;
	Y.y = measured->y - (*pkal_X).y;
	Y.z = measured->w - (*pkal_X).z;

	// S = H * P * H.T + R

	s11 = (*pkal_P)[0][0] + Rx;
	s22 = (*pkal_P)[1][1] + Ry;
	s33 = (*pkal_P)[2][2] + Rz;

	// K = P * H.T * S.I
	kx  = (*pkal_P)[0][0] / s11;
	ky  = (*pkal_P)[1][1] / s22;
	kz  = (*pkal_P)[2][2] / s33;
	kdx = (*pkal_P)[0][3] / s11;
	kdy = (*pkal_P)[1][4] / s22;
	kdz = (*pkal_P)[2][5] / s33;

	// x = x + (K * y)
	(*pkal_X).x  = (*pkal_X).x  + kx * Y.x;
	(*pkal_X).y  = (*pkal_X).y  + ky * Y.y;
	(*pkal_X).z  = (*pkal_X).z  + kz * Y.z;
	(*pkal_X).dx = (*pkal_X).dx + kdx * Y.x;
	(*pkal_X).dy = (*pkal_X).dy + kdy * Y.y;
	(*pkal_X).dz = (*pkal_X).dz + kdz * Y.z;

	// P = (I - (K * H)) * P
	(*pkal_P)[3][3] = ( (0-kdx) * (*pkal_P)[0][3] ) + ( (*pkal_P)[3][3] );
	(*pkal_P)[4][4] = ( (0-kdy) * (*pkal_P)[1][4] ) + ( (*pkal_P)[4][4] );
	(*pkal_P)[5][5] = ( (0-kdz) * (*pkal_P)[2][5] ) + ( (*pkal_P)[5][5] );

	(*pkal_P)[3][0] = ( (0-kdx) * (*pkal_P)[0][0] ) + ( (*pkal_P)[3][0] );
	(*pkal_P)[4][1] = ( (0-kdy) * (*pkal_P)[1][1] ) + ( (*pkal_P)[4][1] );
	(*pkal_P)[5][2] = ( (0-kdz) * (*pkal_P)[2][2] ) + ( (*pkal_P)[5][2] );

	(*pkal_P)[0][0] = ( (1-kx) * (*pkal_P)[0][0] );
	(*pkal_P)[1][1] = ( (1-ky) * (*pkal_P)[1][1] );
	(*pkal_P)[2][2] = ( (1-kz) * (*pkal_P)[2][2] );

	(*pkal_P)[0][3] = ( (1-kx) * (*pkal_P)[0][3] );
	(*pkal_P)[1][4] = ( (1-ky) * (*pkal_P)[1][4] );
	(*pkal_P)[2][5] = ( (1-kz) * (*pkal_P)[2][5] );

	//kalman->x = (*pkal_X).x;
	//kalman->y = (*pkal_X).y;
	//kalman->w = (*pkal_X).z;
#endif

}

