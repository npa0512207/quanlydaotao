#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person {
private:
    float gpa;
    string className;

public:
    Student(string id, string name, string dob,
        float gpa, string className)
        : Person(id, name, dob), gpa(gpa), className(className) {
    }

    void displayInfo() override {
        cout << "Loai: Sinh vien\n";
        cout << "ID: " << id << endl;
        cout << "Ho ten: " << fullName << endl;
        cout << "Ngay sinh: " << dob << endl;
        cout << "Lop: " << className << endl;
        cout << "GPA: " << gpa << endl;
    }

    long calculateReward() override {
        if (gpa > 3.6) return 5000000;
        if (gpa > 3.2) return 3000000;
        return 0;
    }
};

#endif
