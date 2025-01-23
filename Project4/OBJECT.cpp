#include "OBJECT.h"


Object::Object(float x, float y) {
    isVisible = true;
    shape.setSize(sf::Vector2f(100.f, 100.f));
    
    shape.setPosition(x, y);
};

 
void Object::setVisibility(bool visible) {
    isVisible = visible;
};

    
bool Object::getVisibility() const {
    return isVisible;
};

  
void Object::draw(sf::RenderWindow& window) {
    if (isVisible) {
        texture.loadFromFile("textures/potion.png");
        shape.setTexture(&texture);
        window.draw(shape);
    }
};

   
sf::RectangleShape& Object::getShape() {
    return shape;
};

