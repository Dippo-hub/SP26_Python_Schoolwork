#include "card.h"

vector<string> Card::faceNames = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
vector<string> Card::suitNames = {"Hearts", "Diamonds", "Clubs", "Spades"};

Card::Card(int _face, int _suit) : face(_face), suit(_suit) {}
int Card::getFace() const { return face; }
int Card::getSuit() const { return suit; }
string Card::toString() const { return faceNames[face] + " of " + suitNames[suit]; }