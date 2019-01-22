#ifndef TILE_H
#define TILE_H

#include <vector>
#include <memory>
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
            occupied(false){}

        Tile(TileDimensions dim) : 
            m_dim(dim), 
            m_pos({0, 0}),
            occupied(false){}

        
        Tile(TileDimensions dim, TilePosition pos) : 
            m_dim(dim), 
            m_pos(pos),
            occupied(false){}

        Tile(TileDimensions dim, TilePosition pos, ObjectInterface* obj) : 
            m_dim(dim), 
            m_pos(pos),
            m_obj(obj),
            occupied(false){}

        ~Tile(){}

        inline void occupy() { occupied = true; }
        inline void unoccupy() { occupied = false; }
        inline bool isOccupied() const  { return occupied; }
        inline TileDimensions getDimensions() const { return m_dim; }
        inline TilePosition getPos() const { return m_pos; }
        inline void setObject(ObjectInterface* obj) { m_obj = std::shared_ptr<ObjectInterface>(obj); }
        inline ObjectInterface* getObject() const { return m_obj.get(); }
        inline void draw() const { m_obj->draw(); }
        inline bool hasObject() const { return m_obj != nullptr; }
        inline void setParentMatrix(std::vector<std::vector<Tile>>* matrix) { parentMatrix = matrix; }
        inline std::vector<std::vector<Tile>>* getParentMatrix() const { return parentMatrix; }

    private:
        TilePosition m_pos;
        TileDimensions m_dim;
        bool occupied;
        std::shared_ptr<ObjectInterface> m_obj;
        std::vector<std::vector<Tile>>* parentMatrix;

};

typedef std::vector<Tile> TileVector;
typedef std::vector<TileVector> TileMatrix;

#endif