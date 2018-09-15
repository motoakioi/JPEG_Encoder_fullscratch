#include<iostream>
#include<fstream>
#include<vector>

#include"encoder.h"
#include"bmp.h"
#include"rgb_ycbcr.h"
#include"jpeg.h"

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
	std::ifstream bmp_image( argv[1], std::ios::in | std::ios::binary );

	// In case that can't open input file 
	if ( !bmp_image ){
		std::cerr << "Error!" << std::endl;
		std::cerr << "Could NOT open input file." << std::endl;
		return -1;
	}

	// Read header of bmp file
	bmp_image.read( (char*)&file_header, sizeof(BITMAPFILEHEADER) );
	bmp_image.read( (char*)&info_header, sizeof(BITMAPINFOHEADER) );

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
			bmp_image.read( (char*)&tmp_data, ( sizeof(char) * 3 ) );
			rgb_data[ ( height - 1 - y ) * width + x ].set_data( &tmp_data ); 
			if(x == 0 && y == 0){
				std::cout << "R is :" << rgb_data[( height - 1 - y ) * width + x].r_is() << std::endl;
				std::cout << "G is :" << rgb_data[( height - 1 - y ) * width + x].g_is() << std::endl;
				std::cout << "B is :" << rgb_data[( height - 1 - y ) * width + x].b_is() << std::endl;
			}
		}
	}

	std::cout << "OK " << std::endl << "Encoding... ";

	// Execute JPEG Encoder function
	encode( height, width, rgb_data );

	std::cout << "OK " << std::endl << "Writing JPEG file... ";

	// Output File
	std::ofstream jpeg_image( "out.jpg", std::ios::out | std::ios::binary | std::ios::trunc );

	// In case that can't open output file
	if( !jpeg_image ){
		std::cerr << "Error!" << std::endl;
		std::cerr << "Could NOT open output file." << std::endl;
		return -1;
	}

	// Prepare JPEG header
	JPEGHEADER jpeg_header;

	jpeg_image.write( (char*)&jpeg_header, sizeof(JPEGHEADER) );



	return 0;
}
