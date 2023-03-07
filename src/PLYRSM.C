#include "model.h"
#include "events.h"

/*update*/

/*void update(Model *model)*/
void update(Player *player, Event event)
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



enum playerStates next(enum playerEvents *event) {
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

