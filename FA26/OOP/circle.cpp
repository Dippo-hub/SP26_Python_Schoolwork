#include <circle.h>
#include <iostream>

Circle::Circle() {
    radius = 1;
}

Circle::Circle(double radius) {
    this->radius = radius;
}

double Circle::getArea() {
    return Circle::radius*Circle::radius*3.1415;
}

double Circle::getCircumference() {
    return Circle::radius*2*3.1415;
}

void Circle::display() {
    std::cout << "Circle has radius " << radius << ", area " << getArea() << ", and circumference " << getCircumference() << std::endl;
}

