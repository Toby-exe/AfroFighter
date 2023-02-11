#include <osbind.h>
#include <stdio.h>
#include "raster.h"
#include "fonts.h"
#include "splash.h"



int main()
{

    UINT8 *base = (UINT8 *)Physbase();
	UINT16 *base_16 = (UINT16 *) Physbase();
	UINT32 *base_32 = (UINT32 *) Physbase();
	int y, x, i;

	/*plot a rect at 416 x and 0 y that goes to 640 x and 400 y */
	fill_screen(base);

	Cconin();

	clear_screen(base);

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

	printString(base, 62, 36, 8, "TOBY");
	printString(base, 553, 36, 8, "TOBY");

	Cconin();

	clear_screen(base);

	plotBitmap32(base_32, 416, 0, afroManTitle, 400, 7);
	plotBitmap32(base_32, 64, 37, title, 168, 10);

	Cconin();	

	/*plot the avatarPP*/

    return 0;	
}
  