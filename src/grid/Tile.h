#ifndef TILE_H
#define TILE_H

#include <vector>

struct TileDimensions {
    float width;
    float height;
};

class Tile {
    public:
        Tile() : m_dim({0, 0}){}
        Tile(TileDimensions dim) : m_dim(dim){}
        ~Tile(){}

        inline TileDimensions getDimensions() const { return m_dim; }

    private:
        TileDimensions m_dim;
};

typedef std::vector<Tile> TileVector;
typedef std::vector<TileVector> TileMatrix;

#endif