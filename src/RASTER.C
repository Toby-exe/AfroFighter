#include "raster.h"


void plotRect(UINT8 *base, int width, int height, int xPos, int yPos) {

	int x, y;

	plotHorizontal(base, xPos, xPos + width, yPos);
	plotHorizontal(base, xPos, xPos + width, yPos + height);
	plotVertical(base, yPos, yPos + height, xPos);
	plotVertical(base, yPos, yPos + height, xPos + width);
	
}

void plotRectFill(UINT8 *base, int width, int height, int xPos, int yPos) {

	int x, y;

	for(y = yPos; y < yPos + height; y++)
	{
		plotHorizontal(base, xPos, xPos + width, y);
	}
}

void plotVertical (UINT8 *base, int y1, int y2, int x) {
	/*assume y2 > y1*/
	int i, y, length;
	y = y1;
	length = y2 - y1;
	
	for(i = 0; i < length; i++)
	{
		plot_pixel(base, x, y);
		y++;
	}
}

void plotHorizontal (UINT8 *base, int x1, int x2, int y) {
    /*assume x2 > x1*/
    int i, x, remainder;
    x = x1;
    remainder = (x2 - x1) % 8;
    
    while(x <= (x1 + remainder) || x % 8 != 0)
    {
		plot_pixel(base, x, y);
        x++;
    }

	remainder = (x2 - x) / 8;

    for(i = 0; i < remainder; i++)
    {
       plotByte(base, x, y);
        x += 8; 
    }

    while(x <= x2)
    {
        /**(base + y * 80 + (x >> 3)) = 0xFF;*/  /*plot_byte*/
      	plot_pixel(base, x, y);
        x++;
    }	
}


void plotByte(UINT8 *base, int x, int y)
{
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
        *(base + y * 80 + (x >> 3)) = 0xFF;
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
			*(base_32 + y * 20 + x) = 0x00000000;
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

