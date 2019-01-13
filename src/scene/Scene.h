#ifndef SCENE_H
#define SCENE_H

#include "../object/Object.h"
#include <vector>

class Scene {

    public:
        Scene(sf::RenderWindow* parent) : 
            m_parent(parent){};

        ~Scene();

        unsigned int add(Object* obj);
        void remove(unsigned int index);
        void draw() const;

    private:
        std::vector<Object*> m_objects;
        sf::RenderWindow* m_parent;

};

#endif