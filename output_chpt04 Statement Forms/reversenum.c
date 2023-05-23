/**
 * @file reversenum.c
 * @author The Art of Programming C, exercise 4-7
 * @brief 'Reverses a number.'
 * @version 0.1
 * @date 2023-05-12
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    int num, n, ans = 0;

    printf("This program reverses the digits in an integer.\n");
    printf("Enter a positive integer: ");
    num = GetInteger();
    while (num > 0) {
        n = num % 10;
        ans *= 10;
        ans += n;
        num /= 10;
    }
    printf("The reversed number is %d.\n", ans);
}