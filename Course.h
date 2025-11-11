#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Student.h"
#include <iostream>

using namespace std;
// Course.h - declaration only. Implementations are in main.cpp per assignment.

class Instructor; // forward declare (Instructor included in main implementations)

class Course {
private:
    std::string courseCode;
    std::string courseName;
    int maxStudents;
    Student* students; // dynamic array
    int currentStudents;
    Instructor* instructor; // pointer to instructor (store reference externally)
public:
    Course();
    Course(const std::string& code, const std::string& name, int maxStudents, Instructor* instructor);
    ~Course();

    void addStudent(const Student& s);
    void displayCourseInfo() const;

    // getters
    std::string getCourseCode() const;
    std::string getCourseName() const;
};

#endif

