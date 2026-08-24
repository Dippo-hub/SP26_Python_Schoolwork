#include <iostream>

#define PI = 3.1415

int math_out () {
    std::cout << "(7.2 + 3 * 5) / (23-7.8) = ";
    std::cout << (7.2 + 3 * 5) / (23-7.8) << std::endl;
    return 0;
}

//use short for reasonable numbers rather than int, more memory efficient

void size_of() {
    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Size of short: " << sizeof(short) << " bytes" << std::endl;
    std::cout << "Size of bool: " << sizeof(bool) << " bytes" << std::endl;
}

int main () {
    math_out();
    size_of();
    std::cout << (true == 0) <<std::endl; //true=1, false=0
    return 0;
}