/*
 * File: add10f.c
 * ------------
 * This program adds a list of ten float numbers, printing the total at the end.
 * Instead of reading the numers into separate variables, this program reads
 * in each number and adds it to a runnning total.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    int i;
    double value, total;

    printf("This program adds a list of ten float numbers.\n");
    total = 0;
    for (i = 0; i < 10; i++) {
        printf("fnumber? ");
        value = GetReal();
        total += value;
    }
    printf("The total is %f\n", total);
    return 0;
}