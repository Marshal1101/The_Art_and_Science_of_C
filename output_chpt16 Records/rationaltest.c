/**
 * @file rationaltest.c
 * @brief exercise 16-5
 * @date 2023-05-30
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "rational.h"

int main(void)
{
    string line;
    rationalT sum, tmp;

    sum.den = 1; 
    sum.num = 0;
    printf("This program adds a list of rational numbers.\n");
    printf("Signal end of list wtih a 0.\n");
    while (TRUE) {
        printf("  ? ");
        line = GetLine();
        if (line[0] == '0') break;
        tmp = GetStringToRational(line);
        // printf("The tmp is %d/%d\n", tmp.num, tmp.den);
        if (tmp.den != 0) {
            sum = AddRational(sum, tmp);
            // sum = MultiplyRational(sum, tmp);
        }
        else {
            printf("Input Rational format: x/y\n");
        }
        // printf("The total is %d/%d\n", sum.num, sum.den);
    }
    printf("The total is %d/%d\n", sum.num, sum.den);
    return 0;
}