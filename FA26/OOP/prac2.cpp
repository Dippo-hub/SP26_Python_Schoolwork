#include <iostream>
#include <iomanip>

void meter_conversion(short meters) {
    int i=1;
    float conversion=3.280;
    std::cout << std::left;
    std::cout << std::setw(10) << "Meters";
    std::cout << std::right;
    std::cout << std::setw(10) << "Feet" << std::endl;
    do
    {
        float feet = i*conversion;
        std::cout << std::left << std::setw(10) << i << std::right << std::setw(10) << feet << std::endl;
        

    } while (i++<=meters);
    
}

int main () {
    meter_conversion(10);
    return 0;
}