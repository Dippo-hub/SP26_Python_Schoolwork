#include <iostream>

int evenCount(int value) {
    if (value < 10)
    {
        if (value%2==0)
            return 1;
        else
            return 0;
    } else {
        if (value%2==0)
            return evenCount(value/10) + 1;
        else
            return evenCount(value/10);
    }
}

int main(void) {

    int number;
    for(int i = 0; i<4; i++) {
        std::cout << "Enter a number: ";
        std::cin >> number;
        std::cout << "Even digits in number: " << evenCount(number) << std::endl;
    }
}