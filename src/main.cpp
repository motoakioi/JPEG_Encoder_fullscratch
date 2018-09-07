#include<iostream>
#include<fstream>

#include"encoder.h"

int main(int argc, char* argv[]){

	int width, height; // image size
	

	// Check number of argument
	if ( argc != 2 ){
		std::cerr << "Error!" << std::endl;
		std::cerr << "Usage : input.bmp" << std::endl;
		return -1;
	}

	std::cout << "Start..." << std::endl;

	// Open bmp file (argv[1])
	std::ifstream bmp_image( argv[1], std::ios::in | std::ios::binary );

	// In case that can't open bmp file 
	if ( !bmp_image ){
		std::cerr << "Error!" << std::endl;
		std::cerr << "Could NOT open bmp file." << std::endl;
		return -1;
	}

	// Read header of bmp file
	

	// In case that input is not bmp file
	

	// Calculate size of image
	

	// Execute JPEG Encoder function



	return 0;
}
