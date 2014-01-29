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
VBXCOPYRIGHT( scalar_haar_detect )

#include "demo.h"
#include "haar_detect.h"

//generate both the integral image (sum area table) and squared integral image - significanlty reducing loads
void gen_integrals( unsigned short* img, unsigned int* iImg, unsigned int* iiImg, short width, short height)
{
	int x,y;

	//initial integral values set directly to matching pixels
	iImg[0] = (unsigned int)img[0];
	iiImg[0] = (unsigned int)img[0]*(unsigned int)img[0];

	//first rows sums values from its row only
	for(x=1; x<width; x++){
		iImg[ x] = iImg[ x-1] + (unsigned int)img[x];
		iiImg[x] = iiImg[x-1] + (unsigned int)img[x]*(unsigned int)img[x];
	}

	//remaining rows are the sum of all pixels above and left of current position
	for(y=1; y < height; y++){

		int row = 0;
		int rrow = 0;

		for(x=0; x < width; x++){
			//keeping integral and squared integral rows totals to make calculation easier
			row = row + (unsigned int)img[ x + y*width ];
			rrow = rrow + (unsigned int)img[ x + y*width ]*(int)img[ x + y*width ];

			iImg[  x + y*width ] = iImg[  x + (y-1)*width ] + row;
			iiImg[ x + y*width ] = iiImg[ x + (y-1)*width ] + rrow;
		}
	}
}

//calculate the variance of a given window
int get_variance( unsigned int* iImg, unsigned int* iiImg, int x0, int y0, short win, short width)
{
	//calculate mean using integral image (only need 4 loads)
	int mean = (iImg[x0+win + (y0+win)*width] + iImg[x0 + y0*width] - iImg[x0+win + y0*width] - iImg[x0 + (y0+win)*width])/(win*win);
	//calculate var using squared integral image 
	int var = (iiImg[x0+win + (y0+win)*width] + iiImg[x0 + y0*width] - iiImg[x0+win + y0*width] - iiImg[x0 + (y0+win)*width])/(win*win);
	var = var - (mean*mean);
	if (var >= 0)
	  var= (int) sqrt( (double)var );
	else
	  var = 1;
	return var;
}

//sum all weighted rectangular sections of a given feature
int sum_feature( rect* feature, int start, int num_features, unsigned int* iImg, int x0, int y0, short width )
{
	int sum = 0, i;

	for(i=start; i<num_features+start; i++){
		int sx = x0 + feature[i].x;
		int sy = y0 + feature[i].y;
		int sw = x0 + feature[i].w;
		int sh = y0 + feature[i].h;
		int value = feature[i].value;
		sum = sum + (iImg[sw + (sh)*width] + iImg[sx + sy*width] - iImg[sw + sy*width] - iImg[sx + (sh)*width] )*value;
	}

	return sum;
}

//each feature either passes or fails, adding a value to the stage's total
//a binary value is returned, depending if the stage's total is greater than the stage's threshold
int pass_stage( stage stage, unsigned int* iImg, int x, int y, int var, int win, short width )
{
	int sum_stage = 0, i;

	for(i=0;i<stage.size;i++){
		if ( sum_feature(stage.rects, stage.start[i], stage.num[i], iImg, x, y, width)*4096  <  stage.thresh[i] * var * win *win )
			sum_stage = sum_stage + stage.pass[i]; 
		else
			sum_stage = sum_stage + stage.fail[i];
	}
	if (sum_stage > stage.value){
		return 1;
	}
	return 0;
}

//dynamically add features to the feature set -- implemented as a linked list
feat* append_feature(feat* features, int x0, int y0, int w0)
{
	feat* prev = features;
	feat* current = (feat*)malloc(sizeof(feat));

	if(current == NULL)printf("malloc error\n");
	
	current->next = NULL;
	current->x = x0;
	current->y = y0;
	current->w = w0;

	if (prev == NULL){
		return current;
	}
		int i=2;

	while(prev->next != NULL){
		i = i+1;
		prev = prev->next;
	}
	prev->next = current;

	return features;
}

//free all features that had been dynamically allocated
void free_features( feat* features ) 
{
	feat* next; 

	while(features->next !=NULL){
		next = features->next;
		free(features);
		features = next;
	}

	free(features);
}

