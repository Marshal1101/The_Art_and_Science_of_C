/**
 * @file revreadline.c
 * @brief exercise 15-5
 * @date 2023-05-26
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "readfile.h"

static FILE *OpenUserFile(string prompt, string mode);

int main()
{
    FILE *infile;
    string *read, *sp;
    int len;

    printf("This program tests to print reversed readline from a file at once.\n");
    infile = OpenUserFile("open file: ", "r");
    read = ReadFile(infile);
    sp = read;
    len = 0;
    while (*sp) {
        len++;
        sp++;
    }
    printf("lines: %d\n", len);
    while (len) printf("%d %s\n", len--, *--sp);
    fclose(infile);
    return 0;
}

static FILE *OpenUserFile(string prompt, string mode)
{
    string filename;
    FILE *result;

    while (TRUE) {
        printf("%s", prompt);
        filename = GetLine();
        result = fopen(filename, mode);
        if (result != NULL) break;
        printf("File \"%s\" not found -- try agian.\n", filename);
    }
    return result;
}