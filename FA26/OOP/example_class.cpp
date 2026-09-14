#include <iostream>

class Circle {
    public:
        double radius;
        //Constructors (basically __init__. No args is a default value, Circle with args is input.)
        Circle() {
            radius = 1;
        }

        Circle(double newRadius) {
            radius = newRadius;
        }

        double getArea() const {
            return radius*radius*3.1415;
        }

        double getCircumference() const {
            return 2*radius*3.1415;
        }

        void display() {
            std::cout << "Circle has radius " << radius << ", area " << getArea() << ", and circumference " << getCircumference() << std::endl;
        }
};

void printCircle(const Circle &cir) {
    std::cout << "Circle has radius " << cir.radius << ", area " << cir.getArea() << ", and circumference " << cir.getCircumference() << std::endl;
}

int main(void) {
    Circle newCircle1;
    Circle newCircle2(14);

    std::cout << newCircle1.getArea() << " " << newCircle2.getCircumference() << std::endl;

    newCircle1.radius = 34;
    std::cout << newCircle1.getArea() << std::endl;

    Circle *cir = &newCircle2;
    printCircle(*cir);
    newCircle2.display();
}