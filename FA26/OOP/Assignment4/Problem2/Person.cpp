#include "Person.h"

Person::Person(const char* name, int age,
               const std::string& city, const std::string& state)
    : name(new char[std::strlen(name) + 1]),
      age(age),
      address(city, state)
{
    std::strcpy(this->name, name);
}
Person::Person(const Person& other)
    : name(new char[std::strlen(other.name) + 1]),
      age(other.age),
      address(other.address)
{
    std::strcpy(name, other.name);
}
Person& Person::operator=(const Person& other) {
    if (this == &other) {
        return *this;
    }

    char* newName = new char[std::strlen(other.name) + 1];
    std::strcpy(newName, other.name);

    delete[] name;
    name = newName;
    age = other.age;
    address = other.address;

    return *this;
}
Person::~Person() {
    delete [] this->name;
}
void Person::setName(const char* newName) {
    char* nameCopy = new char[std::strlen(newName) + 1];
    std::strcpy(nameCopy, newName);

    delete[] name;
    name = nameCopy;
}

void Person::display() const {
    std::cout << name << ", " << age << ", " << address.getCity() << ", "<< address.getState() << std::endl;
}