#ifndef RGB_YCBCR_H
#define RGB_YCBCR_H

class RGB{
	private:
		int R;
		int G;
		int B;
	public:
		RGB(){};
		RGB( int r, int g, int b ){
			R = r;
			G = g;
			B = b;
		};
		int r_is( void ){
			return R;
		}
		int g_is( void ){
			return G;
		}
		int b_is( void ){
			return B;
		}
		void set_data( int *in ){

/*			// In case of Big endianness, this is correct
			R =   *in & 0xFF;
			G = ( *in & 0xFF00   ) >>  8;
			B = ( *in & 0xFF0000 ) >> 16;
*/
			// In case of Little endianness
			R = ( *in & 0xFF0000 ) >> 16;
			G = ( *in & 0xFF00   ) >>  8;
			B =   *in & 0xFF;

		}
};

class YCbCr{
	private:
		double Y;
		double Cb;
		double Cr;
	public:
		YCbCr( double y, double cb, double cr ){
			Y = y;
			Cb = cb;
			Cr = cr;
		};
		double y_is( void ){
			return Y;
		}
		double cr_is( void ){
			return Cr;
		}
		double cb_is( void ){
			return Cb;
		}
		double *y_ptr( void ){
			return &Y;
		}
		double *cr_ptr( void ){
			return &Cr;
		}
		double *cb_ptr( void ){
			return &Cb;
		}
};

YCbCr rgb_to_ycbcr( RGB* );

#endif
