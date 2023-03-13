#include "render.h"


void renderAvatarIdle(Avatar *player) {
    UINT16 *base_16 = (UINT16 *) Physbase();
        
    if (player->dir == right) {
        plotBitmap16(
            base_16, 
            player->x, 
            player->y, 
            idleAnimationRS[player->currFrame], 
            48, 80
        );

    } else if (player->dir == left) {
         plotBitmap16(
            base_16, 
            player->x, 
            player->y, 
            idleAnimationRS[player->currFrame], 
            48, 80
        );   
    }

    player->currFrame = (player->currFrame + 1) % 2;

    return;
}

