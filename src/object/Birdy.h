#ifndef Birdy_H
#define Birdy_H

#include "Object.h"

class Birdy : public Object {

    public:
        Birdy(sf::RenderWindow* window, sf::Vector2f pos, float speed, sf::Sprite sprite) : 
            Object(window, pos, speed, sprite) 
            {}

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();


};

#endif