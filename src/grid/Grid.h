#ifndef GRID_H
#define GRID_H

#include "Tile.h"
#include <SFML/Graphics.hpp>

class Grid {
    public:
        Grid(
            sf::RenderWindow* parent, 
            unsigned int columns, 
            unsigned int rows,
            std::vector<Object*> objects = std::vector<Object*>()
        );
        ~Grid();
        void add(Object* obj);
        void draw() const;
        inline TileMatrix* getTileMatrix() { return &m_tileMatrix; }
        inline std::vector<Object*> getObjects() const { return m_objects; }
        inline void enableWireframe() {  wireframe = true; }
        inline void disableWireframe() { wireframe = false; }
    private:
        unsigned int columns;
        unsigned int rows;
        bool wireframe;
        TileMatrix m_tileMatrix;
        sf::RenderWindow* m_parent;
        std::vector<Object*> m_objects;

        void rebuildTileMatrix();
        void positionObjectInTile(
            Object* obj, 
            unsigned int row, 
            unsigned int column, 
            float width, 
            float height
        );
};

#endif