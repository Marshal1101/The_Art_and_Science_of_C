/**
 * @file makestar2.c
 * @author The Art of Programming C, exercise 4-7
 * @brief printing stars
 * @version 0.1
 * @date 2023-05-12
 */

#include <stdio.h>

#define ROW 8

int main()
{
    int i, j, t;

    for (i = 1; i <= ROW; i++) {
        for (j = 1; j <= ROW-i; j++) {
            printf(" ");
        }
        for (t = 1; t <= 2*i-1; t++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}