/**
 * @file midpoint.c
 * @brief exercise 16-3
 * @date 2023-05-29
 */

#include <stdio.h>

#include "genlib.h"
#include "simpio.h"


typedef struct {
    double x, y;
} pointT;

pointT Midpoint(pointT p1, pointT p2);


int main(void)
{
    pointT p1, p2;

    printf("let's find the MIDPOINT\n");
    printf("point1 x? ");
    p1.x = GetReal();
    printf("point1 y? ");
    p1.y = GetReal();
    printf("point2 x? ");
    p2.x = GetReal();
    printf("point2 y? ");
    p2.y = GetReal();
    pointT mid = Midpoint(p1, p2);
    printf("midpoint: (%.2lf, %.2lf)\n", mid.x, mid.y);
    return 0;
}


pointT Midpoint(pointT p1, pointT p2)
{
    pointT mid;

    mid.x = (p1.x + p2.x) / 2;
    mid.y = (p1.y + p2.y) / 2;
    return mid;
}