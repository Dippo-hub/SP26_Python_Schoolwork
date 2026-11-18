#include "triangle.h"

Triangle::Triangle() : s1(1), s2(1), s3(1) {}
Triangle::Triangle(double _s1, double _s2, double _s3) : s1(_s1), s2(_s2), s3(_s3) {}
double Triangle::getPerimeter() const { return s1+s2+s3; }
double Triangle::getArea() const {
    double s = getPerimeter()/2;
    return sqrt(s*(s-s1)*(s-s2)*(s-s3));
}
void Triangle::display() const { cout << setprecision(2) << "Sides: " << s1 << " " << s2 << " " << s3 << " Perimeter: " << getPerimeter() << " Area: " << getArea() << endl;}
bool Triangle::operator<(const Triangle& other) const { return getArea() < other.getArea(); }
bool Triangle::operator>=(const Triangle& other) const { return getArea() >= other.getArea(); }
bool Triangle::operator!=(const Triangle& other) const { return getArea() != other.getArea(); }