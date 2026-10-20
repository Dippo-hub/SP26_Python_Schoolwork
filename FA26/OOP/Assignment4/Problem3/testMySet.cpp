#include <iostream>
#include "MySet.h"
int main() {
MySet a(20);
a.insertElement(13);
a.insertElement(7);
a.insertElement(20);
a.insertElement(7); // duplicate
a.insertElement(21); // invalid
std::cout << "A: "; a.printSet();
std::cout << "A size: " << a.getSize() << '\n';
MySet b(a); // copy constructor
a.deleteElement(13);
std::cout << "A after delete: "; a.printSet();
std::cout << "B after copy: "; b.printSet();
MySet c(100);
c.insertElement(7);
c.insertElement(13);
c.insertElement(20);
std::cout << "B equals C: "
<< (b.isEqualTo(c) ? "true" : "false") << '\n';
c = a; // deep-copy assignment
c.insertElement(5);
c = c; // self-assignment
std::cout << "C after assignment: "; c.printSet();
std::cout << "A remains: "; a.printSet();
std::cout << "C contains 99: "
<< (c.contains(99) ? "true" : "false") << '\n';
MySet empty(5);
std::cout << "Empty: "; empty.printSet();
a.deleteElement(-1); // invalid
}