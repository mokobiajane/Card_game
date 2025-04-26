
#include "skill.h"
#include <iostream>

Skill::Skill(const std::string& name, int level)
    : name(name), level(level) {}

Skill::~Skill() {}

void Skill::useSkill() {
    std::cout << "Using skill: " << name << " at level " << level << std::endl;
}