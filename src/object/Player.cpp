#include "Player.h"

void Player::moveUp()
{
    m_pos.y += m_speed;
}

void Player::moveDown()
{
    m_pos.y -= m_speed;
}

void Player::moveLeft()
{
    m_pos.x -= m_speed;
}

void Player::moveRight()
{
    m_pos.x += m_speed;
}