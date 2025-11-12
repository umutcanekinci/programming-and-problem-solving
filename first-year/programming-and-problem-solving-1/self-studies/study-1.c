#include "stdio.h"
#include "stdbool.h"


/**
 * * SE 1105 study material
 *
 * * BASIC STATEMENTS
 * *   - Variable Definition
 * *   - Assignment
 * *   - Simple Functions
 * *   - Simple output
 *
 * * Author: Dindar ÖZ
 */

/* -------------------------------------------------------------------------- */
/*                            PROGRAMMING EXERCISES                           */
/* -------------------------------------------------------------------------- */


/**
 * * 1.1. Write a function that takes an integer k as parameter and returns k+3.
 * */
// !your code here
int addThree(int k) {
    return k+3;
}



/**
 * * 1.2. Write a function that takes an integer n as parameter and returns n^3 ( the cube of n).
 * */
// !your code here
int cubic(int n) {
    return n*n*n;
}


/**
 * * 1.3. Write a function that takes an integer a as parameter and returns -a .
 * */
// !your code here
int negate(int a) {return -a;}


/**
 * * 1.4. Fill the function below as it is commented.
 * */
void simpleFunction()
{
    //* Define a local integer variables x,y, and z
    int x, y, z;

    //* Assign x to 5
    x = 5;

    //* Assign y to 2
    y = 2;

    //* Assign z to x+y
    z = x + y;

    //* Assign y to z+y
    y = z + y;

    //* Assign y to x+z
    y = x + z;

    //* Print the values of x, y, and z to the screen
    printf("x: %d, y: %d, z: %d\n", x, y, z);

    //* Define an integer variable t
    int t;

    //* Assign t to [3(x+y)*(z-y) - 2(x+2z)*(10-x+y)]/(x+y+z)
    t = (3 * (x + y) * (z - y) - 2 * (x + 2 * z) * (10 - x + y)) / (x + y + z);

    //* Print the value of t
    printf("%d\n", t);
}

/**
 * * 1.5. Write a function that prints out your initials by using “*”s
 * *      Example: If your name were "Ali" then the output would be:
 * *          *
 * *         * *
 * *        *   *
 * *       *******
 * *      *       *
 * *     *         *
 *
 * *    *          *
 * *    *          *
 * *    *          *
 * *    *          *
 * *    *          *
 * *    ************
 *
 *
 * */
// !your code here
void printMyInitial() {

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(j % 9 == 0 || i == 9) {
                printf("* ");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }

    printf("\n");
}



/**
 * * 1.6. Write a function that takes an integer n as parameter and prints
 * *      "I have (n) apples" on the screen. ((n) should be the value of the parameter n)
 * *      EXAMPLE: If n:3 then it prints "I have 3 apples"
 * */
// !your code here
void countApples(int n) {
    printf("I have %d apples.\n", n);
}





/**
 * * 1.7. Write a function that takes two integers k and l as parameters and prints
 * *      "The sum of (k) and (l) is (k+l)" on the screen.
 * *      EXAMPLE: If k:1 and l:7 then it prints "The sum of 1 and 7 is 8"
 * */
// !your code here
void sum(int k, int l) {
    printf("The sum of %d, and %d, is %d.\n", k, l, k+l);
}






/* -------------------------------------------------------------------------- */
/*                                MAIN FUNCTION                               */
/* -------------------------------------------------------------------------- */
void main() {
    //* You can call the functions you have implemented above to see if they are working.
    //* You can also print the returning values of the functions if there is any.
    printf("%d\n", addThree(3));
    printf("%d\n", cubic(5));
    printf("%d\n", negate(3));
    simpleFunction();
    printMyInitial();
    countApples(5);
    sum(2, 4);


}