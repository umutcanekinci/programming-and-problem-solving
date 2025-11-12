#include <iostream>

using namespace std;

class A {
public:
    int x;
    A *next;

    A(int x) {
        this->x = x;
    }
};


// Stack memory problem due to local scope
A *createStackA(int x) {
    A object = A(x);
    return &object;
}

A *createHeapA(int x) {
    A *object = new A(x);
    return object;
}

int main() {
    // Primitive values can be NULL
    int a = 5;
    cout << "Value of a : " << a << endl;
    int b = NULL;
    cout << "Value of b : " << b << endl;
//    string c = NULL;
//    cout<<"Value of c : "<<c<<endl; //throws error
    A objectA = A(5);
    cout << "Parameter X in object A : " << objectA.x << endl;
    objectA.x = NULL;
    cout << "Parameter X in object A : " << objectA.x << endl;
//    cout<<"Print objectA"<<objectA<<endl; // Can not do that, you need to override toString or use your toString

    A anotherA = A(7);
    anotherA = NULL;
//     This will raise a compiler error, because "anotherA" is not a pointer but object and NULL does not support
//     this comparison operation implicitly.Therefore, you need to either use object pointer or override the "==" operator
//     for A class.
//    if(anotherA==NULL){
//
//    }
    A *pointerA = new A(8);
    if (pointerA != NULL) {
        cout << "Pointer A is not NULL" << endl;
    }

    A *newStackA = createStackA(100);
//    cout << "Parameter X in newStackA :" << newStackA->x << endl; // Throws error because newA is NULL

    A *newHeapA = createHeapA(100);
    cout << "Parameter X in newHeapA :" << newHeapA->x << endl;
    // You need to manually deallocate the memory from heap to prevent memory leaks.
    // I will provide this part,time to time or ChatGPT will do it for me.
    delete newHeapA;

    return 0;
}
