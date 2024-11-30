#include "stdio.h"

void calculateEvenOddSum(int A, int B) {

    int evenSum = 0;
    int oddSum = 0;

    for(int i = A; i <= B; i++) {
        if (i % 2 == 0) {
            evenSum += i;
        }
        else {
            oddSum += i;
        }
    }

    printf("The sum of even numbers in range [%d, %d] is %d\n", A, B, evenSum);
    printf("The sum of odd numbers in range [%d, %d] is %d\n", A, B, oddSum);

}

int main() {

    int A, B;

    printf("To calculate the sum of even numbers and sum of odd numbers in range [A, B]\n");
    printf("Please enter number A =>");
    scanf_s("%d", &A);
    printf("Pleas enter number B =>");
    scanf_s("%d", &B);

    calculateEvenOddSum(A, B);

    return 0;
}