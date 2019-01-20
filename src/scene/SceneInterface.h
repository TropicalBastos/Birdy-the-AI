#ifndef SCENE_INTERFACE_H
#define SCENE_INTERFACE_H

#include "../grid/GridInterface.h"
#include "../object/ObjectInterface.h"

class SceneInterface {

    public:
        virtual ~SceneInterface(){};
        virtual void add(ObjectInterface* obj) = 0;
        virtual void remove(unsigned int index) = 0;
        virtual void draw() = 0;

};

#endif