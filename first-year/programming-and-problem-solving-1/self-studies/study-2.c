#include "stdio.h"
#include "stdbool.h"
#include "malloc.h"
/**
 * * SE 1105 study material
 *
 * * COMPOUND-STATEMENTS
 * *   - If-else
 * *   - Loops
 *
 * * Author: Dindar ÖZ
 */

/* -------------------------------------------------------------------------- */
/*                            PROGRAMMING EXERCISES                           */
/* -------------------------------------------------------------------------- */


/**
 * * 2.1. Write a function that takes 4 integers as parameters and returns the sum of the minimum and the maximum
 * */
// !your code here
int max(int a, int b) {

    return a > b ? a : b;

}

int min(int a, int b) {

    return a < b ? a : b;

}

int sumOfMinAndMax(int a, int b, int c, int d) {

    return min(min(a, b), min(c, d)) + max(max(a, b), max(c, d));
}

 /**
  * * 2.2. Write a function that takes 3 integers namely x,y and z, calculates and returns the value of |x-y|*|3z-2x|
 * */
// !your code here

int abs(int a) {
    return a > 0 ? a : -a;
}

int func1(int x, int y, int z) { //|x-y|*|3z-2x|

    return abs(x-y) * abs(3*z-2*x);
}

 /**
  * * 2.3. Write a function that reads 2 integers from the user,  and prints all the integers between those to the
  * *    screen in ascending  order seperated by “-“ symbol.
  * *    Example: If the user enters 9 and 2 then the function must print out: 2-3-4-5-6-7-8-9
 * */
// !your code here
void func2Old(int first, int last) {
    if(first > last) {
        last *= first;
        first = last/first;
        last /= first;
    }
    for(int i=0; i<=last-first; i++) {
        printf("%d", first+i);
        if (i != last-first) {
            printf("-");
        }
    }
    printf("\n");
}
void func2Updated(int first, int last) {
    /*
    for(int i=0; (first < last && i < last-first) || (first > last && i<first-last); i++) {
        printf("%d", first < last ? first+i : last+i);
    }
    */
    if(first < last) {
        for(int i=0; i<last-first+1; i++) {
            printf("%d", first + i);
            if (i != last-first) {
                printf("-");
            }
        }
    }
    else {
        for(int i=0; i<first-last+1; i++) {
            printf("%d", last + i);
            if (i != first-last) {
                printf("-");
            }
        }
    }
    printf("\n");
}
void func2Updated2(int a, int b) {
    int first = a < b ? a : b;
    int last = a < b ? b : a;
    int substraction = last - first;

    for(int i=0; i<=substraction; i++) {
        printf("%d", first+i);
        if (i != substraction) {
            printf("-");
        }
    }
    printf("\n");
}
// func2Best
void func2(int first, int last) {
    if (first > last) {
        int temp = first;
        first = last;
        last = temp;
    }
    for (int i = first; i <= last; i++) {
        printf("%d", i);
        if (i != last) {
            printf("-");
        }
    }
    printf("\n");
}

/**
 * * 2.4. Write a function that takes m and n as input and returns m*n without using * operator.
 * */
// !your code here
int multiplyOld(int m, int n) { // what if m or n is negative?
    int result=0;
    for(int i=0; i<n; n>0 ? i++ : i--) {
        result += n>0 ? m : -m;
    }
    return result;
}
int multiply(int m, int n) {

    return n ? ((n > 0 ? m : -m) + multiply(m, n > 0 ? n-1 : n+1)) : 0;

}

/**
 * * 2.5. Write a function that takes n as input and returns n! (factorial of n)
 * */
// !your code here
int factorial(int n) {

    return (n == 0 || n == 1) ? 1 : (n<0) ? -1 : n * factorial(n-1);

}

/**
 * * 2.6. Write a function that takes 2 integers , namely n and m, as parameters and calculates the combination of them (C(n,m))
 * *      which can be calculated via the following formula : n!/(m!(n-m)!)
 * *      Note: You can assume that  n is greater than or equal to m
 * */
// !your code here
int combination(int n, int m) {

    return (n < m || n < 0 || m < 0) ? -1 : factorial(n) / factorial(m) / factorial(n-m);

}

/**
 * * 2.7. Write a function that prints an empty box of edge-size n with “*”s.
 *  * *       Example: If the size is 8 then the function must print out the following:
  * *       ********
  * *       *      *
  * *       *      *
  * *       *      *
  * *       *      *
  * *       *      *
  * *       *      *
  * *       ********
. * */
// !your code here
void printBox(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0; j<n; j++) {
            if(i==0 || i==n-1 || j==0 || j==n-1){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

 /**
  * *  2.8. Write a function that takes the size of a box as parameter and draws an empty box with diagonals to the screen
  * *       Example: If the size is 8 then the function must print out the following:
  * *       ********
  * *       **    **
  * *       * *  * *
  * *       *  **  *
  * *       *  **  *
  * *       * *  * *
  * *       **    **
  * *       ********

 * */
// !your code here
void printBox2(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0; j<n; j++) {
            if(i==0 || i==n-1 || j==0 || j==n-1 || i==j || i+j==n-2){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

/**
 * * 2.9. Write a function that takes an integer, namely n, as parameter and returns true if n is a perfect square
 * *      (i.e 4, 9 ,16.. etc. )
 *
 * */
// !your code here
bool isPerfectSquare(int n) {
    for(int i=0; i<n; i++) {
        if(i*i == n) { return 1;}
    }
    return 0;
}

/**
 * * 2.10. Write a function that takes m and n as inputs and returns (2m+3)^(n-4)
 * */
// !your code here
int func3(int m, int n) {

    int base = (2*m + 3);
    int exponent = n-4;

    if(exponent < 0) { // If exponent is a negative number, make it reciprocal to make exponent positive.
        exponent *= -1;
        base = 1/base;
        m = (base-3)/2;
        n = exponent+4;
    }

    if(exponent == 0) { return 1; }
    return base * func3(m, n-1);
}

/**
 * * 2.11. Write a function that takes m and n as inputs and returns the sum of all positive
 * *       integers from 1 to m that are divisable by n
 * */
// !your code here
int sumOfDivisibles(int m, int n) {
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        if (i % n == 0) {
            sum += i;
        }
    }
    return sum;
}

/**
 * * 2.12. Write a function that takes an integer, namely k, as parameter and returns the difference between
 * *      sum of all positive integers smaller than k that are divisable by 3 and the sum of all positive integers
 * *      smaller than 2*k that are divisable by 5.
 * */
// !your code here

/**
 * ? CHALLENGE
 * * 2.13. Write a function that takes n as input and prints its positive divisors.
 * */
// !your code here
void positiveDivisors(int n) {
    for(int i=1; i<n; i++) {
        if(n % i) {
            printf("%d\n", i);
        }
    }
}


/* -------------------------------------------------------------------------- */
/*                                MAIN FUNCTION                               */
/* -------------------------------------------------------------------------- */
void main() {
    //* You can call the functions you have implemented above to see if they are working.
    //* You can also print the returning values of the functions if there is any.
    //printf("%d\n", sumOfMinAndMax(23, 12, 4, 5));
    //printf("func1= %d\n", func1(20, 4, 5));
    //func2(6, 3);
    //func2Updated(6, 3);
    //printf("%d\n", factorial(5));
    //printf("%d\n", combination(6, 2));
    //printBox(5);
    //printBox2(9);
    //printf("%d\n", multiply(-4, -10));
    //printf("%d", isPerfectSquare(64));
    //positiveDivisors(24);
    //printf("%d", func3(5,7));
    //printf("%d", sumOfDivisibles(10, 2));
}

