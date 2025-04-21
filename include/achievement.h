
#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <string>

class Achievement {
public:
    Achievement(const std::string& description, const std::string& reward);
    ~Achievement();

    void unlockAchievement();
    std::string getDescription() const;

private:
    std::string description;
    std::string reward;
};

#endif