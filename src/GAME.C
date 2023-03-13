#include "game.h"

bool gameIsRunning = true;

void gameLoop() {

    UINT8 *base = (UINT8 *) Physbase();
	UINT16 *base_16 = (UINT16 *) Physbase();
	UINT32 *base_32 = (UINT32 *) Physbase();
    Model model;

    initPlayer(&model.player, 420, 112);

    while (gameIsRunning != false) {

        processAsync(&model);
        clear_screen(base);
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

void processAsync(Model *model) {
    unsigned int input;
    enum avatarEvents newEvent = Idle;
    input = Cnecin();

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

