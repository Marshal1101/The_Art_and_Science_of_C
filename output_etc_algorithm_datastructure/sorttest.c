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


int main(void) {
    int tc, size, total;

    total = tc = 0;
    while (tc++ < MaxTest) {
        size = TimetestSelVsMerge();
        total += size;
    }
    printf("mean size: %d", total/MaxTest);

    // size = TimetestSelVsMerge();
    // total += size;
    // printf("mean size: %d", total/MaxTest);

    return 0;
}

int TimetestSelVsMerge(void)
{
    int *arr1, *arr2;
    int i, size, num;
    double t1, t2;

    Randomize();
    SetInhancedRandom(TRUE);

    size = 1;
    while (size < MaxSize) {
        arr1 = NewArray(size, int);
        arr2 = NewArray(size, int);
        i = 0;
        while (i < size) {
            num = RandomInteger(1, MaxSize);
            arr1[i] = num;
            arr2[i] = num;
            i++;
        }
        clock_t s1s = clock();
        StraightInsertionSort(arr2, size);
        clock_t s1e = clock();
        clock_t s2s = clock();
        Fsort(arr1, size, 0, MaxSize);
        clock_t s2e = clock();

        t1 = s1e - s1s;
        t2 = s2e - s2s;
        if (t1 > t2) break;
        // printf("size: %d, s1: %13llf, s2: %13llf\n", size, t1/CLOCKS_PER_SEC, t2/CLOCKS_PER_SEC);
        size++;
    }
    // printf("sort1 became slower than sort2 at n size = %d\n", size);

    return size;
}