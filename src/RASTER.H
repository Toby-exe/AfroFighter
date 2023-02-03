#ifndef RASTER_H
#define RASTER_H

#include "types.h"
my balls
/* [TO DO] the functions below are examples. Replace them! */
void clear_screen();
void plot_pixel(UINT8 *, int, int);

/*Lines*/
void plot_horizontal(UINT8 *, int, int, int);
void plot_vertical(UINT8 *, int, int, int);
void plot_byte(UINT8 *, int, int);
void plot_line();

/*Shapes*/
void plot_rect();
void plot_rectFill();

/*Bitmaps*/
void plot_bitmap_8(UINT8 *, int, int, const UINT8 *, unsigned int);
void plot_bitmap_16(UINT16 *, int, int, const UINT16 *, unsigned int);
void plot_bitmap_32(UINT32 *, int, int, const UINT32 *, unsigned int);

void plot_something_1(UINT16 *base, int x, int y, ...);
void plot_something_2(UINT32 *base, int x, int y, ...);

#endif
