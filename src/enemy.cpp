
#include "enemy.h"
#include "deck.h"
#include "Player.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>

Enemy::Enemy(const std::string& name, int health, int attack)
    : name(name), health(health), attackPower(attack), stunDuration(0)
{
    deck = new Deck();
}

Enemy::~Enemy() {
    delete deck;
    for (auto c : hand) delete c;
    for (auto c : discardPile) delete c;
    for (auto e : activeEffects) delete e;
}

void Enemy::startTurn() {
    if (stunDuration > 0)
        stunDuration--;
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

void Enemy::playAITurn(Player* player) {
    if (isStunned()) {
        std::cout << name << " is stunned!\n";
        return;
    }
    if (hand.empty()) return;
    int idx = rand() % hand.size();
    Card* c = hand[idx];
    std::cout << name << " plays " << c->getName() << "\n";
    c->play(player, this);
    discardPile.push_back(c);
    hand.erase(hand.begin() + idx);
}

void Enemy::receiveDamage(int dmg) {
    health -= dmg;
}

void Enemy::setStunned(int turns) {
    stunDuration = turns;
}

bool Enemy::isStunned() const {
    return stunDuration > 0;
}

void Enemy::updateEffects() {
    for (auto it = activeEffects.begin(); it != activeEffects.end();) {
        (*it)->decrementDuration();
        if ((*it)->getDuration() <= 0) {
            delete *it;
            it = activeEffects.erase(it);
        } else ++it;
    }
}

std::string Enemy::getName() const { return name; }
int Enemy::getHealth() const     { return health; }