#include <stdio.h>

#pragma region Question 1



// 4574fladkmfsşf-134tvfkdsl*&
// Function should return sum of the alphabetic characters and numbers in the string
int sumOfAlphabeticAndNumbers(char str[]) {
    int sumAlphabeticAndNumbers = 0;
    int sumNumbers = 0;

    for (int i = 0; str[i] != 0; i++)
    {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            sumAlphabeticAndNumbers += str[i];
            continue;
        }
        if(str[i] >= '0' && str[i] <= '9'){
            sumNumbers += str[i] - '0';
        }
    }
    return sum;
}

int main() {

    

    return 0;
}

#pragma endregion