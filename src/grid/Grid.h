#ifndef GRID_H
#define GRID_H

#include "Tile.h"
#include <SFML/Graphics.hpp>

class Grid {
    public:
        Grid(sf::RenderWindow* parent, unsigned int columns, unsigned int rows);
        ~Grid(){};
        void draw() const;
    private:
        unsigned int columns;
        unsigned int rows;
        TileMatrix m_tileMatrix;
        sf::RenderWindow* m_parent;
};

#endif