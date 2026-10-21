#include "generic_stack.h"
template <typename T>
void GenericStack::<T>push(const T& value);

template <typename T>
bool GenericStack::<T>pop(T& removed);

template <typename T>
bool GenericStack::<T>peek(T& value) const;

template <typename T>
bool GenericStack::<T>isEmpty() const;

template <typename T>
std::size_t GenericStack::<T>getSize() const;

// Also implement this function template in the same header:
template <typename T>
T GenericStack::<T>largerOf(const T& a, const T& b);

