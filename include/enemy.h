
#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <vector>
#include "card.h"
#include "effect.h"

class Deck;
class Player;

class Enemy {
public:
    Enemy(const std::string& name, int health, int attack);
    ~Enemy();

    void startTurn();
    void playAITurn(Player* player); 
    void receiveDamage(int damage);
    void setStunned(int turns);
    bool isStunned() const;

    std::string getName() const;
    int getHealth() const;

    Deck* deck;
    std::vector<Card*> hand;
    std::vector<Card*> discardPile;

private:
    void updateEffects();

    std::string name;
    int health;
    int attackPower;
    int stunDuration;
    std::vector<Effect*> activeEffects;
};

#endif