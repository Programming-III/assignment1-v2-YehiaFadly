#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Student.h"
#include <iostream>

using namespace std;
//#write your code here

class Course {
    private:
    // unique coursecode 
    string courseCode;
    string courseName;
    int maxStudents;
    Student* students;
    int currentStudents;
    public:
    Cousre();

    Course(string code, string name, int max);
    void addStudent(const Student& s);

    void displayCourseInfo();
}




#endif
