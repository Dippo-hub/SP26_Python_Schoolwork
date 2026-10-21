#include "MVECTOR.h"

template <typename T>
MVECTOR<T>::MVECTOR() {
    size=0;
    capacity=2;
    arr = new T[capacity];
}

template <typename T>
MVECTOR<T>::MVECTOR(int _capacity) {
    size=0;
    capacity=_capacity;
    arr = new T[capacity];
}

template <typename T>
MVECTOR<T>::MVECTOR(const MVECTOR<T> &o) {
    size=o.size;
    capacity = o.capacity;

    arr = new T[capacity]

    for(int i=0; i<size; i++) {
        arr[i]=other.arr[i];
    }
}
template <typename T>
MVECTOR<T>::~MVECTOR() {
    delete [] arr;
}
template <typename T>
int MVECTOR<T>::getSize() const {
    return size;
}
template <typename T>
int MVECTOR<T>::getCapacity() const {
    return capacity;
}
template <typename T>
T* MVECTOR<T>::getArr() const {
    return arr;
}
template <typename T>
void MVECTOR<T>::print() const {
    cout << "Size: " << size << endl;
    cout << "Capacity" << capacity << endl;
    cout << "{ ";
    for(int y=0; y<size; y++)
        cout << arr[y] << " ";
    cout<< "}" <<  endl;
}
template <typename T>
void MVECTOR<T>::popback() {
    size--;

    if(size<capacity/2) {
        capacity /= 2;
        T *temp = new T[capacity];

        for (int k=0; k<size; k++) 
            temp[k]=arr[k];

        delete [] arr;
        arr = temp;
    }
}

template <typename T>
void MVECTOR<T>::pushback(T element) {
    if(size<capacity) {
        arr[size] = element;
        size++
    } else {
        capacity *= 2;
        T *temp = new T[capacity];

        for(int h=0; h<size; h++) 
            temp[i] = arr[i];

        delete [] arr;
        arr = temp;
        arr[size] = element;
        size++;
    }
}

template class MVECTOR<int>;
template class MVECTOR<double>;
template class MVECTOR<char>;