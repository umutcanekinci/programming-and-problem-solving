#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

/** 
 * * SE 1105 study material
 * 
 * * ENUMERATIONS, RANDOM NUMBERS
 * 
 * * Author: Dindar ÖZ
 */

/* -------------------------------------------------------------------------- */
/*                            PROGRAMMING EXERCISES                           */
/* -------------------------------------------------------------------------- */


/**
 * * 6.1. Define an enumeration for the days of the week
 */
// !your code here
enum Day {Mo, Tu, We, Th, Fr, Sa, Su};


/**
 * * 6.2. Write a function that takes a day of the week and a number n. 
 * *      The function must return the day n day after the given day.
 */
// !your code here
enum Day afterDay(enum Day day, int n) {
    if(day + n < Su) {
        return -1;
    }
    return day + n;
}




/**
 * * 6.3. Define an enumeration for the directions in 2D (i.e. Up, Down, Left, Right)
 */
// !your code here
enum Direction {Up, Down, Left, Right};




/**
 * * 6.4. Write a function that takes a direction and returns the opposite direction
 */
// !your code here
enum Direction opposite(enum Direction direction){
    return direction == Up ? Down : 
    direction == Down ? Up :
    direction == Left ? Right : 
    Left;
}



/**
 * * 6.5. Write a function that takes an integer n and a probability p. 
 * *      It must return a random integer greater than n with probability p 
 * *      and smaller than n with probability 1-p
 */
// !your code here
#define ACCURACY 1000000

int randomBelow(int num) {
    return rand() % num;
}
int randomAbove(int num) {
    return rand() + num + 1;
}
int randomWithProbability(double p){
    return randomBelow(ACCURACY) < p * ACCURACY;
}
int randomNumber(int n, double p){
    srand(time(0));
    return  randomWithProbability(p) ? randomAbove(n) : randomBelow(n);
}


/** CHALLENGE!
 * * 6.6. Write a function that takes an array of real numbers and its size n. 
 * *      Each element of the array represents a probability value and the sum
 * *      of all elements  is 1.0. The function must return an integer i as follows: 
 * *       
 * *      0 <= i < n and p(i) = arr[i] ( p(i) means probability of the function returning i)  
 * *      
 */
// !your code here
double randomElement(double array[], int size) {
    int num = randomBelow(ACCURACY);
    int totalProbability = 0;
    for(int i=0; i<size; i++) {
        totalProbability += array[i] * ACCURACY;
        if(num < totalProbability) {
            return i;
        }
    }
}


/* -------------------------------------------------------------------------- */
/*                                MAIN FUNCTION                               */
/* -------------------------------------------------------------------------- */
void main() { 
    //* You can call the functions you have implemented above to see if they are working.
    //* You can also print the returning values of the functions if there is any.  
    enum Day day = Mo;
    printf("%d\n", afterDay(day, 3));
    printf("%d\n", opposite(Up));
    printf("%d\n", randomNumber(10, 0.5));
    double array[] = {0.1, 0.2, 0.3, 0.4};
    printf("%.2f\n", randomElement(array, 4));
    
}