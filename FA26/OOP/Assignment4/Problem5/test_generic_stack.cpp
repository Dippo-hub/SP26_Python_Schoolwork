#include <iostream>
#include <string>
#include "generic_stack.h"

int main() {
std::cout << std::boolalpha;
GenericStack<int> numbers;
std::cout << "Initially empty: " << numbers.isEmpty() << '\n';
numbers.push(4); numbers.push(7); numbers.push(12);
std::cout << "Integer stack size: " << numbers.getSize() << '\n';
int n = -1;
numbers.peek(n);
std::cout << "Top integer: " << n << '\n';
numbers.pop(n);
std::cout << "Popped integer: " << n << '\n';
std::cout << "Size after pop: " << numbers.getSize() << '\n';
GenericStack<std::string> words;
words.push("red"); words.push("blue");
std::string word;
words.pop(word);
std::cout << "Popped word: " << word << '\n';
words.pop(word);
std::cout << "Popped word: " << word << '\n';
std::cout << "Pop empty succeeds: " << words.pop(word) << '\n';
std::cout << "Larger integer: " << largerOf(4, 9) << '\n';
std::cout << "Larger double: " << largerOf(4.5, 2.25) << '\n';
return 0;
}