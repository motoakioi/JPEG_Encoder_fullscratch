#include<iostream>

#include"rgb_ycbcr.h"

int main(void){

	std::cout << "Test main func is called" <<std::endl;

	RGB data = RGB( 82, 0, 87 );
	YCbCr value = rgb_to_ycbcr( &data );

	std::cout << "Y : " << value.Y <<std::endl;
	std::cout << "Cb : " << value.Cb <<std::endl;
	std::cout << "Cr : " << value.Cr <<std::endl;

	return 0;
}
