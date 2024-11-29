#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using namespace sf;

int score = 0;
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
    sf::FloatRect circleBounds = circle1.getGlobalBounds();
    sf::FloatRect rectBounds = rect.getGlobalBounds();
    return circleBounds.intersects(rectBounds);
    };

int X = rand() % 1000;
int Y = rand() % 800;

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Gestion des Entrées");
    Sound damage;
    SoundBuffer ou;
    if (!ou.loadFromFile("sounds/ou.ogg")) { cout << "Failed to load damage sound" << endl; return -1; }
    damage.setBuffer(ou);
    sf::CircleShape shape(30);
    shape.setPosition(500, 650);
    Texture player;
    if (!player.loadFromFile("textures/player.jpg")) { cout << "Erreur lors du chargement de texture du joueur" << endl; return -1; }
    shape.setTexture(&player);
    Texture zombie;
    if (!zombie.loadFromFile("textures/zombie.jpg")) { cout << "Erreur lors du chargement de texture du zombie" << endl; return -1; }
    sf::CircleShape shape2(30);
    shape2.setFillColor(sf::Color::Blue);
    shape2.setPosition(100, 650);

    bool Attack = false;

    sf::RectangleShape shape1(sf::Vector2f(30.f, 30.f));
    shape1.setFillColor(sf::Color::Magenta);
    shape1.setPosition(500, 100);

    sf::RectangleShape shape3(sf::Vector2f(30.f, 30.f));
    shape3.setFillColor(sf::Color::Yellow);
    shape3.setPosition(100, -650);

    sf::RectangleShape shape5(sf::Vector2f(1000, 800));
    shape5.setFillColor(sf::Color::Green);
    shape5.setPosition(0, 0);
    Texture b;
    if (!b.loadFromFile("textures/background.jpg")) { cout << "Erreur lors du chargement de texture du joueur" << endl; return -1; }
    shape5.setTexture(&b);

    std::vector<sf::CircleShape> redCircles;
    std::vector<sf::CircleShape> redCircles1;
    std::vector<sf::RectangleShape> blueRectangles;
    std::vector<sf::RectangleShape> yellowRectangles;

    bool APressed = false;
    bool SpacePressed = false;

    sf::Clock clock;
    sf::Clock clockYellow;
    sf::Clock clockRed;

    float timeSinceLastSpawnBlue = 0.f;
    float timeSinceLastSpawnYellow = 0.f;
    float timeSinceLastSpawnRed = 0.f;

    while (window.isOpen()) {
        sf::Event event;
        shape2.move(0.02, 0);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

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

        for (auto& rect : blueRectangles) {
            rect.move(0.02f, 0);
            if (rect.getPosition().x > window.getSize().x) {
                rect.setPosition(-150, rand() % 700);
            }
        }

        for (auto& rect : yellowRectangles) {
            rect.move(0.01f, 0);
            if (rect.getPosition().x > window.getSize().x) {
                rect.setPosition(-150, rand() % 700);
            }
        }

        timeSinceLastSpawnRed += clockRed.restart().asSeconds();
        if (timeSinceLastSpawnRed >= 5.f) {
            timeSinceLastSpawnRed = 0.f;
            if (!yellowRectangles.empty()) {
                int index = rand() % yellowRectangles.size();
                sf::CircleShape newRedCircle(20);
                newRedCircle.setFillColor(sf::Color::Red);
                sf::FloatRect rectBounds = yellowRectangles[index].getGlobalBounds();
                newRedCircle.setPosition(rectBounds.left + rectBounds.width / 2 - newRedCircle.getRadius(),
                    rectBounds.top + rectBounds.height / 2 - newRedCircle.getRadius());
                redCircles1.push_back(newRedCircle);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !APressed) {
            APressed = true;
            sf::CircleShape newCircle(20);
            newCircle.setFillColor(sf::Color::Red);
            newCircle.setPosition(shape.getPosition());
            redCircles.push_back(newCircle);
            if (damage.getStatus() != Sound::Playing)
                damage.play();
        }

        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            APressed = false;
        }

        for (auto it = redCircles.begin(); it != redCircles.end(); /* no increment */) {
            it->move(0, -0.07);
            if (checkCollision(*it, shape1)) {
                score = score + 50;
                std::cout << score << std::endl;
                it = redCircles.erase(it);
                X = rand() % 1000;
                Y = rand() % 700;
                shape1.setPosition(X, Y);
            }
            else {
                ++it;
            }
        }

        if (checkCollision(shape, shape1)) {
            X = rand() % 1000;
            Y = rand() % 700;
            shape1.setPosition(X, Y);
        }

        timeSinceLastSpawnBlue += clock.restart().asSeconds();
        if (timeSinceLastSpawnBlue >= 10.f) {
            timeSinceLastSpawnBlue = 0.f;
            sf::RectangleShape newBlueRectangle(sf::Vector2f(100, 30));
            newBlueRectangle.setFillColor(sf::Color::Blue);
            newBlueRectangle.setPosition(-200, rand() % 50);
            blueRectangles.push_back(newBlueRectangle);
        }

        timeSinceLastSpawnYellow += clockYellow.restart().asSeconds();
        if (timeSinceLastSpawnYellow >= 15.f) {
            timeSinceLastSpawnYellow = 0.f;
            sf::RectangleShape newYellowRectangle(sf::Vector2f(60, 60));
            newYellowRectangle.setFillColor(sf::Color::Yellow);
            newYellowRectangle.setPosition(-200, 100);
            newYellowRectangle.setTexture(&zombie);
            yellowRectangles.push_back(newYellowRectangle);
        }

        for (auto& redCircle : redCircles) {
            for (auto& blueRect : blueRectangles) {
                if (checkCollision(redCircle, blueRect)) {
                    redCircle.setPosition(-100, -100);
                }
            }
        }

        for (auto& redCircle1 : redCircles1) {
            redCircle1.move(0, 0.07);
        }

        for (auto& redCircle : redCircles) {
            for (auto& YellowRect : yellowRectangles) {
                if (checkCollision(redCircle, YellowRect)) {
                    redCircle.setPosition(-100, -100);
                    YellowRect.setPosition(-100, -100);
                }
            }
        }

        window.clear();
        window.draw(shape5);
        window.draw(shape);
        window.draw(shape1);
        window.draw(shape3);

        for (const auto& redCircle : redCircles) {
            window.draw(redCircle);
        }

        for (const auto& redCircle1 : redCircles1) {
            window.draw(redCircle1);
        }

        for (const auto& blueRect : blueRectangles) {
            window.draw(blueRect);
        }

        for (const auto& yellowRect : yellowRectangles) {
            window.draw(yellowRect);
        }

        window.display();
    }

    return 0;
}
