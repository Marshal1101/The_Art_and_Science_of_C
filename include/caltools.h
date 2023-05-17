/**
 * @file caltools.h
 * @brief This header is for calendar methods.
 */


#ifndef __caltool_h
#define __caltool_h

#include "genlib.h"

/**
 * @brief Type: WeekdayT
 * 
 * Days of the week are represented by the integers 0-6.
 */
typedef enum {
    Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
} weekdayT;

/**
 * @brief Type: MonthT
 * Months of the year are indentified by the integers 1-12.
 * because this numeric representation for months is in
 * common use, no special constants are defined.
*/
typedef enum {
    January = 1, February, March, April, May, June, July, August, September, October, November, December
} monthT;

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