#include "TYPES.H"
#include "model.h"
#include "render.h"
#include "game.h"
#include <osbind.h>

UINT32 getTime() {
    long old_ssp;
    long timeNow;
    long *timer = (long *) 0x462;

    old_ssp = Super(0);
    timeNow = *timer;
    Super(old_ssp);

    return timeNow;
}

int main () {

    Model model;
    UINT32 timeThen, timeNow, timeDelta;
    UINT8 *base = (UINT8 *) Physbase();
    bool rendering = true;
    unsigned int input;

    
    initPlayer(&model.player, 200, 300);

    clear_screen(base);
    while (rendering == true) {
        timeNow = getTime();
        timeDelta = timeNow - timeThen;

        if(Cconis()) {
            input = Cnecin();
        }
        
        if (input == q_KEY) {
            rendering = false;
        }

        if(timeDelta > 25) {
            clear_screen(base);
            renderAvatarIdle(&model.player); 
            timeThen = timeNow;
        }   
    }

    return 0;
}