#include "triangle.h"

int main(void) {
    Triangle d, t1(4,4,4), t2(5,5,2), t3(5.5,5.5,1);
    Triangle t1copy(t1);

    d.display();
    t1.display();
    t2.display();
    t3.display();

    cout << boolalpha << (t2 < t1) << " " << (t3 >= t1) << " " << (t1 != t1copy) << endl;
}