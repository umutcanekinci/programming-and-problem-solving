#include "stack.h"

int main() {

    ArrayStack<int> *arrayStack = new ArrayStack<int>(5);
    int option;
    cin >> option;

    arrayStack->push(5);
    arrayStack->push(45);
    arrayStack->push(123);

    if (option == 1) {
        cout << arrayStack->isEmpty() << endl; // 0
    } else if (option == 2) {
        cout << arrayStack->isFull() << endl; // 0
    } else if (option == 3) {
        arrayStack->push(66);
        arrayStack->push(78);
        cout << arrayStack->isFull() << endl; // 1
    } else if (option == 4) {
        cout << arrayStack->getTopElement() << endl; // 123
    } else if (option == 5) {
        arrayStack->pop();
        int value = arrayStack->pop();
        cout << value << endl; // 45
    } else if (option == 6) {
        arrayStack->pop();
        arrayStack->pop();
        arrayStack->pop();

        cout << (arrayStack->pop() == NULL) << endl; // 1
    } else if (option == 7) {
        arrayStack->push(100);
        arrayStack->push(355);
        arrayStack->push(428);
        cout << arrayStack->getTopElement() << endl; // 355
    }


    delete arrayStack;
    return 0;
}