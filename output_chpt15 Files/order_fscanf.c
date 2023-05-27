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


#define MaxElementProdName      20
#define MaxElementProdNumber    6

static FILE *OpenUserFile(string prompt, string mode);


int main()
{
    FILE *infile;
    char elementProdNumber[MaxElementProdNumber + 1];
    char elementProdName[MaxElementProdName + 1];
    char atch;
    char termch;
    double cost, total;
    int nscan, ea;

    infile = OpenUserFile("Order file : ", "r");
    total = 0.0;
    while (TRUE) {
        nscan = fscanf(infile, "%6s %20[^/] / %d %c %lf%c",
                        elementProdNumber, elementProdName, &ea, &atch, &cost, &termch);
        // printf("%s -- %s -- %d -- %c -- %.2lf -- %c", elementProdNumber, elementProdName, ea, atch, cost, termch);
        if (nscan == EOF) break;
        if (nscan != 6 || termch != '\n') Error("Improper file format");
        total += ea * cost;
        printf("%6d  %-20s  %3d  %c  %7.2lf  =  %7.2lf\n", elementProdNumber, elementProdName, ea, atch, cost, ea * cost);
    };
    printf("-----------------------------------------------------------\n");
    printf("TOTAL                                              %7.2lf\n", total);
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