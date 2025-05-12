#include <stdio.h>
#include "stdbool.h"

void funcA()
{
    printf("FuncA is called\n");
}

void funcB()
{
    printf("FuncB is called\n");
}

void  main_hello()
{
    printf("Hello, World!\n");
}


void main()
{
    // Example variable definition
    int a;
    int b;

    int c,d,e;

    // Assignment example
    d = e+2;
    e=1;

    d= e+2;


    bool x;


    c = 3;
    c = 3+5;

    c = c-7;

    // Use of paranthesis with arithmetic operators
    c = c + (5 - 6 * (c - 4))/2;

    c = (a+32)-(4-3);

    x = !(( c + 4 < e*3) && ( c/2 > a));




}