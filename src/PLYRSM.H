#ifndef PLYRSM_H
#define PLYRSM_H

#include "events.h"
#include "types.h"
#include "model.h"

enum avatarStates checkIdleNext(Avatar *, enum avatarEvents, UINT16);
void update(Avatar *, enum avatarEvents, UINT16);

#endif
