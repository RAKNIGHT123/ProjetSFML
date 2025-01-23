#ifndef PLAYER_H
#define PLAYER_H
#include "Wall.h"

#include <SFML/Graphics.hpp>

class Player {
public:

    Player(float x, float y);
    int s = 0;
    int m = 1;
    int n = 1;

    virtual void update(float deltaTime);
    virtual void not_move(float deltaTime);
    virtual void draw(sf::RenderWindow& window);

    sf::RectangleShape& getShape();

protected:
    sf::RectangleShape shape;
    sf::Clock clock;
};


#endif