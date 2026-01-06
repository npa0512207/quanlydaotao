#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <vector>
#include <algorithm>
#include "Student.h"
#include "Lecturer.h"
#include <string>
#include <iostream>

using namespace std;

class Management {
private:
    vector<Person*> list;

    // Kiem tra trung ID sinh vien
    bool studentIdExist(string id) {
        for (Person* p : list) {
            Student* s = dynamic_cast<Student*>(p);
            if (s && s->getId() == id)
                return true;
        }
        return false;
    }

    // Kiem tra trung ID giang vien
    bool lecturerIdExist(string id) {
        for (Person* p : list) {
            Lecturer* l = dynamic_cast<Lecturer*>(p);
            if (l && l->getId() == id)
                return true;
        }
        return false;
    }

public:
    // Constructor
    Management() {}

    // Destructor
    ~Management() {
        for (Person* p : list)
            delete p;
        list.clear();
    }

    // Them doi tuong
    void addPerson() {
        int type;
        cout << "1. Sinh vien\n";
        cout << "2. Giang vien\n";
        cout << "Chon: ";
        cin >> type;
        cin.ignore();

        string id, name, dob;
        cout << "Nhap ID: ";
        getline(cin, id);

        cout << "Nhap ho ten: ";
        getline(cin, name);

        cout << "Nhap ngay sinh: ";
        getline(cin, dob);

        if (type == 1) {
            if (studentIdExist(id)) {
                cout << "Trung ID sinh vien!\n";
                return;
            }

            string className;
            float gpa;

            cout << "Nhap lop: ";
            getline(cin, className);

            do {
                cout << "Nhap GPA (0 - 4): ";
                cin >> gpa;
                if (gpa < 0 || gpa > 4)
                    cout << "GPA khong hop le!\n";
            } while (gpa < 0 || gpa > 4);

            list.push_back(new Student(id, name, dob, gpa, className));
        }
        else if (type == 2) {
            if (lecturerIdExist(id)) {
                cout << "Trung ID giang vien!\n";
                return;
            }

            string department;
            int papers;

            cout << "Nhap bo mon: ";
            getline(cin, department);

            cout << "Nhap so bai bao khoa hoc: ";
            cin >> papers;

            list.push_back(new Lecturer(id, name, dob, department, papers));
        }
        else {
            cout << "Lua chon khong hop le!\n";
            return;
        }

        cout << "Them thanh cong!\n";
    }

    // Hien thi danh sach
    void displayAll() {
        if (list.empty()) {
            cout << "Danh sach rong!\n";
            return;
        }

        for (Person* p : list) {
            p->displayInfo();
            cout << "Tien thuong: "
                << p->calculateReward()
                << " VND\n";
            cout << "-----------------------------\n";
        }
    }

    // Tim theo ID
    void searchById() {
        int type;
        cout << "Chon doi tuong can tim:\n";
        cout << "1. Sinh vien\n";
        cout << "2. Giang vien\n";
        cout << "Chon: ";
        cin >> type;

        string id;
        cout << "Nhap ID: ";
        cin >> id;

        bool found = false;

        for (auto p : list) {
            if (p->getId() == id) {
                if (type == 1 && dynamic_cast<Student*>(p)) {
                    p->displayInfo();
                    found = true;
                    break;
                }
                if (type == 2 && dynamic_cast<Lecturer*>(p)) {
                    p->displayInfo();
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            cout << "Khong tim thay doi tuong phu hop!\n";
        }
    }

    // Xoa theo ID
    void deleteById() {
        int type;
        cout << "Chon doi tuong can xoa:\n";
        cout << "1. Sinh vien\n";
        cout << "2. Giang vien\n";
        cout << "Chon: ";
        cin >> type;

        string id;
        cout << "Nhap ID can xoa: ";
        cin >> id;

        for (auto it = list.begin(); it != list.end(); ++it) {
            if ((*it)->getId() == id) {
                if ((type == 1 && dynamic_cast<Student*>(*it)) ||
                    (type == 2 && dynamic_cast<Lecturer*>(*it))) {

                    delete* it;
                    list.erase(it);
                    cout << "Da xoa thanh cong!\n";
                    return;
                }
            }
        }

        cout << "Khong tim thay doi tuong can xoa!\n";
    }

    // Sap xep theo ten
    void sortByName() {
        sort(list.begin(), list.end(),
            [](Person* a, Person* b) {
                return a->getName() < b->getName();
            });
    }

    // Tong tien thuong
    long totalReward() {
        long sum = 0;
        for (Person* p : list)
            sum += p->calculateReward();
        return sum;
    }

    // Hien thi tong tien thuong
    void showTotalReward() {
        cout << "=================================\n";
        cout << "Tong tien thuong nha truong phai chi tra: "
            << totalReward()
            << " VND\n";
        cout << "=================================\n";
    }
};

#endif