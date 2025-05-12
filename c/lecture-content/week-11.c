#include <stdio.h>
#include <stdbool.h>


void printString(char arr[])
{
    printf("%s\n",arr );
}

// ! Write a function that returns the length of a string
int length(char str[])
{
    int len =0;

    for (len = 0;  str[len]!= 0 ; len++) ;

    return len;
}


bool isSmallLetter(char c)
{
    return  c >= 'a' && c<='z';
}

// !Write a function that capitalizes a string
// !Example: "Hello World!" -> "HELLO WORLD!"
void capitalize(char str[])
{
    int delta = 'a'- 'A';
    for (int i = 0; str[i]!=0; ++i) {

        if (isSmallLetter(str[i]))
        {
            str[i] -= delta;
        }
    }
}


// Write a function that takes a string (str) and
// two characters namely c1 and c2 as parameters.
// The function must replace every occurrence of c1 in str with c2.
void replaceAll(char str[], char c1, char c2 )
{
    for (int i = 0; str[i]!=0; ++i) {

        if (str[i]== c1)
        {
            str[i] = c2;
        }
    }
}

//Write a function that returns if two strings are equal.
bool isEqual(char str1[], char str2[])
{
    int finger=0;
    for ( finger = 0; str1[finger]!= 0 ; ++finger) {
        if (str1[finger]!= str2[finger])
            return false;
    }

    return str2[finger]==0;
}

// TODO:Write a function that returns if the given string (sentence)
//  is a pangram.
bool isPalindrome(char str[])
{
    int l =0;
    int r= length(str)-1;

    for ( ; r>l ; l++, r--)
    {
        if (str[l]!= str[r])
            return false;
    }
    return true;



}


int main(void)
{

    char c = 'a';

   // printf("%c", c);

    char arr[] = { 'H', 'e', 'l', 'l','o', 0};
    char arr2[] = "12345";

    char str[]="Hello World!";

    printString(str);

    capitalize(str);

    printString(str);

    return 0;
}