/**
 * @file apxpi.c
 * @brief exercise 6-7, 6-8
 * The technique of series approximation can be used to compute
 * approximations of the mathematical constant π.
 */

#include <stdio.h>
#include <math.h>
#include "genlib.h"

void ApxPi(void);
void ApxPi2(void);
void ApxPi3(void);
void EulerNumber(void);

int main()
{
    ApxPi();
    ApxPi2();
    ApxPi3();
    EulerNumber();
    return 0;
}

void ApxPi(void)
{
    int i;
    double dinominator, sum;

    sum = 0;
    i = 1;
    dinominator = 1.0;
    while (i++ <= 5000) {
        sum += 1 / dinominator;
        dinominator += 4;
    }
    i = 1;
    dinominator = 3.0;
    while (i++ <= 5000) {
        sum -= 1 / dinominator;
        dinominator += 4;
    }
    printf("Approximation of Pi is %g\n", sum * 4);
}

void ApxPi2(void)
{
    double i, c1, c2, c3, cd, term, sum;

    sum = 0;
    c1 = 1;
    c3 = term = 0.5;
    cd = pow(0.5, 2);
    for (i = 1; sum != sum + term; i++) {
        sum += term;
        c1 *= (2*i-1) / (2*i);
        c2 = 1.0 / (2*i+1);
        c3 *= cd;
        term = c1 * c2 * c3;
    }
    printf("Approximation2 of Pi is %.10Lf\n", 6*sum);
}

void ApxPi3(void)
{
    int n, i;
    double t, t2, x, mid, h, sum;

    n = 100;
    t = 2.0 / n;
    t2 = t / 2.0;
    x = 0;
    for (i = 1; i <= n; i++) {
        mid = x + t2;
        h = sqrt(4.0 - mid*mid);
        sum += h * t;
        x += t;
    }
    printf("Approximation3 of Pi is %g\n", sum);
}

void EulerNumber(void)
{
    int i;
    double factorial, term, sum;

    sum = 0.0;
    term = 1.0;
    factorial = 1.0;
    for (i = 1; sum != sum + term; i++) {
        sum += term;
        factorial *= i;
        term = (1.0 / factorial);
    }
    printf("Euler Number e is %.10Lf", sum);
}