/**
 * @file countword.c
 * @brief exercise 15-7
 * @date 2023-05-27
 */

#include <stdio.h>
#include <string.h>
#include "genlib.h"
#include "simpio.h"
#include "readfile.h"
#include "scanner.h"
#include "sort.h"

#define InitialElements        12
#define AddrSize                8

static FILE *OpenUserFile(string prompt, string mode);
static int FindWordInArray(string *array, int n, string word);
static string CopyString(string str);
static void PrintTable(string wordKey[], int wordCnt[], int n);


int main()
{
    FILE *infile;
    string *read, *rsp, *strBuffer, *wordKey, *nsp;
    string token;
    int *wordCnt;
    int n, i;

    infile = OpenUserFile("Input file: ", "r");         // malvolio.txt
    read = ReadFile(infile);
    strBuffer = (string *) GetBlock((InitialElements + 1) * AddrSize);
    strBuffer[InitialElements] = NULL;
    n = 0;
    // printf("=========1============\n");
    for (rsp = read; *rsp != NULL; rsp++) {
        InitScanner(CopyString(*rsp));
        ReturnOnlyWords(TRUE);
        ReturnLowercaseTokens(TRUE);
        while (!AtEndOfLine()) {
            token = GetNextToken();
            // printf("%s\n", token);
            i = FindWordInArray(strBuffer, n, token);
            if (i == -1) {
                strBuffer[n++] = token;
            }
        }
    }
    // printf("=========2============\n");
    strBuffer[n] = NULL;
    wordKey = (string *) GetBlock((n + 1) * AddrSize);
    nsp = wordKey;
    for (rsp = strBuffer; *rsp != NULL; rsp++) {
        *nsp++ = CopyString(*rsp);
    }
    *nsp = NULL;
    // printf("=========3============\n");
    // for (i = 0; i < n; i++) {
    //     printf("%d %s\n", i, wordKey[i]);
    // }
    FreeBlock(strBuffer);
    Alphabetize(wordKey, n);
    // printf("=========4============\n");
    // for (i = 0; i < n; i++) {
    //     printf("%d %s\n", i, wordKey[i]);
    // }
    // printf("=========5 n: %d============\n", n);
    wordCnt = (int *) GetBlock((n + 1) * sizeof(int));
    for (i = 0; i < n; i++) wordCnt[i] = 0;
    for (rsp = read; *rsp != NULL; rsp++) {
        InitScanner(CopyString(*rsp));
        ReturnOnlyWords(TRUE);
        ReturnLowercaseTokens(TRUE);
        while (!AtEndOfLine()) {
            token = GetNextToken();
            i = FindWordInArray(wordKey, n, token);
            // printf("%s %d\n", token, i);
            wordCnt[i]++;
        }
    }

    // printf("=========6============\n");
    PrintTable(wordKey, wordCnt, n);
    // printf("=========7============\n");
    return 0;
}

static void PrintTable(string wordKey[], int wordCnt[], int n)
{
    int i;

    printf("Word frequency table:\n");
    for (i = 0; i < n; i++) {
        printf("%-15s%d\n", wordKey[i], wordCnt[i]);
    }
}


static string CopyString(string word) {
    string copy;
    char *wp, *cp;

    copy = (string) GetBlock(strlen(word) + 1);
    cp = copy;
    for (wp = word; *wp; wp++) {
        *cp++ = *wp;
    }
    *cp = '\0';
    return copy;
}


static int FindWordInArray(string *array, int n, string word)
{
    int i;

    for (i = 0; i < n; i++) {
        if (!strcmp(array[i], word)) {
            return i;
        }
    }
    return -1;
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
        printf("File %s not found -- try agian.\n", filename);
    }
    return result;
}