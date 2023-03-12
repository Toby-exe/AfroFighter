#ifndef EVENTS_H
#define EVENTS_H

#include <osbind.h>
#include "TYPES.H"
#include "model.h"

enum avatarEvents { 
    jumpEv, 
    crouchEv, 
    moveEv, 
    attackEv, 
    superEv 
};

int on_move(UINT16);

#endif