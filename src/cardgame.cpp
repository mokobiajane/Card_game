#include "cardgame.h"
#include "deck.h"
#include "card.h"
#include <cstdlib>
#include <ctime>

CardGame::CardGame() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    player = new Player("Tharion", 40, 2);
    enemy  = new Enemy("Velkra", 35, 7);

    auto populateDeck = [&](Deck* deck){
        deck->addCard(createCardByName("BattleCry"));
        deck->addCard(createCardByName("PowerStrike"));
        deck->addCard(createCardByName("Defend"));
        deck->addCard(createCardByName("HealingPotion"));
        deck->addCard(createCardByName("ArmorUp"));
        deck->addCard(createCardByName("ShieldBash"));
        deck->shuffle();
    };

    populateDeck(player->deck);
    populateDeck(enemy->deck);

    for (int i = 0; i < 3; ++i) {
        player->startTurn();
        enemy->startTurn();
    }
}

CardGame::~CardGame() {
    delete player;
    delete enemy;
}

void CardGame::startGame() {
}