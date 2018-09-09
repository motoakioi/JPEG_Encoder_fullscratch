#include<iostream>
#include<fstream>

#include"bmp.h"

bool bmp_header_read( std::ifstream in_file, int *width, int *height ){
	BITMAPFILEHEADER file_header;
	BITMAPINFOHEADER info_header;

	in_file.read( (char*)&file_header, sizeof(BITMAPFILEHEADER) );
	if ( file_header.bfType != 0x424d ){
		std:: cout << "invalid " << std::endl;
	}
	std:: cout << "bftype " << file_header.bfType << std::endl;
	return true;
}
bool bmp_data_read( std::fstream in_file, std::vector<int[3]> in_data[3] ){
	return true;
}
