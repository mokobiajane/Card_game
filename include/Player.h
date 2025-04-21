
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "card.h"
#include "mana.h"
#include "effect.h"

class Deck;
class Enemy;

class Player {
public:
    Player(const std::string& name, int health, int manaVal);
    ~Player();

    void startTurn();
    void playCard(int index, Enemy* enemy);
    void receiveDamage(int damage);
    void heal(int amount);
    void addDefense(int def);

    void addAttackBonus(int bonus);
    int getAttackBonus() const;
    void resetAttackBonus();

    std::string getName() const;
    int getHealth() const;
    int getDefense() const;

    Deck* deck;
    std::vector<Card*> hand;
    std::vector<Card*> discardPile;

private:
    void updateEffects();

    std::string name;
    int health;
    int defense;
    int attackBonus; 
    Mana* mana;
    std::vector<Effect*> activeEffects;
};

#endif