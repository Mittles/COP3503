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
        //Constructor takes in an array of pointers to Territories, and puts them into 1 organized, unified vector for easier access
        World(Territory* north_america_array[9], Territory* south_america_array[4],
              Territory* europe_array[7], Territory* africa_array[6], Territory* asia_array[12], Territory* australia_array[4]);
        //Default constructor
        World();
        //Returns the data structure for the Territories
        vector<Territory*> getWorld();
        //Deconstructor
        virtual ~World();
    protected:
    private:
        //The organized data structure containing all Territories
        vector<Territory*> world;
};

#endif // WORLD_H
