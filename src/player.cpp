
#include "Player.h"
#include "deck.h"
#include <iostream>
#include <algorithm>

Player::Player(const std::string& name, int health, int manaVal)
    : name(name)
    , health(health)
    , defense(0)
    , attackBonus(0)
{
    mana = new Mana(manaVal, manaVal);
    deck = new Deck();
}

Player::~Player() {
    delete mana;
    delete deck;
    for (auto c : hand) delete c;
    for (auto c : discardPile) delete c;
    for (auto e : activeEffects) delete e;
}

void Player::startTurn() {
    if (deck->isEmpty() && !discardPile.empty()) {
        for (auto c : discardPile)
            deck->addCard(c);
        discardPile.clear();
        deck->shuffle();
    }
    Card* c = deck->drawCard();
    if (c) {
        hand.push_back(c);
        std::cout << name << " drew " << c->getName() << "\n";
    }
    updateEffects();
}

void Player::playCard(int index, Enemy* enemy) {
    if (index < 0 || index >= (int)hand.size()) return;
    Card* c = hand[index];
    std::cout << name << " plays " << c->getName() << "\n";
    c->play(this, enemy);
    discardPile.push_back(c);
    hand.erase(hand.begin() + index);
}

void Player::receiveDamage(int damage) {
    int taken = damage;
    if (defense > 0) {
        if (defense >= taken) {
            defense -= taken;
            taken = 0;
        } else {
            taken -= defense;
            defense = 0;
        }
    }
    health -= taken;
}

void Player::heal(int amount) {
    health += amount;
}

void Player::addDefense(int def) {
    defense += def;
}

void Player::addAttackBonus(int bonus) {
    attackBonus += bonus;
    std::cout << name << " attack bonus increased by "
              << bonus << " to " << attackBonus << "\n";
}

int Player::getAttackBonus() const {
    return attackBonus;
}

void Player::resetAttackBonus() {
    attackBonus = 0;
}

void Player::updateEffects() {
    for (auto it = activeEffects.begin(); it != activeEffects.end();) {
        (*it)->decrementDuration();
        if ((*it)->getDuration() <= 0) {
            delete *it;
            it = activeEffects.erase(it);
        } else {
            ++it;
        }
    }
}

std::string Player::getName() const { return name; }
int Player::getHealth() const    { return health; }
int Player::getDefense() const   { return defense; }