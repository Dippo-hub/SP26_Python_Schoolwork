#include <iostream>
using namespace std;

class MyInt {
    private:
        int number;
        static double averageOfInts;
        static int sumOfInts, numOfInts;

    public:
        MyInt(int _num) {
            number = _num;
            numOfInts++;
            sumOfInts+=_num;
            averageOfInts = sumOfInts/numOfInts;
        }

        int getNum() const {
            return number;
        }

        bool isEven() const {
            if(number%2==0)
                return true;
            return false;
        }

        static bool isOdd(int _number) {
            if(_number%2==1)
                return true;
            return false;
        }

        bool equals(int n) const {
            if (number==n)
                return true;
            return false;
        }

        bool equals(const MyInt &MyInteger) const {
            if (number == MyInteger.getNum())
                return true;
            return false;
        }

        static double getAvgOfInts() {
            if(numOfInts==0)
                return 0;
            else {
                averageOfInts = sumOfInts/numOfInts;
                return averageOfInts;
            }
        }
};

double MyInt::averageOfInts = 0.0;
int MyInt::sumOfInts = 0;
int MyInt::numOfInts = 0;

int main(void) {
    cout << "Initial Average:" << MyInt::getAvgOfInts() << endl;
    cout << "Is Odd)3): " << MyInt::isOdd(3) << endl;
    MyInt i1(9323), i2(147), i3(9323);
    cout << "i1 is Even: " << i1.isEven() << endl;
    cout << "i3 equals 843: " << i3.equals(843) << endl;
    cout << "i3 equals i1: " << i3.equals(i1) << endl;
    cout << "Final Average: " << MyInt::getAvgOfInts() << endl;
}