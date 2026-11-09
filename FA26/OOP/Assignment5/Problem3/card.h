#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Card {
    private:
        int face, suit;
        static vector<string> faceNames, suitNames;
    public:
        Card(int face, int suit);
        int getFace() const;
        int getSuit() const;
        string toString() const;
};

#endif