#include <osbind.h>
#include <stdio.h>

#include "raster.h"


int main()
{
    UINT8 *base = (UINT8 *)Physbase();
	UINT32 *base_32 = (UINT32 *) Physbase();

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

	plotHorizontal(base, 8, 2, 5);
	

    return 0;
}
