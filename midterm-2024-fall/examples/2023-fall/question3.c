#include <stdio.h>

int func(int number) {

    if(!number) {
        return 0;
    }

    int lastDigit = number % 10;
    return lastDigit + number % lastDigit ? func(number/10) : 0;

}