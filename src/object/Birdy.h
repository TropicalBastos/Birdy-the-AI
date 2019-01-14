#ifndef Birdy_H
#define Birdy_H

#include "Object.h"
#include "../config.h"

class Birdy : public Object {

    public:
        Birdy(sf::RenderWindow* window, sf::Vector2f pos, float speed) : 
            Object(window, pos, speed, BIRDY_TEXTURE){}
        
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();

};

#endif