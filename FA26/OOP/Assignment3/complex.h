
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class ComplexNumber {
    private:
        double real, img;
    public:
        ComplexNumber();
        void setReal(double real);
        double getReal();

        void setImg(double img);
        double getImg();

        ComplexNumber(double real, double img);

        void printComplex();

        ComplexNumber addition(ComplexNumber &comp);

};

#endif