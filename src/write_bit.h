#ifndef WRITE_BIT_H
#define WRITE_BIT_H

#include<vector>

#define byte_size 8
#define byte_index_max 7

static const int bit_mask[] = {
	0x01, 0x03, 0x07, 0x0f,
	0x1f, 0x3f, 0x7f, 0xff
};

void write_bit( int, char, std::vector<char>&, int* );
void write_long_data( int, char, std::vector<char>&, int*);

/*
class write_bit_class{
public:
	write_bit_class( std::vector<char>& );
	void write_bit( int , int );
	void write_byte( int );

private:
	int write_pos;
	char tmp_8bit;

};

write_bit_class::write_bit_class( std::vector<char>& out_data ){
	write_pos = 0;
	tmp_8bit = 0x0;
	char* = out_data; 
}

void write_bit_class::write_bit( int size, int data ){
	
	write_pos = ( write_pos + size ) % 8;
}

void write_bit_class::write_byte( int data ){

}
*/

#endif
