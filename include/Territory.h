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
        int troops;
        vector<string> borders;
        string name;
        int owner;
    protected:
    private:
        int num;

};

#endif // TERRITORY_H
