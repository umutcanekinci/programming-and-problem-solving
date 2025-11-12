#include <stdbool.h>
#include "stdio.h"

#include "geometry.h"


#define MAX_SIZE 10


enum Days { Mon, Tue,  Wed ,Thu, Fri, Sat, Sun};

enum CoinFace{ Head, Tail};



int main(void)
{
    enum Days a;

    a = Mon;




    int arr[MAX_SIZE];


    double r = 5.0;

    if (r > 0)
    {
        printf("r is positive");
    }
    printf("Area of circle with r: %.2f = %4.2f!\n", r, areaCircle(r));
    return 0;
}