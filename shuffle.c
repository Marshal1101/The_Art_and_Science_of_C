/**
 * @file shuffle.c
 * @brief 
 * @date 2023-05-22
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "random.h"

#define MaxElements     250
#define Sentinel          0

void Shuffle(int array[], int low, int high);
static void SwapIntegerElements(int array[], int p1, int p2);

int main()
{
    int arr[MaxElements];
    int i;

    printf("This Program tests Shuffle functon from 1 to 52\n");
    for (i = 0; i < 52; i++) arr[i] = i+1;
    Randomize();
    Shuffle(arr, 0, 51);
    for (i = 0; i < 52; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void Shuffle(int array[], int low, int high)
{
    int i, rpos;

    for (i = low; i <= high; i++) {
        rpos = RandomInteger(i, high);
        SwapIntegerElements(array, i, rpos);

    }
}

static void SwapIntegerElements(int array[], int p1, int p2)
{
    int tmp;

    tmp = array[p1];
    array[p1] = array[p2];
    array[p2] = tmp;
}
