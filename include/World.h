#ifndef WORLD_H
#define WORLD_H
#include "Territory.h"
#include <string>
#include <vector>
#include <iostream>


using namespace std;

class World
{
    public:
        World(Territory* north_america_array[9], Territory* south_america_array[4],
              Territory* europe_array[7], Territory* africa_array[6], Territory* asia_array[12], Territory* australia_array[4]);
        virtual ~World();
    protected:
    private:
        vector<Territory*> world;
};

#endif // WORLD_H
