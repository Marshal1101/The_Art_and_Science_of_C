/**
 * @file leapyear.c
 * @author The Art of Programming C, ex 4-1
 * @brief check if a year is a leap year.
 * @version 0.1
 * @date 2023-05-12
 * 
 * @copyright MIT
 * 
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    int year;
    bool isLeapYear;

    printf("Program to determine whether a year is a leap year.\n");
    printf("What year? ");
    year = GetInteger();
    isLeapYear = ((year % 4 == 0) && (year % 100 != 0))
                    || (year % 400 == 0);
    if (isLeapYear) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }
    return 0;
}