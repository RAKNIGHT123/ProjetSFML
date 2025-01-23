#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>

class Wall {
public:    
    Wall(float x, float y);
    sf::Texture texture;
    virtual void draw(sf::RenderWindow& window);

    sf::RectangleShape& getShape();

protected:
    sf::RectangleShape shape;
};
#endif
