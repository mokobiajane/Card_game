
#include "mana.h"
#include <iostream>

Mana::Mana(int currentMana, int maxMana)
    : currentMana(currentMana), maxMana(maxMana) {}

Mana::~Mana() {}

void Mana::restoreMana(int amount) {
    currentMana += amount;
    if(currentMana > maxMana) {
        currentMana = maxMana;
    }
    std::cout << "Mana restored by " << amount << ". Current mana: " << currentMana << "\n";
}

int Mana::getCurrentMana() const {
    return currentMana;
}

int Mana::getMaxMana() const {
    return maxMana;
}