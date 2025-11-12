#include <iostream>
#include "b.cpp"


using namespace std;

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