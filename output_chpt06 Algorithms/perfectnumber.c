/**
 * @file perfectnumber.c
 * @brief perfect numbers are numbers equal their proper divisors's sum.
 * perfect number 완전수, proper divisor 진제수
 */

#include <stdio.h>
#include <math.h>

#include "genlib.h"
#include "simpio.h"

bool PerfectNumber(int n);

int main()
{
    int i, n1, n2;

    printf("Find perfect numbers from n1 to n2\n");
    printf("start n1? ");
    n1 = GetInteger();
    printf("end n2? ");
    n2 = GetInteger();
    for (i = n1; i <= n2; i++) {
        if (PerfectNumber(i)) printf("%d ", i);
    }
    printf("\n");
    return 0;
}

bool PerfectNumber(int n)
{
    int i, limit, total;

    if (n == 1) return (TRUE);
    total = 1;
    limit = sqrt(n) + 1;
    for (i = 2; i <= limit; i++) {
        if (n % i == 0) {
            total += i;
            total += n / i;
        }
    }
    return (n == total);
}