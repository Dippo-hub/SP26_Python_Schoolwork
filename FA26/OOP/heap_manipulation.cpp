#include <iostream>
#include <string>
using namespace std;
#define SIZE 20

//to allocate memory, use new keyword
//to deallocate, use delete keyword

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

int main(void) {
    Student s1;
    s1.age; //accessing primitive type
    s1->firstname; //accessing pointer

    Student *s2 = new Student;
    s2->age;
}