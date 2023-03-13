#ifndef EVENTS_H
#define EVENTS_H

#include <osbind.h>
#include "TYPES.H"
#include "model.h"

enum avatarEvents { 
    moveEv, 
    jumpEv, 
    crouchEv, 
    attackEv, 
    superEv,
    noEv 
};

int on_move(Avatar *, UINT16);

#endif