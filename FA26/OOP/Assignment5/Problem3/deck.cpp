#include "deck.h"

Deck::Deck() {
    topCard = 0;
    for(int i=0; i<4; i++) {
        for(int j=0; j<13; j++) {
            deck.push_back(Card(j, i));
        }
    }
}

Card Deck::deal() {
    if (!moreCards())
        throw std::out_of_range("No cards left to deal");

    return deck[topCard++];
}

bool Deck::moreCards() const { return topCard<52; }

void Deck::shuffle() {
    mt19937 engine(random_device{}());

    for (int i = 51; i > 0; --i) {
        uniform_int_distribution<int> pick(0, i);
        int j = pick(engine);
        swap(deck[i], deck[j]);
    }

    topCard = 0;
}