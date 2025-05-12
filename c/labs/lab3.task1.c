#include "stdio.h"

/* Task 1: Print Divisors of an Integer
 * In this task, you will create a C program that takes an integer as input from the user and then uses a
 * func􀆟on find and print all of its divisors. Divisors of a number are those integers that can divide the
 * given number without leaving a remainder.
 * Create a func􀆟on called findDivisors to find and print the divisors of the given number.
 * In main ask the user to enter an integer.
 * Call the findDivisors func􀆟on, passing the user's integer as a parameter.
 * Expected Output:
    * Enter a positive integer:12
    * Divisors of 12 are: 1 2 3 6 12
 */

int getPositiveInt() {
    int value;
    printf("Enter a positive integer:");
    scanf_s("%d", &value);
    return value;
}

void printDivisors(int n) {
    printf("Divisors of %d are:", n);
    for(int i=1; i<=n; i++) {
        if(n % i == 0) {
            printf(" %d", i);
        }
    }
}

int main() {
    printDivisors(getPositiveInt());
    return 0;
}