#ifndef JPEG_H
#define JPEG_H


//
#pragma pack(1)
typedef struct JPEGHEADER{
	// SOI
	uint16_t SOI = 0xFFD8;

	// APP0
	uint16_t APP0_marker = 0xFFE0;
	uint16_t APP0_LENGTH = 16;
	const char APP0_MSG[5] = "JFIF";
	uint8_t  APP0_V_H = 1;
	uint8_t  APP0_V_L = 1;
	uint8_t  APP0_UNIT = 0;
	uint16_t APP0_X_DENSITY = 1;
	uint16_t APP0_Y_DENSITY = 1;
	uint8_t  APP0_thumbnail_width = 0;
	uint8_t  APP0_thumbnail_height = 0;

	// DQT
	uint16_t DQT_marker = 0xFFDB;
	uint16_t DQT_LENGTH = 132;
	uint8_t  DQT_T1_INFO = 1;
	char DQT_LUMA[64]; 
/*	const char DQT_LUMA[64] =  {
	16,  11,  10,  16,  24,  40,  51,  61,
	12,  12,  14,  19,  26,  58,  60,  55,
	14,  13,  16,  24,  40,  57,  69,  56,
	14,  17,  22,  29,  51,  87,  80,  62,
	18,  22,  37,  56,  68, 109, 103,  77,
	24,  35,  55,  64,  81, 104, 113,  92,
	49,  64,  78,  87, 103, 121, 120, 101,
	72,  92,  95,  98, 112, 100, 103,  99 
	}; 
	uint8_t  DQT_T2_INFO = 1;
	const char DQT_CHROMA[8] ={1,2,3,4,5,6,7,8}; 
*/

	// EOI
	uint16_t EOI = 0xFFD9;

} JPEGHEADER;

#endif
