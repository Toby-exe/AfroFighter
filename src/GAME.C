#include "game.h"
#include "model.h"
#include "plyrsm.h"


int gameIsRunning = 1;

void gameLoop() {
    Model model;

    while (gameIsRunning != 0) {
        processAsync(&model);
    }
    return;
}

void processAsync(Model *model) {
    unsigned int input;
    avatarEvents newEvent;
    input = Cnecin();

    switch (input) {
        case q_KEY:
            gameIsRunning = 0;
            break;

        case a_KEY:
            newEvent = Running;
            break;
        default:
            break;
    }

    update(model->player, newEvent, input);
}

