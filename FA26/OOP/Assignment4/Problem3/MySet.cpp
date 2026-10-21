#include "MySet.h"

        MySet::MySet(unsigned int maxValue)
            : range(maxValue), count(0), elements(new bool[maxValue + 1]{}) {}

        MySet::MySet(const MySet& other)
            : range(other.range), count(other.count),
              elements(new bool[other.range + 1]{}) {
            for (unsigned int i = 0; i <= range; ++i)
                elements[i] = other.elements[i];
        }

        MySet& MySet::operator=(const MySet& other) {
            if (this==&other)
                return *this;

            bool* newElements = new bool[other.range + 1]{};
            for (unsigned int i = 0; i <= other.range; ++i)
                newElements[i] = other.elements[i];

            delete[] elements;
            elements = newElements;
            range = other.range;
            count = other.count;
            return *this;
        }
        
        MySet::~MySet() {
            delete [] elements;
        }
        void MySet::insertElement(int k) {
            if(k < 0 || static_cast<unsigned int>(k) > range) {
                std::cout << std::endl << "Out of range: " << k << std::endl;
                return;}
            if (!(elements[k]))
                count++;
            elements[k] = true;

        }
        void MySet::deleteElement(int k) {
            if(k < 0 || static_cast<unsigned int>(k) > range) {
                std::cout << std::endl << "Out of range: " << k << std::endl;
                return;}
            if(elements[k])
                count--;
            elements[k]=false;
        }
        bool MySet::contains(int k) const {
            if(k < 0 || static_cast<unsigned int>(k) > range) {
                std::cout << std::endl << "Out of range: " << k << std::endl;
                return false;}
            return elements[k];
        }
        unsigned int MySet::getSize() const {
            return count;
        }
        unsigned int MySet::getRange() const {
            return range;
        }
        void MySet::printSet() const {
            std::cout << std::endl << "{ ";
            for(unsigned int j=0; j<=range; j++) {
                if (elements[j])
                std::cout << j << " ";
            }
            std::cout << " }" << std::endl;
        }
        bool MySet::isEqualTo(const MySet& other) const {
            const unsigned int largestRange = range > other.range ? range : other.range;
            for (unsigned int i = 0; i <= largestRange; ++i) {
                const bool inThis = i <= range && elements[i];
                const bool inOther = i <= other.range && other.elements[i];
                if (inThis != inOther)
                    return false;
            }
            return true;
        }