#ifndef KEY_H
#define KEY_H

#include <SFML/Graphics.hpp>

class Key {
public:
    bool isVisible;
    Key(float x, float y);
    sf::Texture texture;
    void setVisibility(bool visible);

    bool getVisibility() const;

    virtual void draw(sf::RenderWindow& window);

    sf::RectangleShape& getShape();

protected:
    sf::RectangleShape shape;
};
#endif
