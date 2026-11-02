#ifndef LARGENUMBER_H
#define LARGENUMBER_H
#include <cmath>
class LargeNumber {
    private:
        double mantissa;
        int exponent;
    public:
        LargeNumber() : mantissa(0), exponent(0) {}

        LargeNumber(double _mantissa, int _exponent) : mantissa(_mantissa), exponent(_exponent) {}

        double getMantissa() const {
            return mantissa;
        }

        int getExponent() const {
            return exponent;
        }

        void setMantissa(double m) {
            mantissa = m;
        }

        void setExponent(double e) {
            exponent = e;
        }
        void normalize() {
            while(mantissa>10) {
                exponent++;
                mantissa /= 10;
            }
            while(mantissa<1 && mantissa>0) {
                exponent--;
                mantissa *= 10;
            }
        }

        //add
        LargeNumber addition(const LargeNumber &other) const {
            int exp_diff = exponent - other.getExponent();
            int workingE;
            if(other.getExponent() > exponent) {
                workingE = other.getExponent();
            } else {
                workingE = exponent;
            }
            double workingM = mantissa * (10 ^ exp_diff);
            double newM = workingM + other.getMantissa();
            LargeNumber result(newM, workingE);
            result.normalize();
            return result;
        }
        //or
        LargeNumber operator +(const LargeNumber &other) const {
            int exp_diff = this->exponent - other.getExponent();
            int workingE;
            if(other.getExponent() > exponent) {
                workingE = other.getExponent();
            } else {
                workingE = exponent;
            }
            double workingM = mantissa * (10 ^ exp_diff);
            double newM = workingM + other.getMantissa();
            while(newM>10) {
                workingE++;
                newM /= 10;
            }
            LargeNumber result(newM, workingE);
            return result;
        }

        //subtract
        LargeNumber subtraction(const LargeNumber &other) const {
            int exp_diff = this->exponent - other.getExponent();
            int workingE;
            if(other.getExponent() > exponent) {
                workingE = other.getExponent();
            } else {
                workingE = exponent;
            }
            double workingM = mantissa * (10 ^ exp_diff);
            double newM = workingM - other.getMantissa();
            LargeNumber result(newM, workingE);
            result.normalize();
            return result;
        }
        //or
        LargeNumber operator -(const LargeNumber &other) const {
            int exp_diff = this->exponent - other.getExponent();
            int workingE;
            if(other.getExponent() > exponent) {
                workingE = other.getExponent();
            } else {
                workingE = exponent;
            }
            double workingM = mantissa * (10 ^ exp_diff);
            double newM = workingM - other.getMantissa();
            LargeNumber result(newM, workingE);
            result.normalize();
            return result;
        }
        //multiply
        LargeNumber multiply(const LargeNumber &other) const {
            double newM = mantissa * other.getMantissa();
            int newE = exponent + other.getExponent();
            LargeNumber result(newM, newE);
            result.normalize();
            return result;
        }
        //or
        LargeNumber operator *(const LargeNumber &other) const {
            double newM = mantissa * other.getMantissa();
            int newE = exponent + other.getExponent();
            LargeNumber result(newM, newE);
            result.normalize();
            return result;
        }
        //divide
        LargeNumber divide(const LargeNumber &other) const {
            double newM = mantissa / other.getMantissa();
            int newE = exponent - other.getExponent();
            LargeNumber result(newM, newE);
            result.normalize();
            return result;
        }
        //or
        LargeNumber operator /(const LargeNumber &other) const {
            double newM = mantissa / other.getMantissa();
            int newE = exponent - other.getExponent();
            LargeNumber result(newM, newE);
            result.normalize();
            return result;
        }
        //comparison 
        bool equals(const LargeNumber &other) const;
        bool lessThan(const LargeNumber &other) const;
        //etc

        void disp() {
            std::cout << mantissa << 'e' << exponent << std::endl;
        }
};

#endif

