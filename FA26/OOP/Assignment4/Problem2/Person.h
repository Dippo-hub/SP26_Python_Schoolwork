#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <cstring>

class Address {
private:
std::string city;
std::string state;
public:
Address(const std::string& c, const std::string& s)
: city(c), state(s) { }
std::string getCity() const { return city; }
std::string getState() const { return state; }
};

class Person {
private:
char* name;
int age;
Address address; // composition: stored by value
public:
Person(const char* name, int age,
const std::string& city, const std::string& state);
Person(const Person& other);
Person& operator=(const Person& other);
~Person();
void setName(const char* newName);
void display() const;
};

#endif