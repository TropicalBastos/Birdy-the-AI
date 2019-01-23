#ifndef TILE_H
#define TILE_H

#include <vector>
#include <memory>
#include <iostream>
#include "../object/ObjectInterface.h"

struct TileDimensions 
{
    float width;
    float height;
};

struct TilePosition 
{
    unsigned int x;
    unsigned int y;
};

class Tile {
    public:
        Tile();
        Tile(TileDimensions dim);
        Tile(TileDimensions dim, TilePosition pos);
        Tile(TileDimensions dim, TilePosition pos, ObjectInterface* obj);
        ~Tile(){}

        inline void occupy() { occupied = true; }
        inline void unoccupy() { occupied = false; }
        inline bool isOccupied() const  { return occupied; }
        inline TileDimensions getDimensions() const { return m_dim; }
        inline TilePosition getPos() const { return m_pos; }
        inline bool hasObject() const { return m_obj.get() != nullptr; }
        inline void setParentMatrix(std::vector<std::vector<Tile>>* matrix) { parentMatrix = matrix; }
        inline std::vector<std::vector<Tile>>* getParentMatrix() const { return parentMatrix; }

        void setObject(ObjectInterface* obj);
        ObjectInterface* getObject() const;
        void draw() const;

    private:
        TilePosition m_pos;
        TileDimensions m_dim;
        bool occupied;
        std::shared_ptr<ObjectInterface> m_obj;
        std::vector<std::vector<Tile>>* parentMatrix;
        ObjectInterface* m_birdy;
        bool isBirdy;

};

typedef std::vector<Tile> TileVector;
typedef std::vector<TileVector> TileMatrix;

#endif