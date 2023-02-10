#include "model.h"

void initPlayer(Player *p, int x, int y)
{
    p->state = Idle;
    p->x = x;
    p->y = y;
}
