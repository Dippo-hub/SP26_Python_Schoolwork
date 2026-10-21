#ifndef GENERIC_STACK_H
#define GENERIC_STACK_H
#include <cstddef>
#include <vector>
template <typename T>
class GenericStack {
private:
std::vector<T> elements;
public:
void push(const T& value);
bool pop(T& removed);
bool peek(T& value) const;
bool isEmpty() const;
std::size_t getSize() const;
};
// Also implement this function template in the same header:
template <typename T>
T largerOf(const T& a, const T& b);
#endif