#include <stdio.h>
#include <stdlib.h>

#define ROW 0
#define COLUMN 0
#define ROW_COUNT 5
#define COLUMN_COUNT 5

#define FAREWELL_MESSAGE "GOODBYE!"

typedef enum {AVAILABLE = 0, BOOKED = 1} SeatStatus;
typedef int Position[2];
SeatStatus theater[ROW_COUNT][COLUMN_COUNT];

int getInputBelow(int max) {

    int input;
    
    do {
        scanf_s("%d", &input);

        if(input >= max)
            printf("Please enter a number below %d\n", max);

    } while (input >= max);

    return input;
}

void getPosition(Position position) {
    
    printf("Enter the row number:\n");
    position[ROW] = getInputBelow(ROW_COUNT);
    printf("Enter the column number:\n");
    position[COLUMN] = getInputBelow(COLUMN_COUNT);

}

int isAvailable(Position position) {

    return theater[position[ROW]][position[COLUMN]] == AVAILABLE;

}

void display() {
    for(int row = 0; row < ROW_COUNT; row++) {
        for(int column = 0; column < COLUMN_COUNT; column++) {
            printf("%d", theater[row][column]);
            printf(" ");
        }
        printf("\n");
    }
}

void book() {
    
    Position position;
    do {
        getPosition(position);

        if(isAvailable(position)) {
            printf("You have booked a seat at row %d column %d\n", position[ROW], position[COLUMN]);
            theater[position[ROW]][position[COLUMN]] = BOOKED;
        }
        else {
            printf("The seat at row %d column %d is not available!\n Please select another seat.\n", position[ROW], position[COLUMN]);
        }
        
    } while(isAvailable(position));

}

void cancel() {

    Position position;
    do {
        getPosition(position);

        if(!isAvailable(position)) {
            printf("The seat at row %d column %d is cancelled succesfuly!\n", position[ROW], position[COLUMN]);
            theater[position[ROW]][position[COLUMN]] = AVAILABLE;
        }
        else {
            printf("The seat at row %d column %d is empty. Please select another seat.\n", position[ROW], position[COLUMN]);
        }
        
    } while(!isAvailable(position));

}

void check() {

    int availbaleSeatCount = 0;
    for(int row = 0; row < ROW_COUNT; row++) {
        for(int column = 0; column < COLUMN_COUNT; column++) {
            if(theater[row][column] == AVAILABLE) {
                availbaleSeatCount += 1;
            }
        }
    }
    int bookedSeatCount = ROW_COUNT * COLUMN_COUNT - availbaleSeatCount;
    printf("There are %d available and %d booked seat(s) in theater.", availbaleSeatCount, bookedSeatCount);

}

void farewell() {
    printf(FAREWELL_MESSAGE);
}

void close() {
    farewell();
    exit(EXIT_SUCCESS);
}

void menu() {

    int choice = 0;
    do {

        printf("1) Display the seating\n");
        printf("2) Book a seat\n");
        printf("3) Cancel a booking\n");
        printf("4) Check availability\n");
        printf("5) Exit\n");

        scanf_s("%d", &choice);

        switch (choice)
        {
            case 1:
                display();
                break;

            case 2:
                book();
                break;

            case 3:
                cancel();
                break;

            case 4:
                check();
                break;

            case 5:
                close();
                break;

            default:
                printf("Please enter a valid option!\n");
                break;
        }

    } while(choice != 5);

}

int main() {

    menu();

    return 0;
}