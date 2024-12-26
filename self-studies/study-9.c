#include "stdio.h"
#include "stdbool.h"


/** 
 * * SE 1105 study material
 * 
 * * STRINGS
 * 
 * * Author: Dindar ÖZ
 */

/* -------------------------------------------------------------------------- */
/*                            PROGRAMMING EXERCISES                           */
/* -------------------------------------------------------------------------- */


/**
 * * 11.1. Write a function that takes a string (str) and returns the number of 
 * *       spaces in str

 */
// !your code here
int numberOfSpaces(char str[]) {

    int count = 0;

    for(int i=0; str[i] != 0; i++) {

        if(str[i] == ' ') {
            count++;
        }

    }
    return count;

} 






/**
 * * 11.2. Write a function that takes two strings (str1 and str2) and returns the 
 * *      index of str2 in str1. It returns -1 if str1 is not in str2
 */
// !your code here
int indexOf(char str1[], char str2[]) {

    int len = 0;
    for (int i=0; str2[i] != 0; i++) {
        len ++;
    }

    int currentIndex = 0;
    for(int i=0; str1[i] != 0; i++) {

        if(str1[i] == str2[currentIndex]) {
            if(currentIndex == len - 1) {
                return currentIndex;
            } 
            currentIndex++;
        
        }
        else {
            currentIndex = 0;
        }
    }
    return -1;

}





/**
 * * 11.3. Write a function that takes a string (str) and a character (c) as parameter.
 * *       The function returns the index of the last occurrences of c in str.
 */
// !your code here
int lastOccurence(char str[], char key) {

    int lastIndex = -1;

    for(int i=0; str[i]!=0; i++) {
        if(str[i] == key) {
            lastIndex = i;
        }
    }
    return lastIndex;

}






/**
 * * 11.4. Write a function that takes a string (str) and a character (c) as parameter.
 * *       The function changes every occurrence of c with '_' in str
 */
// !your code here
void lastOccurence(char str[], char c) {

    for(int i=0; str[i]!=0; i++) {
        if(str[i] == c) {
            str[i] = '_';
        }
    }
}









/**
 * * 11.5. Write a function that takes a string (str) as parameter.
 * *       The function returns true if str s palindrome. (for example "kabak", "adanada")
 * 
 */
// !your code here
bool isPolindrome(char str[]) {

    int length = 0;
    for(int i=0; 0!=str[i]; i++) {
        length +=1;
    }

    for(int i=0; i<length; i++) {
        if(str[i] != str[length - i - 1]) {
            return false;
        }
    }
    return true;
}










/* -------------------------------------------------------------------------- */
/*                                MAIN FUNCTION                               */
/* -------------------------------------------------------------------------- */
void main() { 
    //* You can call the functions you have implemented above to see if they are working.
    //* You can also print the returning values of the functions if there is any.  

    
}