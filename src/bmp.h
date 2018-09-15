#ifndef BMP_H
#define BMP_H

// BITMAPFILEHEADER 14bytes
#pragma pack(1)
typedef struct BITMAPFILEHEADER {
	uint16_t bfType;
	uint32_t bfSize;
	uint16_t bfReserved1;
	uint16_t bfReserved2;
	uint32_t bfOffBits;
} BITMAPFILEHEADER;

// BITMAPINFOHEADER 40bytes
#pragma pack(1)
typedef struct BITMAPINFOHEADER {
	uint32_t biSize;
	int32_t biWidth;
	int32_t biHeight;
	uint16_t biPlanes;
	uint16_t biBitCount;
	uint32_t biCompression;
	uint32_t biSizeImage;
	int32_t biXPixPerMeter;
	int32_t biYPixPerMeter;
	uint32_t biClrUsed;
	uint32_t biClrImporant;
} BITMAPINFOHEADER; 

//bool bmp_header_read( std::ifstream, int*, int* );
//bool bmp_data_read( std::ifstream, std::vector<int[3]>&);

#endif
