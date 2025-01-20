#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <vector>

using namespace sf;

int main() {
    
    sf::RenderWindow window(sf::VideoMode(1500, 1000), "Gestion des Ennemis");

   
    EnemyShape2 enemy2(500.f, 100.f);
    EnemyShape3 enemy3(600.f, 200.f);
    EnemyShape4 enemy4(700.f, 300.f);

   
    std::vector<Enemy*> enemies;
    enemies.push_back(&enemy2);  // Ajouter enemy2
    enemies.push_back(&enemy3);  // Ajouter enemy3
    enemies.push_back(&enemy4);  // Ajouter enemy4

   
    sf::Clock clock;

    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();  
        }

       
        float deltaTime = clock.restart().asSeconds();

       
        for (auto& enemy : enemies) {
            enemy->update(deltaTime);  
        }

        
        window.clear();

        
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


        
    
        
    
