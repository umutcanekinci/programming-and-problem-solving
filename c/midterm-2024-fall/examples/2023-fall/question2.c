#include <stdio.h>

int abs(int a) {

    return a > 0 ? a : -a;

}

int func(int array[], int size) {

    int max = 0;

    for(int i=0; i<size-1; i++) {

        int difference = abs(array[i] - array[i+1]);
        
        if(difference > max) {
            max = difference;
        }

    }
    
    return max;

}