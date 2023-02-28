#include "model.h"
#include "events.h"

/*update*/

void update(Player *player, enum playerEvents *event)
{
    switch(player->state)
    {
        case Idle:
        {   

        }
        break;

        case Running:
        {
                    
        }
        break;

        case Jumping:
        {
            
        }
        break;

        case Crouching:
        {
            
        }
        break;

        case Attacking:
        {
            
        }
        break;

        case Super:
        {
            
        }
        break;

        default:
        break;
    }
}



void next(enum playerEvents *event)
{
    return;
}

