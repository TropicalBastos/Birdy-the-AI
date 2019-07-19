#ifndef Birdy_H
#define Birdy_H

#include "Object.h"
#include "../config.h"
#include "../ai/BirdyAI.h"
#include <atomic>

class Birdy : public Object {

    public:
        static Birdy* createInstance(sf::RenderWindow* window, sf::Vector2f pos, float speed);
        inline static Birdy* getInstance() { return instance; }

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void move();
        void moveInternal();
        void flipDirection();

        inline void setDirection(DIRECTION dir);
        inline DIRECTION getDirection() const { return direction; }

        std::atomic_bool wormEaten;
        int numWormsEaten;

    private:
        Birdy(sf::RenderWindow* window, sf::Vector2f pos, float speed);
        static Birdy* instance;
        DIRECTION direction;
        long directionChanged;
        long directionFlipped;
        BirdyAI ai;

        void checkBoundaries();

};

#endif