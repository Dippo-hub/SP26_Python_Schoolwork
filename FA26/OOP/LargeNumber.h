#ifndef LARGENUMBER_H
#define LARGENUMBER_H
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
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
            if (mantissa == 0) {
                exponent = 0;
                return;
            }
            while(std::abs(mantissa) >= 10) {
                exponent++;
                mantissa /= 10;
            }
            while(std::abs(mantissa) < 1) {
                exponent--;
                mantissa *= 10;
            }
        }

        //add
        LargeNumber addition(const LargeNumber &other) const {
            int workingE = std::max(exponent, other.getExponent());
            double newM =
                mantissa * std::pow(10.0, exponent - workingE) +
                other.getMantissa() * std::pow(10.0, other.getExponent() - workingE);
            LargeNumber result(newM, workingE);
            result.normalize();
            return result;
        }
        //or
        LargeNumber operator +(const LargeNumber &other) const {
            return addition(other);
        }

        //subtract
        LargeNumber subtraction(const LargeNumber &other) const {
            int workingE = std::max(exponent, other.getExponent());
            double newM =
                mantissa * std::pow(10.0, exponent - workingE) -
                other.getMantissa() * std::pow(10.0, other.getExponent() - workingE);
            LargeNumber result(newM, workingE);
            result.normalize();
            return result;
        }
        //or
        LargeNumber operator -(const LargeNumber &other) const {
            return subtraction(other);
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
        bool equals(const LargeNumber &other) const {
            return (mantissa == other.getMantissa() && exponent == other.getExponent());
        }

        bool operator ==(const LargeNumber &other) const {
            return (mantissa == other.getMantissa() && exponent == other.getExponent());
        }

        bool operator <(const LargeNumber &other) const {
            if (other.getExponent() > exponent) 
                return true;
            else if (exponent > other.getExponent())
                return false;
            else
                return mantissa < other.getMantissa();
        }
        bool lessThan(const LargeNumber &other) const {
            if (other.getExponent() > exponent) 
                return true;
            else if (exponent > other.getExponent())
                return false;
            else
                return mantissa < other.getMantissa();
        }

        bool greaterThan(const LargeNumber &other) const {
            if (other.getExponent() > exponent) 
                return false;
            else if (exponent > other.getExponent())
                return true;
            else
                return mantissa > other.getMantissa();
        }

        bool operator >(const LargeNumber &other) const {
            return greaterThan(other);
        }

        bool operator <=(const LargeNumber &other) const {
            return equals(other) || lessThan(other);
        }
        
        bool operator >=(const LargeNumber &other) const {
            return equals(other) || greaterThan(other);
        }

        void disp() {
            std::cout << mantissa << 'e' << exponent << std::endl;
        }
};
#endif
