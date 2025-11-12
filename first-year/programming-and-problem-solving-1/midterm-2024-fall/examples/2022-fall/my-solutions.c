#include <stdio.h>

int abs(int n) {
    if (n > 0)
        return n;
    return -n;
}

int q2(int n) {
    return abs(abs(2*n-7)-abs(3*n-5));
}

double sumOfNeighbour(double array[], int size, int index) {
    double left = (index > 1) ? array[index-1] : 0;
    double right = (index < size-1) ? array[index+1] : 0;
    return left + right;
}

double q3(double array[], int size) {
    double result = array[0];
    double maxValue = sumOfNeighbour(array, size, 0);

    for(int i = 1; i<size; i++) {
        if(sumOfNeighbour(array, size, i) > maxValue) {
            maxValue = sumOfNeighbour(array, size, i);
            result = array[i];
        }
    }
    return result;
}

int jump(int m, int n, int total) {

    if(total >= 1000) {
        return 0;
    }

    printf("%d\n", m);

    if (m > 50) {
        return jump(0, n, total+m);
    }
    return jump(m+n, n, total+m);

}

void q4(int m, int n) {
    jump(m, n, 0);
}

void q4Old(int m, int n) {

    int totalJump = 0;
    int todayJump = m;

    for(;totalJump<1000;) {

        printf("%d\n", todayJump);
        totalJump += todayJump;

        if(todayJump > 50) {
            todayJump = 0;
        }
        else
        {
            todayJump = todayJump + n;
        }

    }

}

int main() {

    printf("%d", q2(-5));

    double array[] = { 1.0, 9.1, -2.1, 3.5, 7.8, 8.0, -3.1, 10.0 };
    printf("%f\n", q3(array, 8));

    double array2[] = { 0.5, 6.3, -2.1, -3.5, 1.8, -8.0, 2.1 };
    printf("%f", q3(array2, 7));

    q4(1, 2);


    return 0;
}