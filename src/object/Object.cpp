#include "Object.h"

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