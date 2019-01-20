#include "BirdyAI.h"
#include "../object/Object.h"

bool BirdyAI::checkForWorm(const Tile& tile)
{
    if(tile.hasObject()){
        Object* obj = dynamic_cast<Object*>(tile.getObject());
        if(obj->getTag() == ObjectInterface::TAG::WORM)
        {
            learnTile(tile);
            return true;
        }
    }
    return false;
}

void BirdyAI::learnTile(const Tile& tile)
{
    TilePosition pos = tile.getPos();
    ObjectTag tag = tile.getObject()->getTag();
    LearnableData learnedData {
        pos.x,
        pos.y,
        tag
    };
    learnedTiles.push_back(learnedData);
}

