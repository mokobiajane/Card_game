
#include "effect.h"

Effect::Effect(const std::string& name, int duration)
    : name(name), duration(duration) {}

Effect::~Effect() {}

std::string Effect::getName() const {
    return name;
}

int Effect::getDuration() const {
    return duration;
}

void Effect::decrementDuration() {
    duration--;
}