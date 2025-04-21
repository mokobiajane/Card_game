#include "GameWindow.h"
#include "Player.h"
#include "enemy.h"
#include <iostream>

GameWindow::GameWindow(int w, int h, const std::string& title)
  : window(sf::VideoMode(w, h), title),
    state(PLAYER_TURN),
    lastAction("Click a card to begin.")
{
    if (!font.loadFromFile("/home/jane/Desktop/Card_game/assets/arial.ttf"))
        std::cerr << "Font load error\n";
}

GameWindow::~GameWindow() {}

void GameWindow::processEvents(CardGame& game) {
    sf::Event e;
    while (window.pollEvent(e)) {
        if (e.type == sf::Event::Closed)
            window.close();

        if (state == PLAYER_TURN && e.type == sf::Event::MouseButtonPressed
            && e.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            int count = (int)game.player->hand.size();
            for (int i = 0; i < count; ++i) {
                sf::FloatRect r(50 + i*120, 400, 100, 150);
                if (r.contains((float)pos.x, (float)pos.y)) {
                    
                    Card* c = game.player->hand[i];
                    lastAction = "You played " + c->getName();
                    c->play(game.player, game.enemy);
                    game.player->discardPile.push_back(c);
                    game.player->hand.erase(game.player->hand.begin()+i);
                    state = ENEMY_TURN;
                    turnClock.restart();
                    break;
                }
            }
        }
    }
}

void GameWindow::update(CardGame& game) {
    if (state == PLAYER_TURN) {
       
    }
    else if (state == ENEMY_TURN && turnClock.getElapsedTime().asSeconds() >= 1.0f) {
        
        game.enemy->startTurn();
        game.enemy->playAITurn(game.player);
        lastAction = game.enemy->getName() + " acted.";
        
        if (game.player->getHealth() <= 0) {
            lastAction = "Defeated! Game Over.";
            state = GAME_OVER;
        } else if (game.enemy->getHealth() <= 0) {
            lastAction = "Victory! You win.";
            state = GAME_OVER;
        } else {
            game.player->startTurn();
            state = PLAYER_TURN;
        }
    }
    else if (state == GAME_OVER) {
        
    }
}

void GameWindow::render(CardGame& game) {
    window.clear();

    
    sf::Text t; t.setFont(font); t.setCharacterSize(24);
    t.setFillColor(sf::Color::White);
    t.setPosition(50,50);
    t.setString("You: " + std::to_string(game.player->getHealth())
                + "   Enemy: " + std::to_string(game.enemy->getHealth()));
    window.draw(t);

    
    sf::Text a; a.setFont(font); a.setCharacterSize(20);
    a.setFillColor(sf::Color::Yellow);
    a.setPosition(50,90);
    a.setString(lastAction);
    window.draw(a);

    
    if (state == PLAYER_TURN) {
        int count = (int)game.player->hand.size();
        for (int i = 0; i < count; ++i) {
            sf::RectangleShape r(sf::Vector2f(100,150));
            r.setPosition(50+i*120, 400);
            r.setFillColor(sf::Color(100,100,200));
            r.setOutlineColor(sf::Color::White);
            r.setOutlineThickness(2);
            window.draw(r);

            sf::Text c; c.setFont(font); c.setCharacterSize(18);
            c.setFillColor(sf::Color::White);
            c.setPosition(60+i*120, 460);
            c.setString(game.player->hand[i]->getName());
            window.draw(c);
        }
    }

    window.display();
}

void GameWindow::run(CardGame& game) {
    
    game.player->startTurn();
    game.enemy->startTurn();

    while (window.isOpen()) {
        processEvents(game);
        update(game);
        render(game);
    }
}