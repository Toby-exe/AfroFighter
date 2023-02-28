#include "model.h"
#include "events.h"

/*update*/

/*void update(Model *model)*/
void update(Player *player, )
{
    switch(player->state)
    {
        case Idle:
        {   
            next();
        }
        break;

        case Running:
        {
            next();
        }
        break;

        case Jumping:
        {
            next();
        }
        break;

        case Crouching:
        {
            next();
        }
        break;

        case Attacking:
        {
            next();
        }
        break;

        case Super:
        {
            next();
        }
        break;

        default:
        break;

    }
}



playerState next()
{
    return;
}

