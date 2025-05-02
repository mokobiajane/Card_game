#include <iostream>

#include "cardgame.h"
#include "GameWindow.h"

int main() {
    CardGame game;

    GameWindow gw(800, 600, "Card RPG");
    gw.run(game);
    game.startGame();
    return 0;
}


