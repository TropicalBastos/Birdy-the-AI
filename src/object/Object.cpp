#include "Object.h"

Object::Object(sf::RenderWindow* parent, sf::Vector2f pos, float speed, std::string texturePath, TAG tag) : 
    m_parent(parent),
    m_pos(pos), 
    m_speed(speed),
    m_tag(tag)
{
   m_texture.loadFromFile(texturePath);
   m_drawable = sf::Sprite(m_texture); 
};

void Object::draw() 
{
    m_drawable.setPosition(m_pos);
    m_parent->draw(m_drawable);
}

sf::FloatRect Object::getSize() const 
{
    return m_drawable.getLocalBounds();
}

float Object::getWidth() const
{
    return m_drawable.getLocalBounds().width;
}

float Object::getHeight() const
{
    return m_drawable.getLocalBounds().height;
}