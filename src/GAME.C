#include "game.h"

bool gameIsRunning = true;
int CLEAR_TIMER = 0;

void gameLoop() {

    UINT8 *base = (UINT8 *) Physbase();
	UINT16 *base_16 = (UINT16 *) Physbase();
	UINT32 *base_32 = (UINT32 *) Physbase();
    Model model;

    initPlayer(&model.player, 420, 112);

    clear_screen(base);

    while (gameIsRunning != false) {
        processAsync(&model);
        processSync(&model);

        /*profile pic box*/
        plotRect(base, 48, 48, 5, 5);
        plotRect(base, 48, 48, 587, 5);

        /*health bar*/
        plotRectFill(base, 250, 24, 54, 8);
        plotRectFill(base, 250, 24, 336, 8);

        /*player name box*/
        plotRect(base, 96, 16, 53, 31);
        plotRect(base, 96, 16, 491, 31);

        /*arena base/floor*/
        plotRectFill(base, 640, 48, 0, 354);
    }
    return;
}

void processSync(Model *model) {

    UINT8 *base = (UINT8 *) Physbase();
    long old_ssp;
    long *timer = 0x462;
    UINT32 then, now, elapsed;

    old_ssp = Super(0); /* enter privileged mode */
    now = *timer;
    Super(old_ssp);     /* exit privileged mode as soon as possible */

    elapsed = now - then;
    if (elapsed > 0)
    {
        /* trigger synchronous events based on timeElapsed */
        clear_screen(base);
        /* render model */
        then = now;
    } 
}

void processAsync(Model *model) {
    unsigned int input = space_KEY;
    enum avatarEvents newEvent = noEv;

    if(Cconis()){
        input = Cnecin();
    }

    switch (input) {
        case q_KEY:
            gameIsRunning = false;
            break;

        case a_KEY:
            newEvent = moveEv;
            break;

        default:
            break;
    }

    if(gameIsRunning != false) {
        update(&model->player, newEvent, input);
    }

    /*clear_game()*/
    /*render_game(Model *model, void* base) <-- void base allows us to
    select between byte, word, longword as needed*/
}

