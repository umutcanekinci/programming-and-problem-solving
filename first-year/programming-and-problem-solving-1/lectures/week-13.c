#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>


int main_intro(void)
{

    int a = 5;
    bool b= true;
    char c = 'x';

    int * pa = &a;

    bool *pb = &b;

    char *pc = &c;

    printf("the value of a: %d\n" , a);
    printf("the address of a: %lu\n" , &a);
    printf("the value of pa: %lu \n", pa);
    printf("the value of pc: %lu \n", pc);
    printf("the address of pa: %lu\n", &pa);


    // How to read the data at a certain memory address
    printf(" the value at adress %ld = %d\n",pa ,*pa);


    return 0;
}

int main_pointer_arithmetic()
{
    int x = 1035;

    int *px= &x;

    printf("the value at the address in px = %d\n", *px);
    *px= 1043;
    printf("the value x = %d\n", x);

    int *py;
    char *pc;
    py = px;

    pc= px;

    printf("the value at the address in px = %d\n", *px);
    printf("the value at the address in pc = %d\n", *pc);

    pc++; // incremented by 1

    printf("the value at the address in pc = %d\n", *pc);

    px++;  // incremented by 4

    printf("%d\n",*px);
    return 0;
}


int main_pointer_to_pointer()
{
   int x =5;
   int *px = &x;
   int*  * ppx; // Pointer to a pointer to int

   ppx = &px;

    printf("the value of x: %d\n", x);
    printf("the value of x: %d\n", *px );
    printf("the value of x: %d\n", **ppx);


    printf("addr of x: %ld\n", &x );
    printf(" %ld", &**&*ppx);
    return 0;

}


void swap(int *px, int *py)
{
    int z = *px;
    *px = *py;
    *py = z;
}

int main_swap()
{
    int x = 3;
    int y = 5;


    printf("x: %d   y: %d\n",x,y);
    swap(&x,&y);
    printf("x: %d   y: %d\n",x,y);

}




int main_arr()
{
    int arr[] = { 1,5,9,13};

    int *px = arr; // arr -> &arr[0]

    px++;
    printf("%d\n", *px);
    printf("%d\n", px[1]);

    printf("%d\n", *arr);
    printf("%d\n", *(arr+2));

    return 0;

}

void printArray(int arr[], int len)
{
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main_size_of()
{
    int x = 5;
    int arr[] = {1,2,3,4,5,6,7,8,9};

    int len = sizeof (arr) / sizeof (int);

    printArray(arr,len);
}


void charFunc( char p[])
{
    p++;
    p[0]= 'a';
    printf("%s\n",p);
}



// Write strlen function with pointers
int strLength(char *str)
{
    int len =0;

    for (len = 0; *str != NULL ; str++,++len);

    return len;
}

// Write a function that returns if a given string is palindrome
bool isPalindrome( char *s)
{
    int len = strLength(s);

    char * r = &s[len-1];
    char * l = s;

    while (l<r)
    {
        if ( *l != *r)
        {
            return false;
        }
        l++; r--;
    }
}


void main_str()
{
    char p[] ="Hello";
    charFunc(p);
    printf("%s\n",p);

}

int main_malloc()
{

    int x = 4;

   //int arr[1000][1000];

   // arr[0][0] = 4;

   // printf("%d\n", arr[0][0]);

    int* p;
    while (true)
    {
        printf("Memory area reserved..\n");
        int* p = malloc( 1000000000 * sizeof (int));

        p [100] = 5;
        if (p == NULL)
        {
            printf("Memory is full!\n");
            return -5;
        }
        free(p);
    }


    p[0] = 3;
    p[10] = 45;

    printf("%d\n", *(p+10));

    free(p);
    return 0;
}


int main_leak()
{

    int *p = malloc(sizeof(int));

    *p = 7;

    printf("%d\n", *p);

    int x = 11;

    free(p);

    p =  &x;
    printf("%d\n",*p);
    *p = 3;

    int y = 10;

    printf("%d\n",*p);
    p = &y;

    printf("%d\n",*p);






    return 0;

}

#define DIRECTIONCOUNT 4

typedef enum  { Up, Right, Down, Left} Direction;
typedef enum  { ClockWise = 1, CounterClockWise= 3} TurnDirection;

Direction final( Direction initial, TurnDirection turns[], int turnCount)
{
    for (int i = 0; i < turnCount; ++i) {
        initial += turns[i];

    }
    return initial%DIRECTIONCOUNT;
}


typedef  int Map[10][10];

int circumf(Map map)
{

}

void main()
{
    Direction  d = Up;

    TurnDirection  turns[] = { CounterClockWise};

    d= final(d,turns,1);
    printf("%d\n", d);

}


