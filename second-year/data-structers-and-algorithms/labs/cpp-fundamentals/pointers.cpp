#include <iostream>

using namespace std;

int main() {

    /*  POINTERS
       The technical explanation of every step to print out even a simple "Hello World" to the terminal
        can be as long as a book. To sum it up briefly in an abstract way, we can say that
        everything you write in a C++ file stored in the RAM of the computer in a sophisticated way then
        executed the commands to produce some output.
        The way computer stores variables/functions etc. in its storage area is by assigning a
        "pointer" (Turkish: belirteç/işaret) to the variable's address in RAM. As a computer/software engineer, you
        have to be familiar with "pointer" logic and its applications.
     */

    /*
       The next example will print out what is the "RAM address" of the variable
       %p is the string format option to print out pointer (the ram address where the pointer points to)
       & symbol is used as "reference operator"
       THERE IS NO DECLARATION SUCH AS "reference a = 0x62febc" or  "pointer p = 0x62febc"
     */
    cout << endl << "POINTERS" << endl;
    cout << endl << "*Address" << endl << endl;
    int number = 5;
    cout << "Number is " << number << endl;
    cout << "The RAM address of number is " << &number << endl;

    /*
     Use int* = &{some_variable} if you want to print out pointer address;
     */
    number = 10;
    int *number_pointer = &number;
    cout << "Int Number pointer " << number_pointer << endl;
    float float_number = 2.78;
    float *float_number_pointer = &float_number;
    cout << "Float number pointer " << float_number_pointer << endl;
    char character = 'a';
    char *character_pointer = &character;
    cout << "Trying to print char character pointer with char* " << character_pointer << endl;
    /* As you see in above the char* actually did not print out the address of the variable
      (you will learn the reason later, for now, if you want to print out to "address" of
      character pointer always uses (int*), for other values use the same type.

     On the right side of the equation, there is something called "type casting"
     which can be very confusing to understand from a brief comment such as this.
     Please learn the concept from a more detailed source if you are not familiar with it.
     */
    int *actual_character_point = (int *) &character;
    cout << "Trying to print char character pointer with int* " << actual_character_point << endl;

    cout << endl << "*Value" << endl << endl;
    int new_number = 10;
    int *new_number_pointer = &new_number;
    cout << "New number pointer " << new_number_pointer << endl;
    // Accessing the value pointed by pointer
    int another_number = *new_number_pointer;
    cout << "Another number value " << another_number << endl;

    /*
     The reason why you could not able to print out "character_pointer" as an address is because of a
    special condition related to char and the pointer declarations. When you declare char *some_name = ...
    the computer interprets that variable as an "array" of character values so, what is an array?
    Array will be the first data structure you are going to learn and use in this course.
    An array is a set of values of the same type stored in a contagious area in the RAM.
    Each of the values in the array can be accessed with a unique index or by iterating a pointer.
    Since the array is stored in a contagious area in the RAM, the computer assigns a pointer for
    the starting location(address) and other values can be accessed simply by iterating the pointer.

    The special condition of character and pointer is when you define a char pointer, the computer interprets is
    as an array of character values instead of the address of a single character.Since we have "string" type in
    C++ this type of declaration is not used too much however, it is an important feature to know.
     */
    cout << endl << "*Character Array" << endl << endl;
    char *character_array = "Multiple characters";
    cout << "Character array with char * " << character_array << endl;

    cout << endl << "ARRAYS" << endl;
    cout << endl << "*Declaration" << endl << endl;

    /* Declaring an array with a predefined size.
       In the example below, we declared an integer array, that contains 5 integer
     */
    int array[5];
    /*
     Printing array values by accessing the values using index
     Array indexes always start from "0".
     */
    for (int i = 0; i < 5; i++) {
        /* Accessing the value stored in array.
           Since we didn't specify the values for array, it will print 5 random integer
           value from the RAM.
        */
        cout << "The " << i << " element of array is " << array[i] << endl;
    }
    cout << endl << "*Declaration with values" << endl << endl;
    //Initializing array with values on declaration;
    int new_array[5] = {1, 3, 5, 7, 11};
    for (int i = 0; i < 5; i++) {
        /* Accessing the value stored in array.
           Since we didn't specify the values for array, it will print 5 random integer
           value from the RAM.
        */
        cout << "The " << i << " element of the new array is " << new_array[i] << endl;
    }

    //You can also change/assign values after the declaration of array
    cout << endl << "*Changing array values" << endl << endl;
    cout << "The 0 element of the new array is " << new_array[0] << endl;
    new_array[0] = 8;
    cout << "The 0 element of the new array is " << new_array[0] << endl;
    cout << "The 1 element of the new array is " << new_array[1] << endl;
    new_array[1] = new_array[0];
    cout << "The 1 element of the new array is " << new_array[1] << endl;

    cout << endl << "MULTI DIMENSIONAL ARRAYS" << endl;
    /*  Multidimensional arrays are data structures that stores arrays inside other arrays.
       The easiest mathematical definition you can relate is the matrix structure and value access by
       multi indexes such as 'i' and 'j'.
     */
    cout << endl << "*Declaration of 2 dimensional array with values" << endl << endl;

    //[3][2] means array contains a 3 element and each one of them has 2 element.
    int multi_array[3][2] = {
            {1, 2},
            {3, 4},
            {5, 6},
    };
    // Printing a 2 dimensional array requires a loop inside a loop to be able to access the value
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "The value in index [" << i << "][" << j << "] is " << multi_array[i][j] << endl;
        }
    }

    // 2 or more dimensional arrays does not permit the assignment of inner arrays with static declaration such as [5][3]
    // If you want to store(bind) another array you can use pointer type of declaration
    int another_array[] = {1, 2, 3};
    int *another_multi_array[5]; // 5 array could be assigned to this variable
    another_multi_array[0] = another_array;

    // If you want to store 5 of 3-element(or more) arrays, you have to use pointer based declaration.
    int *two_2_multi_array[3];
    for (int i = 0; i < 3; i++) {
        two_2_multi_array[i] = (int *) malloc(5 * sizeof(int));
        //two_2_multi_array[i] = new int[5];
    }

    return 0;
}


