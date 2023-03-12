#include "events.h"
#include "types.h"
#include "model.h"

/*void update(Model *model, enum gameStates state) <--- parameters for the game state machine*/
void update (Avatar *player, enum avatarEvents newEvent, UINT16 input)
{
    /*stuff that always happens should go here*/

    switch(player->state)   
    {
        case Idle:
            player->state = checkIdleNext(player, newEvent, input);
            break;

        case Running:
            player->state = Idle;
            
            if (newEvent == Running) {
                player->state = on_move(player, input);
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
                /*player->state = on_crouch();*/
            }
            break;

        case Attacking:
            player->state = Idle;
            
            if (newEvent == Running) {
                if (input == 'J') {
                    /*player->state = on_light();*/
                } else if (input == 'L') {
                    /*player->state = on_heavy();*/
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

enum avatarStates checkIdleNext(Avatar *player, enum avatarEvents event, UINT16 input) {
    switch(event)
    {
        case moveEv:
            return on_move(player, input);
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


