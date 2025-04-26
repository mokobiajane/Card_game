
#ifndef CARD_H
#define CARD_H

#include <string>

class Player;
class Enemy;

class Card {
public:
    Card(const std::string& name, const std::string& type, int cost);
    virtual ~Card();

    std::string getName() const;
    std::string getType() const;
    int getCost() const;


    virtual void play(Player* player, Enemy* enemy) = 0;

protected:
    std::string name;
    std::string type;
    int cost;
};


Card* createCardByName(const std::string& cardName);

#endif