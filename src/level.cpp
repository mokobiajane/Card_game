
#include "level.h"
#include <iostream>

Level::Level(int currentLevel)
    : currentLevel(currentLevel) {}

Level::~Level() {}

void Level::levelUp() {
    currentLevel++;
    std::cout << "Level up! Current level: " << currentLevel << std::endl;
}

int Level::getCurrentLevel() const {
    return currentLevel;
}