#include "a.cpp"
#include "b.cpp"

/* When you try to run this code it will not compile.
 Java and C++ handles the compilation of classes differently.
 Unlike Java Classes, C++ classes needs to know the full-implementation details of the included files.
 Therefore, when you include class "B" into "A" or vice versa they create a situation known as "circular dependency".

 To prevent this problem, as a rule of thumb, you usually only pass the header files like an interface and implement
 the behaviours in different cpp files, so that compiler can link them together.

 However, if you want to use solely C++ files,you need to something "class forwarding".In which, you state to compiler
 that "these classes will be implemented later in other files.
*/

int main() {
    A::printAB();
    B::printBA();

    return 0;
}