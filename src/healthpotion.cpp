
#include "healthpotion.h"
#include <iostream>

HealthPotion::HealthPotion(int healAmount)
    : healAmount(healAmount) {}

HealthPotion::~HealthPotion() {}

void HealthPotion::usePotion() {
    std::cout << "Using health potion to heal " << healAmount << " points." << std::endl;
}