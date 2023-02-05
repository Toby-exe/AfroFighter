#include "raster.h"


void plotRect(UINT8 *base, int width, int height, int xPos, int yPos) {

	int x, y;
	/*point base to correct starting position*/
	*base = *(base + yPos * 80 + xPos); 
}

void plotHorizontal (UINT8 *base, int length, int xPos, int yPos) {
	*base = 0xFF;
}

void plot_pixel(UINT8 *base, int x, int y)
{
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
        *(base + y * 80 + (x >> 3)) |= 1 << (7 - (x & 7));
    /* -----------            ^                    ^
                           (x / 8)               (x % 8)

        this is the original code in the parentheses but lsl and AND
        are faster processes than divide and mod
    */
} 

void blackOut (UINT32 *base_32) {

	int x, y;

	for (y = 0; y < 400; y++) {
		for (x = 0; x < 20; x++) {
			*(base_32 + y * 20 + x) = 0xFFFFFFFF;
		}
	}
}

void greyOutL4(UINT32 *base_32) {

	int x, y;

	for (y = 0; y < 400; y++) {
		for (x = 0; x < 20; x++) {
			*(base_32 + y * 20 + x) = 0x55555555;
		}
	}
}

void greyOutL3(UINT32 *base_32) {

	int shift;
	int x, y;

	for (y = 0; y < 400; y++) {
		for (x = 0; x < 20; x++) {
			shift = (x + y) & 2;
			if (shift == 0) {
				*(base_32 + y * 20 + x) = 0x55555555;
			} else {
				*(base_32 + y * 20 + x) = 0xFFFFFFFF;
			}
		}
	}
}

void greyOutL2(UINT32 *base_32) {

	int shift;
	int x, y;

	/*make the entire screen checkered*/
	for (y = 0; y < 400; y++) {
		shift = (x + y) & 1;
		for (x = 0; x < 20; x++) {
			if (shift == 0) {
				*(base_32 + y * 20 + x) = 0x55555555;
			} else {
				*(base_32 + y * 20 + x) = 0xFFFFFFFF;
			}
		}
	}
}

void greyOutL1(UINT32 *base_32) {

	int shift;
	int x, y;

	/*make the entire screen checkered*/
	for (y = 0; y < 400; y++) {
		shift = (x + y) & 1;
		for (x = 0; x < 20; x++) {
			if (shift == 0) {
				*(base_32 + y * 20 + x) = 0x55555555;
			} else {
				*(base_32 + y * 20 + x) = 0xAAAAAAAA;
			}
		}
	}
}

