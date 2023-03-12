#include "model.h"

enum avatarEvents { 
    jumpEv, 
    crouchEv, 
    moveEv, 
    attackEv, 
    superEv 
};

enum avatarStates on_move ();
enum avatarStates on_heavy ();
enum avatarStates on_light ();
