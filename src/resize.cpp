#include"resize.h"

int resize(int original_size){
	return ( original_size + 8 - ( original_size % 8 ) );
}
