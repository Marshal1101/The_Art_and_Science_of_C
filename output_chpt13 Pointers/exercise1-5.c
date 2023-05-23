/**
 * @file exercise.c
 * @brief exercise chpt 13
 * @date 2023-05-23
 */
#include <stdio.h>
#include <stdlib.h>

#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "scanner.h"

static int globalCount;
static double globalArray[100];
static char *globalPointer;

void exe01(void);
void exe02(void);
void GetDate(int *dp, int *mp, int *yp);
static int MonthToInteger(string month);
void exe03(void);
void GetRealArray(double array[], int maxElements, double sentinel);
void GetMinMaxInArray(double *array, double *min, double *max);
void exe06(void);
int *IndexArray(int nElements);

int main()
{
    // exe01();
    // exe02();
    // exe03();
    exe06();
    return 0;
}

void exe01(void)
{
    int count;
    double array[100];
    char *cp;

    printf("addr = %lu\n", (long long)&globalCount);
    printf("addr = %lu\n", (long long)&globalArray);
    printf("addr = %lu\n", (long long)&globalPointer);
    printf("addr = %lu\n", (long long)&count);
    printf("addr = %lu\n", (long long)&array);
    printf("addr = %lu\n", (long long)&cp);
}

void exe02(void)
{
    int dp, mp, yp;
    GetDate(&dp, &mp, &yp);
    printf("Day = %d\nMonth = %d\nYear = %d\n", dp, mp, yp);
}

void GetDate(int *dp, int *mp, int *yp)
{
    string date, token;
    int num;

    printf("Enter a date as dd-mmm-yy: ");
    date = GetLine();
    InitScanner(date);
    ReturnOnlyWords(TRUE);
    *dp = StringToInteger(GetNextToken());
    token = GetNextToken();
    *mp = MonthToInteger(GetNextToken());
    token = GetNextToken();
    *yp = StringToInteger(GetNextToken());
}

static int MonthToInteger(string month)
{
    int i;
    string monthArr[13] = {
        "",
        "Jan",
        "Feb",
        "Mar",
        "Apr",
        "May",
        "Jun",
        "Jul",
        "Aug",
        "Sep",
        "Oct",
        "Nov",
        "Dec",
    };

    for (i = 1; i < 13; i++)
    {
        if (StringEqual(monthArr[i], month))
            return i;
    }

    return -1;
}

void exe03(void)
{
    double array[256], min, max;

    printf("Enter the elements of the array, one per line.\n");
    printf("Use -1 to signal the end of the list.\n");
    GetRealArray(array, 256, -1);
    GetMinMaxInArray(array, &min, &max);
    printf("The range of values is %g-%g", min, max);
}

void GetRealArray(double array[], int maxElements, double sentinel)
{
    double ans;
    int i;

    i = 0;
    while (i < maxElements)
    {
        printf("? ");
        ans = GetReal();
        array[i++] = ans;
        if (ans == sentinel)
            return;
    }
    Error("The number of elements exceeded.");
}

void GetMinMaxInArray(double *array, double *min, double *max)
{
    int i;
    double num;

    *min = *max = *array++;
    while (TRUE)
    {
        num = *array++;
        if (num == -1)
            break;
        if (num < *min)
            *min = num;
        if (num > *max)
            *max = num;
    }
}

void exe06(void)
{
    int *ip, i;

    ip = IndexArray(10);
    for (i = 0; i < 10; i++)
    {
        printf("%d ", ip[i]);
    }
}

int *IndexArray(int nElements)
{
    int *p, i;

    p = (int *)malloc(sizeof(int) * nElements);
    if (p == NULL)
        Error("Momeory Lick.");
    for (i = 0; i < nElements; i++)
    {
        *(p + i) = i;
    }
    return p;
}