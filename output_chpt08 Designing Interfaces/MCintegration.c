/**
 * @file MCintegration.c
 * @brief Pi approximated by Monte Carlo interation method
 */

#include <stdio.h>
#include "genlib.h"
#include "random.h"


int main()
{
    int i, cnt;
    double tries, x, y;

    Randomize();
    tries = 10000;
    for (i = 0; i < tries; i++) {
        x = RandomReal(-1, 1);
        y = RandomReal(-1, 1);
        if (x*x + y*y < 1) cnt++;
    }
    printf("%g\n", cnt / tries * 4);

    return 0;
}