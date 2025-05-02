
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "deck.h"
#include "card.h"

struct DummyCard : Card {
    DummyCard() : Card("Dummy", "Test", 0) {}
    void play(Player*, Enemy*) override {}
};

TEST_CASE("Deck add, shuffle, draw, and empty behavior", "[Deck]") {
    Deck deck;
    REQUIRE(deck.isEmpty());

    deck.addCard(new DummyCard());
    deck.addCard(new DummyCard());
    deck.addCard(new DummyCard());
    REQUIRE_FALSE(deck.isEmpty());

    Card* c1 = deck.drawCard();
    Card* c2 = deck.drawCard();
    Card* c3 = deck.drawCard();
    REQUIRE(c1);
    REQUIRE(c2);
    REQUIRE(c3);
    REQUIRE(deck.isEmpty());

    delete c1;
    delete c2;
    delete c3;
}

TEST_CASE("Deck reshuffle after empty", "[Deck]") {
    Deck deck;
    std::vector<Card*> store;
    for (int i = 0; i < 5; ++i) {
        store.push_back(new DummyCard());
        deck.addCard(store.back());
    }
    deck.shuffle();

    std::vector<Card*> discard;
    while (!deck.isEmpty()) {
        Card* c = deck.drawCard();
        REQUIRE(c);
        discard.push_back(c);
    }
    REQUIRE(deck.isEmpty());

    for (auto c : discard)
        deck.addCard(c);
    deck.shuffle();
    REQUIRE_FALSE(deck.isEmpty());

    while (!deck.isEmpty()) {
        delete deck.drawCard();
    }
}

