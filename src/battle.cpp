
#include "battle.h"
#include <iostream>

Battle::Battle() {}

Battle::~Battle() {}

void Battle::startBattle() {
    std::cout << "\n*** Battle Initialized: Duel in the Ruins ***\n";
}

void Battle::endBattle() {
    std::cout << "\n*** Battle Concluded ***\n";
}