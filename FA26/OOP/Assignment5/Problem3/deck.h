#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <random>
#include <utility>
#include <stdexcept>

class Deck {
    private:
        vector<Card> deck;
        int topCard;
    public:
        Deck();
        void shuffle();
        Card deal();
        bool moreCards() const;
};

#endif