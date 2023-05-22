/**
 * @file bubblesort.c
 * @brief exercise 12-11
 * @date 2023-05-22
 */

#include <stdio.h>
#include "genlib.h"
#include "random.h"

void RandomIntegerArray(int array[], int n, int low, int high);
void SortIntegerArray(int array[], int low, int high);
void SwapIntegerElements(int array[], int p1, int p2);
static void PrintIntegerArray(int array[], int n);

int main()
{
    // int arr[8] = {31, 41, 59, 26, 53, 58, 97, 93};
    int arr[8];

    printf("This program tests Bubble Sort\n");
    Randomize();
    SetInhancedRandom(TRUE);
    RandomIntegerArray(arr, 8, 1, 100);
    SortIntegerArray(arr, 0, 7);
    PrintIntegerArray(arr, 8);
}

void RandomIntegerArray(int array[], int n, int low, int high)
{
    int i;

    for (i = 0; i < n; i++) {
        array[i] = RandomInteger(low, high);
    }
}


void SortIntegerArray(int array[], int low, int high)
{
    int i, j, n;

    n = high + 1 - low;
    for (i = 0; i < n-1; i++) {
        for (j = low; j < high-i; j++) {
            if (array[j] > array[j+1]) SwapIntegerElements(array, j, j+1);
        }
    }
}

void SwapIntegerElements(int array[], int p1, int p2)
{
    int tmp;

    tmp = array[p1];
    array[p1] = array[p2];
    array[p2] = tmp;
}

static void PrintIntegerArray(int array[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}