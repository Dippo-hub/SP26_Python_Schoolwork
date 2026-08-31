/*Write a complete C++ program that prompts the user to enter an integer number and reads
that number from the keyboard.
• If the entered number is negative, your program should print the following message:
“The program doesn’t accept negative numbers” and stop the execution.
• If the entered number is positive and less or equal 100 (between 0 to 100), the program
should check and display whether the number is divisible by 4 or not. Also, your
program must display quotient and remainder*/

#include <iostream>
#include <cmath>
#include <iomanip>

void integer_comparison() {
    short number, quotient, remainder, root;

    std::cout << "Enter a number: ";
    std::cin >> number;

    if (number<0)
        std::cout << "The program does not accept negative numbers." << std::endl;
    else if (number <= 100) {
        quotient = number/4;
        remainder = number%4;
        if (remainder==0) {
            std::cout << number << " is divisible by 4 with quotient " << quotient << std::endl;
        } else {
            std::cout << number << " is not divisible by 4, it has quotient " << quotient << " and remainder " << remainder << std::endl;
        }
    } else {
        std::cout << std::setprecision(4) << "Number is larger than 100 and has square root: " << sqrt(number) << std::endl;
    }
}

int main() {
    integer_comparison();
    return 0;
}