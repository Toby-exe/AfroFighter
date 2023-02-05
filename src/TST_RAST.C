#include <osbind.h>
#include <stdio.h>

#include "raster.h"
xref	_fill_screen
xref	_clear_screen

int main()
{
    UINT8 *base = (UINT8 *)Physbase();
	UINT32 *base_32 = (UINT32 *) Physbase();

	printf("%x", *base);
	
	Cconin();

	blackOut(base_32);

	Cconin();

	greyOutL1(base_32);

	Cconin();

	greyOutL2(base_32);

	Cconin();

	greyOutL3(base_32);
	
	Cconin();

	greyOutL4(base_32);

	Cconin();

	blackOut(base_32);

	Cconin();

	plotHorizontal(base, 2, 24, 5);
	plotHorizontal(base, 3, 108, 8);

	plot_pixel(base, 24, 4);	
	plot_pixel(base, 108, 7);	
	
	plot_pixel(base, 2, 4);	
	plot_pixel(base, 3, 7);	

    return 0;
}
