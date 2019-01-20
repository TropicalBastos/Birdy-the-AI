#include "BirdyAI.h"
#include "../object/Object.h"
#include "../grid/Grid.h"
#include <unordered_map>
#include <iostream>

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

// ObjectTag BirdyAI::majorityTag(std::vector<ObjectTag> tags)
// {
//     if(tags.size() == 0)
//     {
//         return ObjectTag::NONE;
//     }
//     std::unordered_map<ObjectTag, int> map;
//     ObjectTag mostFrequentTag = tags[0];
//     for(auto tag : tags)
//     {
//         map[tag] = 0;
//     }
//     for(auto tag : tags)
//     {
//         map[tag] = map[tag]++;
//     }
//     mostFrequentTag = tags[0];
//     for(auto tag : tags)
//     {
//         if(map[tag] > map[mostFrequentTag])
//         {
//             mostFrequentTag = tag;
//         }
//     }
//     return mostFrequentTag;
// }

// ObjectInterface::DIRECTION getDirectionByTag(ObjectTag tag, TileMatrix searchMatrix)
// {
//     for(const TileVector& vec : searchMatrix)
//     {
//         for(const Tile& tile : vec)
//         {

//         }
//     }
// }

ObjectInterface::DIRECTION BirdyAI::decide(const Tile& currentTile)
{
    if(learnedTiles.size() == 0)
    {
        ObjectInterface::DIRECTION dir = static_cast<ObjectInterface::DIRECTION>((rand() % 4) + 1);
        return dir;
    }
    // TileMatrix* matrix = currentTile.getParentMatrix();
    // std::vector<ObjectTag> tags;
    // for(auto learned : learnedTiles)
    // {
    //     tags.push_back(learned.tag);
    // }
    // ObjectTag mostFrequent = majorityTag(tags);
    return ObjectInterface::DIRECTION::RIGHT;
}

