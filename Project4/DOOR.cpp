#include "DOOR.h"


Door::Door(float x, float y) {

    shape.setSize(sf::Vector2f(200.f, 200.f));
    shape.setPosition(x, y);
};

void Door::draw(sf::RenderWindow& window) {
    texture.loadFromFile("textures/door.png");
    shape.setTexture(&texture);
    window.draw(shape);
};


sf::RectangleShape& Door::getShape() {
    return shape;
};