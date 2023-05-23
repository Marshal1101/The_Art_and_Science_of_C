/**
 * @file real2power.c
 * @brief (real) x ** (int) k
 * @date 2023-05-13
 */

#include <stdio.h>
#include "genlib.h"

#define LowerLimit  -4
#define UpperLimit   4

double RaiseRealToPower(double x, int k);

int main()
{
    int i;

    printf("           k\n");
    printf(" k       10\n");
    printf("--------------------\n");
    for (i = LowerLimit; i <= UpperLimit; i++) {
        if (i < 0) {
            printf("%3d     %g\n", i, RaiseRealToPower(10, i));
        } else {
            printf("%3d %7.1lf\n", i, RaiseRealToPower(10, i));
        }
    }
    return 0;
}

double RaiseRealToPower(double x, int k)
{
    bool kminus = FALSE;
    double half, ret;

    if (k == -1) return (0.1);
    if (k == 0) return (1);
    if (k == 1) return (x);
    if (k < 0) {
        k = -k;
        kminus = TRUE;
    }
    half = RaiseRealToPower(x, k/2);
    ret = (k % 2) ? x * half * half : half * half;
    return (kminus ? 1/ret : ret);
}