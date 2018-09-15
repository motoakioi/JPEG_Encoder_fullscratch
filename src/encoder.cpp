#include<iostream>
#include<vector>

#include"encoder.h"

#include"rgb_ycbcr.h"
#include"resize.h"
#include"mcu.h"
#include"dct.h"
#include"quantize.h"
#include"quantize_table.h"
#include"zigzag.h"


void encode( int ori_height, 
			 int ori_width, 
			 std::vector<RGB>& in_rgb ){

	int all_pixels = ori_height * ori_width;
	std::vector<YCbCr> in_ycbcr( all_pixels, YCbCr( 0.0, 0.0, 0.0 ) );

	// Set image size to be multiple of 16
	int height = resize( ori_height );
	int width = resize( ori_width );

	// Calculate number of MCU
	int mcu_vertical = height / 16;
	int mcu_horizontal =  width / 16;
	int all_mcu = mcu_vertical * mcu_vertical; 

	std::cout<< "    w:" << ori_width << ",     h:" << ori_height << std::endl;
	std::cout<< "new w:" << width <<     ", new h:" <<height << std::endl;

	// Instance of MCU
	std::vector<mcu> mcu_data( all_mcu );

	// RGB to YCbCr
	int pos = 0;
	for (int y = 0; y < height; y++ ) {
		for (int x = 0; x < width; x++ ) {

			if ( x + 1 > ori_width ||  y + 1 > ori_height ){
				pos--;
			}

			in_ycbcr[ pos ] = rgb_to_ycbcr( &in_rgb[ pos ] );

			// TODO : remove
/*			std::cout<< " pos : " << pos << std::endl;
			std::cout << "  Y:" << in_ycbcr[ pos ].y_is() 
					  << ", Cb:" << in_ycbcr[ pos ].cb_is()
					  << ", Cr:" << in_ycbcr[ pos ].cr_is() << std::endl;
*/
			// Divide image into 16x16 blocks (MCU) and data path
			mcu_data[ mcu_horizontal * ( y / 16 ) + ( x / 16 ) ].set_block( x, y, &in_ycbcr[ pos ] );

			pos++;

		}// for loop of x
	}//for loop of y

	// Data compression for each MCU
	for (int mcu_order = 0; mcu_order < all_mcu; mcu_order++ ){
		for ( int mcu_component = 0; mcu_component < 6; mcu_component++ ){

			double tmp_val[8][8];
			double tmp_dct[8][8];
			int tmp_quant[8][8];
			int tmp_scand[64];

			// copy mcu_data into tmp_val
			mcu_data[ mcu_order ].read_block( mcu_component, tmp_val );

			// DCT
			dct( tmp_val, tmp_dct );

			// Quantize
			quantize( tmp_dct, tmp_quant, &mcu_component, quantize_table );
				std::cout << "quant" << std::endl;

			// ZigZag Scan
			zigzag_scan( tmp_quant, tmp_scand );

			// TODO : remove
			std::cout << "scaned ";
			for ( int i = 0; i < 64; i++ ){
				std::cout << tmp_scand[i] << " ";
			}
			std::cout << std::endl;

			// RunLegth
			

			
		}// for loop of mcu_component
	}// for loop of mcu_order

}// End  of encode func.

