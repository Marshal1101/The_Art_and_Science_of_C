/*
* File: sort.c
* --------------
* This file implements the sort.c interface using the selection
* sort algorithm.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "genlib.h"
#include "strlib.h"
#include "sort.h"

/* sorttest.c 테스트에서 선택정렬보다 합병정렬이 빨라지는 평균 요소 개수 112 */
#define SizeForSelectionSort    112
#define SizeForInsertionSrot    158

/* Private function prototypes */

static void Merge(int array[], int arr1[], int n1, int arr2[], int n2);
static int int_cmp(const void *a, const void *b);
static int BinarySearchInArray(int key, int array[], int lp, int rp);
static void Downheap(int array[], int left, int right);
static int FindSmallestInteger(int array[], int low, int high);
static void SwapIntegerElements(int array[], int p1, int p2);
static int FindMinLexicoElements(string array[], int low, int high);
static void SwapStringElements(string array[], int p1, int p2);
static int FindSmallestRealElements(double array[], int low, int high);
static void SwapRealElements(double array[], int p1, int p2);
static void PrintArray(int array[], int n);

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
    /* SizeForSelectionSort 미만 시에
     * 단순선택정렬, 이상 시에 합병정렬 선택 */
    if (n < SizeForSelectionSort) {
        StraightSelectionSort(array, n);
    } else {
        MergeSort(array, n);
    }

}

/* Selection Sort */
void StraightSelectionSort(int array[], int n)
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

/* Straight Insertion Sort */
void StraightInsertionSort(int array[], int n)
{
    int lh, rh, tmp;

    for (lh = 0; lh < n; lh++) {
        tmp = array[lh];
        for (rh = lh; rh > 0 && array[rh-1] > tmp; rh--) {
            array[rh] = array[rh-1];
        }
        array[rh] = tmp;
    }
}

/* Binary Insertion Sort */
void BinaryInsertionSort(int array[], int n)
{
    int lh, rh, tmp;
    int ip;

    for (lh = 1; lh < n; lh++) {
        // printf("%d: ", array[lh]);
        if (array[lh] > array[lh-1]) continue;
        tmp = array[lh];
        // p = bsearch(&tmp, array, lh-1, sizeof(array[0]), (int(*)(const void *, const void *)) int_cmp);
        ip = BinarySearchInArray(tmp, array, 0, lh-1);
        memcpy(array+ip+1, array+ip, (lh-ip) * sizeof(int));
        array[ip] = tmp;
        // PrintArray(array, n);
    }
}

/* Binary search */
static int BinarySearchInArray(int key, int array[], int lp, int rp)
{
    int mid;

    while (lp <= rp) {
        mid = (lp + rp) / 2;
        if (array[mid] > key) {
            rp = mid - 1;
        } else {
            lp = mid + 1;
        }
    }
    return lp;
}

/* 내림차순 비교함수 */
static int int_cmp(const void *a, const void *b)
{
    if (*(int *)a < *(int *)b) return -1;
    else if (*(int *)a > *(int *)b) return 1;
    else return 0; 
}

/* Shell Sort */
void ShellSort(int array[], int n)
{
    int i, j, h, tmp;

    for (h = n/2; h > 0; h /= 2) {
        for (i = h; i < n; i++) {
            tmp = array[i];
            for (j = i - h; j >= 0 && array[j] > tmp; j -= h) {
                array[j + h] = array[j];
            }
            array[j + h] = tmp;
        }
    }
}

/* Quick Sort */
void QuickSort(int array[], int left, int right)
{
    int pl, pr, x;

    pl = left;
    pr = right;
    x = array[(pl + pr) / 2];
    do {
        while (array[pl] < x) pl++;
        while (array[pr] > x) pr--;
        if (pl <= pr) {
            SwapIntegerElements(array, pl, pr);
            pl++;
            pr--;
        }
    } while (pl <= pr);

    if (left < pr) QuickSort(array, left, pr);
    if (pl < right) QuickSort(array, pl, right);
}

/* Heap Sort */
void HeapSort(int array[], int n)
{
    int i;
    
    for (i = (n - 1) / 2; i >= 0; i--) {
        Downheap(array, i, n - 1);
    }
    for (i = n - 1; i > 0; i--) {
        SwapIntegerElements(array, 0, i);
        Downheap(array, 0, i - 1);
    }
}

static void Downheap(int array[], int left, int right)
{
    int tmp, child, parent, cl, cr;

    tmp = array[left];  // root
    for (parent = left; parent < (right + 1) / 2; parent = child) {
        cl = parent * 2 + 1;
        cr = cl + 1;
        child = (cr <= right && array[cr] && array[cr] > array[cl]) ?
                cr : cl;
        if (tmp >= array[child]) break;
        array[parent] = array[child];
    }
    array[parent] = tmp;
}

void Fsort(int array[], int n, int min, int max)
{
    int i;
    int *f, *b;

    f = NewArray(max - min + 1, int);
    b = NewArray(n, int);

    for (i = 0; i <= max-min; i++) f[i] = 0;                        // 0 초기화
    for (i = 0; i < n; i++) f[array[i]-min]++;                      // 분포
    for (i = 1; i <= max-min; i++) f[i] += f[i-1];                  // 누적합
    for (i = n - 1; i >= 0; i--) b[--f[array[i]-min]] = array[i];   // 누적수치가 자기 순서
    for (i = 0; i < n; i++) array[i] = b[i];                    // 본래 배열에 순서 복사

    FreeBlock(f);
    FreeBlock(b);
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

static void PrintArray(int array[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}