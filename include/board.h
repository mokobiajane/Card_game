
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Player.h"
#include "enemy.h"

class Board {
public:
    Board();
    ~Board();

    void addPlayer(Player* player);
    void addEnemy(Enemy* enemy);
    void updateBoard();
    std::vector<Player*>& getPlayers();
    std::vector<Enemy*>& getEnemies();

private:
    std::vector<Player*> players;
    std::vector<Enemy*> enemies;
};

#endif