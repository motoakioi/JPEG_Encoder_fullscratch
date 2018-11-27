#ifndef HUFFMAN_TABLE_H
#define HUFFMAN_TABLE_H

static const int dc_size_table[] = {
	0x0002, 0x0003, 0x0003, 0x0003, 0x0003, 
	0x0003, 0x0004, 0x0005, 0x0006, 0x0007
};
static const int dc_sign_table[] = {
	0x0000, 0x0002, 0x0003, 0x0004, 0x0005,
	0x0006, 0x000e, 0x001e, 0x003e, 0x007e 
};

#endif