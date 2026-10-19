#include <iostream>
#include "Person.h"

int main() {
Person p1("Alex", 20, "Lakeland", "FL");
Person p2(p1); // copy constructor
Person p3("Sam", 22, "Orlando", "FL");
p3 = p1; // copy assignment
p1.setName("Alex Updated");
std::cout << "Original: "; p1.display();
std::cout << "Copy constructor: "; p2.display();
std::cout << "Assignment: "; p3.display();
p3 = p3; // self-assignment
std::cout << "Self-assignment: "; p3.display();
}