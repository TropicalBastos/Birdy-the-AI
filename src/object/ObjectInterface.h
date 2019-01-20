#ifndef OBJECT_INTERFACE_H
#define OBJECT_INTERFACE_H

#include <SFML/Graphics.hpp>

class Scene;

class ObjectInterface 
{
    public:
        enum DIRECTION {
            NOWHERE,
            LEFT,
            RIGHT,
            UP,
            DOWN
        };

        enum TAG 
        {
            NONE,
            BIRDY,
            TREE,
            WORM
        };

        virtual ~ObjectInterface(){};
        virtual void draw() = 0;
        virtual sf::FloatRect getSize() const = 0;
        virtual float getWidth() const = 0;
        virtual float getHeight() const = 0;
        virtual sf::Vector2f getPos() const = 0;
        virtual void setPos(sf::Vector2f pos) = 0;
        virtual void setScale(sf::Vector2f scale) = 0;
        virtual TAG getTag() const = 0;
        virtual void setScene(Scene* scene) = 0;
};

#endif