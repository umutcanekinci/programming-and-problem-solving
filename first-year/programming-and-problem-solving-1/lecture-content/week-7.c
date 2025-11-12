#include <stdio.h>
#include <stdbool.h>


/**
 * Prints the given array (vals)
 * @param vals
 * @param len
 */
void printArray(int vals[] , int len)
{
    printf("[ ");
    for (int i = 0; i < len; i++) {
        printf("%d",vals[i]);
        if (i<len-1)
            printf(", ");
    }
    printf(" ]\n");
}


// TODO: Write a function that takes an array and sorts it

int findMinimum(int nums[], int len, int start)
{
    int minIndex = start;
    for (int i = start+1; i < len ; i++) {
        if (nums[i]<nums[minIndex])
            minIndex = i;

    }
    return minIndex;
}

void swap(int nums[], int pos1, int pos2)
{
    int t = nums[pos1];
    nums[pos1] = nums[pos2];
    nums[pos2] = t;
}

void sort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++) {
        int minPos = findMinimum(arr,len, i);
        swap(arr, i, minPos);
    }
}

// TODO: Write function that takes an integer array and an integer (key).
//       The function searches for the key in the array.
//       If the key is in the array it returns the index.
//       Otherwise, it returns -1
//
int search(int arr[], int len ,int key)
{
    for (int finger= 0; finger < len; finger++) {
        if ( arr[finger] == key)
            return finger;
    }

    return -1;
}


// TODO: Write function that takes a sorted array and an integer (key).
//       The function searches for the key in the array.
//       If the key is in the array it returns the index.
//       Otherwise, it returns -1

int searchBetween(int arr[], int left, int right, int key)
{
    if (left == right) // Single element left
    {
        if (arr[left] == key)
            return left;
        else return -1;
    }
    int mid = (left + right)/2;
    if (arr[mid]== key)
        return mid;

    if (arr[mid]<key)
        return searchBetween(arr,mid+1,right,key);
    else return searchBetween(arr,left,mid-1,key);
    return -1;
}


int searchSorted(int arr[], int len, int key)
{
    return searchBetween(arr,0,len-1,key);
}


void main_old()
{
    int nums[] = { 19 ,10, 12, 14, 13, 18, 15 ,11,17,16 };

    printArray(nums,10);

    sort(nums,10);

    printArray(nums,10);

    printf("Pos of  %d is %d\n",10,searchSorted(nums, 10 ,10)) ;

    int x = 5;
    x++;
    ++x;

    int b = ++x;

    b = x++;
    x = x+2;



}


int readPositiveNumber()
{
    int p;
    do
    {
        printf("Enter a positive integer");
        scanf_s("%d", &p);
    }while (p<=0);

    return p;

}


void main_old2()
{
    int i = 0;
    while (i < 5  && i > 0) {
        printf("%d\n",i);
        ++i;
    }
}

int main_errorcode()
{
    printf("%d\n", readPositiveNumber());


    return 0;
}

int  main()
{
    int a = 200000;
    int b = 300000;

    printf("%d * %d = %d\n", a,b, a*b);

    return 0;
}
