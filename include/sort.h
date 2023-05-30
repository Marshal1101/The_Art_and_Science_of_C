/*
* File: sort.h
* --------------
* This file provides an interface to a simple procedure
* for sorting an integer array into increasing order.
*/

#ifndef _sort_H
#define _sort_H


#include "genlib.h"

/*
* Function: SortIntegerArray
* Usage: SortIntegerArray (array, n);
* ----------------------------------------------
* This function sorts the first n elements in array into 
* increasing numerical order. In order to use this procedure,
* you must declare the array in the calling program and pass
* the effective number of elements as the parameter n.
* In most cases, the array will have a larger allocated
* size.
*/
void SortIntegerArray(int array[], int n);
void SelectionSort(int array[], int n);
void MergeSort(int array[], int n);

/* string lexicographic sort */
void Alphabetize(string array[], int n);

/* Sort Real array */
void SortRealArray(double array[], int n);

#endif