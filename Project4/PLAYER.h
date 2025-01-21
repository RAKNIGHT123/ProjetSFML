#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:

    Player(float x, float y);
    int s = 0;

    virtual void update(float deltaTime);
    virtual void draw(sf::RenderWindow& window);

    sf::RectangleShape& getShape();

protected:
    sf::RectangleShape shape;
};


#endif