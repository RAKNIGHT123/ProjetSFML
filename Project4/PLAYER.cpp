#include "Player.h"


Player::Player(float x, float y) {
    shape.setSize(sf::Vector2f(50.f, 50.f));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(x, y);
}

void Player::update(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (shape.getPosition().x + shape.getSize().x < 1500) {
            shape.move(0.06f, 0);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (shape.getPosition().x > 0) {
            shape.move(-0.06f, 0);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (shape.getPosition().y > 0) {
            shape.move(0, -0.06f);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (shape.getPosition().y + shape.getSize().y < 1000) {
            shape.move(0, 0.06f);
        }
    }

}


void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::RectangleShape& Player::getShape() {
    return shape;
}