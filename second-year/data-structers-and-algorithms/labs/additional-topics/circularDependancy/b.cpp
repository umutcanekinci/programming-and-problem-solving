#include <iostream>
#include "a.cpp"


using namespace std;

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
