#include "raster.h"


void blackOut (UINT32 *base_32) {

	int x, y;

	for (y = 0; y < 400; y++) {
		for (x = 0; x < 20; x++) {
			*(base_32 + y * 20 + x) = 0xFFFFFFFF;
		}
	}
}

void greyOut_1(UINT32 *base_32) {

	int x, y;

	for (y = 0; y < 400; y++) {
		for (x = 0; x < 20; x++) {
			*(base_32 + y * 20 + x) = 0x55555555;
		}
	}
}

void greyOut_2(UINT32 *base_32) {

	int shift;
	int x, y;

	for (y = 0; y < 400; y++) {
		for (x = 0; x < 20; x++) {
			shift = (x + y) % 2;
			if (shift == 0) {
				*(base_32 + y * 20 + x) = 0x55555555;
			} else {
				*(base_32 + y * 20 + x) = 0xFFFFFFFF;
			}
		}
	}
}

void greyOut_3(UINT32 *base_32) {

	int shift;
	int x, y;

	/*make the entire screen checkered*/
	for (y = 0; y < 400; y++) {
		shift = (x + y) % 2;
		for (x = 0; x < 20; x++) {
			if (shift == 0) {
				*(base_32 + y * 20 + x) = 0x55555555;
			} else {
				*(base_32 + y * 20 + x) = 0xFFFFFFFF;
			}
		}
	}
}

void greyOut_4(UINT32 *base_32) {

	int shift;
	int x, y;

	/*make the entire screen checkered*/
	for (y = 0; y < 400; y++) {
		shift = (x + y) % 2;
		for (x = 0; x < 20; x++) {
			if (shift == 0) {
				*(base_32 + y * 20 + x) = 0x55555555;
			} else {
				*(base_32 + y * 20 + x) = 0xAAAAAAAA;
			}
		}
	}
}

