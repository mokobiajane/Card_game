
#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>

class Equipment {
public:
    Equipment(const std::string& type, int effect);
    ~Equipment();

    std::string getType() const;
    int getEffect() const;
    void equip();

private:
    std::string type;
    int effect;
};

#endif