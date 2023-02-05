#ifndef RASTER_H
#define RASTER_H

#include <stdio.h>
#include "types.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

/* [TO DO] the functions below are examples. Replace them! */
void clear_screen();
void plot_pixel(UINT8 *, int, int);

/*Lines*/
void plotHorizontal(UINT8 *, int, int, int);
void plotVertical(UINT8 *, int, int, int);
void plotByte(UINT8 *, int, int);
void plot_line();

/*Shapes*/
void plotRect(UINT8 *, int, int, int, int);
void plotRectFill(UINT8 *, int, int, int, int);

/*Bitmaps*/
void plotBitmap8(UINT8 *, int, int, const UINT8 *, unsigned int);
void plotBitmap16(UINT16 *, int, int, const UINT16 *, unsigned int);
void plotBitmap32(UINT32 *, int, int, const UINT32 *, unsigned int);

/*scales of threshold black*/
void blackOut (UINT32 *);
void greyOutL4(UINT32 *);
void greyOutL3(UINT32 *);
void greyOutL2(UINT32 *);
void greyOutL1(UINT32 *);

#endif
