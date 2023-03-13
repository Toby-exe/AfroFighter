#include "game.h"

UINT32 timeThen, timeNow, timeDelta;
bool gameIsRunning = true;

UINT32 getTime() {
    long old_ssp;
    long timeNow;
    long *timer = (long *) 0x462;

    old_ssp = Super(0);
    timeNow = *timer;
    Super(old_ssp);

    return timeNow;
}

void gameLoop() {

    UINT8 *base = (UINT8 *) Physbase();
	UINT16 *base_16 = (UINT16 *) Physbase();
	UINT32 *base_32 = (UINT32 *) Physbase();

    Model model;

    initPlayer(&model.player, 420, 112);
    while (gameIsRunning != false) {

        timeNow = getTime();
        timeDelta = timeNow - timeThen;

        if(timeDelta > 0) {
            processAsync(&model);
            render(&model); 
            timeThen = timeNow;
            clear_screen(base);
        } 

    }
    return;
}

void processAsync(Model *model) {
    unsigned int input;
    enum avatarEvents newEvent = Idle;

    if(Cconis()) {
        input = Cnecin();
    }

    switch (input) {
        case q_KEY:
            gameIsRunning = false;
            break;

        case a_KEY:
            newEvent = moveEv;
            break;
        
        case d_KEY:
            newEvent = moveEv;
            break;

        default:
            break;
    }

    if(gameIsRunning != false) {
        update(&model->player, newEvent, input);
    }

}

