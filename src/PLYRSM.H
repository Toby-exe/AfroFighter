#ifndef PLYRSM_H
#define PLYRSM_H

#include "events.h"
#include "types.h"
#include "model.h"

void update(Avatar *, enum avatarEvents, UINT16);
enum avatarStates checkIdleNext(Avatar *, enum avatarEvents, UINT16);

#endif
