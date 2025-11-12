#include <iostream>

using namespace std;

/* Structs are generic type data structures that can be specialized for any purpose.
   You can create any type of association between values and bind functions to the struct.
 */
struct Point {

    int x;
    int y;
    void printPoint() {
        cout << "X : " << this->x << " Y : " << this->y << endl;
    }
};


int main() {
    cout << endl << "STRUCTS" << endl;
    cout << endl << "*Declaration" << endl;
    //Declaring a struct with variables
    Point p1 = {1,2};
    /*Assigning values after declaration
     You can access the structure's variables and functions by using '.'
     The variables and functions in a struct are "public" by default, which means they are visible to any component
     (functions,classes etc.).When you learn classes, this sentence will make more meaning.
     */
    Point p2;
    p2.x = 5;
    p2.y = 7;
    p1.printPoint();
    p2.printPoint();
    cout << endl << "*Struct Array" << endl;
    //An array of "points"
    Point multiple_point[5] = {
            {1, 1},
            {2, 2},
            {3, 3},
            {4, 4},
            {5, 5},
    };
    multiple_point[4] = {6, 6,};
    for (int i = 0; i < 5; i++) {
        multiple_point[i].printPoint();
    }
    cout << endl << "*Struct Pointer" << endl;
    //Declaration of a pointer which points to the address of the "pointer"(struct)
    Point *point_pointer = &p1;
    cout << "Using pointer to access struct values" << endl;
    //As you can see we use '->' instead of '.'
    cout << "The X value : " << point_pointer->x << endl;
    cout << "The Y value : " << point_pointer->y << endl;
    cout << "Calling the print function" << endl;
    point_pointer->printPoint();

    return 0;
}

