#ifndef RENDER_H
#define RENDER_H

#include "types.h"
#include "sprites.h"
#include "model.h"
#include "raster.h"

/*render game*/
void render(Model *);

/*movement*/
void renderAvatarIdle(const Avatar *player, UINT16 *frame);

void renderAvatarRunning(const Avatar *player, UINT16 *frame);

void renderAvatarJumping(const Avatar *player, UINT16 *frame);

void renderAvatarCrouching(const Avatar *player, UINT16 *frame);

/*combat*/
void renderLightAttack(const Avatar *player, UINT16 *frame);

void renderHeavyAttact(const Avatar *player, UINT16 *frame);

void renderSuper(const Avatar *player, UINT16 *frame);

#endif