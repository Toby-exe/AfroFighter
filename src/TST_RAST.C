#include <osbind.h>
#include <stdio.h>

#include "raster.h"


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

	/*
	plotHorizontal(base, 2, 24, 5);
	plotHorizontal(base, 3, 108, 8);

	plot_pixel(base, 24, 4);	
	plot_pixel(base, 108, 7);	
	
	plot_pixel(base, 2, 4);	
	plot_pixel(base, 3, 7);	

	plotVertical(base, 10, 24, 108);
	*/

	/*plot a 5 different rectangele that do not touch each other*/

	plotRect(base, 10, 10, 20, 20);

	plotRect(base, 10, 30, 30, 40);

	plotRect(base, 20, 20, 80, 30);

	plotRectFill(base, 50, 50, 60, 60);

	


	


	
    return 0;
}
