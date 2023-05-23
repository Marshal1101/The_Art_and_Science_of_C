/**
 * @file primefactorization.c
 * @brief print a result of prime factorization (소인수분해)
 *        ex) 60 >> 2 * 2 * 3 * 5
 */

#include <stdio.h>
#include <math.h>

#include "genlib.h"
#include "simpio.h"

void PrimeFactoriztion(int n);

int main()
{
    int n;

    while (TRUE) {
        printf("Enter Number to be factored: ");
        n = GetInteger();
        if (n > 1) {
            PrimeFactoriztion(n);
            break;
        }
        printf("n is above 2.\n");
    }
    return 0;
}

void PrimeFactoriztion(int n)
{
    int i, limit;
    bool is_first;

    if (n < 2) Error("n is above 2.\n");
    limit = n / 2 + 1;
    is_first = TRUE;
    i = 2;
    while (i < limit) {
        if (n % i == 0) {
            n /= i;
            if (is_first) {
                is_first = FALSE;
                printf("%d ", i);
            } else {
                printf("* %d ", i);
            }
        } else {
            i++;
        }
    }
    printf("\n");
}