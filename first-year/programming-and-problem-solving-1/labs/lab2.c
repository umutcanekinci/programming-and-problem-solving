#include <stdio.h>


void main_old() {
    int midterm;
    int final;

    printf("Enter the midterm exam score:");
    scanf("%d", &midterm);

    printf("Enter the final exam score:");
    scanf("%d", &final);

    int grade = (midterm + final) / 2;

    printf("Your grade is:%d\n",grade);
    if(grade>=50){
        printf("You pass the course!");
    }
    else{
        printf("You fail the course!");
    }
}

int add(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a-b;
}

int mult(int a, int b){
    return a*b;
}

int div(int a, int b){
    if(b == 0){
        printf("Cannot divide by zero!\n");
        return 0;
    }
    return a/b;
}

void main(){
    int operation;
    int firstNumber;
    int secondNumber;

    printf("1.Add\n2.Sub\n3.Mult\n4.Div\n");
    printf("Select an operation:");
    scanf("%d",&operation);

    printf("Enter the first number:");
    scanf("%d",&firstNumber);

    printf("Enter the second number:");
    scanf("%d",&secondNumber);

    int result = 0;

    if(operation == 1){
        result = add(firstNumber,secondNumber);
    }
    else if(operation == 2){
        result = sub(firstNumber,secondNumber);
    }
    else if(operation == 3){
        result = mult(firstNumber,secondNumber);
    }
    else if(operation == 4){
        result = div(firstNumber,secondNumber);
    }
    else{
        printf("Unknown operation!");
    }

    printf("Result:%d\n",result);
}
