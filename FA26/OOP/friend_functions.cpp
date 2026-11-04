//member functions that are not actually member functions but can still access private data fields
#include <iostream>
using namespace std;
class J;

class K {
    public:
        void changeStuff(J &j);
};

class J {
    private:
        int stuff;
    public:
        J(int s) : stuff(s) {}

        friend void K::changeStuff(J &j);
        friend ostream &operator << (ostream &out, const J &j); //cout
        friend istream &operator >> (istream &in, const J &j); //cin

    //can overload << like for cout with friend method
};

void K::changeStuff(J &j) {
    j.stuff = 87;
    cout << j.stuff;
}

ostream &operator <<(ostream &out, const J &j) {
    out << "Stuff: " << j.stuff << "\n";
    return out;
}

istream &operator >>(istream &in, const J &j) {
    in >> j.stuff;
    return in;
}

int main(void) {
    J jack(7);
    J james(77);

    cout << jack << james << endl;
}