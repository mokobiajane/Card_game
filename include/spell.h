
#ifndef SPELL_H
#define SPELL_H

#include <string>

class Spell {
public:
    Spell(const std::string& name, const std::string& effect, int cost);
    ~Spell();

    void castSpell();
    std::string getName() const;

private:
    std::string name;
    std::string effect;
    int cost;
};

#endif