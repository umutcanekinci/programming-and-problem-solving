//
// Created by dindar.oz on 12/11/2024.
//

#ifndef WEEK10_UTILS_H
#define WEEK10_UTILS_H


#include <stdlib.h>
#include <time.h>
#include <synchapi.h>

void randomize()
{
    srand(time(NULL));
}

int randomBelow(int n)
{
    return rand() % n;
}



void waitForSomeTime()
{
    Sleep(1000);
}


void clearScreen()
{
    system("CLS");
}









#endif //WEEK10_UTILS_H