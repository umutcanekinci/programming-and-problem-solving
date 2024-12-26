#include <stdio.h>


// Write a function that takes 2-dimensional 20x20 integer array
// returns the sum of all elements.
int sumOf2DArray(int arr[][20], int rowCount)
{
    int sum = 0;
    for (int r = 0; r < rowCount ; ++r) {
        for (int c = 0; c < 20; ++c) {
            sum += arr[r][c];
        }
    }

    return sum;
}








// Write a function that takes 2-dimensional 20x20 integer array
// returns the sum of all elements on the diagonal.
int sumOf2DArrayDiagonal(int arr[][20], int rowCount)
{
    int sum = 0;
    for (int r = 0; r < rowCount ; ++r) {
        sum += arr[r][r];
    }

    return sum;
}



enum Direction { Up , Down, Left, Right};

typedef  enum Direction Direction;

typedef  double Point2D[2] ;

// Define enumerated types for day and coin-face

typedef enum  { Mon, Tue, Wed, Thu, Fri, Sat, Sun} Day;



#define X 0
#define Y 1


Day day;



// Write a function that returns n day after the given day
Day after( Day day, int n)
{
    return (day + n) % 7;
}


int main_old()
{
    day = Mon;

    day +=1;

    char c = '?';
    int x =1;

    x = c;

    for (int c = 0; c < 256 ; ++c) {
        printf("%c - %d\n", c , c);
    }



    Direction d = Up;

    Point2D p1 = { 1.0, 5.0};

    p1[X] = 1;



    return 0;
}

int main_2dArrays()
{
    // Define a 2D array that contain 5 rows and  4 columns

    int matrix[5][4];

    int m[][2] = {  {1,2} , {6,2}, {-3,0}, {1.1}};

    matrix[1][0] = 5;


    return 0;
}