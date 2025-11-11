#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Student.h"
#include <iostream>

using namespace std;

class Instructor; 

class Course {
private:
    std::string courseCode;
    std::string courseName;
    int maxStudents;
    Student* students;
    int currentStudents;
    Instructor* instructor; 
public:
    Course();
    Course(const std::string& code, const std::string& name, int maxStudents, Instructor* instructor);
    ~Course();

    void addStudent(const Student& s);
    void displayCourseInfo() const;

    std::string getCourseCode() const;
    std::string getCourseName() const;
};

#endif

