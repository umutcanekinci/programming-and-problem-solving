#include <iostream>
using namespace std;

class B;

class A{

public:

    static void printA(){
        cout<<"A"<<endl;
    }

    static void printAB(){
        printA();
        B::printB();
    }

};