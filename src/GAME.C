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
    input = Cnecin();

    switch (input) {
        case q_KEY:
            gameIsRunning = 0;
            break;

        case a_KEY:
            update(&model->player, Running, input);
            break;
    
        default:
            break;
    }
}

