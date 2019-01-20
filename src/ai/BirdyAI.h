#ifndef BIRDY_AI
#define BIRDY_AI

#include <vector>
#include "../grid/Tile.h"

class ObjectInterface;

typedef ObjectInterface::TAG ObjectTag;

struct LearnableData
{
    unsigned int posX;
    unsigned int posY;
    ObjectTag tag;
};

class BirdyAI 
{

    public:
        BirdyAI(){};
        ~BirdyAI(){};

        void learnTile(const Tile& tile);
        bool checkForWorm(const Tile& tile);

    private:
        std::vector<LearnableData> learnedTiles;

};

#endif