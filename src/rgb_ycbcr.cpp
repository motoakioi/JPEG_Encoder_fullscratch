#include<iostream>
#include<math.h>

#include"rgb_ycbcr.h"

YCbCr rgb_to_ycbcr( RGB* rgb_in ){
	double Y =   0.299 * (double)rgb_in->r_is() 
			   + 0.587 * (double)rgb_in->g_is() 
			   + 0.114 * (double)rgb_in->b_is();

	double Cb =  - 0.1687 * (double)rgb_in->r_is()
				 - 0.3313 * (double)rgb_in->g_is()
				 + 0.5    * (double)rgb_in->b_is()
				 + 128.0;

	double Cr =    0.5    * (double)rgb_in->r_is()
				 - 0.4187 * (double)rgb_in->g_is()
				 - 0.0813 * (double)rgb_in->b_is()
				 + 128;

	return YCbCr( Y, Cb, Cr );
}

/*
void rgb_to_ycbcr( RGB* rgb_in-> YCbCr* ycbcr_in->){
	*ycbcr_in.Y = 0.299 * (in->*)rgb_in->>R 
				 + 0.587 * (in->*)rgb_in->>G 
				 + 0.114 * (in->*)rgb_in->>B 
				 - 128.0;
}
*/
