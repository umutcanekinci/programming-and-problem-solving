#include <stdio.h>
#include <stdbool.h>


/** 
 * * SE 1105 study material
 * 
 * * ARRAYS
 * 
 * * Author: Dindar ÖZ
 */

/* -------------------------------------------------------------------------- */
/*                            PROGRAMMING EXERCISES                           */
/* -------------------------------------------------------------------------- */


/**
 * * 4.1. Write a function that takes an integer array and its size as parameters. 
 * *      The function must return the number of negative elements in the array
 */
// !your code here
int countNegatives(int array[], int length) {

    int count = 0;
    for(int i=0; i<length; i++) {
        if(array[i] < 0) {
            count++;
        }
    }
    return count;

}

/**
 * * 4.2. Write a function that takes an integer array and its size as parameters. 
 * *      The function must print the sum of the first and last element
 */
// !your code here
int sumOfFirstAndLast(int array[], int length) {
    return array[0] + array[length-1];
}

/**
 * * 4.3. Write a function that takes a double array and its size as parameters. 
 * *      The function must calculate the sum of all elements whose indexes are divisible by 3
 * */
// !your code here
double sumOfDivisibleBy3(double array[], int length) {

    double result = 0;
    for(int i=0; i<length; i++) {
        if(!(i % 3)){
            result += array[i];
        }
    }
    return result;
}

/**
 * * 4.4. Write a function that takes two integer arrays arr1 and arr2, and their sizes , 
 * *      size1 and size2 as parameters. It must return the number of elements that exist 
 * *      in arr1 but do not exist in arr2.
 * */
// !your code here
int disjunction(int array1[], int array2[], int size1, int size2) {

    int count = 0;
    for(int i=0; i<size1; i++) {
        bool doesExist = false;
        for(int j=0; j<size2; j++) {
            if(array1[i] == array2[j]) {
                doesExist = true;
                break;
            }
        }   
        if(!doesExist) {
            count++;
        }
    }
    return count;

}

/**
 * * 4.5. Write a function that takes two integer arrays arr1 and arr2, and their sizes , 
 * *      size1 and size2 as parameters. It must return the number of elements that exist 
 * *      both in arr1 and in arr2.
 * */
// !your code here
int conjunction(int array1[], int array2[], int size1, int size2) {

    int count = 0;
    for(int i=0; i<size1; i++) {
        for(int j=0; j<size2; j++) {
            if(array1[i] == array2[j]) {
                count++;
                break;
            }
        }
    }
    return count;

}

/**
 * ? CHALLENGE
 * * 4.6. Write a function that takes an integer (n) as an integer array storing 
 * *      its digits and the number of digits as parameters. The function must return n. (Reverse of digitizing)
 * *      EXAMPLE: If the array : { 2,0,5 } then the function returns 502

 * */
// !your code here
int powerOfTen(double num) {
    if(num == 0) {
        return 1;
    }
    return 10 * powerOfTen(num-1);
}
int converseOf(int n[], int length) {
    int result = 0;
    for(int i=0; i<length; i++) {
        result += n[i]*powerOfTen(i);
    }
    return result;
}

/**
 * ? CHALLENGE
 * * 4.7. Write a function that takes an integer array and its size as parameters. 
 * *      The function must return the length of the longest repeating sequence
 * */
// !your code here
int mostRepeatingOf(int array[], int size) {

    // declare two arrays which include all different numbers and their counts.
    //use double for to get max count
    int maxCount=0;
    int sequence;
    for(int i=0; i<size-1; i++) {
        int count=1;
        for(int j=i+1; j<size; j++) {
            if(array[j] == array[i]) {
                count++;
            }
        }
        if(count > maxCount) {
            maxCount = count;
            sequence = array[i];
        }
    }
    return sequence;
}

/* -------------------------------------------------------------------------- */
/*                                MAIN FUNCTION                               */
/* -------------------------------------------------------------------------- */
int main() {
    //* You can call the functions you have implemented above to see if they are working.
    //* You can also print the returning values of the functions if there is any.

    int array[] = {1, -3, 4, 5, 5, -1, 28, 4, 5, 5, 2, 2};
    int array2[] = {4, 7, 4,8, 0, 4, 8, 4, 2, 7, 1, 2};
    int len = 12;

    printf("Count of negatives is => %d\n", countNegatives(array, len));
    printf("sumOfFirstAndLast => %d\n", sumOfFirstAndLast(array, len));
    printf("disjunction => %d\n", disjunction(array, array2, len, len));
    printf("conjunction => %d\n", conjunction(array, array2, len, len));
    printf("mostRepeatingOf => %d\n", mostRepeatingOf(array2, len));

    double array3[] = {1, 3, 4, 5, 5, 1, 28, 4, 5, 5, 2, 2};
    printf("sumOfDivisibleBy3=> %f\n", sumOfDivisibleBy3(array3, len));

    int array4[] = {3, 5, 0, 2};
    printf("converse of array is => %d\n", converseOf(array4, 4));//bug

    return 0;
}