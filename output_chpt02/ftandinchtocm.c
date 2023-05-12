/*
 * File: ftandinchtocm.c
 * ---------------------
 * This program reads a length given in feet and inches
 * and converts it to its metric equivalent in centimeters.
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


void main()
{
    double ft, inch, cm;
    
    printf("This program converts from feet and inches to centimeters.\n");
    printf("Number of feet? ");
    ft = GetReal();
    printf("Number of inches? ");
    inch = GetReal();
    inch += ft * 12;
    cm = inch * 2.54;
    printf("The corresponding length is %g cm.\n", cm);
}