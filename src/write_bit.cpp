#include<iostream>

#include"write_bit.h"

void write_bit ( int size,
				 char in_data, 
				 std::vector<char>& out_data, 
				 int* position ){

	char masked_data = in_data & bit_mask[size];

	// In case of write data in 2 byte
	if ( size == 0 ){
		;
	}else if ( int tmp = *position + size > byte_index_max ){

		
		int residue = tmp - byte_size;

		// Write to 1st byte
		out_data.insert( out_data.end(), ( out_data.back() | masked_data >> residue ) );

		// Write to 2nd byte
		out_data.push_back( ( in_data & bit_mask[residue] ) << ( byte_size - residue ) );

		// 
		*position = *position + residue;

	}else{
		char write_data = masked_data << ( byte_size - size - *position );

		if ( position == 0 ){
			out_data.push_back( write_data);

		}else{
			out_data.insert( out_data.end(), ( out_data.back() | write_data ) );

		}

		*position = ( *position + size ) % byte_size;
	}

}

void write_long_data( int size,
					  char in_data, 
					  std::vector<char>& out_data, 
					  int* position ){

	int write_size = size;

	while ( write_size > byte_index_max ){
		write_bit( byte_size, in_data, out_data, position );
		write_size -= byte_size;

	}
	write_bit( size % byte_size, in_data, out_data, position );

}







