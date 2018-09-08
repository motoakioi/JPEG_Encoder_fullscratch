#include<iostream>

#include"encoder.h"
#include"rgb_ycbcr.h"

int main(void){

	std::cout << "Test main func is called" <<std::endl;

	RGB data[2] = { RGB( 82, 0, 87 ), 
					RGB( 82, 0, 87 ) };

	std::cout << "before encoder func" <<std::endl;

	encode( 1, 2, data );

	return 0;
}
