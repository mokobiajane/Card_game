

#include "quest.h"
#include <iostream>

Quest::Quest(const std::string& description, const std::string& reward)
    : description(description), reward(reward) {}

Quest::~Quest() {}

void Quest::completeQuest() {
    std::cout << "Quest completed: " << description << ". Reward: " << reward << std::endl;
}