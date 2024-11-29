#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


auto checkCollision = [](const sf::CircleShape& circle, const sf::RectangleShape& rect) {
    // Obtenir les positions et dimensions des objets
    sf::FloatRect circleBounds = circle.getGlobalBounds();
    sf::FloatRect rectBounds = rect.getGlobalBounds();
    return circleBounds.intersects(rectBounds);
    };

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Gestion des Entrées");

    // Déclaration du cercle principal (ballon magenta)
    sf::CircleShape shape(30); // Rayon de 30 pixels
    shape.setFillColor(sf::Color::Magenta);
    shape.setPosition(500, 650);

    sf::CircleShape shape2(30); // Rayon de 30 pixels
    shape2.setFillColor(sf::Color::Blue);
    shape2.setPosition(100, 650);
    


    bool Attack = false;

    sf::RectangleShape shape1(sf::Vector2f(30.f, 30.f)); // Largeur = 100, Hauteur = 50
    shape1.setFillColor(sf::Color::Green); // Couleur du rectangle
    shape1.setPosition(500, 200); 

    // Vecteur pour stocker les cercles rouges (shape1)
    std::vector<sf::CircleShape> redCircles;

    bool spacePressed = false; // Variable pour savoir si la touche Space est enfoncée

    while (window.isOpen()) {
        sf::Event event;
        shape2.move(0.02, 0);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Vérifier si les touches Right et Left sont enfoncées
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            shape.move(0.05, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            shape.move(-0.05, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            Attack = true;
            shape.move(-0.09, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            Attack = true;
            shape.move(0.09, 0);
        }


        // Vérifier si la touche Space est enfoncée
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !spacePressed) {
            spacePressed = true; // Définir l'état de Space comme enfoncé

            // Créer un nouveau cercle rouge à la position actuelle du cercle magenta
            sf::CircleShape newCircle(20); 
            newCircle.setFillColor(sf::Color::Red);
            newCircle.setPosition(shape.getPosition());
            redCircles.push_back(newCircle); // Ajouter le cercle rouge au vecteur
            // Fonction pour vérifier si un cercle touche le rectangle
            
        }
            



        
        // Si la touche Space n'est plus enfoncée, réinitialiser l'état
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            spacePressed = false;
        }

        // Déplacer tous les cercles rouges vers le haut
        for (auto& redCircle : redCircles) {
            redCircle.move(0, -0.07);
        }

        // Effacer la fenêtre
        window.clear();

        window.draw(shape);
        window.draw(shape1);
        window.draw(shape2);
        // Dessiner tous les cercles rouges
        for (const auto& redCircle : redCircles) {
            window.draw(redCircle);
        }

        // Afficher le contenu
        window.display();
    }

    return 0;
}

