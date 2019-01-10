#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>

class Object {

    public:
        Object(){};

        Object(sf::RenderWindow* parent, sf::Vector2f pos) : 
            m_parent(parent),
            m_pos(pos), 
            m_speed(0.5),
            m_drawable() {};

        Object(sf::RenderWindow* parent, sf::Vector2f pos, float speed) : 
            m_parent(parent),
            m_pos(pos), 
            m_speed(speed),
            m_drawable() {};

        Object(sf::RenderWindow* parent, sf::Vector2f pos, float speed, sf::Sprite drawable) : 
            m_parent(parent),
            m_pos(pos), 
            m_speed(speed),
            m_drawable(drawable) {};

        ~Object(){};

        inline sf::Vector2f getPos() const { return m_pos; }
        inline void setPos(sf::Vector2f pos) { m_pos = pos; }
        inline void setScale(sf::Vector2f scale) { m_drawable.setScale(scale); }

        void draw();
        sf::FloatRect getSize() const;
        float getWidth() const;
        float getHeight() const;

        sf::Vector2f m_pos;
        float m_speed;
        sf::RenderWindow* m_parent;
        sf::Sprite m_drawable;

};

#endif