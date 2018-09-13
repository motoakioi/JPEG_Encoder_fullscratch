#include<iostream>

#include"quantize.h"

void quantize( double in[8][8], int out[8][8], int *component, int table[2][8][8] ){

	int table_sel = *component / 4;

	for ( int y = 0; y < 8; y++ ){
		for (int x = 0; x < 8; x++ ){
			out[x][y] = in[x][y] / table[table_sel][x][y];
		}// for loop of x
	}// for loop of y

}


