//
// Created by dindar.oz on 12/4/2024.
//

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <process.h>
#include <time.h>
#include "numberutils.h"

#define DIGITCOUNT  4




#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define C_EXIT      1000
#define C_GIVEUP    2000
#define C_HELP      3000


// Global variable
int guessCount =0;

bool roundIsOver;

int secretNumber;


void displayIntro()
{
    system("cls");
    printf(ANSI_COLOR_YELLOW);
    printf(".___  ___.      ___           _______.___________. _______ .______         \n"
           "|   \\/   |     /   \\         /       |           ||   ____||   _  \\        \n"
           "|  \\  /  |    /  ^  \\       |   (----`---|  |----`|  |__   |  |_)  |       \n"
           "|  |\\/|  |   /  /_\\  \\       \\   \\       |  |     |   __|  |      /        \n"
           "|  |  |  |  /  _____  \\  .----)   |      |  |     |  |____ |  |\\  \\----.   \n"
           "|__|  |__| /__/     \\__\\ |_______/       |__|     |_______|| _| `._____|   \n"
           "                                                                           \n"
           "               .___  ___.  __  .__   __.  _______                          \n"
           "               |   \\/   | |  | |  \\ |  | |       \\                         \n"
           "               |  \\  /  | |  | |   \\|  | |  .--.  |                        \n"
           "               |  |\\/|  | |  | |  . `  | |  |  |  |                        \n"
           "               |  |  |  | |  | |  |\\   | |  '--'  |                        \n"
           "               |__|  |__| |__| |__| \\__| |_______/                         \n"
           "                                                                           ");

    getch();
    printf(ANSI_COLOR_RESET);
    system("cls");
}


void pickASecretNumber()
{
    secretNumber = randomValidNumber(DIGITCOUNT);
}

void initRound(int round)
{
    pickASecretNumber();

    printf(ANSI_COLOR_CYAN);
    printf("Round-%d started\n", round);
    printf(ANSI_COLOR_RESET);

    guessCount =0;
    roundIsOver = false;



}

bool isRoundOver()
{
    return roundIsOver;
}

int readUserGuess()
{
    int guess;
    printf("Make a valid guess:\n");
    scanf_s("%d", &guess);
    return guess;
}

bool isSpecialCommand(int guess)
{
    return guess== C_EXIT || guess==C_GIVEUP || guess== C_HELP;
}

void giveUp()
{

}

void displayMenu()
{
    printf("Instructions\n");
    printf("-----------------------------\n");
    printf("%d     Exit\n",         C_EXIT);
    printf("%d     GiveUp\n\n",     C_GIVEUP);
    printf("%d     Help\n\n",       C_HELP);
}

void processCommand(int cmd)
{
    if (cmd== C_EXIT) {
        printf("WHYYYY :-(((\n");
        printf("We havent cut the watermelon yet.\n");
        exit(0);
    }
    else if (cmd== C_GIVEUP)
    {
        giveUp();
        roundIsOver = true;
    }
    else if (cmd == C_HELP)
    {
        displayMenu();
    }
}

bool isValid(int guess)
{
    int dc = log10(guess)+1;

    return dc == DIGITCOUNT && !hasDuplicateDigits(guess);
}

void congratulate()
{
    printf(ANSI_COLOR_RED);
    printf("CONGRATULATIONS!!\n");
    printf("You have found my number in %d guess\n",guessCount);
    printf(ANSI_COLOR_RESET);
}

void giveAnswer(int guess)
{
    int digitsSecret[DIGITCOUNT];
    int digitsGuess[DIGITCOUNT];

    digitsOf(secretNumber,digitsSecret);
    digitsOf(guess,digitsGuess);

    int plus = plusComparison(digitsSecret,digitsGuess,DIGITCOUNT);
    int minus = minusComparison(digitsSecret,digitsGuess,DIGITCOUNT);

    printf("%d +%d-%d\n", guess,plus,minus);

    if (plus == DIGITCOUNT)
        congratulate();

}

void playOneTurn()
{
    int guess = readUserGuess();

    if (isSpecialCommand(guess))
        processCommand(guess);
    else
    {
        if (isValid(guess))
        {
            guessCount++;
            giveAnswer(guess);

        }
    }

}

void endRound()
{

}

void playOneRound(int round)
{
    initRound(round);

    while (!isRoundOver())
    {
        playOneTurn();
    }

    endRound();

}





void initGame(int roundCount)
{
    srand(time(0));
    displayIntro();
    displayMenu();


    printf(ANSI_COLOR_MAGENTA);
    printf("%d-round MasterMind game started.\n\n");
    printf(ANSI_COLOR_RESET);
}

void playMasterMind(int rounds)
{
    initGame(rounds);


    for (int r = 0; r < rounds; ++r) {
        playOneRound(r+1);
    }

}

int main()
{
    playMasterMind(10);
    return 0;
}