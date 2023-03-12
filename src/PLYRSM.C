#include "model.h"
#include "events.h"

/*update*/

/*void update(Model *model)*/
void update (Avatar *player, enum avatarEvents newEvent, char input)
{
    /*stuff that always happens should go here*/

    switch(player->state)   /*player's current state*/
    {
        case Idle:
            player->state = idleCheckNext(newEvent);
            break;

        case Running:
            player->state = Idle;
            
            if (newEvent == Running) {
                player->state = on_move();
            }
            break;

        case Jumping:
            player->state = Idle;
            
            if (newEvent == Jumping) {
                player->state = Jumping;
            }
            break;

        case Crouching:
            player->state = Idle;
            
            if (newEvent == Crouching) {
                player->state = on_crouch();
            }
            break;

        case Attacking:
            player->state = Idle;
            
            if (newEvent == Running) {
                if (input == 'J') {
                    player->state = on_light();
                } else if (input == 'K') {
                    player->state = on_heavy();
                }
            }
            break;

        case Super:
            player->state = Idle;
            
            if (newEvent == Super) {
                player->state = Super;
            }
            break;

        default:
            break;

    }
}



enum avatarStates idleCheckNext(enum avatarEvents event) {
    switch(event)
    {
        case moveEv:
            return on_move();
            break;

        case jumpEv:
            return Jumping;
            break;

        case crouchEv:
            return Crouching;
            break;

        case attackEv:
            return Attacking;
            break;

        case superEv:
            return Super;            
            break;

        default:
            return Idle;
            break;
    }
}

