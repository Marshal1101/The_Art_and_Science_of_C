/**
 * @file timestab.c
 * @author The Art of Programming C, ex 4-8
 * @brief Generates a multiplication table where each axis
 *        runs from LowerLimit to UpperLimit.
 * @version 0.1
 * @date 2023-05-12
 * 
 * @copyright MIT
 * 
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

/*
 * Constants
 * ---------
 * LowerLimit -- Starating value for the table
 * UpperLimit -- Final value for the table
*/

// #define LowerLimit 11
// #define UpperLimit 20

/* Main program */

int main()
{
    int i, j, LowerLimit, UpperLimit;

    printf("Generates a multiplication table where each axis runs from LowerLimit to UpperLimit.\n");
    printf("LowerLimit? ");
    LowerLimit = GetInteger();
    printf("UpperLimit? ");
    UpperLimit = GetInteger();
    for (i = LowerLimit; i <= UpperLimit; i++) {
        for (j = LowerLimit; j <= UpperLimit; j++) {
            printf(" %4d", i * j);
        }
        printf("\n");
    }
    return 0;
}