#include<iostream>

#include"zigzag.h"
#include"zigzag_order.h"

void zigzag_scan( int in[8][8], int out[64] ){
	for ( int y = 0; y < 8; y++ ){
		for (int x = 0; x < 8; x++){
			out[ zigzag_order[ x + y * 8 ] ] = in[x][y];
		}// for loop of x
	}// for loop of y
}

