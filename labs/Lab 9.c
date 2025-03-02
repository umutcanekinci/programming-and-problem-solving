#include <stdio.h>
#include "stdbool.h"

void encode(char str[], int key){
    for(int i = 0 ; str[i] != '\0' ; i++){
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) {
            str[i] += key;
        }
    }
}

void decode(char str[], int key){
    for(int i = 0 ; str[i] != '\0' ; i++){
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) {
            str[i] -= key;
        }
    }
}

int countConstanants(char str[], char vowels[]){
    int count = 0;
    bool isVowel = false;
    for(int i = 0 ; str[i] != '\0' ; i++){
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) {
            isVowel = false;
            for (int j = 0; vowels[j] != '\0'; j++) {
                if (str[i] == vowels[j]) {
                    isVowel = true;
                }
            }

            if (!isVowel) {
                count++;
            }
        }
    }
    return count;
}

int longestWord(char str[]){
    int maxLength = 0;
    int curLength = 0;

    for(int i = 0 ; str[i] != '\0' ; i++){
        if(str[i] != ' '){
            curLength++;
        }
        else{
            if(maxLength<curLength){
                maxLength = curLength;
            }
            curLength = 0;
        }
    }
    if(maxLength<curLength){
        maxLength = curLength;
    }
    return maxLength;
}

void main(){
    char str[] = "Hello World!";
//    int key = 3;
//    printf("%s\n",str);
//    encode(str,key);
//    printf("%s\n",str);
//    decode(str,key);
//    printf("%s\n",str);
    char vowels[] = "aeiouAEIOU";
//    printf("Constanant Count:%d\n", countConstanants(str,vowels));
    char str2[] = "Good luck to everybody on their finals!";
    printf("Longest Word:%d\n", longestWord(str2));
}
