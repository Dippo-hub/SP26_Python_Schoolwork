#ifndef COURSE_H
#define COURSE_H

#include "student.h"

class Course {
    private:
        string name;
        int capacity, numAttending, ID, credits;
        Student *students;

    public:
        Course();
        Course(string &name_, int capacity_, int ID_, int credits_);
        ~Course(); //MUST DEALLOCATE POINTERS BEFOER DEALLOCATING CLASS
        Course(const Course &c); //To create a "deep copy" by creating a new student array rather than the default pointing to the original one

        string getCourseName() const;
        int getCapacity() const;
        int getNumAttending() const;
        int getID() const;
        Student* getStudents() const;

        void setCourseName(const string &name_);
        void setID(int ID_);
        void setCredits(int credits_);
        void setCapacity(int capacity_);
        void addStudent(const Student &s);

        void completeCourse(char grades[]) const;
};

#endif