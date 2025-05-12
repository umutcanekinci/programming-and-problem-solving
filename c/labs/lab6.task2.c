#include <stdio.h>
//failed
void assign(int resultArr[], int arr[], int left, int right) {

    resultArr[left] = arr[left];
    if(left<right-1) {
        assign(resultArr, arr, left+1, right);
    }
}

void printArray(int arr[], int i, int size) {

    if(i==0)
        printf("{");
    printf(" %d", arr[i]);

    if(i!=size-1)
        printf(",");
        printArray(arr, i+1, size);

    if(i==size-1){
        printf(" }");
    }
}

int main() {

    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 7, 1, 1};
    int result[7];
    assign(result, arr1, 0, 2);
    assign(result, arr2, 3, 7);
    printArray(result, 0, 7);
    return 0;
}