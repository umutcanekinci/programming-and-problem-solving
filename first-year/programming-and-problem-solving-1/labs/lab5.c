#include <stdio.h>

int sum(int temperatures[], int size, int left) {
    return temperatures[left] + left < size ? sum(temperatures, size, left) : 0;
}

double calculateAverage(int temperatures[], int size) {
    
    if (size < 0){
        return (double) 0;
    }

    return sum(temperatures, size, 0) / size;

}

void findHottestAndCoolestTemperature(int temperatures[], int size) {

    int min = temperatures[0];
    int max = temperatures[0];

    for(int i=1; i<size; i++) {

        if(temperatures[i] < min) {
            min = temperatures[i];
        }

        if(temperatures[i] > max) {
            max = temperatures[i];
        }

    }

    printf("The hottest day: %d", max);
    printf("The coldest day: %d", min);

}

void addTemperature(int temperatures[], int size, int index, int value) {

    if(index < 0 || index >= size){
        printf("Index is out of bound.");
    }
    else 
    {
        temperatures[index] = value;
    }
    
}

int main() {

    int temperatures[6] = { -2, 7, 9, 12, 56, 45 };

    printf("Average temperature: ", calculateAverage(temperatures, 6));
    findHottestAndCoolestTemperature(temperatures, 6);

    return 0;

}