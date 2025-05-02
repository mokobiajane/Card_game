
#include "card.h"
#include "Player.h"
#include "enemy.h"
#include <iostream>

Card::Card(const std::string& n, const std::string& t, int c)
    : name(n), type(t), cost(c) {}

Card::~Card() {}

std::string Card::getName() const { return name; }
std::string Card::getType() const { return type; }
int Card::getCost() const         { return cost; }


class BattleCryCard : public Card {
public:
    BattleCryCard() : Card("BattleCry", "Buff", 1) {}
    void play(Player* player, Enemy* enemy) override {
        player->addAttackBonus(5);
    }
};

class PowerStrikeCard : public Card {
public:
    PowerStrikeCard() : Card("PowerStrike", "Attack", 1) {}
    void play(Player* player, Enemy* enemy) override {
        int baseDamage = 8;
        int totalDamage = baseDamage + player->getAttackBonus();
        if (enemy) {
            enemy->receiveDamage(totalDamage);
            std::cout << enemy->getName() << " received "
                      << totalDamage << " damage, health now "
                      << enemy->getHealth() << "\n";
        }
        player->resetAttackBonus();
    }
};

class DefendCard : public Card {
public:
    DefendCard() : Card("Defend", "Defense", 1) {}
    void play(Player* player, Enemy* enemy) override {
        player->addDefense(10);
        std::cout << "Gaining 10 defense.\n";
    }
};

class HealingPotionCard : public Card {
public:
    HealingPotionCard() : Card("HealingPotion", "Item", 1) {}
    void play(Player* player, Enemy* enemy) override {
        player->heal(10);
        std::cout << "Healing 10 health.\n";
    }
};

class ArmorUpCard : public Card {
public:
    ArmorUpCard() : Card("ArmorUp", "Buff", 1) {}
    void play(Player* player, Enemy* enemy) override {
        player->addDefense(3);
        std::cout << "Gaining 3 defense.\n";
    }
};

class ShieldBashCard : public Card {
public:
    ShieldBashCard() : Card("ShieldBash", "Stun", 1) {}
    void play(Player* player, Enemy* enemy) override {
        if (enemy) {
            enemy->setStunned(1);
            std::cout << enemy->getName() << " is stunned!\n";
        }
    }
};

Card* createCardByName(const std::string& cardName) {
    if (cardName == "BattleCry")    return new BattleCryCard();
    if (cardName == "PowerStrike")  return new PowerStrikeCard();
    if (cardName == "Defend")       return new DefendCard();
    if (cardName == "HealingPotion")return new HealingPotionCard();
    if (cardName == "ArmorUp")      return new ArmorUpCard();
    if (cardName == "ShieldBash")   return new ShieldBashCard();
    return nullptr;
}