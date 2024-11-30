#include "stdio.h"

float STARTING_BALANCE = 0;

void printOptions() {
    printf("Please enter an integer between 1-4 to select an option:\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
}

int getInt() {

    int input = 0;
    printf("=>");
    scanf_s("%d", &input);

    return input;
}

float getFloat() {

    float input = 0;
    printf("=>");
    scanf_s("%f", &input);

    return input;
}

void checkBalance(float balance) {
    printf("Your current balance is %.2f.\n", balance);
}

void deposit(float *balance) {
    printf("Please enter the amount of money you want to deposit\n");
    float amount = getFloat();
    if(amount <= 0) {
        printf("Please enter a positive number!");
        deposit(balance);
    } else {
        *balance += amount;
    }
}

void withdraw(float *balance) {
    printf("Please enter the amount of money you want to withdraw\n");
    float amount = getFloat();
    if(amount > *balance) {
        printf("You have not enough money!\n");
        checkBalance(*balance);
        withdraw(balance);
    }
    else if(amount <= 0) {
        printf("Please enter a positive number!");
        withdraw(balance);
    } else {
        *balance -= amount;
    }

}

void farewell() {
    printf("Thank you to use our ATM, have a nice day!\n");
}

void showError() {
    printf("Please enter a correct number.\n");
}

void loop() {

    float balance = STARTING_BALANCE;

    for(int operation=0; ; operation != 4) {

        operation = getInt();

        switch (operation) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                deposit(&balance);
                checkBalance(balance);
                break;
            case 3:
                withdraw(&balance);
                checkBalance(balance);
                break;
            case 4:
                farewell();
                break;
            default:
                showError();
                break;
        }
    }

}

int main() {
    printOptions();
    loop();
}