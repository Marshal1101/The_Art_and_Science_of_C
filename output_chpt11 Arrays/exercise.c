/**
 * @file exercise.c
 * @brief 
 * @date 2023-05-20
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "hist.h"

/**
 * Constants
 * ---------
 * MaxElements  -- Maximun number of elements
 * Sentinel     -- Value used to terminate input
 */
#define MaxElements 250
#define Sentinel     -1    

void exe01(void);
void exe02(void);
void exe06(void);
void exe07(void);
static int GetIntegerArray(int array[], int max, int sentinel);
static void GiveInstrucitons(void);
// static void PrintHistogram(int array[], int n);
// static string StrStar(int num);
void exe08(void);

int main()
{
    // exe01();
    // exe02();
    // exe05();
    // exe07();
    exe08();

    return 0;
}

void exe01(void)
{
    printf("Values of type char require %I64d byte.\n", sizeof(char));
    printf("Values of type int require %I64d byte.\n", sizeof(int));
    printf("Values of type short require %I64d byte.\n", sizeof(short));
    printf("Values of type long require %I64d byte.\n", sizeof(long));
    printf("Values of type float require %I64d byte.\n", sizeof(float));
    printf("Values of type double require %I64d byte.\n", sizeof(double));
}

void exe02(void)
{
    int i;
    double maxp, minp, total;
    double arr[7];

    printf("Inputs seven judges' each valuation.\n");
    i = 1;
    while (i < 8) {
        printf("#%d? ", i);
        arr[i++] = GetReal();
    }
    total = 0.0;
    maxp = arr[0];
    minp = arr[0];
    for (i = 0; i < 7; i++) {
        total += arr[i];
        if (arr[i] > maxp) maxp = arr[i];
        if (arr[i] < minp) minp = arr[i];
    }
    printf("the mean point is %g\n", (total - maxp - minp) / 5.0);
}

void exe06(void)
{
    int i, j, pcnt;
    int numArr[101];
    
    for (i = 0; i < 101; i++) numArr[i] = i;
    numArr[0] = numArr[1] = 0;
    for (i = 2; i < 101; i++) {
        if (numArr[i] != 0) {
            for (j = i+1; j < 101; j++) {
                if (j % i == 0) {
                    numArr[j] = 0;
                }
            }
        }
    }

    for (i = 0; i < 101; i++) {
        if (numArr[i] != 0) pcnt++;
    }

    int primeArr[pcnt];
    j = 0;
    for (i = 2; i < 101; i++) {
        if (numArr[i] != 0) primeArr[j++] = numArr[i];
    }
    for (j = 0; j < pcnt; j++) {
        printf("%d ", primeArr[j]);
    }
}

void exe07(void)
{
    int list[MaxElements], n;

    GiveInstrucitons();
    n = GetIntegerArray(list, MaxElements, Sentinel);
    PrintHistogram(list, n);
}

static int GetIntegerArray(int array[], int max, int sentinel)
{
    int n, value;

    n = 0;
    while (TRUE) {
        printf("point(0~100) ? ");
        value = GetInteger();
        if (value == sentinel) break;
        if (value < 0 || value > 100) {
            printf("point is 0~100.\n");
            continue;
        }
        if (n == max) Error("Too many input items for array");
        array[n] = value;
        n++; 
    }
    return (n);
}

static void GiveInstrucitons(void)
{
    printf("Enter numbers, one per line, ending with the\n");
    printf("sentinel value %d. The program will then\n", Sentinel);
    printf("display those values in reverse order.\n");
}

// static void PrintHistogram(int array[], int n)
// {
//     int i;
//     int historamArr[11] = {0, };
//     string axis[11] = {
//         "0-9", "10-19", "20-29", "30-39", "40-49", "50-59",
//         "60-69", "70-79", "80-89", "90-99", "100",
//     };

//     for (i = 0; i < n; i++) {
//         historamArr[array[i]/10] += 1;
//     }
//     for (i = 0; i < 11; i++) {
//         printf("%-5s|%s\n", axis[i], StrStar(historamArr[i]));
//     }
// }

// static string StrStar(int num)
// {
//     int i;
//     string ret = "";

//     for (i = 0; i < num; i++) ret = Concat(ret, "*");
//     return ret;
// }

void exe08(void)
{
    int list[MaxElements], n;

    GiveInstrucitons();
    n = GetIntegerArray(list, MaxElements, Sentinel);
    SetHistMax(90);
    SetHistMin(10);
    SetHistRange(4);
    PrintHistogram(list, n);
}