#include "database.h"

int main() {
    Database<int> *db = new Database<int>(5);
    Data<int> *data1 = new Data<int>(1, 100);
    Data<int> *data2 = new Data<int>(20, 200);
    Data<int> *data3 = new Data<int>(300, 300);
    Data<int> *data4 = new Data<int>(4, 400);
    int option;
    cin >> option;

    db->insertData(data1);
    db->insertData(data2);
    if (option == 1) {
        cout << db->isExist(500) << endl; // 0
    } else if (option == 2) {
        cout << db->isExist(100) << endl; // 1
    } else if (option == 3) {
        cout << db->deleteData(5) << endl; // 0
    } else if (option == 4) {
        cout << db->deleteData(20) << endl; // 1
    } else if (option == 5) {
        db->insertData(data3);
        db->deleteData(20);
        db->insertData(data4);
        cout << db->getByIndex(1)->getData() << endl; // 400
    }
    db->toString();


    delete db;
    return 0;
}