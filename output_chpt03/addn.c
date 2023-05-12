/*
 * File: addn.c
 * ------------
 * This program adds a list of 'n' numbers, printing the total at the end.
 * Instead of reading the numers into separate variables, this program reads
 * in each number and adds it to a runnning total.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    int i, n, value, total;

    printf("This program adds a list of 'n' numbers.\n");
    printf("how many times do you add numbers? ");
    n = GetInteger();
    total = 0;
    for (i = 0; i < n; i++) {
        printf("number? ");
        value = GetInteger();
        total += value;
    }
    printf("The total is %d\n", total);
    return 0;
}