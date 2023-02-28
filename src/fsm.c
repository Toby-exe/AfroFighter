#include "model.h"
#include "events.h"

/*update*/

void update(Player *player, enum playerEvents *event)
{
    switch(player->state)
    {
        case Idle:
        {   
            player->state = next(event);
        }
        break;

        case Running:
        {
            player->state = next(event);
        }
        break;

        case Jumping:
        {
            player->state = next(event);
        }
        break;

        case Crouching:
        {
            player->state = next(event);
        }
        break;

        case Attacking:
        {
            player->state = next(event);
        }
        break;

        case Super:
        {
            player->state = next(event);            
        }
        break;

        default:
        break;
    }
}


enum playerStates next(enum playerEvents *event)
{
    switch(event)
    {
        case moveEv:
        {
            return Running;
        }
        break;

        case jumpEv:
        {
            return Jumping;
        }
        break;

        case crouchEv:
        {
            return Crouching;
        }
        break;

        case attackEv:
        {
            return Attacking;
        }
        break;

        case superEv:
        {
            return Super;            
        }
        break;

        default:
        {
            return Idle;
        }
        break;
    }
}

