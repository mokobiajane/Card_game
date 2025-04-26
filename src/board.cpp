
#include "board.h"
#include "Player.h"
#include <iostream>

Board::Board() {
    Player* p = new Player("Jane", 40, 2);
    players.push_back(p);
}

Board::~Board() {
    for(auto player : players) {
        delete player;
    }
    for(auto enemy : enemies) {
        delete enemy;
    }
}

void Board::addPlayer(Player* player) {
    players.push_back(player);
}

void Board::addEnemy(Enemy* enemy) {
    enemies.push_back(enemy);
}

void Board::updateBoard() {
    std::cout << "Updating game board...\n";
    for(auto player : players) {
        std::cout << "Player " << player->getName() << " Health: " << player->getHealth() << "\n";
    }
    for(auto enemy : enemies) {
        std::cout << "Enemy " << enemy->getName() << " Health: " << enemy->getHealth() << "\n";
    }
}

std::vector<Player*>& Board::getPlayers() {
    return players;
}

std::vector<Enemy*>& Board::getEnemies() {
    return enemies;
}