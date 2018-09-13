#include<iostream>
#include<math.h>

#include"dct.h"


void dct( double in[8][8], double out[8][8] ){
	for ( int v = 0; v < 8; v++ ){
		double C_v = ( v == 0 ) ? 1 / sqrt(2) : 1;

		for ( int u =0; u < 8; u++ ){
			double C_u = ( u == 0 ) ? 1 / sqrt(2) : 1;
			double tmp_x = 0.0;

			for(int x = 0; x < 8; x++ ){

				double tmp_y = 0.0;

				for ( int y = 0; y < 8; y++ ){
					tmp_y += in[x][y] * cos( ( 2.0 * y + 1.0 ) * v * M_PI  / 16.0 ); 
				}// for loop of y

				tmp_x += tmp_y * cos( ( 2.0 * x + 1.0 ) * u * M_PI / 16.0 );

			}// for loop of x

			out[u][v] = 1.0 / 4.0 * C_u * C_v * tmp_x;

		}// for loop of u
	}// for loop of v


}
