#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
void runGame() {


    srand(time(0));
    int roll = 0, lastRoll = 0;
    double score = 0;

    do {
        
        printf("Rolling a dice..\n");
        roll = rollTheDice();
        printf("You have rolled %d.", roll);

        if (roll == 5) {
            if(lastRoll == 5) {
                printf(" Your have rolled double 5 you have lost.");
                score = 0;
            } else {
                printf(" Your score is halfed.");
                score /= 2;
            }
        } else {
            score += roll;
        }
        if(roll == 6) {
            printf("\nCongrats you have rolled a 6 and you won with score %.1lf", score);
        }
        else{
            printf(" Your new score: %.1lf\n", score);
        }

        lastRoll = roll;
    }
    while(roll != 6);
        


}

*/

int randomBetween(int min, int max) {
    
    return rand() % max + min;

}

int rollTheDice() {

    return randomBetween(1, 6);

}

double diceLoop(int lastRoll, double score) {
    
    printf("Rolling a dice..\n");
    int roll = rollTheDice();
    printf("You have rolled %d.", roll);

    if(lastRoll == 5 && roll == 5)
        return 0;

    if(lastRoll != 5 && roll == 5) {
        score /= 2;
        printf(" Your score is getting halfed..");
    }
    else 
        score += roll;
    
    printf(" Your new score is %.1lf.\n", score);

    if(roll == 6) 
        return score;

    return diceLoop(roll, score);
}

int runGame() {

    srand(time(0));
    double score = diceLoop(5, 0);

    if(score == 0)
        printf("\nYou have lost with score %.1lf.", score);
    else
        printf("You have won with score %.1lf!", score);

}

int main (void)
{

    runGame();
    return 0;
}