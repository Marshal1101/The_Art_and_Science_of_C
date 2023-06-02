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
void StraightSelectionSort(int array[], int n);
void MergeSort(int array[], int n);
void StraightInsertionSort(int array[], int n);
void BinaryInsertionSort(int array[], int n);
void ShellSort(int array[], int n);
void QuickSort(int array[], int left, int right);
void HeapSort(int array[], int n);
void Fsort(int array[], int n, int min, int max);

/* string lexicographic sort */
void Alphabetize(string array[], int n);

/* Sort Real array */
void SortRealArray(double array[], int n);

#endif