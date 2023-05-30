/**
 * @file fibonacci.c
 * @brief exercise 17-1
 * @date 2023-05-30
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

static int Fibonacci(int n);

int main(void)
{
    int num;

    printf("This program tets Fibonacci Recursion.\n");
    printf("n? ");
    num = GetInteger();
    printf("%d\n", Fibonacci(num));
    return 0;
}

int Fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}