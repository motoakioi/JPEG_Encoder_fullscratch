#ifndef MCU_H
#define MCU_H

#include"rgb_ycbcr.h"

class block8x8{
	private:
		double val[8][8];
	public:
		block8x8( void ){};
		void set_val( int x, int y, double *in_val ){
			val[x][y] = *in_val;
		};
		void path_to( double out[8][8] ){
			memcpy( out, val, sizeof(val) );
		}
		void show(void){
			for ( int x = 0; x < 8; x++ ){
				for ( int y = 0; y < 8; y++ ){
					std::cout << val[x][y] << " ";
				}
				std::cout<<std::endl;
			}
		}
/*		void set_all( double in_all[8][8] ){
			&val = &in_all;
		}*/
};

class mcu{
	private:
	public:
		mcu( void ){};
		void set_block( int, int, YCbCr* );
		void ys(void){y_block[0][0].show();};
		void bs(void){cb_block.show();};
		void rs(void){cr_block.show();};
		block8x8 y_block[2][2];
		block8x8 cb_block;
		block8x8 cr_block;
};
void mcu::set_block( int mcu_x, int mcu_y, YCbCr *in_ycbcr){
	y_block[ mcu_x / 8 ][ mcu_y / 8 ].set_val( mcu_x % 8, mcu_y % 8, in_ycbcr->y_ptr() );

	// In case of 4:2:0
	if ( mcu_x % 2 == 0 && mcu_y % 2 == 0){
		cb_block.set_val( (mcu_x / 2) % 8, (mcu_y / 2) % 8, in_ycbcr->cb_ptr() );
		cr_block.set_val( (mcu_x / 2) % 8, (mcu_y / 2) % 8, in_ycbcr->cr_ptr() );
	}

}

#endif
