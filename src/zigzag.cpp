#include<iostream>

#include"zigzag.h"

void zigzag( int in[8][8], int out[64] ){
	for ( int y = 0; y < 8; y++ ){
		for (int x = 0; x < 8; x++){
			out[ x + y * 8 ] = in[x][y];
		}// for loop of x
	}// for loop of y

}

