#ifndef MVECTOR_H
#define MVECTOR_H

template<typename T>
class MVECTOR {
    private:
        int size, capacity;
        T *arr;
    public:
        MVECTOR();
        MVECTOR(int _capacity);

        MVECTOR(const MVECTOR<T> &o);
        ~MVECTOR();

        int getSize() const;
        int getCapacity() const;
        T* getArr() const;
        void print() const;
        void popback();
        void pushback(T element);
};

#endif