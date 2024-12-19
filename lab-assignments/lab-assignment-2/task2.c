int abs(int num) {
    return num > 0 ? num : -num;
}

int min(int arr[], int size) {
    int min = arr[0];
    for(int i=1; i<size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int max(int arr[], int size) {
    int max = arr[0];
    for(int i=1; i<size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int sumOfMinAndMax(int arr1[], int arr2[], int size1, int size2) {
    
    return abs(min(arr1, size1) + max(arr2, size2));
    
}

/*

void test() {
    int arr1[] = {-1, 2, 3, 14};
    int arr2[] = {-2, -4, -5};
    printf("Result: %d", sumOfMinAndMax(arr1, arr2, 4, 3));
}

int main() {

    test();
    return 0;
}

*/