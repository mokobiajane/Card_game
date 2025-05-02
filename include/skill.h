
#ifndef SKILL_H
#define SKILL_H

#include <string>

class Skill {
public:
    Skill(const std::string& name, int level);
    ~Skill();

    void useSkill();

private:
    std::string name;
    int level;
};

#endif