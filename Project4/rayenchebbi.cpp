#include <SFML/Graphics.hpp>
#include "ENEMY.h"
#include <vector>
#include "PLAYER.h"
#include "OBJECT.h"
#include "KEY.h"
#include "WALL.h"
#include "DOOR.h"
#include <iostream>

using namespace sf;
int a = 0;
int T[21][40] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};





int main() {
    sf::RectangleShape shape5(sf::Vector2f(1800, 1000));
    
    shape5.setPosition(0, 0);
    sf::RenderWindow window(sf::VideoMode(1800, 950), "Gestion des Ennemis");
    Texture b;
    if (!b.loadFromFile("textures/bc.png")) { std::cout << "Erreur lors du chargement de texture du joueur" << std::endl; return -1; }
    shape5.setTexture(&b);
   
    EnemyShape2 enemy2(-500.f, -100.f);
    EnemyShape3 enemy3(-600.f, -200.f);
    EnemyShape4 enemy4(600.f, 400.f);

   
    

    Player player(400.f, 500.f);
    std::vector<Wall*> walls;
   
    
    Door door(30.f, 30.f);
    Object Object(1600.f, 700.f);
    Key Key(1300.f, 200.f);
    std::vector<Enemy*> enemies;

    std::vector<EnemyShape4*> enemiesAttack;
    enemies.push_back(&enemy2);  
    enemies.push_back(&enemy3); 
    //enemies.push_back(&enemy4);  
    
    sf::Clock clock;

    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 40; j++) {
            if (T[i][j] == 1)
                walls.push_back(new Wall(j * 50.f, i * 50.f));
            if (T[i][j] == 2)
                enemies.push_back(new EnemyShape2(j * 50.f, i * 50.f));
            if (T[i][j] == 3)
                enemies.push_back(new EnemyShape3(j * 50.f, i * 50.f));
            if (T[i][j] == 4)
                enemiesAttack.push_back(new EnemyShape4(j * 50.f, i * 50.f));
            
        }
    }

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
        } for (auto& enemy : enemiesAttack) {
            enemy->update(deltaTime);
        }
        if (clock.getElapsedTime().asSeconds() >= 2.0f) {
            player.s = 0;
        }

        if (player.getShape().getGlobalBounds().intersects(Key.getShape().getGlobalBounds())) {
            Key.setVisibility(false);
            a = 1;
        }
        if (player.getShape().getGlobalBounds().intersects(door.getShape().getGlobalBounds())) {
            
            if (a = 1)
                player.getShape().setPosition(-100.f, -100.f);
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
            else;
            player.getShape().setPosition(-100.f, -100.f);
        }
        if (player.getShape().getGlobalBounds().intersects(enemy3.getShape().getGlobalBounds())) {
            if (player.s == 1) {
                enemy3.getShape().setPosition(-100.f, -100.f);
            }
            else;
            player.getShape().setPosition(-100.f, -100.f);
        }
        if (player.getShape().getGlobalBounds().intersects(enemy4.getShape().getGlobalBounds())) {
            if (player.s == 1) {
                enemy4.getShape().setPosition(-100.f, -100.f);
            }
            else;
            player.getShape().setPosition(-100.f, -100.f);
        }
        for (auto& rect :walls) {
            if (player.getShape().getGlobalBounds().intersects(rect->getShape().getGlobalBounds())) {
            
                
                player.not_move(deltaTime);
   
            }
        }
        
        window.clear();
        window.draw(shape5);
        player.draw(window);
        door.draw(window);
        for (auto& wall : walls) {
            wall->draw(window);
        }
        Object.draw(window);
        Key.draw(window);

        for (auto& rect : enemies) {
            rect->draw(window);  
        }
        for (auto& rect : enemies) {
            rect->draw(window);
        }
            //for (auto& rect : enemy4.redRectangles) {
            //    window.draw(rect);
            //}
            //for (auto& rect : enemy4.redRectangles1) {
            //    window.draw(rect);
            //}
            //for (auto& rect : enemy4.redRectangles2) {
            //    window.draw(rect);
            //}
            //for (auto& rect : enemy4.redRectangles3) {
            //    window.draw(rect);
            //}
        for(auto& ennemi:enemiesAttack){
            ennemi->draw(window);
            for (auto& rect : ennemi->redRectangles) {
                window.draw(rect);
            }
            for (auto& rect : ennemi->redRectangles1) {
                window.draw(rect);
            }
            for (auto& rect : ennemi->redRectangles2) {
                window.draw(rect);
            }
            for (auto& rect : ennemi->redRectangles3) {
                window.draw(rect);
            }
        }
        
        window.display();
    }

    return 0;
}



