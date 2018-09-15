cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 14)

add_executable(jpeg-enc
	../src/main.cpp
	../src/encoder.cpp
	../src/rgb_ycbcr.cpp
	../src/resize.cpp
	../src/dct.cpp
	../src/quantize.cpp
	../src/zigzag.cpp
	../src/
	)
