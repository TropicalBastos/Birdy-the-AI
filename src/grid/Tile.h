#ifndef TILE_H
#define TILE_H

#include <vector>
#include "../object/ObjectInterface.h"

class Object;

struct TileDimensions {
    float width;
    float height;
};

struct TilePosition {
    unsigned int x;
    unsigned int y;
};

class Tile {
    public:
        Tile() : 
            m_dim({0, 0}), 
            m_pos({0, 0}),
            occupied(false),
            m_obj(nullptr){}

        Tile(TileDimensions dim) : 
            m_dim(dim), 
            m_pos({0, 0}),
            occupied(false),
            m_obj(nullptr){}

        
        Tile(TileDimensions dim, TilePosition pos) : 
            m_dim(dim), 
            m_pos(pos),
            occupied(false),
            m_obj(nullptr){}

        Tile(TileDimensions dim, TilePosition pos, ObjectInterface* obj) : 
            m_dim(dim), 
            m_pos(pos),
            m_obj(obj),
            occupied(false){}

        ~Tile()
        {
            if(m_obj != nullptr)
            {
                delete m_obj;
            }
        }

        inline void occupy() { occupied = true; }
        inline void unoccupy() { occupied = false; }
        inline bool isOccupied() const  { return occupied; }
        inline TileDimensions getDimensions() const { return m_dim; }
        inline TilePosition getPos() const { return m_pos; }
        inline void setObject(ObjectInterface* obj) { m_obj = obj; }
        inline ObjectInterface* getObject() const { return m_obj; }
        inline void draw() const { m_obj->draw(); }
        inline bool hasObject() const { return m_obj != nullptr; }

    private:
        TilePosition m_pos;
        TileDimensions m_dim;
        bool occupied;
        ObjectInterface* m_obj;
};

typedef std::vector<Tile> TileVector;
typedef std::vector<TileVector> TileMatrix;

#endif