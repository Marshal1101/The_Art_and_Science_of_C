/**
 * @file f2ctable.c
 * @brief Fahrenheit to Celsius table. exec 5-3
 * @date 2023-05-13
 */

#include <stdio.h>
#include "genlib.h"

/**
 * Constants
 * ---------
 * LowerLimit -- Starting value for temperature table
 * UpperLimit -- Final value for temperature table
 * StepSize   -- Step size between table entries
 */

#define LowerLimit  32
#define UpperLimit 100
#define StepSzie     2

/* Function prototypes */
double FahrenheitToCelsius(double f);

/* Main program */
int main()
{
    int f;

    printf("Fahrenheit to Celsius table.\n");
    printf("  F    C\n");
    for (f = LowerLimit; f <= UpperLimit; f += StepSzie) {
        printf("%3d  %5.1lf\n", f, FahrenheitToCelsius(f));
    }
    return 0;
}

double FahrenheitToCelsius(double f)
{
    return ((f - 32) * 9.0 / 5.0);
}