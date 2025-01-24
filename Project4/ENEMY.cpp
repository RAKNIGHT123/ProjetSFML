#include "Enemy.h"


Enemy::Enemy(float x, float y) {
    shape.setSize(sf::Vector2f(70.f, 80.f)); 
    shape.setPosition(x, y);                  
}

void Enemy::update(float deltaTime) {
   
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(shape);  
}

sf::RectangleShape& Enemy::getShape() {
    return shape;
}

EnemyShape2::EnemyShape2(float x, float y) : Enemy(x, y) {
    
}

void EnemyShape2::update(float deltaTime) {
    
    if (moveClock.getElapsedTime().asSeconds() >= 1.0f) {
        shape.move(0.7f, 0);  
    }
    if (moveClock.getElapsedTime().asSeconds() >= 5.0f) {
        shape.move(-0.7f, 0);  
    }
    if (moveClock.getElapsedTime().asSeconds() >= 6.0f) {
        shape.move(-0.7f, 0); 
    }
    if (moveClock.getElapsedTime().asSeconds() >= 10.0f) {
        moveClock.restart();  
    }
    texture.loadFromFile("textures/1.png");
    shape.setTexture(&texture);
}
EnemyShape3::EnemyShape3(float x, float y) : Enemy(x, y) {
   
}


void EnemyShape3::update(float deltaTime) {

    if (moveClock.getElapsedTime().asSeconds() >= 1.0f) {
        shape.move(0, 1.0f);
    }
    if (moveClock.getElapsedTime().asSeconds() >= 5.0f) {
        shape.move(0, -1.0f);
    }
    if (moveClock.getElapsedTime().asSeconds() >= 6.0f) {
        shape.move(0, -1.0f);
    }
    if (moveClock.getElapsedTime().asSeconds() >= 10.0f) {
        moveClock.restart();
    }
    texture.loadFromFile("textures/1.png");
    shape.setTexture(&texture);
}
EnemyShape4::EnemyShape4(float x, float y) : Enemy(x, y) {
    
}
void EnemyShape4::update(float deltaTime) {
    shape.setSize(sf::Vector2f(150.f, 150.f));
    texture.loadFromFile("textures/2.png");
    shape.setTexture(&texture);
    if (spawnClock.getElapsedTime().asSeconds() >= 4.0f) {
        spawnClock.restart();
        //right
        sf::RectangleShape newRedRect(sf::Vector2f(30.f, 30.f));
        newRedRect.setFillColor(sf::Color::Red);
        newRedRect.setPosition(shape.getPosition().x, shape.getPosition().y);
        redRectangles.push_back(newRedRect);
        //UP
        sf::RectangleShape newRedRect1(sf::Vector2f(30.f, 30.f));
        newRedRect1.setFillColor(sf::Color::Red);
        newRedRect1.setPosition(shape.getPosition().x, shape.getPosition().y);
        redRectangles1.push_back(newRedRect1);
        //DOWN
        sf::RectangleShape newRedRect2(sf::Vector2f(30.f, 30.f));
        newRedRect2.setFillColor(sf::Color::Red);
        newRedRect2.setPosition(shape.getPosition().x, shape.getPosition().y);
        redRectangles2.push_back(newRedRect2);
        //left
        sf::RectangleShape newRedRect3(sf::Vector2f(30.f, 30.f));
        newRedRect3.setFillColor(sf::Color::Red);
        newRedRect3.setPosition(shape.getPosition().x, shape.getPosition().y);
        redRectangles3.push_back(newRedRect3);
       
    }
    //right
    for (auto& rect : redRectangles) {
        rect.move(0.7f, 0);
    }
    //UP
    for (auto& rect : redRectangles1) {
        rect.move(0, 0.7f);
    }
    //Down
    for (auto& rect : redRectangles2) {
        rect.move(0, -0.7f);
    }
    //left
    for (auto& rect : redRectangles3) {
        rect.move(-0.7f, 0);
    }
}