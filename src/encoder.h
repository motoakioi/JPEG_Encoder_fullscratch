#ifndef ENCODER_H
#define ENCODER_H

#include<vector>
#include"rgb_ycbcr.h"

void encode( int, int, std::vector<RGB>&, std::vector<char>&, int* );

#endif
