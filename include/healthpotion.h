
#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

class HealthPotion {
public:
    HealthPotion(int healAmount);
    ~HealthPotion();

    void usePotion();

private:
    int healAmount;
};

#endif