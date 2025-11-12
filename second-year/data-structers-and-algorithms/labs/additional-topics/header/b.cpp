#include <iostream>
#include "b.h"
#include "a.h"

void B::printB() {
    std::cout << "B" << std::endl;
}

void B::printBA() {
    B::printB();
    A::printA();
}