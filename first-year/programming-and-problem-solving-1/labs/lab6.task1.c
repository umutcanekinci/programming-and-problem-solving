#include <stdio.h>
#include <time.h>

int getRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int getScore(int num, int score, int isDoubled) {

    if(isDoubled) {
        score += num*2;
        printf("Rolling a double roll...\n");
        printf("You rolled: %d, doubled to %d (Current score: %d)\n", num, num*2, score);
    } else{
        score += num;
        printf("You rolled: %d (Current score: %d)\n", num, score);
    }
    
    return num == 6 ? score : getScore(getRandomInt(1, 6), score, num==3);
           
}

void diceGame() {
    srand(clock()); // or time(0)
    int sum = getScore(getRandomInt(1, 6), 0, 0);
    printf("Game over. Your final score: %d", sum);
}

void diceGame2() {

    srand(clock());
    int sum = 0;
    int num = 0;

    do {
        if(num == 3)
            sum += num*2;
        else
            sum += num;
        
        num = getRandomInt(1, 6);
        printf("You have rolled %d\n", num);

    } while(num != 6);
    sum += num;
    printf("The sum is %d", sum);
    
}

int main() {

    diceGame();
    return 0;

}