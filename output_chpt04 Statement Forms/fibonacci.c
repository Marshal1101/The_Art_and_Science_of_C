/**
 * @file fibonacci.c
 * @author The Art of Programming C, exercise 4-7
 * @brief 'the Fibonacci sequence.'
 * @version 0.1
 * @date 2023-05-12
 */

#include <stdio.h>

#define LIMIT 10000

int main()
{
    int i = 0, n1 = 0, n2 = 1, ans = 1;

    printf("This program lists the Fibonacci sequence. under %d\n", LIMIT);
    printf("F(%d)  = ", i++);
    printf("%d\n", n1);
    while (ans < LIMIT) {
        printf("F(%d)  = ", i++);
        printf("%d\n", ans);
        ans = n2 + n1;
        n1 = n2;
        n2 = ans;
    }
    return 0;
}