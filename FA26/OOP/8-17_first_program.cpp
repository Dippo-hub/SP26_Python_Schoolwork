#include <iostream>
using namespace std;

std::string get_name () {
    std::string name;
    std::cout << "Please enter your name: ";
    std::cin >> name;
    return name;
}

int greet_name(std::string name) {
    std::cout << "Hello there, " << name << std::endl;
    return 0;
}

int main () {
    std:: cout << "Object Oriented Programming" << endl;
    std::string name = get_name();
    greet_name(name);
    return 0;
}