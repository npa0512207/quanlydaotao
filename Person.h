#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string id;
    string fullName;
    string dob; 

public:
    Person(string id, string name, string dob) {
        this->id = id;
        this->fullName = name;
        this->dob = dob;
    }

    virtual ~Person() {}

    string getId() { return id; }
    string getName() { return fullName; }
    string getDob() { return dob; }

    virtual void displayInfo() = 0;
    virtual long calculateReward() = 0;
};

#endif
