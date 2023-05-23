/*
 * File: ncube
 * -------------
 * This program is printing the square and the cube of n1 to n2 given.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    int i, n1, n2;
    string c1, c2, c3;

    printf("starting number? ");
    n1 = GetInteger();
    printf("ending number? ");
    n2 = GetInteger();
    c1 = "Number";
    c2 = "Square";
    c3 = "Cube";
    printf("%7.7s %7.7s %7.7s\n", c1, c2, c3);
    for (i = n1; i <= n2; i++) {
        printf("%7d %7d %7d\n", i, i*i, i*i*i);
    }
    return 0;
}