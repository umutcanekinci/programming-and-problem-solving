#include <stdio.h>

// Write a function that takes an integer as parameter and returns its absolute value
int mutlakdeger(int d)
{
    if ( d>= 0)
        return d;
    else return -1*d;
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

// Write a function that takes 5 integers as parameters and returns the minimum
int minofFive(int n1, int n2, int n3, int n4, int n5)
{
    return minOfThree(n1,n2, minOfThree(n3,n4,n5));
}


// Write a function that takes an integer as parameter and prints out if it is even or not
void printIfEven(int m)
{
    if (  m % 2 == 0) // m is even
        printf("%d is even\n",m);
    else printf("%d is odd\n",m);

}

void main_old3()
{
    int x = -7;

    printf("Absolute Value of %d is %d\n", x, mutlakdeger(x));

    printf("The minimum of %d %d %d is %d\n",5,2,8 ,minOfThree(5,2,8));

    printIfEven(7);
}


// Write a program that reads 3 integers from user and prints out if the minimum is even or not
void main_old4()
{
    int a1, a2, a3;

    printf("Please enter 3 integers:\n");

    scanf_s("%d",&a1);
    scanf_s("%d",&a2);
    scanf_s("%d",&a3);

    printf("a1:%d a2:%d a3:%d\n", a1,a2,a3);

    printIfEven(minOfThree(a1,a2,a3));
}

void main_for_intro()
{


    for (int a = 0; a<5;a = a+1)
    {
        printf("a:%d\n",a);
    }



    // Infinite loop
    // for (;;)
    // {
//
    //  }
}

// Write a function that prints a line of length n with “*”s.
void printLine(int n)
{
    for (int count = 0; count<n ; count = count+1 )
    {
        printf("O");
    }
    printf("\n");
}

//Write a function that prints a square of edge-size n with “*”s.
void printSquare(int edge_size)
{
    for (int a =0; a<edge_size; a= a+1)
    {
        printLine(edge_size);
    }
}



// Write a function that prints even integers from 1 to n(inclusive).
void printEvens(int n)
{
    for (int a = 0; a<= n; a = a + 2)
    {
        printf("%d ",a);
        printf("\n");
    }

}

// Write a function that returns the sum of all odd integers from 1 to n(inclusive).
int sumOfOdds(int n)
{
    int sum = 0;
    int  a = 1;
    for (; a <= n ; ) {
        sum = sum +a;
        a = a+2;
    }

    return sum;
}


// Write a function that takes m and n as input and returns m^n.
int power(int m, int n)
{
    int x =1;
    for (int c = 0; c<n; c = c+1)
    {
        x = x*m;
    }

    return x;
}

// Write a function that takes n as input and
// return the closest integer to the squareroot of n (not bigger than)
int squareRoot(int n)
{
    int a = 0;

    for( ; a*a<=n ; a= a+1)
    {}

    return a-1;
}

void main()
{
    // printEvens(50);
    printf("%d\n", sumOfOdds(100));


}

