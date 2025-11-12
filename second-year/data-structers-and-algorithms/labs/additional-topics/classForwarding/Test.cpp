#include "a.cpp"
#include "b.cpp"


/*
 * Class forwarding lets you resolve the "type" problems. However, you can not use the methods in forwarded classes,
 * because they are just a "class pointers" and the details on that class are unknown by the compiler. The compiler
 * only have the knowledge of, these "forwarded classes" will be implemented later on other files but the functional or
 * variable usage is not guaranteed to be exist prior to the compilation, hence it is forbidden to use.
 */


int main() {
    A::printAB();
    B::printBA();

    return 0;
}