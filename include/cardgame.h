

#ifndef CARDGAME_H
#define CARDGAME_H

#include "board.h"
#include "battle.h"
#include "Player.h"
#include "enemy.h"

class CardGame {
public:
    CardGame();
    ~CardGame();

    void startGame();
    Player* player;
    Enemy* enemy;
};

#endif