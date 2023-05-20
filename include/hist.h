#ifndef _hist_h
#define _hist_h


/**
 * @file hist.h
 * @brief 
 * @date 2023-05-20
 */

#include "genlib.h"

/**
 * @brief Print a Histogram graph from the array 
 * @param array 
 * @param n 
 */
void PrintHistogram(int array[], int n);

/**
 * @brief Set the Hist Min object
 * @param min 
 */
void SetHistMin(int min);

/**
 * @brief Set the Hist Max object
 * @param max 
 */
void SetHistMax(int max);

/**
 * @brief Set the Hist Range object
 * @param range 
 */
void SetHistRange(int range);


#endif