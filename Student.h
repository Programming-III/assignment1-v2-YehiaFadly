#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>
#include <iostream>

#endif
// Student.h - declaration only. Implementations are in main.cpp per assignment.

class Student : public Person {
private:
    int yearLevel;
    std::string major;
public:
    Student();
    Student(const std::string& name, int id, int yearLevel, const std::string& major);
    ~Student();

    void setYearLevel(int y);
    int getYearLevel() const;
    void setMajor(const std::string& m);
    std::string getMajor() const;

    void display() const override;
};

#endif
