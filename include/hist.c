#include <stdio.h>
#include "genlib.h"
#include "strlib.h"
#include "hist.h"

/* Static Values */
static int Max = 100;
static int Min = 0;
static int Range = 10;

/* Static Functions */
static string StrStar(int num);

/* Prototyple Functions */
void PrintHistogram(int array[], int n);
void SetHistMin(int min);
void SetHistMax(int max);
void SetHistRange(int range);

/**
 * @brief 
 * @param array 
 * @param n 
 */
void PrintHistogram(int array[], int n)
{
    string tail;
    int i, hn;
    
    hn = (Max - Min) / Range + 1;
    
    int histArr[hn];
    string axis[hn];

    for (i = 0; i < hn; i++ ) {
        if ((i+1)*Range-1 == Max) tail = "";
        else if ((i+1)*Range-1 > Max) tail = Concat("-", IntegerToString(Max));
        else tail = Concat("-", IntegerToString(Min + (i+1)*Range-1));
        axis[i] = Concat(IntegerToString(Min + i*Range), tail);
    }

    for (i = 0; i < hn; i++) histArr[i] = 0;
    for (i = 0; i < n; i++) histArr[array[i]/Range]++;
    for (i = 0; i < hn; i++) {
        printf("%-9s|%s\n", axis[i], StrStar(histArr[i]));
    }
}

static string StrStar(int num)
{
    int i;
    string ret = "";

    for (i = 0; i < num; i++) ret = Concat(ret, "*");
    return ret;
}

/**
 * @brief Set the Hist Min object
 * @param min 
 */
void SetHistMin(int min)
{
    Min = min;
}

/**
 * @brief Set the Hist Max object
 * @param max 
 */
void SetHistMax(int max)
{
    Max = max;
}

/**
 * @brief Set the Hist Range object
 * @param range 
 */
void SetHistRange(int range)
{
    Range = range;
}