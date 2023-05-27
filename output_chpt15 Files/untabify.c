/**
 * @file untabify.c
 * @brief exercise 15-3
 * @date 2023-05-26
 */

#include <stdio.h>
#include <string.h>

#include "genlib.h"
#include "simpio.h"

static char *GetUntabifiedLine(char *line, int tabsize);

int main()
{
    string filename, line;
    FILE *infile;
    int tabsize;

    tabsize = 8;
    printf("This program tests untabify.c\n");
    while (TRUE) {
        printf("filename: ");
        filename = GetLine();               // tabtest.txt
        infile = fopen(filename, "r");
        if (infile != NULL) break;
        printf("File %s not found -- try agian.\n", filename);
    }

    while ((line = ReadLine(infile)) != NULL) {
        printf("%s\n", GetUntabifiedLine(line, tabsize));
    }
    fclose(infile);
    return 0;
}

static char *GetUntabifiedLine(char *line, int tabsize)
{
    char *cp, *rp, *ret;
    int tabcount, n, pad;

    tabcount = 0;
    for (cp = line; *cp; cp++) {
        if (*cp == '\t') tabcount++;
    }
    ret = (char *) malloc(strlen(line) - tabcount + (tabcount * tabsize) + 1);
    if (ret == NULL) Error("GetUntabifiedLine:rp:memory error");
    n = 0;
    rp = ret;
    for (cp = line; *cp; cp++) {
        if (*cp == '\t') {
            pad = (tabsize - (n % tabsize));
            n += pad;
            while (pad-- > 0) {
                *rp++ = ' ';
            }
        } else {
            *rp++ = *cp;
            n++;
        }
    }
    *rp = '\0';
    return ret;
}