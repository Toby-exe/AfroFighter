#include "events.h"

enum avatarStates on_move(Avatar *player, UINT16 key)
{
    enum avatarStates state = Running;

    if(key = a_KEY)
    {
        move_player(player, left);
    }
    else if(key = d_KEY)
    {
        move_player(player, right);
    }

    return state;
}


