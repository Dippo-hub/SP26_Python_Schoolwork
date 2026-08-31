/*Write a program that prompts the user to enter a string and displays the characters at oddindex positions (1, 3, 5 …). Use getline function to read a string from an input stream*/

#include <iostream>

void process_string() {
    std::string message, result="";
    short i = 0;

    std::cout << "Enter a string: ";
    getline(std::cin, message);

    for (i=0; i<message.length(); i++) { //Because offset by 1
        if (i%2==0) {
            result += message.at(i);
        }
    }

    std::cout << result << std::endl;
}

int main () {
    process_string();
    return 0;
}