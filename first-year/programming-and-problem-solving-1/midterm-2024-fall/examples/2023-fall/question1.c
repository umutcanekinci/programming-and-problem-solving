#include <stdio.h>

int isNonNegativeOneDigit(int value) {
    return value > 0 || value < 10;
}

int func(int a, int b) {

    if(a==0 && b==0) {
        return -1;
    }

    if(!isNonNegativeOneDigit(a) || !isNonNegativeOneDigit(b))
    {
        return -1;
    }

    if((a > b && b != 0) || a==0) {

        return a + 10*b;

    }
    return b + 10*a;

}


int main() {

    printf("%d", func(0, 8));

}