#include <stdbool.h>
#include "stdio.h"

#pragma region Question 2

#define DIRECTONCOUNT 4
typedef enum {UP, RIGHT, DOWN, LEFT} Direction;
typedef enum {CLOCKWISE, COUNTERCLOCKWISE} TurnDirection;

Direction finalDirection(Direction initialDirection, TurnDirection turns[], int turnCount) {

    for(int i=0; i<turnCount; i++) {
        if(turns[i] == CLOCKWISE) {
            initialDirection++;
        }
        else {
            initialDirection--;
        }
    }
    initialDirection = initialDirection % 4;
    if(initialDirection < 0){
        initialDirection += 4;
    }
    return initialDirection;
}

void question2Test() {

    Direction initialDirection = UP;
    TurnDirection turns[] = { CLOCKWISE, CLOCKWISE, COUNTERCLOCKWISE, CLOCKWISE, CLOCKWISE };
    printf("The final direction is: %d", finalDirection(initialDirection, turns, 5));
}

#pragma endregion

#pragma region Question 3

int circumference(int map[4][4])
{
    int sum = 0;
    for (int row = 0; row < 4; row++)
    {
        for (int column = 0; column < 4; column++)
        {
            if(map[row][column] == 1)
            {
                int edges = 0;

                if(row == 0 || map[row-1][column] == 0){
                    edges++;
                }
                if(row == 3 || map[row+1][column] == 0){
                    edges++;
                }
                if(column == 0 || map[row][column-1] == 0){
                    edges++;
                }
                if(column == 3 || map[row][column+1] == 0){
                    edges++;
                }
                sum += edges;
            }
        }
    }
    return sum;
}

void question3Test()
{
    int map[4][4] = {
                        {0, 1, 1, 0},
                        {0, 0, 1, 0},
                        {0, 0, 1, 0},
                        {0, 1, 1, 1}};

    printf("The circumference of the map is: %d", circumference(map));

}

#pragma endregion

#pragma region Question 4

bool doesOccur(char str[], int n) {

    for(int i=0; str[i] != 0; i++) {
        int count = 0;
        for(int j=0; str[j] != 0; j++) {
            if(str[i] == str[j]) {
                count++;
            }
        }
        if(count >= n) {
            return true;
        }
    }
    return false;

}

void question4Test() {
    char str[] = "hello";
    int n = 3;
    printf("Does the string contain a character that occurs %d times: %d", n, doesOccur(str, n));
}

#pragma endregion