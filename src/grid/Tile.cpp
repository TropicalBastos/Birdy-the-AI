#include "Tile.h"

Tile::Tile(): 
    m_dim({0, 0}), 
    m_pos({0, 0}),
    occupied(false),
    noTile(false){}

Tile::Tile(TileDimensions dim) : 
    m_dim(dim), 
    m_pos({0, 0}),
    occupied(false),
    noTile(false){}


Tile::Tile(TileDimensions dim, TilePosition pos) : 
    m_dim(dim), 
    m_pos(pos),
    occupied(false),
    noTile(false){}

Tile::Tile(TileDimensions dim, TilePosition pos, ObjectInterface* obj) : 
    m_dim(dim), 
    m_pos(pos),
    m_obj(obj),
    occupied(false),
    noTile(false){}

void Tile::setObject(ObjectInterface* obj) 
{ 
    if(obj->getTag() != ObjectInterface::TAG::BIRDY)
    {
        isBirdy = false;
        m_obj = std::shared_ptr<ObjectInterface>(obj); 
    } else 
    {
        isBirdy = true;
        m_birdy = obj;
    }
}

ObjectInterface* Tile::getObject() const 
{ 
    if(isBirdy)
    {
        return m_birdy;
    } else
    {
        return m_obj.get();
    }
}

void Tile::draw() const 
{ 
    if(isBirdy)
    {
        m_birdy->draw();
    } else 
    {
        m_obj->draw(); 
    }
}