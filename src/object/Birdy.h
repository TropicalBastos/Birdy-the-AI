#ifndef Birdy_H
#define Birdy_H

#include "Object.h"
#include "../config.h"

class Birdy : public Object {

    public:
        static Birdy* createInstance(sf::RenderWindow* window, sf::Vector2f pos, float speed);
        inline static Birdy* getInstance() { return instance; }

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void move();

    private:
        Birdy(sf::RenderWindow* window, sf::Vector2f pos, float speed) : 
            Object(window, pos, speed, BIRDY_TEXTURE){}
        static Birdy* instance;

};

#endif