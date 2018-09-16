#include<iostream>
//#include<fstream>
#include<stdio.h>
#include<vector>

#include"encoder.h"
#include"bmp.h"
#include"rgb_ycbcr.h"
#include"jpeg.h"
//#include"quantize_table.h"

int main(int argc, char* argv[]){

	int width, height; // image size
	BITMAPFILEHEADER file_header;
	BITMAPINFOHEADER info_header;

	// Check number of argument
	if ( argc != 2 ){
		std::cerr << "Error!" << std::endl;
		std::cerr << "Usage : input.bmp" << std::endl;
		return -1;
	}

	std::cout << "Start..." << std::endl;
	std::cout << "Opening input file... ";

	// Open bmp file (argv[1])
	//std::ifstream bmp_image( argv[1], std::ios::in | std::ios::binary );
	FILE* bmp_image = fopen( argv[1], "rb");

	// In case that can't open input file 
	if ( !bmp_image ){
		std::cerr << "Error!" << std::endl;
		std::cerr << "Could NOT open input file." << std::endl;
		return -1;
	}

	// Read header of bmp file
	//bmp_image.read( (char*)&file_header, sizeof(BITMAPFILEHEADER) );
	fread( &file_header, sizeof(BITMAPFILEHEADER), 1, bmp_image );

	//bmp_image.read( (char*)&info_header, sizeof(BITMAPINFOHEADER) );
	fread( &info_header, sizeof(BITMAPINFOHEADER), 1, bmp_image );

	// In case that input is not bmp file
	if ( file_header.bfType != 0x4d42 ){
		std::cerr << "Error!" << file_header.bfType << std::endl;
		std::cerr << "Input file is NOT bmp file." << std::endl;
		return -1;
	}

	// Calculate size of image
	width = info_header.biWidth;
	height = info_header.biHeight;
	std::vector<RGB>rgb_data( width * height, RGB( 0, 0, 0 ) );

	std::cout <<  "OK" << std::endl << "Width : " << width << ", Height : " << height << std::endl;
	std::cout << "Loading bmp data... ";


	for ( int y = 0; y < height; y++ ){
		for ( int x = 0; x < width; x++ ){
			int tmp_data;
			//bmp_image.read( (char*)&tmp_data, ( sizeof(char) * 3 ) );
			fread( &tmp_data, ( sizeof(char) * 3 ), 1, bmp_image );

			rgb_data[ ( height - 1 - y ) * width + x ].set_data( &tmp_data ); 
			if(x == 0 && y == 0){
				std::cout << "R is :" << rgb_data[( height - 1 - y ) * width + x].r_is() << std::endl;
				std::cout << "G is :" << rgb_data[( height - 1 - y ) * width + x].g_is() << std::endl;
				std::cout << "B is :" << rgb_data[( height - 1 - y ) * width + x].b_is() << std::endl;
			}
		}
	}

	// Close input file
	fclose( bmp_image );

	std::cout << "OK " << std::endl << "Encoding... ";

	// Declare output variables
	std::vector<int> run_length_data;
	int length = 0;

	// Execute JPEG Encoder function
	encode( height, width, rgb_data, run_length_data, &length );

	std::cout << "OK " << std::endl << "Writing JPEG file... ";

	// TODO :remove
	std::cout << "run data :  " << std::endl;
	for( int i = 0 ; i < 64; i++ ){
		std::cout << run_length_data[i] << " ";
	}
	std::cout << std::endl;

	// Output File
	//std::ofstream jpeg_image( "out.jpg", std::ios::out | std::ios::binary | std::ios::trunc )
	FILE* jpeg_image = fopen( "out.jpg", "wb" );

	// In case that can't open output file
	if( !jpeg_image ){
		std::cerr << "Error!" << std::endl;
		std::cerr << "Could NOT open output file." << std::endl;
		return -1;
	}

	// Prepare JPEG header
	JPEGHEADER jpeg_header;

//	memcpy( jpeg_header.DQT_LUMA,  quantize_table[0], sizeof(jpeg_header.DQT_LUMA) );

	// jpeg_image.write( (char*)&jpeg_header, sizeof(JPEGHEADER) );
	fwrite( &jpeg_header, 1, sizeof(JPEGHEADER), jpeg_image );

	// Close output file
	fclose( jpeg_image );

	return 0;
}
