#include "MySet.h"

        MySet::MySet(unsigned int maxValue) {
            range = maxValue;
            elements = new bool[range+1]{};
            count = 0;
        }
        MySet::MySet(const MySet& other) {
            range = other.getRange();
            count = other.getSize();
            bool* newElements = new bool[range+1]{};

            for(short i=0; i<+range; i++) {
                if(other.contains(i))
                    newElements[i]=true;
            }

            delete [] elements;
            elements = newElements;
        }

        MySet& MySet::operator=(const MySet& other) {
            if (this==&other)
                return *this;
            range = other.getRange();
            count = other.getSize();
            bool* newElements = new bool[range+1]{};

            for(short i=0; i<+range; i++) {
                if(other.contains(i))
                    newElements[i]=true;
            }

            delete [] elements;
            elements = newElements;
            return *this;
        }
        
        MySet::~MySet() {
            delete [] elements;
        }
        void MySet::insertElement(int k) {
            if(k<0||k>range) {
                std::cout << std::endl << "Out of range: " << k << std::endl;
                return;}
            if (!(elements[k]))
                count++;
            elements[k] = true;

        }
        void MySet::deleteElement(int k) {
            if(k<0||k>range) {
                std::cout << std::endl << "Out of range: " << k << std::endl;
                return;}
            if(elements[k])
                count--;
            elements[k]=false;
        }
        bool MySet::contains(int k) const {
            if(k<0||k>range) {
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
            for(short j=0; j<=range; j++) {
                if (elements[j])
                std::cout << j << " ";
            }
        }
        //i'm unsure what the question is asking here, my interpretation is an element
        //by element comparison along the range of the smaller set and if they all match
        //then return true regardless of the fact that the ranges are different
        bool MySet::isEqualTo(const MySet& other) const {
            unsigned int smallest;
            if(range>other.getRange())
                smallest = range;
            else
                smallest = other.getRange();
            unsigned int matches = 0;
            for(int h=0; h<=smallest; h++) {
                if (this->contains(h) && other.contains(h))
                    matches++;
            }

            return matches==smallest;
        }