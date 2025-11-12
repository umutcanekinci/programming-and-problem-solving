#include <stdio.h>

void hello() {
    printf("Hello Everyone!");
}

void goodbye(){
    printf("Goodbye!!");
}

void newLine(){
    printf("\n");
}

void mehmet(){
    hello();
    newLine();
    printf("I am Mehmet and I am 20 years old");
    newLine();
    goodbye();
}

void ahmet(){
    hello();
    newLine();
    int age = 22;
    printf("I am Ahmet and I am %d years old",age);
    newLine();
    goodbye();
}

void main() {
    mehmet();
    newLine();
    ahmet();
  
}
