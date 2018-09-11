#include"resize.h"

int resize(int original_size){
	if ( (original_size % 16 ) == 0 )  {
		return original_size;
	}else{
		return ( original_size +  16 - original_size % 16 );
	}
}
