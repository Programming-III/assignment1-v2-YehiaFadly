#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "Person.h"
#include <string>
#include <iostream>
using namespace std;
//#write Instructor class here

class Instructor: public Person{
    private:
    string department;
    int experienceYears;
    public:
    Instructor(string n, int d, string dept, int exp) : Person(n, d);
    void display();
};


#endif
