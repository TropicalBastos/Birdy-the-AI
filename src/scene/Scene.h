#ifndef SCENE_H
#define SCENE_H

#include "../object/Object.h"
#include "../grid/Grid.h"
#include <vector>

class Scene {

    public:
        Scene(sf::RenderWindow* parent) : 
            m_parent(parent),
            m_grid(Grid(parent, 6, 5))
        {};

        Scene(sf::RenderWindow* parent, Grid grid) : 
            m_parent(parent),
            m_grid(grid)
        {};

        void add(Object* obj);
        void remove(unsigned int index);
        void draw();
        inline void setBackground(sf::Sprite background) { m_background = background; }
        inline Grid& getGrid() { return m_grid; }

    private:
        sf::RenderWindow* m_parent;
        Grid m_grid;
        sf::Sprite m_background;


};

#endif