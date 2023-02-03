#include <osbind.h>
#include "raster.h"


int main()
{
    UINT8 *base = (UINT8 *)Physbase();
	UINT32 *base_32 = (UINT32 *) Physbase();

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

	plotRect(base, 80, 50, 320, 200);
	

    return 0;
}
