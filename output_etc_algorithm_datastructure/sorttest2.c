/**
 * @file sorttest.c
 * @brief exercise 17-10
 * @date 2023-05-31
 */

#include <stdio.h>
#include <time.h>
#include "genlib.h"
#include "random.h"
#include "sort.h"


#define MaxSize     500
#define MaxTest     1000

int TimetestSelVsMerge(void);
void PrintArray(int array[], int n);

int main(void)
{
    int *arr1;
    int i, size, num;
    double t1, t2;

    Randomize();
    SetInhancedRandom(TRUE);
    // int arr2[10] = {3, 4, 5, 1, 2, 10, 7, 3, 5};

    i = 0;
    size = 50;
    arr1 = NewArray(size, int);
    // arr2 = NewArray(size, int);
    while (i < size) {
        num = RandomInteger(1, MaxSize);
        arr1[i] = num;
        // arr2[i] = num;
        i++;
    }
    PrintArray(arr1, size);
    printf("===========1=======\n");
    Fsort(arr1, size, 0, MaxSize);
    printf("===========2=======\n");
    PrintArray(arr1, size);
    return 0;
}

void PrintArray(int array[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}