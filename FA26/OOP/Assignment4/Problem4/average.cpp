#include <iostream>
#include <cmath>
using namespace std;

int average(const int* array, int size) {
    int sum=0;
    for(int i=0; i<size; i++) 
        sum+=*(array+i);
    return floor(sum/size);
}
double average(const double* array, int size) {
    double sum=0;
    for(int j=0; j<size; j++)
        sum+=*(array+j);
    return sum/size;
}

int main(void) {
    int ints[] = {2, 4, 6, 8, 10};
    double doubles[] = {1.5, 2.0, 4.0, 6.5};
    std::cout << "Integer average: " << average(ints, 5) << '\n';
    std::cout << "Double average: " << average(doubles, 4) << '\n';
}