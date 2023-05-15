/**
 * @file algoritm.c
 * @brief functions about Number theory
 * @date 2023-05-14
 */

#include <stdio.h>
#include <math.h>

#include "genlib.h"
#include "simpio.h"

#define Epsilon 0.000000001

bool IsPrime(int n);
int GCD(int x, int y);
bool ApproximatelyEqual(double x, double y);
double Sqrt(double x);
double ZenoSeries(int r);
double CuteRoot(double x);
double NewtonRaphson(double x, int k);


int main()
{
    int n, n1, n2;
    double x;

    printf("what number x ? ");
    // x = GetReal();
    n = GetInteger();
    printf("The cube root of x is %g\n", CuteRoot(n));
    // printf("The sum of Zeno's series is %g\n", ZenoSeries(n));
    // printf("%g\n", Sqrt(x));
    // printf("what number y ? ");
    // n2 = GetInteger();
    // printf("%d is GCD of %d and %d.\n", GCD(n1, n2), n1, n2);
    // printf("%d is %s", number, (IsPrime(number) ? "prime." : "not prime.\n"));

    return 0;
}

bool IsPrime(int n)
{
    int i, limit;

    if (n == 1) return FALSE;
    if (n == 2) return TRUE;
    if (n % 2 == 0) return FALSE;
    limit = sqrt(n) + 1;
    for (i = 3; i <= limit; i += 2) {
        if (n % i == 0) return (FALSE);
    }

    return (TRUE);
}

int GCD(int x, int y)
{
    int r = 1;

    while (r != 0) {
        r = x % y;
        // printf("x:%d y:%d r:%d\n", x, y, r);
        x = y;
        y = r;
    }
    return (x);
}

bool ApproximatelyEqual(double x, double y)
{
    double xyabs, min;

    xyabs = fabs(x - y);
    min = (x < y ? x : y);
    return (xyabs / min < Epsilon);
}

double Sqrt(double x) {
    double g;

    if (x == 0) return (0);
    if (x < 0) Error("Sqrt called with negatvie argument %g", x);
    g = x;
    while (!ApproximatelyEqual(x, g * g)) {
        g = (g + x / g) / 2;
    }
    return (g);
}

double ZenoSeries(int r)
{
    double sum, term;

    if (r == 0) Error("r is a integer not zero.");
    sum = 0.0;
    term = 1.0 / r;
    while (sum != sum + term) {
    // while (term != 0) {
        sum += term;
        term /= r;
    }
    // printf("the lastest term: %g\n", term);
    return sum;
}

double CuteRoot(double x)
{
    double g, sw;

    if (x == 0) return (0);
    if (x < 0) Error("Sqrt called with negatvie argument %g", x);
    g = x;
    while (!ApproximatelyEqual(x, g * g * g)) {
        g = (2*g + x/g/g) / 3;
        // printf("%g ", g);
    }
    return (g);
}

double NewtonRaphson(double x, int k)
{
    double nx;

    nx = x;
    while (!ApproximatelyEqual(x, pow(nx, k))) {
        nx = nx - (pow(nx, k) - x) / (k*pow(nx, k-1));
        // printf("%g ", nx);
    }
    return nx;
}