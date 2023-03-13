#include "game.h"

int main () {
    UINT8 *base = (UINT8 *) Physbase();
	UINT16 *base_16 = (UINT16 *) Physbase();
	UINT32 *base_32 = (UINT32 *) Physbase();

    clear_screen(base);
    gameLoop();
    return 0;
}