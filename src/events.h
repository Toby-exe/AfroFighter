#ifndef EVENTS_H
#define EVENTS_H

#include "TYPES.H"
#include "MODEL.H"

enum avatarEvents { 
    jumpEv, 
    crouchEv, 
    moveEv, 
    attackEv, 
    superEv 
};

int on_move(UINT16);

#endif