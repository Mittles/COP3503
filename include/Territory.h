#ifndef TERRITORY_H
#define TERRITORY_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Territory
{
    public:
        Territory(int num, string name, int borderNum, string borders[]);
        virtual ~Territory();
        void setTroops(int t);
        int getTroops();
        int getNum();
        void setOwner(int o);
        int getOwner();
        string getName();
        vector<string> getBorders();
    protected:
    private:
        int troops;
        int num;
        int owner;
        string name;
        vector<string> borders;
};

#endif // TERRITORY_H
