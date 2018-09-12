#include<iostream>

#include"quantize.h"
#include"quantize_table.h"

void quantize( double in[8][8], double out[8][8], double table[8][8] ){
	for ( int y = 0; y < 8; y++ ){
		for (int x = 0; x < 8; x++ ){
			out[x][y] = in[x][y] / table[x][y];
		}// for loop of x
	}// for loop of y

}


