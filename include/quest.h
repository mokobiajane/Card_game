
#ifndef QUEST_H
#define QUEST_H

#include <string>

class Quest {
public:
    Quest(const std::string& description, const std::string& reward);
    ~Quest();

    void completeQuest();

private:
    std::string description;
    std::string reward;
};

#endif