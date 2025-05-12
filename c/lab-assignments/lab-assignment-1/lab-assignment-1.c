#include <stdio.h>

// Don't use arrays
// Don't use something you didn't learned in class.

void printLine() {
    printf("-------------------------------------------------------------------------------------------------------\n");
}

void printIntro() {

    printLine();
    printf("------------------------------ SE 1105 PROGRAMMING AND PROBLEM SOLVING I ------------------------------\n");
    printf("| Week 6 || Lab Assignment 1 || Date: 11/7/2024 || Author: Umutcan Ekinci || Student ID: 23070006011 |\n");
    printLine();
}

/*
 * Task 1: Find Even Numbers
 * Lab Assignment 1
 * Write a C program that lists all numbers up to a given integer n that are even.
 * Instructions:
 * 1. Write a function called listEvenNumbers that takes one positive integer n as argument
 * and lists all even numbers within the range [0, n].
 * 2. In the main function:  Prompt the user to enter a positive integer n.  Call the listEvenNumbers function with the user's input as argument
 */

void listEvenNumbers(int n) {
    printf("The even numbers in range [0, %d] are => ", n);
    for(int i=0; i<=n; i+=2) {
        printf("%d ", i);
    }
    printf("\n");
}

void task1_main(){

    int num;

    printf("Task 1: Find Even Numbers\n");
    printf("Enter a positive integer =>");
    scanf_s("%d", &num);
    listEvenNumbers(num);

}

/*
 * Task 2: Temperature Logger Tracker
 * Create a simple temperature logging program where the user can log temperatures and view the
 * highest and lowest logged values.
 * Instructions:
 * 1. Implement a menu system that allows users to choose from the following options: (1) Log
 * Temperature, (2) View Highest Temperature, (3) View Lowest Temperature, and (4) Exit.
 * 2. Initialize three variables: highestTemp and lowestTemp set to -1 initially, and a currentTemp
 * for logging each new temperature.
 * 3. Use a for loop to repeatedly display the menu and process the user's choice until the user
 * selects "Exit."
 * 4. If the user chooses "Log Temperature" prompt them to enter the temperature as an integer.
 * • If it’s the first temperature being logged, set both highestTemp and lowestTemp to
 * this value.
 * • For subsequent entries, update highestTemp if the new temperature is greater,
 * and lowestTemp if it’s lower.
 * 5. If the user chooses "View Highest Temperature" display highestTemp.
 * 6. If the user chooses "View Lowest Temperature" display lowestTemp.
 * 7. If the user enters an invalid input, ask the user to enter a new input until a valid input is
 * provided.
 * 8. If the user selects "Exit" display a farewell message with the highest and lowest
 * temperatures recorded.
 *
*/

void farewell() {

    printLine();
    printf("Thank you for using Temperature Logger Tracker, have a nice day!\n");
    printLine();
}

void task2_main() {

    int choice = 0;
    int highestTemp = -1;
    int lowestTemp = -1;
    int currentTemp = -1;
    printf("Task 2: Temperature Logger Tracker \n");
    printf("(1) Log Temperature\n(2) View Highest Temperature\n(3) View Lowest Temperature\n(4) Exit\n\n");

    while(choice != 4) {

        printf("Please select an option =>");
        scanf_s("%d", &choice);

        if(choice == 1) {//1) Log Temperature

            printf("Enter the temperature value =>");
            scanf_s("%d", &currentTemp);

            if(highestTemp == -1 && lowestTemp == -1) {
                highestTemp = currentTemp;
                lowestTemp = currentTemp;
            }
            else
            {
                if(currentTemp > highestTemp) {
                    highestTemp = currentTemp;
                }
                if(currentTemp < lowestTemp) {
                    lowestTemp = currentTemp;
                }
            }

        }
        else if(choice == 2) { // 2) View Highest Temperature

            printf("The highest temperature is %d\n", highestTemp);

        }
        else if(choice == 3) { // 3) View Highest Temperature

            printf("The lowest temperature is %d\n", lowestTemp);

        }
        else if(choice == 4) { // 4) Exit

            printf("The highest temperature is %d\n", highestTemp);
            printf("The lowest temperature is %d\n", lowestTemp);
            farewell();
        }
        else
        {
            printf("You haven't entered a valid option number!\n");
        }

    }

}

int main(){

    printIntro();

    task1_main();
    printLine();
    task2_main();

    return 0;

}