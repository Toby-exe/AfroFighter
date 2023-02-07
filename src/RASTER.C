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

void plotBitmap8(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int size)
{
	int i;
    for (i = 8; i < 16; i++) {
        *(base + i * 80 + (x >> 4)) = bitmap[i];
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

void clearScreen(UINT32 *base_32) {

	int x, y;

	for (y = 0; y < 400; y++) {
		for (x = 0; x < 20; x++) {
			*(base_32 + y * 20 + x) = 0x00000000;
		}
	}
}

void blackOut(UINT32 *base_32) {

	int x, y;

	for (y = 0; y < 400; y++) {
		for (x = 0; x < 20; x++) {
			*(base_32 + y * 20 + x) = 0xFFFFFFFF;
		}
	}
}




