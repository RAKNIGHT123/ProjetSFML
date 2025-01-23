#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy {
public:
   
    Enemy(float x, float y);

    void setVisibility(bool visible);

    bool getVisibility() const;

    virtual void update(float deltaTime); 
    virtual void draw(sf::RenderWindow& window);

    sf::RectangleShape& getShape();  
    sf::Texture texture;

protected:
    sf::RectangleShape shape; 
    sf::Clock moveClock;      
};

class EnemyShape2 : public Enemy {
public:
    
    EnemyShape2(float x, float y);

    void setVisibility(bool visible);

    bool getVisibility() const;

    
    void update(float deltaTime) override;

private:
    
};

class EnemyShape3 : public Enemy {
public:

    EnemyShape3(float x, float y);



    void update(float deltaTime) override;

private:

};
class EnemyShape4 : public Enemy {
public:

    EnemyShape4(float x, float y);


    void update(float deltaTime) override;

    //void spawnRedRectangles(float deltaTime);
    std::vector<sf::RectangleShape> redRectangles;
    std::vector<sf::RectangleShape> redRectangles1;
    std::vector<sf::RectangleShape> redRectangles2;
    std::vector<sf::RectangleShape> redRectangles3;
private:
    sf::Clock spawnClock;
};

#endif

