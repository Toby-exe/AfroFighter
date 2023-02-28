#include "model.h"

void initPlayer(Player *player, int x, int y)
{
    player->state = Idle;
    player->x = x;
    player->y = y;
}
