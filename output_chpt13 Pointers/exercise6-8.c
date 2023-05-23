/**
 * @file exercise6-8.c
 * @brief chpt 13-6 ~ 13-8
 * @date 2023-05-23
 */

#include <stdio.h>
#include <stdlib.h>

#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "random.h"
#include "myalloc.h"
#include "scanner.h"

void exe06(void);
void Tabulate(int *array, int n);
void RandomIntegerArray(int array[], int n, int low, int high);
void PrintArray(int array[], int nElements);
void exe07(void);
void exe08(void);
int TypeToBytes(string type);

int main()
{
    // exe06();
    // exe07();
    exe08();
    return 0;
}

void exe06(void)
{
    int nElements = 13;
    int arr[nElements];

    printf("This program tests Tabulate Fuction.\n");
    Randomize();
    SetInhancedRandom(TRUE);
    RandomIntegerArray(arr, nElements, 1, 100);
    // PrintArray(arr, nElements);
    Tabulate(arr, nElements);
}

void Tabulate(int *array, int n)
{
    int i, min, max, nElements, *p;

    min = max = array[0];
    for (i = 1; i < n; i++)
    {
        if (min > array[i])
            min = array[i];
        if (max < array[i])
            max = array[i];
    }
    nElements = max - min + 1;
    // printf("min: %d, max: %d, nElements: %d\n", min, max, nElements);
    p = (int *)malloc(sizeof(int) * nElements);
    if (p == NULL)
        Error("memory error!");
    for (i = 0; i < nElements; i++)
        p[i] = 0;
    for (i = 0; i < n; i++)
    {
        p[array[i] - min] += 1;
    }

    for (i = 0; i < nElements; i++)
    {
        if (p[i] != 0)
            printf("%d: %d\n", i + min, p[i]);
    }
}

void RandomIntegerArray(int array[], int n, int low, int high)
{
    int i;

    for (i = 0; i < n; i++)
    {
        array[i] = RandomInteger(low, high);
    }
}

void PrintArray(int array[], int nElements)
{
    int i;

    // printf("=========array========\n");
    for (i = 0; i < nElements; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void exe07(void)
{
    int *p, *k, i;

    printf("This Program tests MyGetBlock in malloc.h\n");
    p = (int *)MyGetBlock(sizeof(int) * 10);
    for (i = 0; i < 10; i++)
    {
        p[i] = i;
        printf("p[i]: %d, addr: %lu\n", p[i], (long long)&p[i]);
    }
    k = (int *)MyGetBlock(sizeof(int) * 5);
    for (i = 0; i < 5; i++)
    {
        k[i] = i;
        printf("k[i]: %d, addr: %lu\n", k[i], (long long)&k[i]);
    }
}

void exe08(void)
{
    string line, token, type, var;
    int tsize, elem;
    bool isPtr, isArr;

    elem = 1;
    isPtr = isArr = FALSE;
    printf("Enter variable declarations, ending with a blank line.\n");
    while (TRUE) {
        line = GetLine();
        if (StringEqual(line, "")) return;
        InitScanner(line);
        ReturnOnlyWords(TRUE);
        type = GetNextToken();
        tsize = TypeToBytes(type);
        while (!AtEndOfLine()) {
            token = GetNextToken();
            // printf("token: %s\n", token);
            if (StringEqual(token, ",") || StringEqual(token, ";")) {
                if (isPtr) {
                    printf("%s requires %I64d bytes\n", var, sizeof(char *));
                } else if (isArr) {
                    printf("%s requires %d bytes\n", var, elem, tsize * elem);
                } else {
                    printf("%s requires %d bytes\n", var, tsize);
                }
                if (StringEqual(token, ";")) break;
                isPtr = isArr = FALSE;
            }
            else if (StringEqual(token, "*")) isPtr = TRUE;
            else if (StringEqual(token, "[") || StringEqual(token, "]")) isArr = TRUE;
            else {
                if (isArr) elem = StringToInteger(token);
                else var = token;
            }
        }
    }
}

int TypeToBytes(string type)
{
    int i, idx;
    string ref[6] = {
        "char", "int", "short", "long", "float", "double"
    };
    
    for (i = 0; i < 6; i++) {
        if (StringEqual(ref[i], type)) idx = i;
    }
    switch (idx)
    {
    case 0: return (sizeof(char));
    case 1: return (sizeof(int));
    case 2: return (sizeof(short));
    case 3: return (sizeof(long));
    case 4: return (sizeof(float));
    case 5: return (sizeof(double));
    default:
        Error("wrong type in TypeToBytes");
        break;
    }
}