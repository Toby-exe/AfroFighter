#include "model.h"

void initPlayer(Player *player, int x, int y)
{
    player->state = Idle;
    player->x = x;
    player->y = y;
}



void initBar(Bar *bar, int health, char *name, UINT8 *pfpBitmap, int x, int y)
{
    bar->health = health;
    strcpy(bar->name, name);
    bar->pfpBitmap = pfpBitmap;
    bar->x = x;
    bar->y = y;
    /*as defined by specifications*/
    bar->barWidth = 248;
    bar->barHeight = 36;
}



