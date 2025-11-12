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
        this->capacity = capacity;
        this->front = -1;
        this->rear = -1;
        this->elements = new T[capacity];
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
        if (isFull())
            return;
        
        if (isEmpty()) {
            front = 0;
            rear = 0;
            elements[rear] = element;
            return;
        }

        rear += 1;
        rear %= capacity;
        elements[rear] = element;
    }
    
    // Fill this function
    // return the element
    // if element does not exist return 0
    T dequeue() {
        if (isEmpty()) {
            return 0;
        }
        
        T element = elements[front];

        // One element
        if (front == rear) {
            front = -1;
            rear = -1;
            return element;
        }

        front += 1;
        front %= capacity; 
        return element;
    }
    
    // Fill this function
    bool isEmpty() {
        return front == -1 && rear == -1;
    }
    
    // Fill this function
    bool isFull() {
        return (rear == (front + capacity - 1) % capacity);// || (front == 0 && rear == 7);
        //return front + rear == capacity - 1;    
    }
    
    int getFront(){
        return front;
    }

    int getRear(){
        return rear;
    }

};
