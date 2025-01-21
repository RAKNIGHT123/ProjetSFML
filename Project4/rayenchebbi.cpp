#include <SFML/Graphics.hpp>
#include "ENEMY.h"
#include <vector>
#include "PLAYER.h"
#include "OBJECT.h"

using namespace sf;

int main() {
    
    sf::RenderWindow window(sf::VideoMode(1500, 1000), "Gestion des Ennemis");

   
    EnemyShape2 enemy2(500.f, 100.f);
    EnemyShape3 enemy3(600.f, 200.f);
    EnemyShape4 enemy4(700.f, 300.f);

    Player player(400.f, 500.f);

    Object Object(700.f, 500.f);

    std::vector<Enemy*> enemies;
    enemies.push_back(&enemy2);  
    enemies.push_back(&enemy3); 
    enemies.push_back(&enemy4);  
    
    sf::Clock clock;

    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();  
        }

       
        float deltaTime = clock.restart().asSeconds();

        player.update(deltaTime);
       
        for (auto& enemy : enemies) {
            enemy->update(deltaTime);  
        }
        if (clock.getElapsedTime().asSeconds() >= 2.0f) {
            player.s = 0;
        }

        if (player.getShape().getGlobalBounds().intersects(Object.getShape().getGlobalBounds())) {
            Object.setVisibility(false);
            player.s = 1;
            clock.restart();
        }
        if (player.getShape().getGlobalBounds().intersects(enemy2.getShape().getGlobalBounds())) {
            if (player.s == 1) {
                enemy2.getShape().setPosition(-100.f, -100.f);
            }
        }
        if (player.getShape().getGlobalBounds().intersects(enemy3.getShape().getGlobalBounds())) {
            if (player.s == 1) {
                enemy3.getShape().setPosition(-100.f, -100.f);
            }
        }
        if (player.getShape().getGlobalBounds().intersects(enemy4.getShape().getGlobalBounds())) {
            if (player.s == 1) {
                enemy4.getShape().setPosition(-100.f, -100.f);
            }
        }
        
        window.clear();
      
        player.draw(window);

        Object.draw(window);

        for (auto& enemy : enemies) {
            enemy->draw(window);  
        }


        for (auto& rect : enemy4.redRectangles) {
            window.draw(rect);  
        }
        for (auto& rect : enemy4.redRectangles1) {
            window.draw(rect);  
        }
        for (auto& rect : enemy4.redRectangles2) {
            window.draw(rect);  
        }
        for (auto& rect : enemy4.redRectangles3) {
            window.draw(rect);  
        }

        
        window.display();
    }

    return 0;
}


        
    
        
    
