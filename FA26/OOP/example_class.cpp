#include <iostream>
#include <string>
#include <circle.h>


int id = 0;

class Student {
    public:
        std::string firstname, lastname;
        int studentID, credits;
        double GPA;

        Student() {
            firstname = "John";
            lastname = "Doe";
            studentID = 0;
            credits = 0;
            GPA = 0;
        }

        Student(std::string _firstname, std::string _lastname, int _studentID, int _credits, double _GPA) {
            firstname = _firstname;
            lastname = _lastname;
            studentID = _studentID;
            credits = _credits;
            GPA = _GPA;
        }

        Student(std::string firstname, std::string lastname) {
            this->firstname = firstname;
            this->lastname = lastname;
            this->studentID = ++id;
            this->credits = 0;
            this->GPA = 0;
        }

        void display() {
            std::cout << "Student name: " << firstname << " " << lastname << std::endl;
            std::cout << "Student ID: " << studentID << std::endl;
            std::cout << "Student stats. GPA: " << GPA << " Credits: " << credits << std::endl;
        }

        void addCourse(int __credits, const char grade) {

            int gNum;
            switch(grade) {
                case 'A': gNum = 4;
                break;
                case 'B': gNum = 3;
                break;
                case 'C': gNum = 2;
                break;
                case 'D': gNum = 1;
                break;
                case 'F': gNum = 0;
                break;
                default: std::cout << "Grade is not correct." << std::endl;
            }
            GPA = ((GPA*credits) + (gNum * __credits)) / (credits + __credits);
            credits += __credits;
        }
};
/*void printCircle(const Circle &cir) {
    std::cout << "Circle has radius " << cir.radius << ", area " << cir.getArea() << ", and circumference " << cir.getCircumference() << std::endl;
}*/

int main(void) {
/*

    Circle newCircle1;
    Circle newCircle2(14);

    std::cout << newCircle1.getArea() << " " << newCircle2.getCircumference() << std::endl;

    newCircle1.radius = 34;
    std::cout << newCircle1.getArea() << std::endl;

    Circle *cir = &newCircle2;
    printCircle(*cir);
    newCircle2.display();
    */
    Student s1;
    Student s2("James", "Barclay", 57, 12, 4.0);
    Student s3("Jeremy", "Clarkson");

    s1.display();
    s2.display();
    s3.display();

    s3.addCourse(3, 'C');
    s3.display();
    s2.addCourse(4, 'B');
    s2.display();
    
}

//Can make a class as library with a new file with .h