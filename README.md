# JPEG_Encoder_fullscratch
Aim for full scratch, something like that.

## Purpose
Making JPEG encoder without using libraries such as libjpeg.

## Current status
main func :
bmp -> RGB -> encode (midstream) ...  

encode func :  
RGB -> YCbCr -> MCU -> ...  

Not done since DCT.

## File Organization
.  
├── CMakeLists.txt  
├── LICENSE  
├── README.md  
├── build  
│   ├── Makefile  
│   └── jpeg-enc  
└── src  
    ├── bmp.h  
    ├── dct.cpp  
    ├── dct.h  
    ├── encoder.cpp  
    ├── encoder.h  
    ├── main.cpp  
    ├── mcu.h  
    ├── quantize.cpp  
    ├── quantize.h  
    ├── quantize_table.h  
    ├── resize.cpp  
    ├── resize.h  
    ├── rgb_ycbcr.cpp  
    ├── rgb_ycbcr.h  
    └── table.h    



