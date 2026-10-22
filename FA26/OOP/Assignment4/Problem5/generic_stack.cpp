#include "generic_stack.h"
template <typename T>
void GenericStack<T>::push(const T& value) {
    elements.emplace_back(value);
}

template <typename T>
bool GenericStack<T>::pop(T& removed) {
    if(elements.size == 0) {
        cout << "Cannot pop, stack is empty." << endl;
        return false;
    } else {
        elements.pop_back();
        cout << "Popped: " << removed << endl;
        return true;
    }
}

template <typename T>
bool GenericStack<T>::peek(T& value) const {
    if(elements.size == 0) {
        cout << "Stack is empty, cannot peek." << endl;
        return false;
    } else {
        *value = elements.end + *value;
        return true;
    }
} //looks at order right to left

template <typename T>
bool GenericStack<T>::isEmpty() const {
    return (elements.size == 0);
}

template <typename T>
std::size_t GenericStack<T>::getSize() const {
    return elements.size;
}

// Also implement this function template in the same header:


