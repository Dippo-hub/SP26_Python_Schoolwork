#include "deck.h"
int main() {
std::cout << std::boolalpha;
Deck deck;
int count = 0;
std::cout << "Before shuffle\n";
while (deck.moreCards()) {
std::cout << deck.deal().toString() << '\n';
++count;
}
std::cout << "Unshuffled cards dealt: " << count << '\n';
std::cout << "Cards remaining after first deal: "
<< deck.moreCards() << '\n';
deck.shuffle();
count = 0;
std::cout << "After shuffle\n";
while (deck.moreCards()) {
std::cout << deck.deal().toString() << '\n';
++count;
}
std::cout << "Shuffled cards dealt: " << count << '\n';
std::cout << "Cards remaining after second deal: "
<< deck.moreCards() << '\n';
return 0;
}
