#ifndef SCENE_H
#define SCENE_H

#include "SceneInterface.h"
#include "../grid/Grid.h"
#include <vector>

class Scene : public SceneInterface {

    public:
        Scene(sf::RenderWindow* parent) : 
            m_parent(parent),
            m_grid(Grid(parent, 6, 5))
        {};

        Scene(sf::RenderWindow* parent, Grid grid) : 
            m_parent(parent),
            m_grid(grid)
        {};

        void add(ObjectInterface* obj, bool beggining = false);
        void draw();
        inline void setBackground(sf::Sprite background) { m_background = background; }
        inline Grid& getGrid() { return m_grid; }
        void resetObjects();

    private:
        sf::RenderWindow* m_parent;
        Grid m_grid;
        sf::Sprite m_background;


};

#endif