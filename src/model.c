#include "model.h"

void initPlayer(Player *player, int x, int y)
{
    player->state = Idle;
    player->x = x;
    player->y = y;
}

void initBar(Bar *bar, int health, char *name, UINT8 *pfpBitmap)
{
    bar->health = health;
    strcpy(bar->name, name);
    bar->pfpBitmap = pfpBitmap;
}