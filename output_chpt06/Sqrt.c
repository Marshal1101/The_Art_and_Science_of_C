/**
 * @file Sqrt.c
 * @brief Squrt Function with Taylor's Series
 * @date 2023-05-14
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

double Sqrt(double x);
double TSqrt(double x);

int main()
{
    double x;

    printf("Sqrt: what number? ");
    x = GetReal();
    printf("Sqrt(%g) is %g", x, Sqrt(x));
    return 0;
}

/*
* Function: Sqrt
* Usage: root = Sqrt (x);
* ------------------------------
* Return the square root of x, calculated using a
* Taylor series expansion, as described in the text.
* The Sqrt function is actually implemented as two
* functions. The job of the outer Sqrt function is to
* divide the argument repeatedly by 4 until it is in 
* the range 0 < x < 2, where the Taylor series converges.
* It then calls TSqrt to perform the actual Taylor series
* calculation. When finished, Sqrt adjusts the answer by 
* multiplying the result by 2 for each time it needed to
* be divided by 4 to bring it in range.
*/
double Sqrt(double x)
{
    double result, correction;

    if (x == 0) return (0);
    if (x < 0) Error("Sqrt called with negative argument %g", x);
    correction = 1;
    while (x >= 2) {
        x /= 4;
        correction *= 2;
    }
    return (TSqrt(x) * correction);
}

/*
* Function: TSqrt
* Usage: root = TSqrt (x);
* ------------------------------
* Returns the square root of x, calculated by expanding
* the Taylor series around a = 1, as described in the 
* text. The function is effective only if x is in the
* range 0 < x < 2. Term i in the summation has the form
* xpower
* coff * ----------------
* factorial
* where coeff comes from ith derivative of the function,
* factorial is i!, and xpower is the ith power of (x –a).
* Each of these components is computed from its previous
* value.
*/
double TSqrt(double x)
{
    double sum, factorial, coeff, term, xpower;
    int i;

    factorial = coeff = xpower = 1;
    sum = 0;
    term = 1;
    for (i = 0; sum != sum + term; i++) {
        sum += term;
        coeff *= (0.5 - i);
        xpower *= (x - 1);
        factorial *= (i + 1);
        term = coeff * xpower / factorial;
    }
    return (sum);
}