#include <osbind.h>
#include "raster.h"



int main()
{
    UINT8 *base = (UINT8 *)Physbase();
	UINT32 *base_32 = (UINT32 *) Physbase();

	blackOut(base_32);

	Cconin();

	greyOut_1(base_32);

	Cconin();

	greyOut_2(base_32);

	Cconin();

	greyOut_3(base_32);
	
	Cconin();

	greyOut_4(base_32);
	

    return 0;
}
