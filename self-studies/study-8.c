#include "stdio.h"
#include "stdbool.h"
#include <stdlib.h>
#include <time.h>


/** 
 * * SE 1105 study material
 * 
 * * 2D-ARRAYS
 * 
 * * Author: Dindar ÖZ
 */

/* -------------------------------------------------------------------------- */
/*                            PROGRAMMING EXERCISES                           */
/* -------------------------------------------------------------------------- */


/**
 * * 8.1. Write a function that takes 2-dimensional 20x20 integer array and 
 * *      returns the maximum element
 */
// !your code here
int maxElement(int arr[20][20]) {

    int max = arr[0][0];
    int count = 20;

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if(arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
    
}






/**
 * * 8.2. Write a function that takes 2-dimensional 20x20 integer array and 
 * *      returns the maximum of the sum of the rows
 */
// !your code here
int maxRow(int arr[20][20]) {

    int max = 0;
    int count = 20;

    for (size_t i = 0; i < count; i++)
    {
        int sum = 0;
        for (size_t j = 0; j < count; j++)
        {
            sum += arr[i][j];
        }
        if(sum > max) {
            max = sum;
        }
    }
    return max;
}







/**
 * * 8.3. Write a function that takes 2-dimensional 20x20 integer array and 
 * *      returns the sum of the elements on the diagonal
*/
 
int sumDiagonal(int arr[20][20]) {

    int sum = 0;
    int count = 20;
    for (size_t i = 0; i < count; i++)
    {
        sum += arr[i][i];
    }
    return sum;

}







/**
 * * 8.4. Write a function that takes 2-dimensional 20x20 integer array and 
 * *      fills the array with random numbers between 0 an 100
 */
// !your code here
int getRandBetween(int min, int max) {
    return rand() % max + min;
}
void fillRandomly(int arr[20][20]) {

    int count = 20;
    for (size_t i = 0; i < count; i++)
    {
        for (size_t j = 0; j < count; j++)
        {
            arr[i][j] = getRandBetween(1, 99);
        }
        
    }
}









/* -------------------------------------------------------------------------- */
/*                                j FUNCTION                               */
int main() { 
    //* You can call the functions you have implemented above to see if they are working.
    //* You can also print the returning values of the functions if there is any.  

    srand(time(0));
    int arr[20][20];
    fillRandomly(arr);
    printf("Max element: %d\n", maxElement(arr));
    printf("Max row: %d\n", maxRow(arr));
    printf("Sum of diagonal: %d\n", sumDiagonal(arr));
    return 0;   
}