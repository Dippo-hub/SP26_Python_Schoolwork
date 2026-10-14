#include <iostream>
#include <string>
using namespace std;
#define SIZE 20

//to allocate memory, use new keyword
//to deallocate, use delete keyword

int* reverseOrderArray(const int* arr, int size) { //uses the heap memory to "return" a list
    //int result[size]; antiquated
    int* result = new int[size]; //integer pointer result to array on the heap, able to be accessed outside function

    for(int i=0, j=size-1; i<size; i++, j--) {
        result[j] = arr[i];
    }

    return result;
}

class Student {
    public:
        string *firstname, *lastname;
        int age;
        double GPA;

        Student() {
            firstname = new string[SIZE];
            lastname = new string[SIZE];
            age = 18;
            GPA = 4;
        }
};

class Circle {
    private:
        double radius;
        static int circleCount;
    public:
        void setRadius(double radius) {
            if(radius>=0)
                this->radius = radius;
        }
        Circle() {
            radius = 1;
            circleCount++;
        }

        Circle(double radius) {
            if(radius>=0)
                this->radius = radius;
            else   
                this->radius = 1;
        }

        double getRadius() const {
            return radius;
        }

        static int getCircleCount() {
            return circleCount;
        }
};

int main(void) {
    Student s1;
    s1.age; //accessing primitive type
    s1.firstname; //accessing pointer

    Student *s2 = new Student;
    s2->age; //for pointer object on heap
    delete s2;

    //Circle c1;
    //Circle *c2 = new Circle();

    //cout << c1.getRadius() << endl;
    //cout << c2->getRadius() << endl;
    //for deleting array, use delete [] arrayname

    int series[] = {1,2,3,4,5};
    int* result = reverseOrderArray(series, 5);
    for(int k=0; k<5; k++)
        cout << result[k] << " ";
    cout << endl;
}