#include "World.h"

World::World(Territory* north_america_array[], Territory* south_america_array[],
              Territory* europe_array[], Territory* africa_array[], Territory* asia_array[], Territory* australia_array[])
{
    //Add North America Territories to Vector
    for (int i=0; i<9; i++) {
        north_america.push_back(north_america_array[i]);
    }
    //Add South America Territories to Vector
    for (int i=0; i<4; i++) {
        south_america.push_back(south_america_array[i]);
    }
    //Add Europe Territories to Vector
    for (int i=0; i<7; i++) {
        europe.push_back(europe_array[i]);
    }
    //Add Africa Territories to Vector
    for (int i=0; i<6; i++) {
        africa.push_back(africa_array[i]);
    }
    //Add Asia Territories to Vector
    for (int i=0; i<12; i++) {
        asia.push_back(asia_array[i]);
    }
    //Add Australia Territories to Vector
    for (int i=0; i<4; i++) {
        australia.push_back(australia_array[i]);
    }
    //Add Continent Vectors to World vector
    world.push_back(north_america);
    world.push_back(south_america);
    world.push_back(europe);
    world.push_back(africa);
    world.push_back(asia);
    world.push_back(australia);
}

World::~World()
{

}
