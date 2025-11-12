#include "stdio.h"
#include "stdbool.h"


/**
 * * SE 1105 study material
 *
 * * RECURSION
 *
 * * Author: Dindar ÖZ
 */

/* -------------------------------------------------------------------------- */
/*                            PROGRAMMING EXERCISES                           */
/* -------------------------------------------------------------------------- */


/**
 * * 5.1. Write a function that calculates m^n without using loops
 */
int power(int m, int n) {
    return n ? m * power(m, n-1) : 1;
}


/**
 * * 5.2. Write a function that takes an integer array and its size as paramaters.
 * *      The function prints the array without using loops
 */
// !your code here
void printElement(int arr[], int size, int n) {
    if(n >= size || n < 0) return;
    if(n) printf(",");
    printf(" %d", arr[n]);
    printElement(arr, size, n+1);
}

void printArray(int arr[], int size) {
    printf("{");
    printElement(arr, size, 0);
    printf(" }\n");
}


/* [OPTIONAL] Self-Study
 * Write a program that reads three integers from the user (keyboard) namely n, a and b.
 * Your program should print all positive numbers that are smaller than n and the sum of whose positive divisors
 * is between to a and b (included).
 * You should print the numbers in ascending order and print
 * their positive divisors and the sum of their positive divisors on the same line as the numbers.
 * 
 * Example:
 * If the user entered n : 5, a : 5 and b : 10 then only 3 and 4 satisfies the condition
 *         and the output should be as follows" :
 * 3 1 3 4
 * 4 1 2 4 7
*/
int sumOfPositiveDivisors(int number, int divisor) {
    if(divisor > number) return 0;
    return sumOfPositiveDivisors(number, divisor + 1) + (number % divisor == 0 ? divisor : 0);
}

void printPositiveDivisors(int number, int divisor) {
    if(divisor > number || divisor <= 0) return;
    if(!(number % divisor)) printf(" %d", divisor);
    printPositiveDivisors(number, divisor + 1);
}
void optional() {

    int a, b, n;
    scanf_s("%d", &n);
    scanf_s("%d", &a);
    scanf_s("%d", &b);

    for(int i = 1; i < n; i++) {
        int sum = sumOfPositiveDivisors(i, 1);
        if(sum <= b && sum >= a) {
            printf("%d", i);
            printPositiveDivisors(i, 1);
            printf(" %d\n", sum);
        }
    }

}





/* -------------------------------------------------------------------------- */
/*                                MAIN FUNCTION                               */
/* -------------------------------------------------------------------------- */
void main() {
    //* You can call the functions you have implemented above to see if they are working.
    //* You can also print the returning values of the functions if there is any.

    printf("%d\n", power(2, 3));
    printArray((int[]){1, 2, 3, 4, 5}, 5);
    optional();

}