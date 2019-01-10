#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"

class Player : public Object {

    public:
        Player(sf::RenderWindow* window, sf::Vector2f pos, float speed, sf::Sprite sprite) : 
            Object(window, pos, speed, sprite) 
            {}

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();

};

#endif