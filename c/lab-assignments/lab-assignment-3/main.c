#include <stdio.h>

#define SUBJECT_COUNT 4
#define STUDENT_COUNT 6
#define DEFAULT_GRADE F

typedef enum {A, B, C, D, F} LetterGrade;
char gradeLetters[] = "ABCDF";

void setGrades(LetterGrade grades[STUDENT_COUNT][SUBJECT_COUNT], LetterGrade grade) {

    for(int i=0; i<STUDENT_COUNT; i++) {
        for(int j=0; j<SUBJECT_COUNT; j++) {
            grades[i][j] = grade;
        }
    }

}

void displayGrades(LetterGrade grades[STUDENT_COUNT][SUBJECT_COUNT]) {

    for(int i=0; i<STUDENT_COUNT; i++) {
        printf("Student %d -> ", i+1);
        for(int j=0; j<SUBJECT_COUNT; j++) {
            printf("%c ", gradeLetters[grades[i][j]]);
        }
        printf("\n");
    }

}

void printIntro() {

    printf("======================= LAB ASSIGNMENT 3 =======================\n");

}

void printOptions() {
    
    printf("1) Display Grades\n");
    printf("2) Change Letter Grade\n");
    printf("3) Count Failures\n");
    printf("4) Exit\n\n");

}

void printFarewell() {

    printf("Thank you for using our application, have a nice day!");

}

int isBetween(int num, int min, int max) {

    return num >= min && num <= max;

}

int getIntegerBetween(int min, int max) {

    int num;
    do{
        printf("\n=>");
        scanf_s("%d", &num);

        if(!isBetween(num, min, max)) {
            printf("Please enter a number between %d and %d!", min, max);
        }

    }while(!isBetween(num, min, max));

    return num;

}

void changeLetterGrade(LetterGrade grades[STUDENT_COUNT][SUBJECT_COUNT]) {

    printf("Enter student number between 1 and %d", STUDENT_COUNT);
    int studentIndex = getIntegerBetween(1, STUDENT_COUNT) - 1;
    printf("Enter subject number 1 and %d", SUBJECT_COUNT);
    int subjectIndex = getIntegerBetween(1, SUBJECT_COUNT) - 1;
    printf("Enter new grade [1=A, 2=B, 3=C, 4=D, 5=F]");
    int grade = getIntegerBetween(1, 5) - 1;

    grades[studentIndex][subjectIndex] = grade;
}

void countFailures(LetterGrade grades[STUDENT_COUNT][SUBJECT_COUNT]) {

    int count = 0;
    for(int i=0; i<STUDENT_COUNT; i++) {

        for (int j=0; j<SUBJECT_COUNT; j++)
        {
            if(grades[i][j] == F) {
                count += 1;
            }
        }
    }
    printf("There are %d failures with grade F.\n", count);

}

void loop(LetterGrade grades[STUDENT_COUNT][SUBJECT_COUNT]) {

    printf("Please choose an option");
    int choice = getIntegerBetween(1, 4);

    switch (choice)
    {
    case 1:
        displayGrades(grades);
        break;
    
    case 2:
        
        changeLetterGrade(grades);
        break;

    case 3:
        
        countFailures(grades);
        break;

    case 4:
        
        printFarewell();
        return;

    }

    loop(grades);


}

int main() {

    LetterGrade grades[STUDENT_COUNT][SUBJECT_COUNT];
    setGrades(grades, DEFAULT_GRADE);
    
    printIntro();
    printOptions();
    loop(grades);

    return 0;

}