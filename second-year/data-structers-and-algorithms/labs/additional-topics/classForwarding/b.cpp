#include <iostream>

using namespace std;

class A;

class B{

public:

    static void printB(){
        cout<<"B"<<endl;
    }

    static void printBA(){
        printB();
        A::printA();
    }

};
