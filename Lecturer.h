#ifndef LECTURER_H
#define LECTURER_H

#include "Person.h"

class Lecturer : public Person {
private:
    string department;
    int papersCount;

public:
    Lecturer(string id, string name, string dob,
        string dept, int papers)
        : Person(id, name, dob),
        department(dept), papersCount(papers) {
    }

    void displayInfo() override {
        cout << "Loai: Giang vien\n";
        cout << "ID: " << id << endl;
        cout << "Ho ten: " << fullName << endl;
        cout << "Ngay sinh: " << dob << endl;
        cout << "Bo mon: " << department << endl;
        cout << "So bai bao: " << papersCount << endl;
    }

    long calculateReward() override {
        return papersCount * 2000000;
    }
};

#endif
