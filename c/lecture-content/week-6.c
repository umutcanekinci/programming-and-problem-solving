#include <stdio.h>
#include <stdbool.h>

void main_arrray_intro()
{
    int nums[10];

    nums[0] = 1;
    nums[3] = 2;

    for (int i = 0; i < 10; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    int x = 4;
    int numbers2[6] = { 1,3,x,6,9};



    for (int i = 0; i < 6; ++i) {
        printf("%d ", numbers2[i]);
    }

}

// Write a function that returns the average of elements in an array
double averageOf(int a[]  , int len)
{
    int sum =0;
    for (int f= 0 ; f< len; f++ )
    {
        sum = sum + a[f];
    }
    return (double ) sum/ (double )len; // casting int to double
}

// Write a function that returns the maximum element of an array
int maxOf(int vals[], int count)
{
    int max = vals[0];

    for (int c = 1; c < count; c++) {
        if (vals[c] >max)
            max = vals[c];
    }

    return max;
}

// Write a function that prints an integer array on the screen.
void printArray(int arr[], int len)
{
    printf("[ ");

    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i<len-1)
            printf(",");
    }
    printf("]\n");
}

void main_arr()
{
    int arr[] = { 1,4,-3, 5, 5,7 ,0 ,10, -1, 20 };
    int arr2[] = { 1,3,5};

    printf("Average of arr: %f\n", averageOf(arr,10));

    printf("Maximum of arr: %d\n", maxOf(arr,10));

    printArray(arr,10);
}



// Write a function that  calculates m*n without using *
// assumes that n is positive without using loops
int multiply3(int m, int n)
{
    if (n==0) return 0;

    int result = m + multiply3(m, n-1);

    return result;
}

// Write a function that calculates factorial of n without loop
int fact(int n)
{
    if (n ==0)
        return 1;
    return n* fact(n-1);
}

void main()
{

    printf("Factorial of 3 is : %d \n", fact(3));
    int a = 3;
    int b = 5;
    printf("%d times %d = %d\n", a, b, multiply3(a,b));

    main_arr();
}