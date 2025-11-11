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

    // ---------------- Person ----------------
    Person::Person() : name(""), id(0) {}
    Person::Person(const std::string& name_, int id_) : name(name_), id(id_) {}
    Person::~Person() {}

    void Person::setName(const std::string& name_) { name = name_; }
    std::string Person::getName() const { return name; }
    void Person::setId(int id_) { id = id_; }
    int Person::getId() const { return id; }

    void Person::display() const {
        std::cout << "Name: " << name << " (ID: " << id << ")" << std::endl;
    }

    // ---------------- Student ----------------
    Student::Student() : Person(), yearLevel(0), major("") {}
    Student::Student(const std::string& name, int id, int yearLevel_, const std::string& major_)
        : Person(name, id), yearLevel(yearLevel_), major(major_) {}
    Student::~Student() {}

    void Student::setYearLevel(int y) { yearLevel = y; }
    int Student::getYearLevel() const { return yearLevel; }
    void Student::setMajor(const std::string& m) { major = m; }
    std::string Student::getMajor() const { return major; }

    void Student::display() const {
        // Match required output for Student Info
        std::cout << "Name: " << getName() << std::endl;
        std::cout << "Year: " << yearLevel << std::endl;
        std::cout << "Major: " << major << std::endl;
    }

    // ---------------- Instructor ----------------
    Instructor::Instructor() : Person(), department(""), experienceYears(0) {}
    Instructor::Instructor(const std::string& name, int id, const std::string& department_, int experienceYears_)
        : Person(name, id), department(department_), experienceYears(experienceYears_) {}
    Instructor::~Instructor() {}

    void Instructor::setDepartment(const std::string& d) { department = d; }
    std::string Instructor::getDepartment() const { return department; }
    void Instructor::setExperienceYears(int e) { experienceYears = e; }
    int Instructor::getExperienceYears() const { return experienceYears; }

    void Instructor::display() const {
        std::cout << "Name: " << getName() << std::endl;
        std::cout << "Department: " << department << std::endl;
        std::cout << "Experience: " << experienceYears << " years" << std::endl;
    }

    // ---------------- Course ----------------
    Course::Course() : courseCode(""), courseName(""), maxStudents(0), students(nullptr), currentStudents(0), instructor(nullptr) {}

    Course::Course(const std::string& code, const std::string& name, int maxStudents_, Instructor* instr)
        : courseCode(code), courseName(name), maxStudents(maxStudents_), students(nullptr), currentStudents(0), instructor(instr) {
        if (maxStudents > 0) {
            students = new Student[maxStudents];
        }
    }

    Course::~Course() {
        delete[] students;
    }

    void Course::addStudent(const Student& s) {
        if (currentStudents >= maxStudents) {
            return;
        }
        students[currentStudents++] = s;
    }

    void Course::displayCourseInfo() const {
        std::cout << "Course: " << courseCode << " - " << courseName << std::endl;
        std::cout << "Max Students: " << maxStudents << std::endl;
        std::cout << "Currently Enrolled: ";
        if (currentStudents > 0) {
            std::cout << students[0].getName() << " (ID: " << students[0].getId() << ")" << std::endl;
        } else {
            std::cout << "None" << std::endl;
        }

        std::cout << std::endl;
        std::cout << "Instructor Info:" << std::endl;
        if (instructor) {
            instructor->display();
        } else {
            std::cout << "No instructor assigned." << std::endl;
        }

        std::cout << std::endl;
        std::cout << "Student Info:" << std::endl;
        for (int i = 0; i < currentStudents; ++i) {
            students[i].display();
            if (i < currentStudents - 1) std::cout << std::endl;
        }
    }

    // ---------------- Main ----------------
    int main() {
        Instructor instr("Dr. Lina Khaled", 1001, "Computer Science", 5);

        Student s1("Omar Nabil", 2202, 2, "Informatics");

        Course course("CS101", "Introduction to Programming", 3, &instr);
        course.addStudent(s1);

        course.displayCourseInfo();

        return 0;
    }
