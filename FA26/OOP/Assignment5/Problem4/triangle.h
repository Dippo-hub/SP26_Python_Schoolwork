#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Triangle {
    private:
        double s1,s2,s3;
    public:
        Triangle();
        Triangle(double s1, double s2, double s3);
        double getPerimeter() const;
        double getArea() const;
        void display() const;
        bool operator<(const Triangle& other) const;
        bool operator>=(const Triangle& other) const;
        bool operator!=(const Triangle& other) const;
};

#endif