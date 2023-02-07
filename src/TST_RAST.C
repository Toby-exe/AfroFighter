#include <osbind.h>
#include <stdio.h>
#include "raster.h"
#include "fonts.h"

int main()
{

    UINT8 *base = (UINT8 *)Physbase();
	UINT32 *base_32 = (UINT32 *) Physbase();
	int y, x, i;

	Cconin();

	fill_screen(base);

	Cconin();

	clear_screen(base);

	Cconin();

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
	plotBitmap8(base, 62, 36, customFont_8bit, 0);
	plotBitmap8(base, 64, 28, customFont_8bit, 1);
	
	Cconin();

    return 0;
}
  