#include<iostream>
#include<vector>

#include"huffman_encoding.h"

void huffman_encode( 
					 int in_scaned[64],
					 int *prev_dc,
					 std::vector<char>& out_encoded){

	// calculate DC value
	out_encoded.push_back( (char)( in_scaned[0] - *prev_dc ) );

	// update DC value
	*prev_dc = in_scaned[0];

}
