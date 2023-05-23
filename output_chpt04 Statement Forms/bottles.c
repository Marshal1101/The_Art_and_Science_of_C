/**
 * @file bottles.c
 * @author The Art of Programming C, exercise 4-1
 * @brief reversed 'for' iteration
 * @version 0.1
 * @date 2023-05-12
 */

#include <stdio.h>

int main()
{
    int t;
    for (t = 99; t > 0; t--) {
        printf("%d bottles of beer on the wall.\n", t);
        printf("%d bottles of beer.\n", t);
        printf("You take one down, pass it around.\n");
    }

    return 0;
}