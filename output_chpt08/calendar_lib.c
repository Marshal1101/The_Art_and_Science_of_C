/**
 * @file calendar.c
 * @author The Art and Science of C, 5-6, exec 5-13, 5-14
 * @brief This program is used to generate a calendar for a year entered by the user
 * @version 0.1
 * @date 2023-05-13
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "caltools.h"

/* Functio prototypes */
void GiveInstructions(void);
int GetYearFromUser(void);
void PrintCalendar(int year);
bool GetADorBC(void);

/* Main program */
int main()
{
    int year;

    GiveInstructions();
    year = GetYearFromUser();
    PrintCalendar(year);
    return 0;
}

/**
 * Function: GiveInstructions
 * Usage: GiveInstructions();
 * --------------------------
 * This procedure prints out instructions to the user.
 */
void GiveInstructions(void)
{
    printf("This program displays a calendar for a full year.\n");
    printf("The year must not be bellow 1.\n");
}

/**
 * Function: GetYearFromUser
 * Usage: year = GetYearFromUser();
 * --------------------------------
 * This function reads in a year from the user and returns
 * that value. If the user enters an year bellow 1, the
 * function gives the user another chance.
 */
int GetYearFromUser(void)
{
    int year;
    bool isAD;

    isAD = GetADorBC();
    while (TRUE) {
        printf("Which year? ");
        year = GetInteger();
        if (year > 0) return (isAD ? year : -year + 1);
        // if (year > 0) return year;
        printf("The year must be at least 1.\n");
    }
}

/**
 * Function: PrintCalendar
 * Usage: PrintCalendar(year);
 * ---------------------------
 * This procedure prints a calendar for and entire year.
 */
void PrintCalendar(int year)
{
    int month;

    printf("\n");
    for (month = 1; month <= 12; month++) {
        PrintCalendarMonth(month, year);
        printf("\n");
    }
}

/**
 * Function: GetADorBC
 * Usage: answer = GetADorBC();
 * ----------------------------
 * This function returns TRUE if AD ad, FALSE if BC bc.
 */
bool GetADorBC(void)
{
    string ans;

    while (TRUE) {
        printf("AD? or BC?\n");
        ans = GetLine();
        if (StringEqual(ans, "AD") || StringEqual(ans, "ad")) {
            return TRUE;
        } else if (StringEqual(ans, "BC") || StringEqual(ans, "bc")) {
            return FALSE;
        } else {
            printf("Please answer AD or BC.\n");
        }
    }
}