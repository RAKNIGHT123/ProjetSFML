#ifndef DOOR_H
#define DOOR_H

#include <SFML/Graphics.hpp>

class Door {
public:
    bool isVisible;
    Door(float x, float y);
    sf::Texture texture;
    void setVisibility(bool visible);

    bool getVisibility() const;

    virtual void draw(sf::RenderWindow& window);

    sf::RectangleShape& getShape();

protected:
    sf::RectangleShape shape;
};
#endif
