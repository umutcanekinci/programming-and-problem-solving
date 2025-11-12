#include <iostream>

using namespace std;

template<class T>
class ArrayQueue {
private:
    int capacity;
    int front;
    int rear;
    T *elements; // primitive types such as integers,floats etc.
public:
    ArrayQueue(int capacity) {
        // Initialize other variables
        // change random memory values with NULL/0
        for (int i = 0; i < capacity; i++) {
            elements[i] = 0;
        }
    }

    ~ArrayQueue() {
        delete[] elements;
    }
    // Fill this function
    // Do not print anything if you can not enqueue 
    void enqueue(T element) {
    }
    
    // Fill this function
    // return the element
    // if element does not exist return 0
    T dequeue() {
        
    }
    
    // Fill this function
    bool isEmpty() {

    }
    
    // Fill this function
    bool isFull() {
    }
    
    int getFront(){
        return front;
    }

    int getRear(){
        return rear;
    }

};
