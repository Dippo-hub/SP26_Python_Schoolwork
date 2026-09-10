/*Write a complete C++ program that prompts the user to enter the side of a hexagon and
displays its area. The area of a hexagon can be computed using the following formula (s is thelength of a side): Area = 6s^2/4*tan(pi/6)*/

#include <iostream>
#include <iomanip>
#include <cmath>

#define PI 3.1415

void hex_area() {
    double s, numerator, denominator, area;

    std::cout << "Enter side length: ";
    std::cin >> s;

    numerator = 6*s*s;
    denominator = 4*tan(PI/6);

    area = numerator / denominator;
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Area: " << area << std::endl;
}

int main () {
    hex_area();
    return 0;
}