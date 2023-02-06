#include <osbind.h>
#include <stdio.h>

#include "raster.h"



int main()
{

    UINT8 *base = (UINT8 *)Physbase();
	UINT32 *base_32 = (UINT32 *) Physbase();
	int y, x, i;

	/*plot a rect at 416 x and 0 y that goes to 640 x and 400 y */
	clearScreen(base_32);

	plotHorizontal(base, 10, 200, 200, lightGray);
	plotRectFill(base, 100, 100, 10, 10, lightGray);
	
	Cconin();
	
    return 0;
}
  