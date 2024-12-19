#include "stdio.h"
#include "stdbool.h"
#include "utils.h"
#include "stdlib.h"


// Necessary Data types and constant definitions for Maze
#define  WALL "\xDB\xDB"   // Full-cursor character
#define  EMPTY "  "
#define  EXIT  "\xDA\xBF"  // Special box-like character
#define  ROBOT "* "





// Define a datatype to represent a cell of a maze MazeCell
enum MazeCell { Empty, Wall, Exit, Outside};
typedef enum MazeCell MazeCell;













// Define a datatype to represent a Maze
#define MAZESIZE 10
#define DIRECTION_COUNT 4
typedef MazeCell Maze[MAZESIZE][MAZESIZE];











































// Define a data type to represent Direction
typedef enum { Up, Left, Down, Right} Direction;





















// write a function that returns the opposite of  given Direction without if-s (oppositeOf)
Direction oppositeOf_withIf(Direction dir)
{
    if ( dir == Up)
        return Down;
    if ( dir == Down)
        return Up;
    if ( dir == Left)
        return Right;
    if ( dir == Right)
        return Left;
}
Direction oppositeOf_withSwitch(Direction dir)
{
    switch (dir)
    {
        case Up: {
            return Down;
            break;
        }
        case Down: {
            return Up;
            break;
        }
        case Left: {
            return Right;
            break;
        }
        case Right: {
            return Left;
            break;
        }
    }
}

Direction oppositeOf(Direction dir)
{
    return (dir +2) % DIRECTION_COUNT;


}















// Define a data type to represent a Position in a maze
#define ROW 0
#define COL 1
typedef int Position[2];
















// Define a (arbitrary) global Maze variableas follows

Maze maze = { { 1,1,1,1,0,1,1,1,0,1 },
              { 1,0,1,1,0,1,1,1,0,1 },
              { 1,0,0,0,0,0,0,0,0,1 },
              { 1,0,1,1,0,1,1,1,0,1 },
              { 1,0,1,1,0,1,1,1,2,1 },
              { 1,0,0,0,0,0,0,0,0,1 },
              { 1,1,1,0,1,1,1,1,0,1 },
              { 1,1,1,0,1,1,1,1,0,1 },
              { 1,0,0,0,0,0,0,0,0,1 },
              { 1,1,1,1,1,1,0,1,1,1 }
              };

















// Define an arbitrary global variable for the position of the robot
Position robot = {3,1};


void printMazeCell(Maze maze, int row,int  col, Position robot)
{
    if ( row == robot[ROW] && col == robot[COL]) {
        printf(ROBOT);
        return;
    }
    switch ( maze[row][col]) {
        case Wall: {
            printf(WALL);
            break;
        }
        case Empty: {
            printf(EMPTY);
            break;
        }
        case Exit: {
            printf(EXIT);
            break;
        }
    }
}

// Write a function that prints a given maze (printMaze) with a given robot at a given position
void printMaze(Maze maze, Position robot)
{
    for (int r = 0; r < MAZESIZE; ++r) {

        for (int c = 0; c < MAZESIZE; ++c) {
            printMazeCell(maze, r, c, robot);
        }

        printf("\n");
    }

}

























































// Write a function that returns if a given  position is inside the maze or not (isInside)
bool isInside(Position p)
{
    return p[ROW] < MAZESIZE && p[ROW]>= 0 && p[COL] < MAZESIZE && p[COL]>= 0 ;
}















// Write a function that returns the cell at a given Position in a given Maze (getCell)
MazeCell  getCell(Maze maze, Position p)
{
    if (isInside(p))
        return  maze[ p[ROW]][ p[COL]];
    else return Outside;

}















// Write a function that returns if a given  position is exit (isExit)
bool isExit(Maze maze, Position p)
{
    return (getCell(maze, p) == Exit);
}



void copyPosition(Position source , Position target) {

    return getCell(maze, movePosition())    

}





































void main()
{
    printMaze(maze, robot);

    Position p = { 30,23};

    MazeCell  cell = getCell(maze, p);
}





