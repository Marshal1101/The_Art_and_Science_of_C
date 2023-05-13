/**
 * @file pascal.c
 * @brief Combinations, Factorials, Pascal's Triangle exec 5-12
 * @date 2023-05-14
 */

#include <stdio.h>
#include "genlib.h"

#define Height   8

void IndentLine(int i);
int Combinations(int n, int k);
int Factorial(int n);

int main()
{
    int i, j;

    for (i = 0; i < Height; i++) {
        IndentLine(i);
        for (j = 0; j <= i; j++) {
            printf("%4d", Combinations(i, j));
        }
        printf("\n");
    } 
    return 0;
}

void IndentLine(int i)
{
    int k;

    for (k = 0; k < Height - i; k++) {
        printf("  ");
    }
}

int Combinations(int n, int k)
{
    return (Factorial(n) / Factorial(n-k) / Factorial(k));
}

int Factorial(int n)
{
    int ret = 1;
    
    while (n > 0) {
        ret *= n--;
    }
    return ret;
}