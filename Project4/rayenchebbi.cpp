
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

auto checkCollision = [](const sf::CircleShape& circle, const sf::RectangleShape& rect) {
    sf::FloatRect circleBounds = circle.getGlobalBounds();
    sf::FloatRect rectBounds = rect.getGlobalBounds();
    return circleBounds.intersects(rectBounds);
    };

auto checkCircleCollision = [](const sf::CircleShape& circle1, const sf::CircleShape& circle2) {
    sf::Vector2f position1 = circle1.getPosition();
    sf::Vector2f position2 = circle2.getPosition();
    float distance = std::sqrt(std::pow(position2.x - position1.x, 2) + std::pow(position2.y - position1.y, 2));
    float radius1 = circle1.getRadius();
    float radius2 = circle2.getRadius();
    return distance <= (radius1 + radius2);
    };

auto checkCollision1 = [](const sf::CircleShape& circle1, const sf::RectangleShape& rect) {
    sf::FloatRect circleBounds = circle1.getGlobalBounds(); // Utiliser circle1 au lieu de circle
    sf::FloatRect rectBounds = rect.getGlobalBounds();
    return circleBounds.intersects(rectBounds);
    };

int X = rand() % 1000;
int Y = rand() % 800;

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Gestion des Entr�es");

    // D�claration du cercle principal (ballon magenta)
    sf::CircleShape shape(30); // Rayon de 30 pixels
    shape.setFillColor(sf::Color::Magenta);
    shape.setPosition(500, 650);

    sf::CircleShape shape2(30); // Rayon de 30 pixels
    shape2.setFillColor(sf::Color::Blue);
    shape2.setPosition(100, 650);

    bool Attack = false;

    sf::RectangleShape shape1(sf::Vector2f(30.f, 30.f)); // Largeur = 100, Hauteur = 50
    shape1.setFillColor(sf::Color::Green); // Couleur du rectangle
    shape1.setPosition(X, Y);

    sf::RectangleShape shape3(sf::Vector2f(30.f, 30.f)); // Largeur = 30, Hauteur = 30
    shape3.setFillColor(sf::Color::Yellow); // Couleur du rectangle
    shape3.setPosition(100, -650);

    // Vecteur pour stocker les cercles rouges (shape1)
    std::vector<sf::CircleShape> redCircles;
    // Vecteur pour stocker les cercles rouges qui apparaissent dans les rectangles jaunes
    std::vector<sf::CircleShape> redCircles1;
    // Vecteur pour stocker les rectangles bleus
    std::vector<sf::RectangleShape> blueRectangles;
    // Vecteur pour stocker les rectangles jaunes
    std::vector<sf::RectangleShape> yellowRectangles;

    bool APressed = false;
    bool SpacePressed = false; // Variable pour savoir si la touche Space est enfonc�e

    // Cr�ation d'un chronom�tre pour g�rer le spawn des cercles bleus et jaunes
    sf::Clock clock;
    sf::Clock clockYellow;
    sf::Clock clockRed; // Chronom�tre pour g�rer l'apparition des cercles rouges

    float timeSinceLastSpawnBlue = 0.f;
    float timeSinceLastSpawnYellow = 0.f;
    float timeSinceLastSpawnRed = 0.f; // Temps �coul� pour l'apparition des cercles rouges dans les rectangles jaunes

    while (window.isOpen()) {
        sf::Event event;
        shape2.move(0.02, 0); // D�placer le cercle bleu (shape2) vers la droite
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // V�rifier si les touches Right et Left sont enfonc�es
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if (shape.getPosition().x + shape.getRadius() < window.getSize().x) {
                shape.move(0.06, 0);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if (shape.getPosition().x - shape.getRadius() > 0) {
                shape.move(-0.06, 0);
            }
        }

        // D�placer chaque rectangle bleu
        for (auto& rect : blueRectangles) {
            rect.move(0.02f, 0); // D�placer le rectangle bleu vers la droite

            // R�initialiser la position du rectangle bleu lorsqu'il d�passe l'�cran
            if (rect.getPosition().x > window.getSize().x) {
                rect.setPosition(-150, rand() % 700); // R�initialise � une position � gauche de l'�cran
            }
        }

        // D�placer chaque rectangle jaune
        for (auto& rect : yellowRectangles) {
            rect.move(0.01f, 0); // D�placer le rectangle jaune vers la droite

            // R�initialiser la position du rectangle jaune lorsqu'il d�passe l'�cran
            if (rect.getPosition().x > window.getSize().x) {
                rect.setPosition(-150, rand() % 700); // R�initialise � une position � gauche de l'�cran
            }
        }

        // Chronom�tre pour cr�er un cercle rouge dans les rectangles jaunes toutes les 5 secondes
        timeSinceLastSpawnRed += clockRed.restart().asSeconds();
        if (timeSinceLastSpawnRed >= 5.f) {
            timeSinceLastSpawnRed = 0.f;

            // Cr�er un nouveau cercle rouge
            if (!yellowRectangles.empty()) {
                // Choisir un rectangle jaune au hasard
                int index = rand() % yellowRectangles.size();
                sf::CircleShape newRedCircle(20); // Rayon du cercle rouge
                newRedCircle.setFillColor(sf::Color::Red);

                // Positionner le cercle rouge au centre du rectangle jaune s�lectionn�
                sf::FloatRect rectBounds = yellowRectangles[index].getGlobalBounds();
                newRedCircle.setPosition(rectBounds.left + rectBounds.width / 2 - newRedCircle.getRadius(),
                    rectBounds.top + rectBounds.height / 2 - newRedCircle.getRadius());

                // Ajouter le cercle rouge au vecteur
                redCircles1.push_back(newRedCircle);
            }
        }

        // V�rifier si la touche Space est enfonc�e
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !APressed) {
            APressed = true; // D�finir l'�tat de Space comme enfonc�

            // Cr�er un nouveau cercle rouge � la position actuelle du cercle magenta
            sf::CircleShape newCircle(20);
            newCircle.setFillColor(sf::Color::Red);
            newCircle.setPosition(shape.getPosition());
            redCircles.push_back(newCircle); // Ajouter le cercle rouge au vecteur
        }

        // Si la touche Space n'est plus enfonc�e, r�initialiser l'�tat
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            APressed = false;
        }

        // D�placer tous les cercles rouges vers le haut
        for (auto it = redCircles.begin(); it != redCircles.end(); /* no increment */) {
            it->move(0, -0.07); // D�placer chaque cercle rouge
            // V�rifier la collision avec le rectangle
            if (checkCollision(*it, shape1)) {
                // Si une collision est d�tect�e, supprimer le cercle du vecteur
                it = redCircles.erase(it); // Supprime et retourne un it�rateur vers l'�l�ment suivant
                X = rand() % 1000;
                Y = rand() % 700;
                shape1.setPosition(X, Y);
            }
            else {
                ++it; // Si aucune collision, passer � l'�l�ment suivant
            }
        }

        // V�rifier la collision entre le cercle magenta et le rectangle vert
        if (checkCollision(shape, shape1)) {
            X = rand() % 1000;
            Y = rand() % 700;
            shape1.setPosition(X, Y);
        }

        // V�rifier si 10 secondes se sont �coul�es et cr�er un nouveau rectangle bleu
        timeSinceLastSpawnBlue += clock.restart().asSeconds(); // Calcul du temps �coul�
        if (timeSinceLastSpawnBlue >= 10.f) {
            // R�initialiser le timer
            timeSinceLastSpawnBlue = 0.f;

            // Cr�er un nouveau rectangle bleu
            sf::RectangleShape newBlueRectangle(sf::Vector2f(100, 30));
            newBlueRectangle.setFillColor(sf::Color::Blue);
            newBlueRectangle.setPosition(-200, rand() % 200); // Position al�atoire
            blueRectangles.push_back(newBlueRectangle); // Ajouter le nouveau rectangle bleu au vecteur
        }

        // V�rifier si 25 secondes se sont �coul�es et cr�er un nouveau rectangle jaune
        timeSinceLastSpawnYellow += clockYellow.restart().asSeconds(); // Calcul du temps �coul�
        if (timeSinceLastSpawnYellow >= 7.f) {  // Ajouter un rectangle jaune toutes les 7 secondes
            timeSinceLastSpawnYellow = 0.f;

            // Cr�er un nouveau rectangle jaune
            sf::RectangleShape newYellowRectangle(sf::Vector2f(60, 60));
            newYellowRectangle.setFillColor(sf::Color::Yellow);
            newYellowRectangle.setPosition(-200, rand() % 200); // Position al�atoire
            yellowRectangles.push_back(newYellowRectangle); // Ajouter le rectangle jaune au vecteur
        }

        // V�rifier les collisions entre les cercles rouges et les rectangles bleus
        for (auto& redCircle : redCircles) {
            for (auto& blueRect : blueRectangles) {
                if (checkCollision(redCircle, blueRect)) {
                    redCircle.setPosition(-100, -100); // D�placer le cercle rouge vers le bas
                }
            }
        }
        for (auto& redCircle : redCircles) {
            for (auto& YellowRect : blueRectangles) {
                if (checkCollision(redCircle, YellowRect)) {
                    redCircle.setPosition(-100, -100); 
                    YellowRect.setPosition(-100, -100);
                }
            }
        }
        for (auto& redCircle : redCircles) {
                if (checkCircleCollision(redCircle, shape)) {
                    redCircle.setPosition(-100, -100); // D�placer le cercle rouge vers le bas
                }
            }
        }
        
        for (auto& redCircle1 : redCircles1) {
            redCircle1.move(0, -0.07); 
        }


        // Effacer la fen�tre
        window.clear();

        // Dessiner les objets
        window.draw(shape);
        window.draw(shape1);
        window.draw(shape3);

        // Dessiner tous les cercles rouges
        for (const auto& redCircle : redCircles) {
            window.draw(redCircle);
        }

        // Dessiner tous les cercles rouges dans les rectangles jaunes
        for (const auto& redCircle1 : redCircles1) {
            window.draw(redCircle1);
        }

        // Dessiner tous les rectangles bleus
        for (const auto& blueRect : blueRectangles) {
            window.draw(blueRect);
        }

        // Dessiner tous les rectangles jaunes
        for (const auto& yellowRect : yellowRectangles) {
            window.draw(yellowRect);
        }

        // Afficher le contenu
        window.display();
    }

    return 0;
}
