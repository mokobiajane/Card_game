
#ifndef MANA_H
#define MANA_H

class Mana {
public:
    Mana(int currentMana, int maxMana);
    ~Mana();

    void restoreMana(int amount);
    int getCurrentMana() const;
    int getMaxMana() const;

private:
    int currentMana;
    int maxMana;
};

#endif