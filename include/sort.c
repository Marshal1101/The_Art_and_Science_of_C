/*
* File: sort.c
* --------------
* This file implements the sort.c interface using the selection
* sort algorithm.
*/

#include <stdio.h>
#include "genlib.h"
#include "strlib.h"
#include "sort.h"

/* sorttest.c 테스트에서 선택정렬보다 합병정렬이 빨라지는 평균 요소 개수 112 */
#define SizeUseMergeSort    112

/* Private function prototypes */

static void Merge(int array[], int arr1[], int n1, int arr2[], int n2);
static int FindSmallestInteger(int array[], int low, int high);
static void SwapIntegerElements(int array[], int p1, int p2);
static int FindMinLexicoElements(string array[], int low, int high);
static void SwapStringElements(string array[], int p1, int p2);
static int FindSmallestRealElements(double array[], int low, int high);
static void SwapRealElements(double array[], int p1, int p2);

/*
* Function: SortIntegerArray
* ---------------------------------
* This implementation uses an algorithm called selection sort, 
* which can be described in English as follows. With your left
* hand, point at each element in the array in turn, starting at 
* index 0. At each step in the cycle:
*
* (1) Find the smallest elemnt inteh range between your left
* hand and the end of the array, and point at that element
* with your right hand.
* (2) Move that element into its correct index position by 
* switching teh elements indicated by your left and right
* hands.
*/

void SortIntegerArray(int array[], int n) {
    /* SizeUseMergeSort 미만 시에 선택정렬, 이상 시에 합병정렬 선택 */
    if (n < SizeUseMergeSort) {
        SelectionSort(array, n);
    } else {
        MergeSort(array, n);
    }

}

/* Selection Sort */
void SelectionSort(int array[], int n)
{
    int lh, rh;
    for (lh = 0; lh < n; lh++) {
        rh = FindSmallestInteger(array, lh, n-1);
        SwapIntegerElements(array, lh, rh);
    }
}

/* Merge Sort */
void MergeSort(int array[], int n)
{
    int i, n1, n2;
    int *arr1, *arr2;

    if (n > 1) {
        n1 = n / 2;
        n2 = n - n1;
        arr1 = NewArray(n1, int);
        arr2 = NewArray(n2, int);
        for (i = 0; i < n1; i++) arr1[i] = array[i];
        for (i = 0; i < n2; i++) arr2[i] = array[n1 + i];
        MergeSort(arr1, n1);
        MergeSort(arr2, n2);
        Merge(array, arr1, n1, arr2, n2);
        FreeBlock(arr1);
        FreeBlock(arr2);
    }
}

static void Merge(int array[], int arr1[], int n1, int arr2[], int n2)
{
    int p, p1, p2;

    p = p1 = p2 = 0;
    while (p1 < n1 && p2 < n2) {
        if (arr1[p1] < arr2[p2]) {
            array[p++] = arr1[p1++];
        } else {
            array[p++] = arr2[p2++];
        }
    }
    while (p1 < n1) array[p++] = arr1[p1++];
    while (p2 < n2) array[p++] = arr2[p2++];
}

/*
* Function: FindSmallestInteger
* Usage: index = FindSmallestInteger (array, low, high);
* -----------------------------------------------------------------------
* This function returns the index of the smallest value in the 
* specified array of integers, searching only between the index
* positions low and high, inclusive. It operates by keeping track
* of the index of the smallest so far in the variables spos. If the 
* index range is empty, the function returns low.
*/
static int FindSmallestInteger(int array[], int low, int high)
{
    int i, spos;

    spos = low;
    for (i = low; i <= high; i++) {
        if (array[i] < array[spos]) spos = i;
    }
    return (spos);
}

/*
* Function: SwapIntegerElements
* Usage: SwapIntegerElement (array, p1, p2);
* ----------------------------------------------------------
* This function swaps the elements in array at index
* positions p1 and p2.
*/
static void SwapIntegerElements(int array[], int p1, int p2)
{
    int tmp;

    tmp = array[p1];
    array[p1] = array[p2];
    array[p2] = tmp;
}

void Alphabetize(string array[], int n)
{
    int lh, rh;

    for (lh = 0; lh < n; lh++) {
        rh = FindMinLexicoElements(array, lh, n-1);
        SwapStringElements(array, lh, rh);
    }
}

static int FindMinLexicoElements(string array[], int low, int high)
{
    int i, spos;

    spos = low;
    for (i = low; i <= high; i++) {
        if (StringCompare(array[spos], array[i]) > 0) spos = i;
    }
    return spos;
}

static void SwapStringElements(string array[], int p1, int p2)
{
    string tmp;

    tmp = array[p1];
    array[p1] = array[p2];
    array[p2] = tmp;
}

void SortRealArray(double array[], int n)
{
    int lh, rh;

    for (lh = 0; lh < n; lh++) {
        rh = FindSmallestRealElements(array, lh, n-1);
        SwapRealElements(array, lh, rh);
    }
}

static int FindSmallestRealElements(double array[], int low, int high)
{
    int i, spos;

    spos = low;
    for (i = low; i <= high; i++) {
        if (array[i] < array[spos]) spos = i;
    }
    return spos;
}

static void SwapRealElements(double array[], int p1, int p2)
{
    double tmp;

    tmp = array[p1];
    array[p1] = array[p2];
    array[p2] = tmp;
}