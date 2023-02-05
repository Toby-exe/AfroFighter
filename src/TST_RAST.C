#include <osbind.h>
#include <stdio.h>

#include "raster.h"


int main()
{
    UINT8 *base = (UINT8 *)Physbase();
	UINT32 *base_32 = (UINT32 *) Physbase();

	_fill_screen(); /*asm fill screen method*/

	Cconin();

	_clear_screen(); /*asm clear screen method*/

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

	plotHorizontal(base, 24, 1, 5);
	plotHorizontal(base, 32, 1, 8);
	

    return 0;
}

