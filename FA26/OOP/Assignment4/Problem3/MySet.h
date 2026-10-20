#ifndef MYSET_H
#define MYSET_H

#include <iostream>

class MySet {
    private:
        unsigned int range; // valid values: 0 ... range
        unsigned int count; // number of distinct values in the set
        bool* elements; // dynamically allocated array of range + 1
    public:
        explicit MySet(unsigned int maxValue);
        MySet(const MySet& other);
        MySet& operator=(const MySet& other);
        ~MySet();
        void insertElement(int k);
        void deleteElement(int k);
        bool contains(int k) const;
        unsigned int getRange() const;
        unsigned int getSize() const;
        void printSet() const;
        bool isEqualTo(const MySet& other) const;
};

#endif