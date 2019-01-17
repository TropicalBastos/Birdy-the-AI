#ifndef Birdy_H
#define Birdy_H

#include "Object.h"
#include "../config.h"

class Birdy : public Object {

    public:
        static Birdy* createInstance(sf::RenderWindow* window, sf::Vector2f pos, float speed);
        inline static Birdy* getInstance() { return instance; }

        enum DIRECTION {
            LEFT,
            RIGHT,
            UP,
            DOWN
        };

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void move();
        void flipDirection();

        inline void setDirection(DIRECTION dir);
        inline DIRECTION getDirection() const { return direction; }

    private:
        Birdy(sf::RenderWindow* window, sf::Vector2f pos, float speed);
        static Birdy* instance;
        DIRECTION direction;

};

#endif