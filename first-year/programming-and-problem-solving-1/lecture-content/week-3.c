#include <stdio.h>
#include "stdbool.h"

// A simple function with no input and no output
void funcA()
{
    printf("FuncA is called\n");
}

// Write a function that takes 3 integers as parameters and returns the sum of them.
int sumOfThree(int x, int y, int z)
{
    return x+y+z;
}

// Write a function that prints «Hello» to the screen
void sayHello()
{
    printf("Hello!\n");
    printf("People!\n");
    printf("All around the world!\n");
}


// Write a function that prints 3 times “Hello” to the screen
void sayHelloThree()
{
    sayHello();
    sayHello();
    sayHello();
}

// Write a function that prints 9 times “Hello” to the screen
void sayHelloTen()
{
    sayHelloThree();
    sayHelloThree();
    sayHelloThree();
    sayHello();
}

void main_old()
{
    // Variable definition statements
    int a;
    bool b;

    // Assignment statements
    a = 3 * 5;
    b = false;

    // Function call statement
    funcA();

    int k = 4;
    int l = 7;
    int m = 1;

    int o = sumOfThree(k,l, sumOfThree(k,l,m));


    printf("The value of o is %d.\n" , o);
    printf("The value of o is %d.\n" , o+2);
    printf("The value of o is %d.\n" , sumOfThree(2,3,4)+ 3* sumOfThree(1,3,4));


    printf("%d plus %d is %d \n", 3, 5, 8);


}

void main_old2()
{
    sayHelloThree();
}

void main_swap()
{
    int x = -2;
    int y = 8;

    printf("x:%d  y:%d \n", x, y);

    // Swap the variables x and y without 3rd variable
    x = x+y;
    y = x-y;
    x = x-y;

    // Swap the variables x and y with 3rd variable
    int z = x;

    // Compund statement - block
    {
        x = y;
        y = z;
    }

    printf("x:%d  y:%d \n", x, y);

}

// Write a function that takes an integer as parameter and returns its absolute value
int mutlakdeger(int d)
{
    if ( d>= 0)
        return d;
    else return -1*d;
}

void main_if()
{
    int x = -3;

    if (x > 4  &&  x < 50) {
        printf("X is greater than 4");
        if ( x <30)
            printf("x is smaller than 30\n");

    }
    else  if ( x >0 ){
        printf("X is smaller than or equal to 4");
    }

}

// Write a function that takes 3 integers as parameters and returns the minimum
int minOfThree(int n1, int n2, int n3)
{

    if ( n1 >= n3  && n2>=n3)
    {
        return n3;
    } else if ( n1 <= n2  && n1<=n3)
    {
        return n1;
    }

    return n2;
}


// Write a function that takes an integer as parameter and prints out if it is even or not

void main()
{
    int x = -7;

    printf("Absolute Value of %d is %d", x, mutlakdeger(x));
}
