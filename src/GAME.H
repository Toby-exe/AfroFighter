#ifndef GAME_H
#define GAME_H

#include <osbind.h>
#include <stdio.h>
#include "raster.h"
#include "sprites.h"
#include "plyrsm.h"
#include "events.h"
#include "render.h"

void gameLoop();
void processAsync(Model *model);
void processSync();

#endif