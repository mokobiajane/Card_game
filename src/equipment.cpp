
#include "equipment.h"
#include <iostream>

Equipment::Equipment(const std::string& type, int effect)
    : type(type), effect(effect) {}

Equipment::~Equipment() {}

std::string Equipment::getType() const {
    return type;
}

int Equipment::getEffect() const {
    return effect;
}

void Equipment::equip() {
    std::cout << "Equipping " << type << " with effect value " << effect << ".\n";
}