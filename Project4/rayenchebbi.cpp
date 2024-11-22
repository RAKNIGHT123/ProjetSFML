#include <SFML/Graphics.hpp>
#include <vector> // Pour stocker les rectangles

int main() {
    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fenêtre SFML");

    // Dimensions de la fenêtre
    const int windowWidth = 800;
    const int windowHeight = 600;

    // Dimensions de chaque "case" de la grille
    const float cellWidth = 30.f;
    const float cellHeight = 30.f;

    // Calcul du nombre de cases dans la grille
    int rows = windowHeight / cellHeight;
    int cols = windowWidth / cellWidth;

    // Vecteur pour stocker les rectangles créés
    std::vector<sf::RectangleShape> rectangles;

    // Variable pour stocker la couleur actuelle
    int colorCode = 0;  // 0 = aucune couleur, 1 = vert, 2 = bleu, 3 = rouge, etc.

    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                // Modifier la couleur en fonction de la touche pressée
                if (event.key.code == sf::Keyboard::G)
                    colorCode = 1;  // Vert
                if (event.key.code == sf::Keyboard::B)
                    colorCode = 2;  // Bleu
                if (event.key.code == sf::Keyboard::R)
                    colorCode = 3;  // Rouge
                if (event.key.code == sf::Keyboard::Y)
                    colorCode = 4;  // Jaune
                if (event.key.code == sf::Keyboard::M)
                    colorCode = 5;  // Violet
                if (event.key.code == sf::Keyboard::W)
                    colorCode = 6;  // Violet
            }

            // Fermer la fenêtre si l'événement de fermeture est déclenché
            if (event.type == sf::Event::Closed)
                window.close();  // Fermer la fenêtre

            // Détecter un clic gauche de souris
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                // Récupérer les coordonnées du clic
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;

                // Calculer les indices de la grille
                int col = x / 30;  // L'indice de la colonne
                int row = y / 30;  // L'indice de la ligne

                x = col * 30;
                y = row * 30;

                // Créer un rectangle
                sf::RectangleShape shape(sf::Vector2f(30.f, 30.f)); // Largeur = 30, Hauteur = 30

                // Choisir la couleur en fonction de la touche pressée
                if (colorCode == 1)
                    shape.setFillColor(sf::Color::Green);  // Vert
                else if (colorCode == 2)
                    shape.setFillColor(sf::Color::Blue);   // Bleu
                else if (colorCode == 3)
                    shape.setFillColor(sf::Color::Red);    // Rouge
                else if (colorCode == 4)
                    shape.setFillColor(sf::Color::Yellow); // Jaune
                else if (colorCode == 5)
                    shape.setFillColor(sf::Color::Magenta); // Violet

                // Positionner le rectangle dans la grille
                shape.setPosition(x, y);

                // Ajouter le rectangle au vecteur
                rectangles.push_back(shape);
            }
        }

        // Effacer la fenêtre
        window.clear();

        // Dessiner tous les rectangles
        for (const auto& rectangle : rectangles) {
            window.draw(rectangle);
        }

        // Afficher le contenu
        window.display();
    }

    return 0;
}