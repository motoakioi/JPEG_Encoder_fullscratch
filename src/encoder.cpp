#include<iostream>
#include<vector>

#include"encoder.h"

#include"rgb_ycbcr.h"
#include"resize.h"
#include"dct.h"
#include"quantize.h"

void encode( 
		int ori_height, 
		int ori_width, 
		RGB *in_rgb){

	int all_pixels = ori_height * ori_width;
	std::vector<YCbCr> in_ycbcr( all_pixels, YCbCr( 0.0, 0.0, 0.0 ) );

	std::cout<< "all_pixels : " << all_pixels << std::endl;

	// RGB to YCbCr
	int pos = 0;
	while ( pos < all_pixels ) {

		in_ycbcr[ pos ] = rgb_to_ycbcr( &in_rgb[ pos ] );

		// TODO : remove
		std::cout<< " pos : " << pos << std::endl;
		std::cout << "  Y:" << in_ycbcr[ pos ].Y 
				  << ", Cb:" << in_ycbcr[ pos ].Cb
				  << ", Cr:" << in_ycbcr[ pos ].Cr << std::endl;

		pos++;
	}

	// Set image size to be multiple of 16
	int height = resize( ori_height );
	int width = resize( ori_width );

	// Divide image into 16x16 blocks (MCU)
	// Calculate number of MCU
	int mcu_vertical = height / 16;
	int mcu_horizontal =  width / 16;
	//int all_mcu = mcu_vertical * mcu_vertical; 

	// path data into MCU class 
	

	// DCT
	

	// Quantize
	

	// RunLegth
	

	// ZigZag Scan

}

