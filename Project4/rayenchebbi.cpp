#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Gestion des Entrées");
    sf::Clock clock;  // Chronomètre pour mesurer le temps écoulé

    // Joueur 
    sf::RectangleShape shape1(sf::Vector2f(50.f, 50.f));
    shape1.setFillColor(sf::Color::Green);
    shape1.setPosition(500, 500);

    // Ennemi (Magenta)
    sf::RectangleShape shape2(sf::Vector2f(30.f, 30.f));
    shape2.setFillColor(sf::Color::Magenta);
    shape2.setPosition(500, 100);

    bool hasStartedMovingDown = false;  // Variable pour suivre si shape2 doit descendre

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Déplacer le joueur (shape1)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if (shape1.getPosition().x + shape1.getSize().x < window.getSize().x) {
                shape1.move(0.06f, 0);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if (shape1.getPosition().x > 0) {
                shape1.move(-0.06f, 0);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if (shape1.getPosition().y > 0) {
                shape1.move(0, -0.06f);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if (shape1.getPosition().y + shape1.getSize().y < window.getSize().y) {
                shape1.move(0, 0.06f);
            }
        }

        // Déplacement de l'ennemi (shape2)
        sf::Clock clock1;
        sf::Clock clock2;
        sf::Clock clock3;

        if (clock1.getElapsedTime().asSeconds() >= 2.0f) {
            shape2.move(0, 0.05);
        }
        if (clock2.getElapsedTime().asSeconds() >= 3.0f) {
            shape2.move(0.05, 0);
            clock1.restart();
        }
        if (clock3.getElapsedTime().asSeconds() >= 7.0f) {
            shape2.move(-0.05, 0);
            clock1.restart();
            clock2.restart();
            clock3.restart();
        }
        else {
            shape2.move(0.01, 0);
        }

        // Vérification de la collision entre shape1 (joueur) et shape2 (magenta)
        if (shape1.getGlobalBounds().intersects(shape2.getGlobalBounds())) {
            // Si une collision est détectée, on fait disparaître shape1
            shape1.setPosition(-100, -100);  // Déplacer le rectangle vert hors de la fenêtre (disparaître)
        }

        // Rendu
        window.clear();
        window.draw(shape1);  // Dessiner shape1 (qui disparaît après collision)
        window.draw(shape2);  // Dessiner shape2
        window.display();
    }

    return 0;
}


        
    
        
    
