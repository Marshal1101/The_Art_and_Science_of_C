/*
 * File: nsquare
 * -------------
 * This program is squaring n1 to n2 given and printing each result.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    int i, n1, n2;
    
    printf("starting number? ");
    n1 = GetInteger();
    printf("ending number? ");
    n2 = GetInteger();
    for (i = n1; i <= n2; i++) {
        printf("%d squared is %d\n", i, i*i);
    }
    return 0;
}