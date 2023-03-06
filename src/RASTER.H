#ifndef RASTER_H
#define RASTER_H

#include <stdio.h>
#include "types.h"
#include "fonts.h"


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

/* [TO DO] the functions below are examples. Replace them! */


void plot_pixel(UINT8 *, int, int);

/*Lines*/
void plotHorizontal(UINT8 *, int, int, int);
void plotVertical(UINT8 *, int, int, int);
void plotByte(UINT8 *, int, int);


/*Shapes*/
void plotRect(UINT8 *, int, int, int, int);
void plotRectFill(UINT8 *, int, int, int, int);

/*Bitmaps*/
void plotBitmap8(UINT8 *, int, int, const UINT8 *, unsigned int, unsigned int);
void plotBitmap16(UINT16 *, int, int, const UINT16 *, unsigned int, unsigned int);
void plotBitmap32(UINT32 *, int, int, const UINT32 *, unsigned int, unsigned int);
void plotBitmap16_advncd(UINT16 *, int, int, const UINT16 *, unsigned int);
/*Text*/
void printCharacter(UINT8 *, int, int, char);
void printString(UINT8 *, int, int, int, const char[]);

/*ASM Subroutines*/
void clear_screen(UINT8 *);
void fill_screen(UINT8 *);

#endif
