#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "Person.h"
#include <string>
#include <iostream>
// Instructor.h - declaration only. Implementations are in main.cpp per assignment.

class Instructor : public Person {
private:
    std::string department;
    int experienceYears;
public:
    Instructor();
    Instructor(const std::string& name, int id, const std::string& department, int experienceYears);
    ~Instructor();

    void setDepartment(const std::string& d);
    std::string getDepartment() const;
    void setExperienceYears(int e);
    int getExperienceYears() const;

    void display() const override;
};

#endif
