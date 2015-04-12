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
        World(Territory* north_america_array[], Territory* south_america_array[],
              Territory* europe_array[], Territory* africa_array[], Territory* asia_array[], Territory* australia_array[]);
        virtual ~World();
    protected:
    private:
        vector<Territory*> north_america;
        vector<Territory*> south_america;
        vector<Territory*> europe;
        vector<Territory*> africa;
        vector<Territory*> asia;
        vector<Territory*> australia;
        vector<vector<Territory*> > world;
};

#endif // WORLD_H
