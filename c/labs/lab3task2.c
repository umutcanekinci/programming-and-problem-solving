#include "standard.c"

int takePositiveInt() {
    printf("Enter a positive number");
    int value = getInt();
    if(value<=0) {
        printf("Please enter a positive number!\n");
        return takePozitiveInt();
    }
    return value;
}

void collatzSequence(int N) {

    if(N==1) {
        printf("1");
        return;
    }

    printf("%d -> ", N);

    if (N % 2) {
        return collatzSequence(3 * N + 1);
    }
    return collatzSequence(N / 2);

}

int main() {
    collatzSequence(takePozitiveInt());
    return 0;
}