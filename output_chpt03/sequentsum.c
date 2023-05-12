/**
 * @file sequentsum.c
 * @author hjpark
 * @brief this program adds n1 to n2 squential numbers.
 * @version 0.1
 * @date 2023-05-12
 * 
 * @copyright MIT
 * 
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    int i, n1, n2, total;

    printf("This program adds n1 to n2 squential numbers.\n");
    printf("starting number? ");
    n1 = GetInteger();
    printf("ending number? ");
    n2 = GetInteger();
    total = 0;
    for (i = n1; i <= n2; i++) {
        total += i; 
    }
    printf("total is %d\n", total);
    return 0;
}