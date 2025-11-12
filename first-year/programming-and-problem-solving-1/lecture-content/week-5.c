#include <stdio.h>
#include <stdbool.h>


/**
 * Returns a positiive integer read from the user
 * @return
 */
int readPositiveNumber()
{
    int a= 0;

    for (; a <=0 ; ) {
        printf("Enter a positive integer:\n");
        scanf_s("%d", &a);
        if (a<=0)
            printf("%d is not a positive number.\n",a);
    }

    return a;
}

// Write a function that takes n as input and
// return the closest integer to the squareroot of n (not bigger than)
int squareRoot(int n)
{
    int a = 0;

    for( ; a*a<=n ; a= a+1); // Empty Body!

    return a-1;
}

/**
 * Returns if the given number (a) is prime
 * @param a
 * @return
 */
bool isPrime(int a)
{
    int sq_a = squareRoot(a);
    for (int b = 2; b<= sq_a; b++)
    {
        if ( a % b ==0) {
            return false;
        }
    }
    return true;
}



/**
 * TODO: Write a program that reads a positive number from the user as n
 *       and prints out the first n prime numbers
 */


void main_primes()
{
    int n = readPositiveNumber();

    for( int current =2, count = 0; count<n; current = current+1)
    {
        if (isPrime(current))
        {
            printf("%d\n",current);
            count++;
        }
    }
}

int  main_scope()
{
    int x = 3;
    int y = 3;

    if (x %2 ==0)
    {
        int y = 4;
        y = 5;
        printf("%d\n ", y);
        return y;
    }

    if (true)
    {
        bool y = 9;
    }
    printf("%d\n ", y);

    {
        int b = 3;
        isPrime(b);
    }
    int a = 4;


}

int funcA()
{
    int a = 3;
    return a+2;
}

int func(int a)
{
    a++;
    int b= a+2 * funcA();

    b= b +funcA();
    return b;
}

void main_func_call()
{
    int b=5;
    int a = 7;

    b= func(a);
}

// This does not work
void swap(int a, int b)
{
    int c = a;
    a = b;
    b = c;

}

void main_swap()
{
    int a = 4;
    int b = 9;

    printf("a:%d  b:%d\n", a,b);

    a = a+b;

    printf("a:%d  b:%d\n", a,b);

}

// Write a function that returns the average of two real numbers
double avg(double h1, double h2)
{
    return (h1+h2)/2;
}

void main()
{
    main_scope();
}
