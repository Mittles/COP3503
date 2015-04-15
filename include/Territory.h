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
        int owner;
    protected:
    private:
        int num;
        string name;
        vector<string> borders;
};

#endif // TERRITORY_H
