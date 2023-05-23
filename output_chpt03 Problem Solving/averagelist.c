/**
 * @file averagelist.c
 * @author hjpark
 * @brief This program is calculating the average of a list of numbers.
 * @version 0.1
 * @date 2023-05-12
 * 
 * @copyright MIT
 * 
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    int value, cnt;
    double total;

    printf("This program is calculating the average of a list of numbers.\n");
    printf("Signal end of list with a -1.\n");
    cnt = 0;
    total = 0.0;
    while (TRUE) {
        printf("a number ? ");
        value = GetInteger();
        if (value == -1) break;
        total += value;
        cnt++;
    }
    printf("The average is %.1f", total / cnt);
    return 0;
}