//check if two features overlap, indicating they may point to the same object
int overlapped_features( int ax, int ay, int aw , int bx, int by, int bw )
{
	int dist = aw*3/10; 

	// are A and B similar in size? and if the are, do they overlap closely?
	if(aw <= (bw*13/10) && bw <= (aw*13/10))
		if ( abs(ax-bx) <= dist && abs(by-ay) <= dist )
			return 1;

	// is A fully contained in B?
	if (ax >= bx && ay >= by)
		if (ax+aw <= bx+bw && ay+aw <= by+bw)
			return 2;

	return 0;
}	

//merge overlapping features, producing a reduced feature list where overlapped features are averaged together
feat* merge_features(feat* raw, feat* merged)
{
	int i,j, num = 1, solo = 0;
	feat* current;

	if (raw == NULL)return NULL;

	//get number of potential features
	current = raw;
	while( current->next != NULL){
		current = current->next;
		num = num + 1;
	}

	int* feature = (int*) malloc(num*sizeof(int));
	int* neighbors = (int*) malloc(num*sizeof(int));
	feat* temp = (feat*) malloc(num*sizeof(feat));
	feat* original = (feat*) malloc(num*sizeof(feat));

	current = raw;

	// Switch from linked list, into array
	for(i=0; i<num;i++){
		original[i] = *current;
		current = current->next;
	}

	for(i=0; i<num;i++){
		int found = 0;
		// go through all previous features
		for(j=0; j<i; j++){
			if (overlapped_features( original[j].x, original[j].y, original[j].w, original[i].x, original[i].y, original[i].w)){
				found = 1;
				feature[i] = feature[j];
			}
		}
		if (!found){
				feature[i] = solo;
				solo = solo + 1;
		}

	}
	// Get the fields used to merged the features ready
	for(i=0; i<solo;i++){
		neighbors[i]=0;
		temp[i].x=0;
		temp[i].y=0;
		temp[i].w=0;
	}	

	// index is the base feature the current feature matches
	// we increase the num of matching features in this base features neighborhood
	// we add the current feature to the merged feature total
	for(i=0; i<num;i++){
		int index = feature[i];
		neighbors[index] = neighbors[index] + 1;
		temp[index].x = temp[index].x + original[i].x;
		temp[index].y = temp[index].y + original[i].y;
		temp[index].w = temp[index].w + original[i].w;
	}
	// take our summed merged features, and get the average values of coordinates for all features
	int mfaces = 0;
	for(i=0; i<solo;i++){
		int n = neighbors[i];
		if (n >= MIN_NEIGHBORS){
			// mutliply by 2 and add n for better rounding
			int x = (temp[i].x*2 + n) / (2*n);
			int y = (temp[i].y*2 + n) / (2*n);
			int win = (temp[i].w*2 + n) / (2*n);
			
			mfaces = mfaces+1;
			merged = append_feature(merged, x, y, win);
		}
	}

	free(feature);
	free(neighbors);
	free(temp);
	free(original);

	return merged;
		
}

//scales image using bilinear interpolation, to the given percentage
void scalar_BLIP(unsigned short* img, short height, short width, unsigned short* scaled_img, short scaled_height, short scaled_width, float percent)
{
	short row,pixel;
	unsigned int x,y,x0,y0,dx,dy,d1x,d1y;
	short point_a, point_b, point_c, point_d; 
	unsigned int weight_a, weight_b, weight_c, weight_d;
	int out;
	int scale = (int)((1.0/percent)*4096.0);

	for(row=0; row < scaled_height-1; row++){

		y = row * scale; 
		y0 =  (0xFFFFF000 &  y )>>12; //get the floor of y
		dy =   0x00000FFF &  y; //get the frac of y
		d1y =  0x00001000 - dy; //get 1-frac of y

		for(pixel=0; pixel < scaled_width-1; pixel++){
			//convert from int to Fixed12 and get source pixels for this reduced image
			x = pixel * scale; //(int)(1.20/1.0 *4096) -- scaled by 120% + switched to Fixed12
			y = row   * scale; 

			//get floor and fractional components of point
			x0 =  (0xFFFFF000 &  x )>>12;  //get the floor of x
			dx =   0x00000FFF &  x; //get the frac of x
			d1x =  0x00001000 - dx;  //get 1-frac of x

			//get pixels 'boxing in' point
			point_a = img[    x0+    y0*width]; 
			point_b = img[(x0+1)+    y0*width];
			point_c = img[    x0+(y0+1)*width];
			point_d = img[(x0+1)+(y0+1)*width];
			
			//determine pixel weights
			weight_a = (d1x * d1y) >> 6; //BLIP weighting of pixel a = (1-dx*1-dy) , divided by 64
			weight_b = (dx  * d1y) >> 6; //BLIP weighting of pixel b = (  dx*1-dy)
			weight_c = (d1x * dy ) >> 6; //BLIP weighting of pixel c = (1-dx*  dy)
			weight_d = (dx  * dy ) >> 6; //BLIP weighting of pixel d = (  dx*  dy)

			//get BLIP value of point from weighted pixel values, convert back from Fixed12 to int
			out = (point_a*weight_a + point_b*weight_b + point_c*weight_c + point_d*weight_d) >> 12; //sum of weighted pixel values, divided by 4096 
			scaled_img[pixel+row*scaled_width] = out >>6; //divided by a final 64
		}
	}
	//clean up edge cases
	for(pixel=0; pixel < scaled_width-1; pixel++){
		scaled_img[pixel+(scaled_height*(scaled_width-1))] = 255; 
	}
	for(row=0; row < scaled_height; row++){
		scaled_img[scaled_width-1+(row*scaled_width)] = 255; 
	}

}

