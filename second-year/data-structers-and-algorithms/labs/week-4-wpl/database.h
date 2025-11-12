#include <iostream>

using namespace std;

template<class T>
class Data {
private:
    int ID;
    T data;


public:

    Data(int ID, T data) {
    }

    T getData() {
    }

    int getID() {
 
    }

    void toString() {

    }

};


template<class T>
class Database {
private:
    Data<T> **elements;
    int capacity;

public:
    Database(int capacity) {
        this->capacity = capacity;
        elements = new Data<T> *[capacity];
        // Override the random values in memory with NULL
        for (int i = 0; i < capacity; i++) {
            elements[i] = NULL;
        }
    }

    ~Database() {
        // Delete each element that has been allocated
        for (int i = 0; i < capacity; ++i) {
            delete elements[i];  // Free memory for each element
            elements[i] = nullptr; // Set pointer to nullptr for safety
        }

        // Delete the array of pointers itself
        delete[] elements;
        elements = nullptr; // Set pointer to nullptr for safety
    }

    // Check if there is a data with the given ID
    // Insert new data to the first available position,if it is not exist
    // Try to do it in a single for-loop.
    bool insertData(Data<T> *newData) {
        
    }

    // Find the data with the given ID and assign its position to NULL
    bool deleteData(int ID) {
        
    }

    // Check if there is a Data instance with the given "data".
    bool isExist(T data) {
        
    }

    // Return data by index (not ID)
    Data<T> *getByIndex(int index) {
        
    }

    void toString() {
        cout << "Database" << endl;
        for (int i = 0; i < capacity; i++) {
            if (elements[i] != NULL) {
                elements[i]->toString();
            }
        }
    }


};