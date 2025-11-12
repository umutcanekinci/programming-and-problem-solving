#include <iostream>

using namespace std;

/* Functions can be used to get rid of repetitive code and makes your code more modular
   by increasing the usability of some task you have to perform.
   Functions may have "parameters" (value(s)) to perform some tasks on/with them
   and return a value such as int,char,float etc.

   If you desire a function which does not return something such as "cout" you can use "void" type
 */

/* int a and int b are "parameters"
 As you can see the general structure of the "summation" function is very similar to our "main" function.
 The only difference is main function does not use any parameter.(not necessarily)
*/

void function() {
    cout << "I do not return a value" << endl;
}

int increase_by_five(int number) {
    return number + 5;
}

int summation(int number_1, int number_2) {
    return number_1 + number_2;
}

/*
 Any function you define ABOVE the "main" can be used inside in the main function.However, the majority of the
 people prefer to keep main function on the top as much as possible to not scrolling all the way down in the file.
 If you want to define a function BELOW the "main", you have to type the "skeleton function" ABOVE it.
 Skeleton function is just the definition of function with parameters.
 */

int summation_function_below(int number_1, int number_2);

void increase_by_2(int number) {
    number = number + 2;
    cout << "Number value inside increase_by_2 function " << number << endl;
}

void recursive_countdown(int number);

void increase_by_3(int &number);

int main() {
    cout << endl << "FUNCTIONS" << endl;
    //Since the "function" does not return something we didn't assign the "result".
    function();
    int result = increase_by_five(7);
    cout << "Result of 7 with increase_by_five function " << result << endl;
    // The result(returned value) of summation function is assigned to "result" variable.
    result = summation(5, 7);
    cout << "Result of summation function with 5 and 7 variable " << result << endl;
    cout << "Result of summation function below with 5 and 7 " << summation_function_below(5, 7) << endl;

    /* When you pass variables without their reference operator (&), the changes you performed on function
      is not permanent. (This functionality may differ from language the language and generally referred as
      "pass by value" and "pass by reference")
     */
    cout << endl << "*Pass by Value" << endl;
    int number = 5;
    cout << "Number value in main is " << number << endl;
    increase_by_2(number);
    cout << "Number value after increase_by_2 function is " << number << endl;
    /*
     You may think that this is an expected behaviour since we didn't return something from increase_by_2 function.
     However, we can achieve permanent change without assigning the result (returned value of function) to our variable
     again.
     */
    cout << endl << "*Pass by Reference" << endl;
    number = 10;
    cout << "Number value in main is " << number << endl;
    increase_by_3(number);
    cout << "Number value after increase_by_3 function is " << number << endl;

    /* Recursive functions call themselves in the same function.
     If the function does not call itself, it is referred to as "iterative function".
     Most of the time functions are written iteratively, so generally,
     recursive functions will be referred to as "recursive" and others will simply be referred to as just "function".
     */

    cout << endl << "RECURSIVE FUNCTIONS" << endl;
    recursive_countdown(5);
    /*
     !!! DANGER !!! The code in line 93 will force your CPU to do some real work. (Mac Users, behold!)
     If you are using DevC++, close the black screen or press cancel when windows give crash warning.
     If you are using CLion, PRESS THE RED SQUARE BUTTON on the left side of the output area.
     If you still could not manage to stop the execution, throw your pc/laptop out of the window, the gravity will handle the rest.
     */
    //recursive_countdown(-1);
    return 0;
}


int summation_function_below(int number_1, int number_2) {
    return number_1 + number_2;
}

// Now you use the "address" of the "number" instead of its value so the changes will be permanent.
void increase_by_3(int &number) {
    number = number + 3;
};

/*
    While writing a recursive function, you have to write a "terminating" functionality to be able to
    prevent infinite recursion.
    In the function below, the recursion executed as;
    1 - Check if the number satisfies the terminating condition
    2 - If it does, print the "Number is 0.No ...." Go to the Final step
    3 - If it does not, print the number. Go to Step 4
    4 - Call the recursive_countdown with the number-1 value. Go to Step 1
    Final Step - Exit the function
    ...
    So what happens if you call the initial function with -1 ?
 */
void recursive_countdown(int number) {
    if (number == 0) {
        cout << "Number is 0.No more recursive call" << endl;
    } else {
        cout << number << endl;
        recursive_countdown(number - 1);
    }
}
