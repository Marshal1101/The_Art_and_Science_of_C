/**
 * @file readfile.c
 * @brief reads a file to get a line unit every call
 * @date 2023-05-26
 */

#include <stdio.h>
#include <string.h>

#include "genlib.h"
#include "readfile.h"

/* Constants */
#define InititalElementSize           4
#define Addrsize                      8
#define InitialBufferSize           120

/* Private Variables */
static string *buffer;
static int buflen;
static int spos;

/* Private Funcions */
static string Readline(FILE *infile);
static string CopyLine(string line);

int GetTotalLineCnt(void)
{
    return buflen;
}

bool AtEndOfFile(void)
{
    return (spos >= buflen);
}

string GetNextLine(void)
{
    if (spos >= buflen) Error("No more Lines");
    return CopyLine(buffer[spos++]);
}


string *ReadFile(FILE *infile) {
    string line, *arr, *narr, *sp, *nsp;
    int n, size, i;
    // printf("=====1=========\n");
    arr = (string *) GetBlock((InititalElementSize + 1) * Addrsize);
    arr[InititalElementSize] = NULL;
    size = InititalElementSize;
    n = 0;
    // printf("=====2 arr: %d\n", arr);
    while ((line = Readline(infile)) != NULL) {
        if (n == size) {
            // printf("%d ======size up=====\n", n);
            size *= 2;
            narr = (string *) GetBlock((size + 1) * Addrsize);
            narr[size] = NULL;
            nsp = narr;
            for (sp = arr; *sp != NULL; sp++) {
                *nsp++ = CopyLine(*sp);
            }
            FreeBlock(arr);
            arr = narr;
        }
        // printf("%d: %s\n", n, line);
        arr[n++] = line;
    }
    if (n == 0 && line == NULL) {
        FreeBlock(arr);
        return (NULL);
    }
    arr[n] = NULL;
    // printf("=====3 &arr[n]: %d, arr[n]: %d\n", &arr[n], arr[n]);
    narr = (string *) GetBlock((n + 1) * Addrsize);
    // printf("=====4 n: %d, narr: %d\n", n, narr);
    nsp = narr;
    // printf("=====5 nsp: %d\n", nsp);
    for (sp = arr; *sp != NULL; sp++) {
        *nsp++ = CopyLine(*sp);
    }
    *nsp = NULL;
    // printf("=====6 nsp: %d\n", nsp);
    FreeBlock(arr);
    // printf("=====9============\n");
    buffer = narr;
    buflen = n;
    return narr;
}

static string Readline(FILE *infile)
{
    string line, nline;
    int n, ch, size;

    n = 0;
    size = InitialBufferSize;
    line = GetBlock(size + 1);
    while ((ch = getc(infile)) != '\n' && ch != EOF) {
        if (n == size) {
            size *= 2;
            nline = (string) GetBlock(size + 1);
            strncpy(nline, line, n);
            FreeBlock(line);
            line = nline;
        }
        line[n++] = ch;
    }
    if (n == 0 && ch == EOF) {
        FreeBlock(line);
        return (NULL);
    }
    line[n] = '\0';
    nline = (string) GetBlock(n + 1);
    strcpy(nline, line);
    FreeBlock(line);
    return (nline);
}

static string CopyLine(string line)
{
    string copy;
    char *cp;

    copy = (string) GetBlock(strlen(line) + 1);
    cp = copy;
    while (*line) *cp++ = *line++;
    *cp = '\0';
    return copy;
}