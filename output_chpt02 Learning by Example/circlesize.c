/*
 * File: circlesize
 * --------------------
 * This program reads a length and calculates its size.
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


void main()
{
    double r, size, PI=3.14159;
    
    printf("This program reads a length and calculates its size.\n");
    printf("Number of Radius? ");
    r = GetReal();
    size = r * r * PI;
    printf("The circle size is %g.\n", size);
}