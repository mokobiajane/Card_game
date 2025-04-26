#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SFML/Graphics.hpp>
#include "cardgame.h"

enum TurnState { PLAYER_TURN, ENEMY_TURN, GAME_OVER };

class GameWindow {
public:
    GameWindow(int width, int height, const std::string& title);
    ~GameWindow();
    void run(CardGame& game);

private:
    sf::RenderWindow window;
    sf::Font font;
    TurnState state;
    sf::Clock turnClock;
    std::string lastAction;

    void processEvents(CardGame& game);
    void update(CardGame& game);
    void render(CardGame& game);
};

#endif