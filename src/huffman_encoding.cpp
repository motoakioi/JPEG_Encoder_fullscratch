#include<iostream>
#include<vector>

#include"huffman_encoding.h"

int Y_DC_table;

int bit_size( int in_data ){
	int tmp = ( in_data > 0 ) ? in_data : ( -1 * in_data ); 
	int length = 0;
	for ( length = 0; tmp; tmp>>=1 ){
		length++;
	}
	return length;
}

void huffman_encode( 
					 int in_scaned[64],
					 int *prev_dc,
					 std::vector<char>& out_encoded){

	// calculate DC value
	char dc_value =  (char)( in_scaned[0] - *prev_dc ) ;

	// update DC value
	*prev_dc = in_scaned[0];

	// Huffman DC
	


	// calculate AC
	int index = 1;
	while( index < 64 ){
		char run;
		index++;
	}

}


