/*Write a program that reads an integer between 0 and 1000000 and adds all the digits in the integer. For example, if an integer is 932, the sum of all its digits is 14.Hint: Use the % operator to extract digits and use the / operator to remove the extracted digit. Bonus (+2 bonus points). Repeatedly add all digits of the entered number until the result has only one digit and display it*/

#include <iostream>

short single_digit(short d = 0) {
    while (d > 9) {
        short sum = 0;

        while (d > 0) {
            sum += d % 10;
            d /= 10;
        }

        d = sum;
    }

    return d;
}



int main () {
    short number, result;
    std::cout << "Enter a number: ";
    std::cin >> number;
    result = single_digit(number);
    std::cout << result << std::endl;
    return 0;
}