#include <iostream>
#include "a.h"
#include "b.h"

void A::printA() {
    std::cout << "A" << std::endl;
}

void A::printAB() {
    A::printA();
    B::printB();  // This works because B is forward-declared in b.h and included here
}