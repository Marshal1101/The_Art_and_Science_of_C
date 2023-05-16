/**
 * @file caltools.h
 * @brief This header is for calendar methods.
 */


#ifndef __caltool_h
#define __caltool_h

#include "genlib.h"

/**
 * @brief Returns how long days of the month in year.
 * 
 * @param month 
 * @param year 
 * @return int 
 */
int MonthDays(int month, int year);

/**
 * @brief Returns what day at the first in month, year.
 * 
 * @param month 
 * @param year 
 * @return int 
 */
int FirstDayOfMonth(int month, int year);

/**
 * @brief Returns months' english name
 * 
 * @param month 
 * @return string 
 */
string MonthName(int month);

/**
 * @brief Return TRUE if the year is a leap
 * 
 * @param year 
 * @return true 
 * @return false 
 */
bool IsLeapYear(int year);

/**
 * @brief Print the month in the year.
 * 
 * @param month 
 * @param year 
 */
void PrintCalendarMonth(int month, int year);

#endif