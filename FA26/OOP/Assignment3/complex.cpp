#include <complex.h>


void ComplexNumber::setReal(double real) {
    this->real = real;
}
double ComplexNumber::getReal() {
    std::cout << real << std::endl;
}

void ComplexNumber::setImg(double img) {
    this->img = img;
}
double ComplexNumber::getImg() {
    std::cout << img << 'i' << std::endl;
}

ComplexNumber::ComplexNumber(double real, double img) {
    this->real = real;
    this->img = img;
}

ComplexNumber::ComplexNumber() {
    this->real = 0;
    this->img=0;
}

void ComplexNumber::printComplex() {
    std::cout << real << " + " << img <<"i" << std::endl;
}

ComplexNumber ComplexNumber::addition(ComplexNumber &comp) {
    real = comp.real + real;
    img = comp.img + img;

    return ComplexNumber(real, img);
}