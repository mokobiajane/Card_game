
#ifndef EFFECT_H
#define EFFECT_H

#include <string>

class Effect {
public:
    Effect(const std::string& name, int duration);
    ~Effect();

    std::string getName() const;
    int getDuration() const;
    void decrementDuration();

private:
    std::string name;
    int duration;
};

#endif