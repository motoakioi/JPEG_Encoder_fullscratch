#include<iostream>

#include"encoder.h"
#include"resize.h"
#include"dct.h"
#include"quantize.h"

void encode( 
		int original_height, 
		int original_width, 
		){

	// Set image size to be multiple of 16
	int height = resize( original_height );
	int width = resize( original_width );



	// Divide image into 8x8 blocks

	// DCT
	

	// Quantize
	

	// RunLegth
	

	// ZigZag Scan

}

