#include <iostream>
class Complex {
    private:
        double real, img;
    public:
        Complex()
        {
        real = 0.0;
        img = 0.0;
        }
        Complex(double _real, double _img)
        {
        real = _real;
        img = _img;
        }
        double getReal()
        {
        return real;
        }
        double getImg()
        {
        return img;
        }
        void setReal(double _real)
        {
        real = _real;
        }
        void setImg(double _img)
        {
        img = _img;
        }
        void printComplex()
        {
        if(img < 0)
        std::cout << real << " " << img << 'i' << std::endl;
        else
        std::cout << real << " + " << img << 'i' << std::endl;
        }
        Complex addition (Complex & comp)
        {
        Complex result(real + comp.getReal(), img + comp.getImg());
        return result;
        }
        Complex operator +(Complex &c) {
            Complex result(real + c.getReal(), img + c.getImg());
            return result;
        }
        };

int main(void) {
    Complex c(4, 3), i(2, 7);
    Complex j = c+i;
    j.printComplex();
}