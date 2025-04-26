
#include "spell.h"
#include <iostream>

Spell::Spell(const std::string& name, const std::string& effect, int cost)
    : name(name), effect(effect), cost(cost) {}

Spell::~Spell() {}

void Spell::castSpell() {
    std::cout << "Casting spell: " << name << " with effect: " << effect << std::endl;
}

std::string Spell::getName() const {
    return name;
}