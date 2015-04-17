#include "World.h"

World::World(Territory* north_america_array[9], Territory* south_america_array[4],
              Territory* europe_array[7], Territory* africa_array[6], Territory* asia_array[12], Territory* australia_array[4])
{
   /*
        Pushing back all the territories into a unified vector
    */

    for(int i=0; i<4; i++) {
        world.push_back(australia_array[i]);
    }

    for(int i=0; i<12; i++) {
        world.push_back(asia_array[i]);
    }

    for(int i=0; i<7; i++) {
        world.push_back(europe_array[i]);
    }

    for (int i=0; i<6; i++) {
        world.push_back(africa_array[i]);
    }

    for (int i=0; i<4; i++) {
        world.push_back(south_america_array[i]);
    }

    for (int i=0; i<9; i++) {
        world.push_back(north_america_array[i]);
    }
}

World::~World()
{

}
