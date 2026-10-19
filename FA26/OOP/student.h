#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student {
    private:
        string firstname, lastname;
        int age, totalCredits, numOfCourses;
        double GPA;
        static string university;
        static int studentCount;

    public:
        Student();
        Student(const string &firstname_, const string &lastname_, int age_);
        ~Student();

        void setName(const string &firstname_, const string &lastname_);
        void setAge(int age_);

        int getAge() const;
        int getCredits() const;
        int getNumOfCourses() const;
        string getName() const;
        double getGPA() const;

        static string getUniAddress();
        static int getStudentCount();

        void addCourse(int credit, char grade);
};

#endif