#include <osbind.h>
#include <stdio.h>
#include "raster.h"
#include "fonts.h"
#include "splash.h"

int main()
{
	
    UINT8 *base = (UINT8 *) Physbase();
	UINT16 *base_16 = (UINT16 *) Physbase();
	UINT32 *base_32 = (UINT32 *) Physbase();
	UINT16 input;
	int y, x, i;
	
	const UINT8 letterEbitmap [] = {
		0x00,0x7E,0x40,0x7C,0x40,0x40,0x7E,0x00
	};

	/*plot a rect at 416 x and 0 y that goes to 640 x and 400 y */
	fill_screen(base);
	
	Cconin();

	clear_screen(base);
	/*arena base/floor*/
	/*plotRectFill(base, 640, 48, 0, 354);*/

	/*plot bit map with font array*/
	plotBitmap16(base_16, 1, 1, avatarProfilePic, 48, 48);
	plotBitmap16(base_16, 2, 49, avatarProfilePic, 48, 48);
	plotBitmap16(base_16, 3, 97, avatarProfilePic, 48, 48);
	
	/*plot letter E*/
	plot_pixel(base, 3, 150);
	plotBitmap8(base, 3, 150, letterEbitmap, 8, 8);

	/*plot afro fighter (fix issue with greys)*/
	plotBitmap32(base_32, 64, 0, afroManTitle, 224, 400);

	Cconin();
	/*plot the avatarPP*/

    return 0;	
}
  