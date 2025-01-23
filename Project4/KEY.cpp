#include "KEY.h"


Key::Key(float x, float y) {
    isVisible = true;
    shape.setSize(sf::Vector2f(100.f, 80.f));
    
    shape.setPosition(x, y);

};


void Key::setVisibility(bool visible) {
    isVisible = visible;
};


bool Key::getVisibility() const {
    
    return isVisible;
};


void Key::draw(sf::RenderWindow& window) {
    texture.loadFromFile("textures/key.png");
    shape.setTexture(&texture);
    if (isVisible) {
        window.draw(shape);
    }
};


sf::RectangleShape& Key::getShape() {
    return shape;
};

