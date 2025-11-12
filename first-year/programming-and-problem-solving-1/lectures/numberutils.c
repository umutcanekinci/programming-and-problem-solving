//
// Created by dindar.oz on 12/4/2024.
//

#ifndef WEEK9_NUMBERUTILS_H
#define WEEK9_NUMBERUTILS_H

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

//
// Created by dindar.oz on 11/27/2023.
//

/**
 * Prints out the given array
 * @param arr
 * @param len
 *
void printArray(int arr[], int len)
{
    printf("[ ");
    for (int i = 0; i < len; ++i) {
        printf("%d ",arr[i]);
    }
    printf("]\n");
}
*/



// TODO: Write a function that takes an integer (n) and a sufficiently big array
//       as parameters. The function fills the array with the digits of n
//       .
//       Example : n : 3207 then the array digits : { 7, 0, 2, 3}

void digitsOf(int n, int digits[])
{
    for (int d = 0 ; n>0 ; d++)
    {
        digits[d] = n %10;
        n /=10;
    }

}










// TODO: Write a function that takes the digits of an integer as array
//       and the digit count as parameter. It returns the integer
//       .
//       Example: digits[] = { 1,5,3,7 } digitcount:4  -> returns 7351
//  7531
int fromDigits(int digits[], int digitCount)
{

    int num = 0;
    for (int d =digitCount-1 ; d>=0; d--)
    {
        num *=10;
        num += digits[d];
    }
    return num;
}








// TODO: Write a function that takes an integer array and returns if it
//       contains any duplicate elements
//
bool hasDuplicates(int arr[], int size)
{
    for (int l = 0; l <size-1; l++)
    {
        for( int r = l+1; r< size ; r++)
        {
            if (arr[l] == arr[r])
                return true;
        }
    }

    return false;

}
















// TODO: Write a function that takes an integer (n) as parameter and returns
//       if it contains and duplicate digits
//
bool hasDuplicateDigits(int n)
{
    int arr[10];

    digitsOf(n,arr);

    int dc = log10(n)+1; // digit count of n

    return hasDuplicates(arr,dc);

}








// TODO: Write a function that takes two integer array of the same size
//       and the size as parameter. It returns the number of elements taking place
//       in both arrays and in the same position.
//       EXAMPLE : arr1 = {1,4,3,7} and arr2 = { 3,4,2,7}
int plusComparison(int arr1[], int arr2[], int len)
{
    int plus=0;


    for (int f = 0; f < len; ++f) {
        if ( arr1[f]== arr2[f])
            plus++;
    }


    return plus;
}










// TODO : Write a function that takes two integer array of the same size
//        and the size as parameter. It returns the number of elements taking place
//        in both arrays but in the different positions.
//
int minusComparison(int arr1[], int arr2[], int len)
{
    int minus=0;

    for (int f1 = 0; f1 < len; ++f1) {
        for (int f2 = 0; f2 < len; ++f2) {
            if ( f1 != f2 && arr1[f1] == arr2[f2])
                minus++;
        }
    }

    return minus;
}









/**
 * Returns a random positive number smaller than n
 * @param n
 * @return
 */
int randBelow(int n)
{
    return rand()%n;
}


/**
 * Returns a random number between m and n
 * @param n
 * @param m
 * @return
 */
int randomBetween(int n, int m)
{
    int x = randBelow(m-n);

    return n+x;
}


// TODO: Write a function that takes an integer (digitcount) as parameter
//       and returns a random positive integer that has digitcount digits.
//
int randomNumber(int digitCount)
{
    int max= pow(10,digitCount);
    int min= pow(10,digitCount-1);

    return randomBetween(min,max);
}







// TODO: Write a function that takes an integer(digitcount as parameter
//       and returns a random positive integer that has digitcount digits
//       and no repeating digits.
//
int randomValidNumber(int digitCount)
{
    int n;

    do {
        n = randomNumber(digitCount);
    } while (hasDuplicateDigits(n));

    return n;

}










#endif //WEEK9_NUMBERUTILS_H