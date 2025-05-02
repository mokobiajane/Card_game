
#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

class Deck {
public:
    Deck();
    ~Deck();

    void addCard(Card* card);
    void shuffle();
    Card* drawCard();
    bool isEmpty() const;

private:
    std::vector<Card*> cards;
};

#endif