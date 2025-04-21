
#include "deck.h"
#include <algorithm>
#include <random>
#include <chrono>

Deck::Deck() {}
Deck::~Deck() {
    for (auto c : cards) delete c;
}

void Deck::addCard(Card* card) {
    cards.push_back(card);
}

void Deck::shuffle() {
    unsigned seed = (unsigned)std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}

Card* Deck::drawCard() {
    if (cards.empty()) return nullptr;
    Card* c = cards.back();
    cards.pop_back();
    return c;
}

bool Deck::isEmpty() const {
    return cards.empty();
}