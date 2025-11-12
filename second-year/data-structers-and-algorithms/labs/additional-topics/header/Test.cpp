#include "a.h"
#include "b.h"

/*
 * To run this system, you need to link all necessary files together. If you just try to run
 * add_executable(Week3-Header week3/header/Test.cpp) //Clion command
 * It will not work, because the cpp files of header files are not included.
 * Java unifies compilation process,but it is not a thing in C++, you need to specifically include the files.
 * add_executable(Week3-Header week3/header/Test.cpp week3/header/a.cpp week3/header/b.cpp)
 *
 */
int main() {
    A::printAB();
    B::printBA();

    return 0;
}