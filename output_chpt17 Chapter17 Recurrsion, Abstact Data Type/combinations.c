/**
 * @file combinations.c
 * @brief exercise 17-2 
 * @date 2023-05-30
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int Combinations(int n, int k);

int main(void)
{
    int n, k;

    printf("This program tests Combinations with Recursion.\n");
    printf("n? ");
    n = GetInteger();
    printf("k? ");
    k = GetInteger();
    printf("%dC%d = %d\n", n, k, Combinations(n, k));
    return 0;
}

int Combinations(int n, int k)
{
    if (k == 0) {
        return 1;
    } else if (n == k) {
        return 1;
    } else {
        return Combinations(n-1, k-1) + Combinations(n-1, k);
    }
}