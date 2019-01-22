#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <string>
#include "../scene/Scene.h"
#include "ObjectInterface.h"

class Object : public ObjectInterface {

    public:
        Object() : m_tag(ObjectInterface::TAG::NONE){};
        Object(sf::RenderWindow* parent, sf::Vector2f pos, float speed, std::string texturePath, TAG tag);

        inline sf::Vector2f getPos() const { return m_pos; }
        inline void setPos(sf::Vector2f pos) { m_pos = pos; }
        inline void setScale(sf::Vector2f scale) { m_drawable.setScale(scale); }
        inline void setTag(ObjectInterface::TAG tag) { m_tag = tag; }
        inline ObjectInterface::TAG getTag() const { return m_tag; }
        inline Scene* getScene() const { return m_scene; }
        inline void setScene(Scene* scene) { m_scene = scene; }

        void draw();
        sf::FloatRect getSize() const;
        float getWidth() const;
        float getHeight() const;

        sf::Vector2f m_pos;
        float m_speed;
        sf::RenderWindow* m_parent;
        sf::Sprite m_drawable;
        sf::Texture m_texture;
        ObjectInterface::TAG m_tag;
        Scene* m_scene;

};

#endif