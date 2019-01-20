#ifndef GRID_H
#define GRID_H

#include "GridInterface.h"
#include "Tile.h"
#include <SFML/Graphics.hpp>

class Grid : public GridInterface 
{
    public:
        Grid(
            sf::RenderWindow* parent, 
            unsigned int columns, 
            unsigned int rows
        );
        void add(ObjectInterface* obj);
        void draw() const;
        ObjectInterface* getObjectByGridPosition(int x, int y) const;
        inline TileMatrix* getTileMatrix() { return &m_tileMatrix; }
        inline void enableWireframe() {  wireframe = true; }
        inline void disableWireframe() { wireframe = false; }
        TileVector& operator[](const unsigned int index);
        inline size_t size() const { return m_tileMatrix.size(); }
        const Tile& getTileByAbsolutePosition(float x, float y);
    private:
        unsigned int columns;
        unsigned int rows;
        bool wireframe;
        TileMatrix m_tileMatrix;
        sf::RenderWindow* m_parent;

        void buildTileMatrix();
        void positionObjectInTile(
            ObjectInterface* obj, 
            unsigned int row, 
            unsigned int column, 
            float width, 
            float height
        );
};

#endif