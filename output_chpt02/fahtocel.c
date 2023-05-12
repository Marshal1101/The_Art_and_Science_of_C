/*
 * File: fahtocel
 * --------------
 * This program reads a degree in Fahrenheit
 * and converts it to its metric equivalent in Celsius.
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    double fah, cel;

    printf("Program to convert Fahrenheit to Celsius.\n");
    printf("Fahrenheit temperature? ");
    fah = GetReal();
    cel = (fah - 32) * 5 / 9;
    printf("Celsius equivalent: %g", cel);
}