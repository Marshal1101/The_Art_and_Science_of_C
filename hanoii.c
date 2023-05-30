/**
 * @file hanoii.c
 * @brief exercise 17-4
 * @date 2023-05-30
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

void Hanoii(int n);
static void HanoiiMove(int n, char start, char dest, char mid);

int main(void)
{
    int n;

    printf("This program tests Hanoii with Recursion\n");
    printf("Hanoii N? ");
    n = GetInteger();
    Hanoii(n);
    return 0;
}

void Hanoii(int n)
{
    HanoiiMove(n, 'A', 'B', 'C');
}

static void HanoiiMove(int n, char start, char dest, char mid)
{
    if (n == 1) {
        printf("%c -> %c\n", start, dest);
        return;
    }
    HanoiiMove(n-1, start, mid, dest);
    printf("%c -> %c\n", start, dest);
    HanoiiMove(n-1, mid, dest, start);
}