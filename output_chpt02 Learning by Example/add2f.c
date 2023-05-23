#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


int main()
{
    double n1, n2, total;

    printf("This program adds two numbers.\n");
    printf("1st number? ");
    n1 = GetReal();
    printf("2nd number? ");
    n2 = GetReal();
    total = n1 + n2;
    printf("The total is %g.\n", total);
    return 0;
}