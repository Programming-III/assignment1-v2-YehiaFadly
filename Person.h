#ifndef PERSON_H
#define PERSON_H
 
#include <string>
// Person.h - declaration only. Implementations are in main.cpp per assignment.

class Person {
private:
    std::string name;
    int id;
public:
    Person();
    Person(const std::string& name, int id);
    virtual ~Person();

    // setters/getters
    std::string getName() const;
    void setId(int id);
    int getId() const;

    // polymorphic display
    virtual void display() const;
};

#endif
