#ifndef GAME_H
#define GAME_H

#include <osbind.h>
#include <stdio.h>
#include "raster.h"
#include "sprites.h"
#include "plyrsm.h"
#include "events.h"

void gameLoop();
void processAsync(Model *model);
void processSync(Model *model);

#endif