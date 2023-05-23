/*
 * File: balance
 * --------------------
 * This program reads in a starting balance and the an annual interest rate
 * and calcuates its balance after one year.
*/

#include <stdio.h>
#include "getopt.h"
#include "simpio.h"

int main()
{
    double balance, interest;

    printf("Interest calculation program.\n");
    printf("Starting balance? ");
    balance = GetReal();
    printf("Annual interest rate percentage? ");
    interest = GetReal();
    balance = balance * (1 + interest / 100);
    printf("Balance after one year: %g\n", balance);
    balance = balance * (1 + interest / 100);
    printf("Balance after two year: %g\n", balance);
}