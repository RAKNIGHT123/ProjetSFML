#include "Enemy.h"


Enemy::Enemy(float x, float y) {
    shape.setSize(sf::Vector2f(50.f, 50.f));  
    shape.setFillColor(sf::Color::Magenta);    
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
    shape.setFillColor(sf::Color::Magenta); 
}


void EnemyShape2::update(float deltaTime) {
    
    if (moveClock.getElapsedTime().asSeconds() >= 1.0f) {
        shape.move(0.02f, 0);  
    }
    if (moveClock.getElapsedTime().asSeconds() >= 3.0f) {
        shape.move(-0.02f, 0);  
    }
    if (moveClock.getElapsedTime().asSeconds() >= 5.0f) {
        shape.move(-0.02f, 0); 
    }
    if (moveClock.getElapsedTime().asSeconds() >= 7.0f) {
        moveClock.restart();  
    }
}
EnemyShape3::EnemyShape3(float x, float y) : Enemy(x, y) {
    shape.setFillColor(sf::Color::Magenta);
}


void EnemyShape3::update(float deltaTime) {

    if (moveClock.getElapsedTime().asSeconds() >= 1.0f) {
        shape.move(0, 0.02f);
    }
    if (moveClock.getElapsedTime().asSeconds() >= 3.0f) {
        shape.move(0, -0.02f);
    }
    if (moveClock.getElapsedTime().asSeconds() >= 5.0f) {
        shape.move(0, -0.02f);
    }
    if (moveClock.getElapsedTime().asSeconds() >= 7.0f) {
        moveClock.restart();
    }
}
EnemyShape4::EnemyShape4(float x, float y) : Enemy(x, y) {
    shape.setFillColor(sf::Color::Red);
}
void EnemyShape4::update(float deltaTime) {
    if (spawnClock.getElapsedTime().asSeconds() >= 2.0f) {
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
        rect.move(0.02f, 0);
    }
    //UP
    for (auto& rect : redRectangles1) {
        rect.move(0, 0.02f);
    }
    //Down
    for (auto& rect : redRectangles2) {
        rect.move(0, -0.02f);
    }
    //left
    for (auto& rect : redRectangles3) {
        rect.move(-0.02f, 0);
    }
}