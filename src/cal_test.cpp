#include<iostream>
#include<stdio.h>

int main(void){

	char test_c[1] = {3};
	char test_i[1];

	int in = 5;

	FILE *fp = fopen( "test_out", "r" );

	test_i[0] = (char)in;

	fwrite( test_i, 1, sizeof(char), fp );

	std::cout << (int)test_c[0] << "test" << (int)test_i[0] << ") "<< std::endl;

	return 0;
}
