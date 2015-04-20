#ifndef TERRITORY_H
#define TERRITORY_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Territory
{
    public:
        //Constructor
        Territory(int num, string name, int borderNum, string borders[]);
        //Deconstructor
        virtual ~Territory();
        //Sets the number of troops present in the Territory
        void setTroops(int t);
        //Returns the number of troops present in the Territory
        int getTroops();
        //Returns the numeric ID of this Territory
        int getNum();
        //Sets the owner of this Territory to a player's numeric ID
        void setOwner(int o);
        //Returns the numeric ID of this Territory's owner
        unsigned int getOwner();
        //Returns the string name for this Territory
        string getName();
        //Returns the vector of strings naming the bordering Territories
        vector<string> getBorders();
        //Checks if troops have changed, used in the GUI
        bool troopsChanged;
    private:
        //Number of troops in this Territory
        int troops;
        //Numeric ID of this Territory
        int num;
        //Numeric ID of this Territory's owner
        int owner;
        //String name for this Territory
        string name;
        //Vector of strings naming bordering Territories. Used to check adjacency in Game.cpp
        vector<string> borders;
};

#endif // TERRITORY_H
