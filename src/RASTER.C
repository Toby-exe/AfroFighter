#include "raster.h"
#include "fonts.h"



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

void printCharacter(UINT8 *base, int x, int y, char c)
{	
	int i;
	const UINT8 *hexOfChar = CUSTOMFONT_START(c);
	for (i = 0; i < FONT_HEIGHT; i++)
	{
		*(base + (y + i) * 80 + (x >> 3)) = *hexOfChar;
		hexOfChar++;
	}
}

void printString(UINT8 *base, int x, int y, int spacing, const char string[])
{
	int i;
	for(i = 0; string[i] != '\0'; i++)
	{
		printCharacter(base, x, y, string[i]);
		x += spacing;
	}
}

void plotBitmap8 (UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height, unsigned int width) {
	
	int w, h, i;
	base = base + y * 80 + (x >> 3);

	i = 0;
	for (h = 0; h < height; h++) {
		for (w = 0; w < width; w++) {
			*(base + (h * 80) + w) = bitmap[i];	
			i++;
		}
	}
}

void plotBitmap16 (UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height, unsigned int width) {
	
	int w, h, i;
	base = base + y * 40 + (x >> 4);

	i = 0;
	for (h = 0; h < height; h++) {
		for (w = 0; w < width; w++) {
			*(base + (h * 40) + w) = bitmap[i];	
			i++;
		}
	}
}

void plotBitmap32 (UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height, unsigned int width) {
	
	int w, h, i;
	base = base + y * 20 + (x >> 5);

	i = 0;
	for (h = 0; h < height; h++) {
		for (w = 0; w < width; w++) {
			*(base + (h * 20) + w) = bitmap[i];	
			i++;
		}
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
