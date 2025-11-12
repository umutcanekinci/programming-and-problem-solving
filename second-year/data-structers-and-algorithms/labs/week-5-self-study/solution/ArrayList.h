#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>

using namespace std;

template<class T>
class ArrayList {
    int capacity;
    T **elements; // T* is necessary to allocate the necessary space after its declaration.
    // T* means set of objects "T" whereas T** set of pointers with the type "T"
    // In C++ objects can not be null (beside the primitive types) but pointers can be null
public:

    ArrayList(int capacity) {
        this->capacity = capacity;
        elements = new T *[capacity];
        // Override the random values in memory with NULL
        for (int i = 0; i < capacity; i++) {
            elements[i] = NULL;
        }
    }

    ~ArrayList() {
        // Delete each element that has been allocated
        for (int i = 0; i < capacity; ++i) {
            delete elements[i];  // Free memory for each element
            elements[i] = nullptr; // Set pointer to nullptr for safety
        }

        // Delete the array of pointers itself
        delete[] elements;
        elements = nullptr; // Set pointer to nullptr for safety
    }

    bool add(T *element) {
        bool added = false;
        for (int i = 0; i < capacity; i++) {
            if (elements[i] == NULL) {
                elements[i] = element;
                added = true;
                break;
            }
        }

        return added;
    }

    T *getByObject(T *element) {
        T *exist = NULL;
        for (int i = 0; i < this->capacity; i++) {
            if (elements[i] == element) {
                exist = elements[i];
                break;
            }
        }

        return exist;
    }

    T *getByIndex(int index) {
        T *element = NULL;
        if (index >= 0 && index < capacity) {
            element = elements[index];
        }
        return element;
    }

    int size() {
        return capacity;
    }


};

#endif // ARRAYLIST_H