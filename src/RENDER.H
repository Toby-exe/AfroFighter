#ifndef RENDER_H
#define RENDER_H

#include "TYPES.H"
#include "sprites.h"
#include "model.h"
#include "raster.h"
#include "anims.h"

/*render game*/
void render(Model *);

/*movement*/
void renderAvatarIdle(Avatar *player);

#endif