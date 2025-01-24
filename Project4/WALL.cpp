#include "WALL.h"


Wall::Wall(float x, float y) {
   
    shape.setSize(sf::Vector2f(50.f, 50.f));
    shape.setPosition(x, y);
};

void Wall::draw(sf::RenderWindow& window) { 
    texture.loadFromFile("textures/block.png");
    shape.setTexture(&texture);
        window.draw(shape);
};


sf::RectangleShape& Wall::getShape() {
    return shape;
};
