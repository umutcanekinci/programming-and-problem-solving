#include <stdio.h>

int getNumber() {
    int temp; printf("Input: ");
    scanf("%d", &temp); printf("Output: ");
    return temp;        
}
int hours(int secs) {
    return secs/3600;
}
int mins(int secs) {
        return (secs-hours(secs)*3600) / 60;
    }
int secs(int secs) {
    return secs-hours(secs)*3600-mins(secs)*60;
}
void q2a() {
    int num = getNumber(); // I should have gotten number with parameter instead of scanf so I have lost 2 points in this question.
    if(num <= 0) { printf("0"); return; }
    int h = hours(num); if(h) { printf("%dh ", h); }
    int m = mins(num); if(m) { printf("%dm ", m); }
    int s = secs(num); if(s) { printf("%ds ", s); }
}

int recieveNumber(int n) {
    int temp; printf("Enter %dth number: ", n);
    scanf_s("%d", &temp);
    return temp;
}
void q3a() {
    int min = recieveNumber(1), max = recieveNumber(2);
    printf("Perfect squares between %d and %d are:", min, max);
    for (int i=0; i*i<max; i++) {
        if(i*i>min) {
            printf(" %d", i*i);
        }
    }
}

int maxIndex(int temps[], int size) {
    int max = temps[0]; int maxIn = 0;
    for(int i=0; i<size; i++) {
        if(temps[i] > max){
            max = temps[i]; maxIn = i;
        }
    }
    return maxIn;
}
int q4a(int arr[], int length) {

    int maxIn = maxIndex(arr, length);
    int maxChange = 0;
    for(int i=maxIn; i<length-1; i++) {
        int change = arr[i] - arr[i+1]; change = (change > 0) ? change : -change;
        if(change > maxChange) { maxChange = change; }
    }
    return maxChange;

}


int main() {

    q2a();
    q3a();

    int arr[] = { 12, 11, 12, 13, 13, 14, 10, 15 };
    printf("%d", q4a(arr, 8));

    return 0;

}