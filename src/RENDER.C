#include "render.h"

void render(Model *model) {
    switch(model->player.state) {
        case Idle:
            renderAvatarIdle(&model->player);
            break;
     /*
        case Running:
            renderAvatarRunning(&model->player);
            break;
        case Jumping:
            renderAvatarJumping(&model->player);
            break;
        case Crouching:
            renderAvatarCrouching(&model->player);
            break;
        case Attacking:
            renderAvatarAttacking(&model->player);
            break;
        case Super:
            renderAvatarSuper(&model->player);
            break;
     */
        default:
            break;
    }
}

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

