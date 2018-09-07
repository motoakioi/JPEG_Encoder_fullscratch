#ifndef RGB_YCBCR_H
#define RGB_YCBCR_H

class RGB{
	private:
	public:
		int R;
		int G;
		int B;
		RGB( int r, int g, int b ){
			R = r;
			G = g;
			B = b;
		};
};

class YCbCr{
	private:
	public:
		double Y;
		double Cb;
		double Cr;
		YCbCr( double y, double cb, double cr ){
			Y = y;
			Cb = cb;
			Cr = cr;
		};
};

YCbCr rgb_to_ycbcr( RGB );

/*
class RGB_to_CbCr: public RGB, YCbCr{
	private:
	public:
		RGB_to_CbCr ( RGB rgb_data, YCbCr ycbcr_data ) {
			ycbcr_data.Y = 1.0;
			ycbcr_data.Cb = 2.0;
			ycbcr_data.Cr = 3.0;
		};
};
*/


#endif
