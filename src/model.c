#include "model.h"

void initPlayer(Avatar *player, int x, int y)
{
    player->state = Idle;
    player->dir = right;
    player->x = x;
    player->y = y;
    player->currFrame = 0;

    /*init hitbox*/
    player->hitbox.top_left_x = player->x;
    player->hitbox.top_left_x = player->x;
    player->hitbox.width = 48;
    player->hitbox.height = 80;

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

void move_player(Avatar *player, direction dir)
{
    player->delta_x = 0;    /*set by default in case a move is out of bounds*/

    switch (dir) {
        case left:
            if (posInBounds(player->x - moveSpeed, player->y))
                player->x -= moveSpeed;
            break;

        case right:
            if (posInBounds(player->x + player->hitbox.width + moveSpeed, player->y))
                player->x += moveSpeed;
            break;
            
        default:
            break;
    }
}



