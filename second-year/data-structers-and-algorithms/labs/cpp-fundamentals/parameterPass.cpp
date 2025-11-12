#include <iostream>
#include <vector>

using namespace std;

void passByValue(int number);

void passByReference(int &number);

void passByPointer(int *number);

void passArray(int array[]);

void passArrayWithFixedSize(int array[5]);

void passArrayWithLength(int array[], int length);

void pass2DArrayWithFixedSize(int **array, int rowLength, int columnLength);

void passVector(vector<int> numbers);

void passVectorByReference(vector<int> &numbers);

void addValueToVector(vector<int> &numbers, int index, int value) {
    numbers.insert(numbers.begin() + index, value);
}

int main() {
    //https://www.cplusplus.com/reference/vector/vector/vector/
    int number = 5;
    cout << "Value of number  : " << number << endl;
    passByValue(number);
    cout << "Value of number after Pass by value : " << number << endl;
    passByReference(number);
    cout << "Value of number after Pass by reference : " << number << endl;
    passByPointer(&number);
    cout << "Value of number after Pass by pointer : " << number << endl;
    /*
     * More information in https://www.cplusplus.com/articles/z6vU7k9E/
     * Navigate to the "So, to summarize:" part at the end of the page for
     * too long don't read (TLDR) part.
     */
    int array[] = {1, 2, 3, 4, 5};

    cout << "1 dimensional array with the values {1,2,3,4,5}" << endl;
    passArray(array);
    cout << "The value of the first element after passing to function : " << array[0] << endl;
    cout << "Array sizes" << endl;
    cout << "Size of array : " << (sizeof(array) / sizeof(array[0])) << endl;
    passArrayWithFixedSize(array);
    passArrayWithLength(array, 5);
    int **array2D = new int *[3];
    for (int i = 0; i < 3; i++) {
        array2D[i] = new int[2];
    }
//    int array2D[3][2] = {
//            {1, 2},
//            {3, 4},
//            {5, 6},
//    };
    //int array2D[3][2];
    pass2DArrayWithFixedSize(array2D, 3, 2);
    vector<int> numbers(5, 5);
    cout << "A vector with the values {5,5,5,5,5}" << endl;
    passVector(numbers);
    cout << "2nd vector value after passing to a function : " << numbers[2] << endl;
    passVectorByReference(numbers);
    cout << "2nd vector value after passing to a function by reference : " << numbers[2] << endl;
}

void passByValue(int number) {
    number = number + 1;
}

void passByReference(int &number) {
    number = number + 1;
}

void passByPointer(int *number) {
    *number = *number + 1;
}

void passArray(int array[]) {
    array[0] = 5;
}

void passArrayWithFixedSize(int array[5]) {
    cout << "Size of array : " << 5 << endl;
}

void passArrayWithLength(int *array, int length) {
    cout << "Size of array : " << length << endl;
    //array[0] = 5;
}

void pass2DArrayWithFixedSize(int **array, int rowLength, int columnLength) {
    cout << "Size of row and columns : " << rowLength << "," << columnLength << endl;
}

void passVector(vector<int> numbers) {
    numbers[2] = 9;
}

void passVectorByReference(vector<int> &numbers) {
    numbers[2] = 9;
}


