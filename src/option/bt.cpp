#include<iostream>
#include<math.h>

#include"bt.h"

// [u][x]
double table[8][8] = {
	{1,  1,  1,  1,  1,  1,  1,  1 },
	{1,  1,  0,  0,  0, -1, -1, -1 },
	{1,  1,  0,  0, -1, -1, -1, -1 },
	{1,  0,  0,  0, -1, -1,  0,  0 },
	{1,  0,  0, -1, -1,  0,  0,  1 },
	{1,  1, -1, -1,  0,  1,  1,  0 },
	{1,  0, -1,  0,  1,  0, -1,  0 },
	{1, -1,  1, -1,  1, -1,  1, -1 }
};



void bt( double in[8][8], double out[8][8] ){
for( int x = 0; x < 8; x++){
	for(int u = 0; u < 8; u++){
		table[u][x] = cos( ( 2 * x + 1 ) * u * M_PI / (2.0 * 8) );
	}
}
for ( int v = 0; v < 8; v++ ){
		double C_v = ( v == 0 ) ? 1 / sqrt(2) : 1;

		for ( int u =0; u < 8; u++ ){
			double C_u = ( u == 0 ) ? 1 / sqrt(2) : 1;

			double tmp_x = 0.0;

			for(int x = 0; x < 8; x++ ){

				double tmp_y = 0.0;

				for ( int y = 0; y < 8; y++ ){
					tmp_y += in[x][y] * table[v][y]; 
				}// for loop of y

				tmp_x += tmp_y * table[u][x];

			}// for loop of x

			out[u][v] = 1.0 / 4.0 * C_u * C_v * tmp_x;

		}// for loop of u
	}// for loop of v

}


void ibt( double in[8][8], double out[8][8] ){
	for ( int y = 0; y < 8; y++ ){

		for ( int x = 0; x < 8; x++ ){
			double tmp_u = 0.0;

			for(int u = 0; u < 8; u++ ){
				double C_u = ( u == 0 ) ? 1 / sqrt(2) : 1;
				double tmp_v = 0.0;

				for ( int v = 0; v < 8; v++ ){
					double C_v = ( v == 0 ) ? 1 / sqrt(2) : 1;

					tmp_v += C_u * C_v * in[u][v] * table[v][y]; 
				}// for loop of v

				tmp_u += tmp_v * table[u][x];

			}// for loop of u

			out[x][y] = 1.0 / 4.0 * tmp_u;

		}// for loop of x
	}// for loop of y

}

