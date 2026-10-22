#ifndef GENERIC_STACK_H
#define GENERIC_STACK_H
#include <cstddef>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class GenericStack {
private:
std::vector<T> elements;
public:
void push(const T& value) {
    elements.emplace_back(value);
}
bool pop(T& removed) {
    if (elements.empty()) {
        cout << "Stack empty, cannot pop." << endl;
        return false;
    }
    removed = elements.back();
    elements.pop_back();
    return true;
}

bool peek(T& value) const {
    if (elements.empty()) {
        cout << "Stack empty, cannot peek." << endl;
        return false;
    }
    value = elements.back();
    return true;
} //looks at order right to left


bool isEmpty() const {
    return (elements.size() == 0);
}


std::size_t getSize() const {
    return elements.size();
}

};

template <typename T>
T largerOf(const T& a, const T& b) {
    return (a > b) ? a : b;
}

#endif