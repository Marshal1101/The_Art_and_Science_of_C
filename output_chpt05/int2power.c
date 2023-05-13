/**
 * @file int2power.c
 * @brief n**k
 * @date 2023-05-13
 */

#include <stdio.h>
#include "genlib.h"

#define LowerLimit   0
#define UpperLimit  10

int RaiseIntToPower(int n, int k);

int main()
{
    int i;

    for (i = LowerLimit; i <= UpperLimit; i++) {
        printf("2 ** %d = %d\n", i, RaiseIntToPower(2, i));
    }
    return 0;
}

int RaiseIntToPower(int n, int k)
{
    int half;

    if (k == 0) return (1);
    if (k == 1) return (n);
    half = RaiseIntToPower(n, k/2);
    return (k % 2 ? n * half * half : half * half);
}