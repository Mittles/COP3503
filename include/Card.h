#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card
{
    public:
        Card(string name, int owner, int value);
        void setName(string n);
        void setOwner(int o);
        void setValue(int v);
        string getName();
        int getOwner();
        int getValue();
        struct cardType;
        virtual ~Card();
    protected:
    private:
        string cardName;
        int cardOwner;
        int cardValue;
};

#endif // CARD_H
