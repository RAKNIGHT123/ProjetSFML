#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>

class Object {
public:
    bool isVisible;
    Object(float x, float y);

    void setVisibility(bool visible);

    bool getVisibility() const;

    virtual void draw(sf::RenderWindow& window);

    sf::RectangleShape& getShape();

protected:
    sf::RectangleShape shape;
};
#endif