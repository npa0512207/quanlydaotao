#include <iostream>
#include "Management.h"

using namespace std;

int main() {
    Management app;
    int choice;

    do {
        cout << "\n=== HE THONG QUAN LY DAO TAO ===\n";
        cout << "1. Them doi tuong\n";
        cout << "2. Hien thi danh sach\n";
        cout << "3. Tim theo ID\n";
        cout << "4. Xoa theo ID\n";
        cout << "5. Sap xep theo ten\n";
		cout << "6. Tong tien thuong\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;
        cin.ignore();

        string id;
        switch (choice) {
        case 1:
            app.addPerson();
            break;

        case 2:
            app.displayAll();
            break;

        case 3:
            app.searchById();
            break;

        case 4:
            app.deleteById();
            break;

        case 5:
            app.sortByName();
            cout << "Da sap xep theo ten!\n";
            break;

        case 6:
            app.showTotalReward();
            break;

        case 0:
            cout << "Tam biet!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}