//get a list of features that pass the stages of the haar filter
feat* scalar_get_haar_features_image_scale( stage *cascade, unsigned short* img, int min_scale, int scale_inc, feat* features, short width, short height, short window, short max_stage )
{

	float percent = 1000.0/((float)scale_inc);
	unsigned int *iImg = (unsigned int*)malloc( width * height * sizeof(unsigned int) );
	unsigned int *iiImg = (unsigned int*)malloc( width * height * sizeof(unsigned int) );
	unsigned short *rimg = (unsigned short*)malloc( width * height * sizeof(unsigned short) );
	unsigned short *orig_rimg = rimg;
	unsigned short *tmp;

	if(iImg == NULL || iiImg == NULL || rimg == NULL){
		printf("Error allocating integral images!\n");
		return NULL;
	}

	float scaled =1.0;

	int x, y, sx, sy, sw;
	int x_max, y_max;
	int i, var, result;
	short orig_width, orig_height;
	int ystep = Y_STEP;

	while( width >= window && height >= window ){
		x_max = width-window;
		y_max = height-window;

		if (scaled*1000 >= min_scale){
			gen_integrals( img, iImg, iiImg, width, height);
			for(y=0; y<y_max; y=y+ystep){
				for(x=0; x<x_max; x++){
					var = get_variance(iImg, iiImg, x, y, window, width);
					result= 1;
					for (i=0; i<max_stage; i++){
						result = pass_stage( cascade[i], iImg, x, y, var, window, width);
						if (!result){
							break;
						}
					}
					if(result){
						sx = (int)(scaled*x);
						sy = (int)(scaled*y);
						sw = (int)(scaled*window);
						features = append_feature(features, sx, sy, sw);
					}
				}
			}
		} 
		//reduce image
		orig_width = width; 
		orig_height = height;
		width =(short)((float)width*percent); 
		height=(short)((float)height*percent);

		if (height>=window && width >=window){
			SWAP(img,rimg,tmp);
			scalar_BLIP(rimg, orig_height, orig_width, img, height, width, percent);
		}
		//increase scaled
		scaled = scaled*scale_inc/1000;
	}
	free(iImg);
	free(iiImg);
	free(orig_rimg);
	return features;
}	

//find and display the features found in an image using a haar cascade
int scalar_face_detect_luma(unsigned short *input, pixel *output, const int image_width, const int image_height, const int image_pitch)
{
	pixel *color =(pixel*)malloc(sizeof(pixel));

	feat* features = NULL; 
	feat* merged = NULL; 

	features = scalar_get_haar_features_image_scale( face_alt, input, INITIAL_ZOOM, SCALE_FACTOR, features, image_width, image_height, 20, 22);

	merged = merge_features( features, merged);

	if(merged != NULL){
	  color->r = 0;color->b = 0;color->g = 255;
	  draw_features( merged , color, output, image_width, image_height, image_pitch);
	  free_features( features );
	  free_features( merged );
	}else if(features != NULL){
#if DEBUG
	  color->r = 0;color->b = 0;color->g = 75;
	  draw_features( features , color, output, image_width, image_height, image_pitch);
#endif
	  free_features( features );
	}
	free(color);

	return 0;
}
