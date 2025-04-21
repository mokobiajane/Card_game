
#include "achievement.h"
#include <iostream>

Achievement::Achievement(const std::string& description, const std::string& reward)
    : description(description), reward(reward) {}

Achievement::~Achievement() {}

void Achievement::unlockAchievement() {
    std::cout << "Achievement unlocked: " << description << " Reward: " << reward << std::endl;
}

std::string Achievement::getDescription() const {
    return description;
}