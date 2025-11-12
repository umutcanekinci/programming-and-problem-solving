// This is a comment line, use "//" to comment out a single line
/*
  If you want to comment out multiple lines,
  You can use "/*" and "*./" (delete the ".")
*/

/* include comment, add necessary functionality for you to use in your code
   "iostream" includes standard input&output functions such as "cout,cin"*/
#include <iostream>

// C++ Version 11
#define PI = 3.14  // Variables defined in this way are immutable (can not be changed)
float global_pi = 3.14; // This is a global variable you can use anywhere after this line in this file.
/* using namespace prevent name confusion for compiler to use variables and functions etc. */
using namespace std;

/*
namespace example{
   void function cout(){
       // When you want to use std's cout function in this code, you have to
       //use it as std::cout...
   }
}
 */

// "main" is the function you will write code inside it

/*  For the rest of this semester you will code everything in the
    form of

    int main(){
    	...
		//your code
    	...
    	return 0;
	}
 	unless it is said otherwise.
*/

int main() {

    /*"cout" function prints out the variables to terminal/console (black screen)
	 Anything you write between double quotes ("...") considered as String
	 and can be directly used with cout without any format option*/
    cout << "Hello World";
    // "endl" is used to start to print out from new line
    cout << endl;
    // You can also use multiple of them.
    cout << "4 lines will be skipped after this sentence";
    cout << endl << endl << endl << endl;
    cout << "Next Line" << endl;

    /* There are a set of rules you have to follow while coding,
       1 - Use ";" at the end of the line after declaration or function use
       2 - YOU CAN NOT use special words as a variable name, for example
       int new = 5; int int = 8; are not valid
       you will learn more throughout the semester. */

    /* "int" is an abbreviation of "integer",
	   you can only assign integer values to "int" variable
	*/
    /*
      Since the "number" defined in main function, you can not use this variable
      out of this scope (main function) as it is.(for now)
     */
    int number = 1;
    // You can also assign values to variables after their declaration
    int new_number;
    new_number = 2;
    cout << "Printing new number " << new_number << endl;

    /* You can print out the multiple variables*/
    cout << "Printing number " << number << endl;
    cout << "Printing number multiple times " << number << number << number << endl;

    /*   As said before, you can only assign integer values to "int" variable
         If you try to do something like "int number = 2.78;" ,
         it will be automatically cast to an integer (2)
    */
    number = 2;
    cout << "Number assigned to 2" << endl;
    cout << "Number = " << number << endl;

    number = 2.78;
    cout << "Number assigned to 2.78" << endl;
    cout << "Number = " << number << endl;

    // Mathematical Operations on Integers		

    int number_1 = 6;
    int number_2 = 3;
    int result = number_1 + number_2;
    cout << "Number_1 + Number_2 = " << result << endl;
    result = number_1 - number_2;
    cout << "Number_1 - Number_2 = " << result << endl;
    result = number_1 * number_2;
    cout << "Number_1 * Number_2 = " << result << endl;
    result = number_1 / number_2;
    cout << "Number_1 / Number_2 = " << result << endl;
    result = number_1 % number_2;
    /* Do not use "%" symbol to represent "mod" in string,
       compiler will try to interpret it as a "string format option"
       in some cases,instead of a regular symbol
    */
    printf("b % a %d \n", result); //C version example to demonstrate the case
    cout << "b % a = " << result << endl;
    cout << "number_1 % number_2 = " << result << endl;
    cout << "number_1 mod number_2 = " << result << endl;

    /* Operator Precedence
     You can get the entire list from https://doc.bccnsoft.com/docs/cppreference_en/operator_precedence.html
     For simplicity I'm going to sum it up as
     1 - ()
     2 - ! (logical not)
     3 - *,/,% has same precedence, so calculation will be from to right
     4 - +,-
     5 = ==
     6 - &&
     7 - ||
     If it seems too complicated, an easy solution is always using "()" for the operation you
     want to perform. As an example, "a" multiplied by "b+1" then divided to "c" can be written as
     1 - (b+1)
     2 - (a*(b+1))
     3 - (a*(b+1))/c
     and even
     result = ((a*(b+1))/c);
    */

    // Pre- / Post-Number increase
    int current_value;
    number = 10;
    cout << "Number assigned to 10" << endl;
    cout << "Number = " << number << endl;
    cout << "Pre increasing number current_value = ++number" << endl;
    current_value = ++number;
    cout << "Current value = " << current_value << " Number = " << number << endl;
    number = 10;
    cout << "Number assigned to 10" << endl;
    cout << "Post increasing number current_value = number++" << endl;
    current_value = number++;
    cout << "Current value = " << current_value << " Number = " << number << endl;

    /* Logical Operations !(Not) , &&(And) , ||(Or) can be used to write
      conditional branches (if,else if,else etc.) to change the behaviour of
      execution of the code*/

    /* Example 1 Demonstration of Basic If Else
       A child wants to buy a ticket for an "R" rated movie. The general rule for R
       the rated movie is "Restricted, Children Under 17 Require Accompanying Parent or Adult Guardian"
       To be able to decide if the child can buy a ticket or not, you have to check
       both the age of the child and the existence of an accompanied parent
     */
    // Example values to test out the code
    int age = 15;
    bool parent_exist = false;
    bool can_buy_ticket = false;
    if (age > 17) {
        can_buy_ticket = true;
    } else {
        if (parent_exist) {
            can_buy_ticket = true;
        } else {
            can_buy_ticket = false;
        }
    }

    /* Example 2 Conditional Branch with Logical Operations
        In addition to conditions in Example1, you have to check if
        the customer has enough money to buy a ticket and the number of available seats.
     */
    int ticket_price = 25;
    int child_age = 15;
    int money = 20;
    bool child_parent_exist = false;
    int available_seats = 5;

    //Even if one of these conditions is true, the other values are irrelevant so, we check them first
    //In other words, there is no meaning to check if the customer is adult if there is no seat or enough money for a ticket
    if ((available_seats < 1) || (money < ticket_price)) {
        can_buy_ticket = false;
    } else {
        if (child_age > 17) {
            can_buy_ticket = true;
        } else if ((child_age < 17) && child_parent_exist) {
            can_buy_ticket = true;
        } else {
            can_buy_ticket = false;
        }
    }

    /* I/O (Input/Output) Commands
      cout(character output) used to print out various types of variables to the console/terminal screen.
      cin(character in) used to store user input values to various variables.
      The variable type you provide to "cin" and user input must be compatible otherwise program will terminate.
     */

    int user_input;// change with string user_input to fix it;
    //string user_input;
    cout << "Next operation will terminate program.Please fix it after testing" << endl;
    cout << "Enter 'abc' as input and press enter";
    cin >> user_input;
    cout << "Cin stored value = " << user_input << endl;
    cout << "The second cin operation will be skipped if you don't fix the first operation" << endl;
    cout << "Enter something else as input and press enter";
    //Even if you enter 435, if it stored as string instead of integer
    cin >> user_input;
    cout<<endl;
    cout << "Cin stored value = " << user_input << endl;
    /* Convert "integer string" to actual integer
    //#include <sstream> directly under the #include<iostream> to be able to run this part of the code.
     int integer_number;
     stringstream(user_input)>>integer_number;
     cout<<"Integer value = "<<integer_number<<endl;
     */

    return 0;
}

