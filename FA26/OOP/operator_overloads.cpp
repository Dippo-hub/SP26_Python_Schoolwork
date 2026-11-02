//overloading +,-, etc

#include <iostream>
#include "LargeNumber.h"
using namespace std;


int main(void) {
    LargeNumber a(2, 12), b(3, 10);
    LargeNumber c = a + b;
    LargeNumber d = a.addition(b);
    a.disp();
    b.disp();
    c.disp();
    d.disp();
}