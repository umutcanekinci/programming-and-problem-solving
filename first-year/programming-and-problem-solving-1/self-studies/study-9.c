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
 * *     For example, indexOf("Hello World", "lo") returns 3
 */
// !your code here
int indexOf(char str1[], char str2[]) {
    int len1 = 0, len2 = 0;

    // Calculate the length of str1 and str2
    while (str1[len1] != '\0') len1++;
    while (str2[len2] != '\0') len2++;

    // If str2 is longer than str1, it cannot be a substring
    if (len2 > len1) return -1;

    // Iterate through str1
    for (int i = 0; i <= len1 - len2; i++) {
        int j;
        // Check if str2 matches str1 starting from index i
        for (j = 0; j < len2; j++) {
            if (str1[i + j] != str2[j]) break;
        }
        // If str2 matches str1 starting from index i
        if (j == len2) return i;
    }

    return -1;
}

int indexOfUpdatedint(char str1[], char str2[]) {

    int len = 0;
    for (int i=0; str2[i] != 0; i++) {
        len ++;
    }

    int currentIndex = 0;
    for(int i=0; str1[i] != 0; i++) {

        if(str1[i] == str2[currentIndex]) {
            if(currentIndex == len - 1) {
                return i - len + 1;
            } 
            currentIndex++;
        
        }
        else if (currentIndex > 0) {
            i -= currentIndex; // reset i to the next character after the first match
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
void replaceChar(char str[], char c) {

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

    char str1[] = "HeloWlo World";
    char str2[] = "lo Wo";
    char str3[] = "kabak";

    printf("Number of spaces in str1: %d\n", numberOfSpaces(str1));
    printf("Index of str2 in str1: %d\n", indexOf(str1, str2));
    printf("Last occurence of 'l' in str1: %d\n", lastOccurence(str1, 'l'));
    replaceChar(str1, 'l');
    printf("After replacing 'l' with '_': %s\n", str1);
    printf("Is str1 a polindrome: %d\n", isPolindrome(str1));
    printf("Is str3 a polindrome: %d\n", isPolindrome(str3));
}