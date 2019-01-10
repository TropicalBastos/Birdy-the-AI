#include "Birdy.h"

void Birdy::moveUp()
{
    m_pos.y += m_speed;
}

void Birdy::moveDown()
{
    m_pos.y -= m_speed;
}

void Birdy::moveLeft()
{
    m_pos.x -= m_speed;
}

void Birdy::moveRight()
{
    m_pos.x += m_speed;
}