#include <iostream>

using namespace std;

template<class T>
class ArrayStack {

private:
    int capacity;
    int top;
    T *elements; // primitive types such as integers,floats etc.
public:
    ArrayStack(int capacity) {
        this->capacity = capacity;
        this->top = -1;
        elements = new T[capacity];
        // change random memory values with NULL
        for (int i = 0; i < capacity; i++) {
            elements[i] = NULL;
        }
    }

    ~ArrayStack() {
        delete[] elements;
    }
    
    // Fill this function
    bool isFull() {
    }
    
    // Fill this function
    bool isEmpty() {
    }
    
    // Fill this function
    // Prevent potential errors but DO NOT print them
    void push(T element) {

    }
    
    // Fill this function
    // Prevent potential errors but DO NOT print them
    T pop() {

    }
    
    // Fill this function
    // Prevent errors but DO NOT print them
    // Just return the element DO NOT remove it from stack
    T getTopElement() {

    }


};