/**
 * @file order.c
 * @brief exercise 15-8
 * @date 2023-05-27
 */


#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "readfile.h"
#include "scanner.h"


#define AddrSize        8

static FILE *OpenUserFile(string prompt, string mode);


int main()
{
    FILE *infile;
    string line, token;
    string *model, *product;
    int *ea, *cost;
    int maxElements, n, colmn;

    infile = OpenUserFile("Order file : ", "r");
    ReadFile(infile);
    maxElements = GetTotalLineCnt();
    model = GetBlock((maxElements + 1) * AddrSize);
    product = GetBlock((maxElements + 1) * AddrSize);
    ea =  GetBlock((maxElements + 1) * sizeof(int));
    cost =  GetBlock((maxElements + 1) * sizeof(int));
    n = 0;
    while (!AtEndOfFile()) {
        line = GetNextLine();
        
        /* 각 라인에 담긴 자료를 각 배열에 배정한다 */
    }
    return 0;
}

static FILE *OpenUserFile(string prompt, string mode)
{
    FILE *result;
    string filename;

    while (TRUE) {
        printf("%s", prompt);
        filename = GetLine();
        result = fopen(filename, mode);
        if (result != NULL) break;
        printf("File %s not found -- try again.\n", filename);
    }
    return result;
}