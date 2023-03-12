#include "model.h"

void initPlayer(Avatar *player, int x, int y)
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

    bar->barWidth = 248;
    bar->barHeight = 36;
}

void move_player(Avatar *player, char key)
{
    if(key == 'A') {
        player->delta_x = -1;
    } else if (key == 'D') {
        player->delta_x = 1;
    }

    player->x += player->delta_x;
}



