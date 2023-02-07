#include <osbind.h>
#include <stdio.h>

#include "raster.h"
#include "font.h"



int main()
{

    UINT8 *base = (UINT8 *)Physbase();
	UINT32 *base_32 = (UINT32 *) Physbase();
	int y, x, i;

	/*plot a rect at 416 x and 0 y that goes to 640 x and 400 y */
	clearScreen(base_32);

	/*profile pic box*/
	plotRect(base, 48, 48, 5, 5);
	plotRect(base, 48, 48, 587, 5);

	/*health bar*/
	plotRectFill(base, 250, 24, 54, 8);
	plotRectFill(base, 250, 24, 336, 8);

	/*player name box*/
	plotRect(base, 96, 16, 53, 31);
	plotRect(base, 96, 16, 491, 31);

	/*arena base/floor*/
	plotRectFill(base, 640, 48, 0, 354);

	/*plot bit map with font array*/
	plotBitmap8(base, 62, 36, font, 8);
	Cconin();
	
    return 0;
}
  