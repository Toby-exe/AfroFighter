#ifndef RASTER_H
#define RASTER_H

#include <stdio.h>
#include "types.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

/* [TO DO] the functions below are examples. Replace them! */
enum shades_8bit {
	black = 0xFF,
	white = 0x00,
	lightGray = 0x55,
	darkGray = 0xAA,
};

void plot_pixel(UINT8 *, int, int);

/*Lines*/
void plotHorizontal(UINT8 *, int, int, int, enum shades_8bit shade);
void plotVertical(UINT8 *, int, int, int, enum shades_8bit shade);
void plotByte(UINT8 *, int, int, enum shades_8bit shade);
void plot_line();

/*Shapes*/
void plotRect(UINT8 *, int, int, int, int, enum shades_8bit shade);
void plotRectFill(UINT8 *, int, int, int, int, enum shades_8bit shade);

/*Bitmaps*/
void plotBitmap8(UINT8 *, int, int, const UINT8 *, unsigned int);
void plotBitmap16(UINT16 *, int, int, const UINT16 *, unsigned int);
void plotBitmap32(UINT32 *, int, int, const UINT32 *, unsigned int);

/*scales of threshold black*/
void clearScreen(UINT32 *);
void blackOut(UINT32 *);
void greyOutL4(UINT32 *);
void greyOutL3(UINT32 *);
void greyOutL2(UINT32 *);
void greyOutL1(UINT32 *);

#endif
