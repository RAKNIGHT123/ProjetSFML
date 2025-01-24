#include "Player.h"


Player::Player(float x, float y) {
    shape.setSize(sf::Vector2f(100.f, 100.f));
    
    shape.setPosition(x, y);
}

void Player::update(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (shape.getPosition().x + shape.getSize().x < 18000) {
            shape.move(1.0f, 0);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (shape.getPosition().x > 0) {
            shape.move(-1.0f, 0);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (shape.getPosition().y > 0) {
            shape.move(0, -1.0f);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (shape.getPosition().y + shape.getSize().y < 1000) {
            shape.move(0, 1.0f);
        }
    }

}
void Player::not_move(float deltaTime) {
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (m = 1) {
            shape.move(-1.0f, 0);
            m = 0;

        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (m = 0) {
            shape.move(-1.0f, 0);
            m = 1;

        }
    }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                if (m = 1) {
                    shape.move(1.0f, 0);
                    m = 0;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                if (m = 0) {
                    shape.move(1.0f, 0);
                    m = 1;
                }
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if (n = 1) {
                shape.move(0, 1.0f);
                n = 0;
                
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if (n = 0) {
                shape.move(0, 1.0f);
                n = 1;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if (n = 1) {
                shape.move(0, -1.0f);
                n = 0;
                
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if (n = 0) {
                shape.move(0, -1.0f);
                n = 1;
            }
        }
}

void Player::draw(sf::RenderWindow& window) {
    texture.loadFromFile("textures/player.png");
    shape.setTexture(&texture);
    window.draw(shape);
}

sf::RectangleShape& Player::getShape() {
    return shape;
}