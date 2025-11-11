#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Instructor.h"
#include "Course.h"


using namespace std;

// ==================== Person Class Implementation =========================
Person( string& name, int age) : name(name), age(age) {


}
virtual void display() const {
    cout << "Name: " << Person.name << ", Age: " << Person.age << endl;
}




// ==================== Student Class Implementation ====================
Student(const string& name, int age, const string& studentID)
    : Person(name, age), studentID(studentID) {

}
void display(){
        Person::display();
        cout << "Year Level: " << yearLevel << ", Major: " << major << endl;
    }


// ==================== Instructor Class Implementation ====================
Instructor(const string& name, int age, const string& department)
    : Person(name, age), department(department) {

}
void display(){


}


// ==================== Course Class Implementation ====================
Course( string& courseName,  Instructor& instructor)
    : courseName(courseName), instructor(instructor) {

}
void addStudent(const Student& student) {
    students.push_back(student);
}
void displayCourseInfo() const {
    cout << "Course Name: " << courseName << endl;
    cout << "Instructor Info: ";
    instructor.display();
    cout << "Enrolled Students:" << endl;
    for (const auto& student : students) {
        student.display();
    }
}

// ==================== Main Function ====================
int main() {


    return 0;
}
