#include <stdio.h>

#pragma region Question 1

double sum(double arr[10][10]) {
    double sum = 0;
    for(int i=0; i<9; i++) {
        for(int j=i+1; j<10; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

void test1() {
    double arr[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
    };
    printf("Sum: %f\n", sum(arr));
}

#pragma endregion

#pragma region Question 2

int longestAlphabeticSequence(char str[]) {
    /*
    int j, max = 0;
    for(int i=0; str[i] != 0; i++) {
        for(j=i+1; str[j]!=0 && str[j-1] <= str[j]; j++);
        max = j-i >= max ? j-i : max;
    }
    */
    int max = 0, count = 1;
    for (int i = 1; str[i] != 0; i++)
    {
        if(str[i-1] <= str[i]){
            count += 1;
        }
        else{
            max = count > max ? count : max; 
            count = 1;
        }
    }
    return count > max ? count : max;
}

void test2() {
    char str[] = "encyclopedia";
    printf("Longest Alphabetic Sequence: %d\n", longestAlphabeticSequence(str));
}

#pragma endregion

#pragma region Question 3

typedef int Time[3];
int timeBetween(Time t1, Time t2) {
    int deltaTime = (t1[0] - t2[0])*3600 + (t1[1] - t2[1])*60 + (t1[2] - t2[2]); 
    return deltaTime < 0 ? -deltaTime : deltaTime;
}

void test3() {
    Time t1 = {14, 30, 0};
    Time t2 = {15, 20, 0};
    printf("Time Between: %d\n", timeBetween(t1, t2));
}

#pragma endregion

int main() {
    
    test1();
    test2();
    test3();

    return 0;
}