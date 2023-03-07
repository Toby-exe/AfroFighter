#include "raster.h"
#include "fonts.h"


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

void plotByte(UINT8 *base, int x, int y)
{
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
        *(base + y * 80 + (x >> 3)) = 0xFF;
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



void plotBitmap8 (UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int width, unsigned int height) {
	
	int i, h, currByte, nBytes;
	i = 0;
	nBytes = width / 8;

	/*vertical loop*/
	for (h = 0; h < height; h++)
	{
		/*single row loop*/
		for (currByte = 0; currByte < nBytes; currByte++)
		{
			*(base + y * 80 + (x >> 3) + currByte) |= bitmap[i + currByte] >> ((x + currByte * 8) % 8);
			*(base + y * 80 + (x >> 3) + currByte + 1) |= bitmap[i + currByte] << (7 - (x + currByte * 8) % 8);
		}
		i += nBytes;
		y++;
	}
}

void plotBitmap16 (UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int width, unsigned int height) {
	
	int i, h, currWord, nWords;
	i = 0;
	nWords = width / 16;

	/*vertical loop*/
	for (h = 0; h < height; h++)
	{
		/*single row loop*/
		for (currWord = 0; currWord < nWords; currWord++)
		{
			*(base + y * 40 + (x >> 4) + currWord) |= bitmap[i + currWord] >> ((x + currWord * 16) % 16);
			*(base + y * 40 + (x >> 4) + currWord + 1) |= bitmap[i + currWord] << (15 - (x + currWord * 16) % 16);
		}
		i += nWords;
		y++;
	}
}

void plotBitmap32 (UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int width, unsigned int height) {
	
	int i, h, currLong, nLongs;
	i = 0;
	nLongs = width / 32;

	/*Vertical loop*/
	for (h = 0; h < height; h++)
	{
		/*single row loop*/
		for (currLong = 0; currLong < nLongs; currLong++)
		{
			*(base + y * 20 + (x >> 5) + currLong) |= bitmap[i + currLong] >> ((x + currLong * 32) % 32);
			*(base + y * 20 + (x >> 5) + currLong + 1) |= bitmap[i + currLong] << (31 - (x + currLong * 32) % 32);
		}
		i += nLongs;
		y++;
	}
}