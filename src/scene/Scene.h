#ifndef SCENE_H
#define SCENE_H

#include "../object/Object.h"
#include "../grid/Grid.h"
#include <vector>

class Scene {

    public:
        Scene(sf::RenderWindow* parent) : 
            m_parent(parent),
            m_grid(Grid(parent, 12, 12)),
            gridEnabled(false)
        {};

        ~Scene();

        unsigned int add(Object* obj);
        void remove(unsigned int index);
        void draw() const;
        void enableGrid(unsigned int columns, unsigned int rows);
        inline void disableGrid() { gridEnabled = false; }

    private:
        std::vector<Object*> m_objects;
        sf::RenderWindow* m_parent;
        bool gridEnabled;
        Grid m_grid;


};

#endif