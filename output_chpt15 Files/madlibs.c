/**
 * @file madlibs.c
 * @brief exercise 15-6
 * @date 2023-05-27
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "readfile.h"
#include "scanner.h"

#define InitialElements     5
#define Addrsize            8

static FILE *OpenUserFile(string prompt, string mode);
static string *FindMadlibs(string *read);
static string *ExtendCopyMalibs(string *madlibs, int size);
static string *MakeMadlibs(int size);
static void CopyMadlibs(string *newlib, string* oldlib, bool isPlusNULL);
static string CopyWord(string word);


int main()
{
    FILE *infile, *outfile;
    string *read, *madlibs, temp;

    
    printf("This program tests Madlibs.\n");
    infile = OpenUserFile("Input file: ", "r");         // hamlet.mad
    read = ReadFile(infile);
    if (read == NULL) Error("File is Empty");
    madlibs = FindMadlibs(read);
    if (madlibs == NULL) Error("Can't find madlibs");


    /* 단어 들어갈 거 물어보고 단어수집해서 임시파일에 쓰기 만들기(미구현) */


    temp = tmpnam(NULL);
    outfile = fopen(temp, "w");
    if (outfile == NULL) Error("Can't open temporary file");

    return 0;
}

static string *FindMadlibs(string *read)
{
    string *rP, *mP, *madlibs, *newlibs, line, word;
    char *cp, *bp, *wp;
    int currentSize, madCnt, wordlen;
    bool isBracket;

    madlibs = MakeMadlibs(InitialElements);
    currentSize = InitialElements;
    madCnt = 0;
    for (rP = read; *rP != NULL; rP++) {
        line = *rP;
        for (cp = line; *cp; cp++) {
            if (isBracket) {
                if (*cp == '>') {
                    isBracket = FALSE;\
                    if (madCnt == currentSize) {
                        newlibs = ExtendCopyMalibs(madlibs, 2 * currentSize);
                        FreeBlock(madlibs);
                        madlibs = newlibs;
                    }
                    word = (char *) GetBlock(wordlen + 1);
                    if (word == NULL) Error("FindMadlibs:word:memory error");
                    wp = word;
                    while (wordlen--) *wp++ = *bp++;
                    *wp = '\0';
                    madlibs[madCnt++] = word;
                    
                } else {
                    wordlen++;
                }

            } else {
                if (*cp == '<') {
                    isBracket = TRUE;
                    wordlen = 0;
                    bp = cp + 1;
                }
            }
        }
    }
    if (madCnt == 0) {
        FreeBlock(madlibs);
        return (NULL);
    }
    madlibs[madCnt] = NULL;
    newlibs = (string *) GetBlock((madCnt + 1) * Addrsize);
    CopyMadlibs(newlibs, madlibs, TRUE);
    FreeBlock(madlibs);
    return newlibs;
}

static FILE *OpenUserFile(string prompt, string mode)
{
    FILE *result;
    string filename;

    while (TRUE) {
        printf("%s", prompt);
        filename = GetLine();
        fopen(filename, mode);
        if (filename != NULL) break;
        printf("File %s not found -- try agian.\n", filename);
    }
    return result;
}

static string *ExtendCopyMalibs(string *madlibs, int size)
{
    string *newlibs;

    newlibs = MakeMadlibs(size);
    CopyMadlibs(newlibs, madlibs, FALSE);
    return newlibs;
}

static string *MakeMadlibs(int size)
{
    string *madlibs;

    madlibs = (string *) GetBlock((size + 1) * Addrsize);
    madlibs[size] = NULL;
    return madlibs;
}

static void CopyMadlibs(string *newlib, string* oldlib, bool isPlusNULL)
{
    string *nP, *oP;

    nP = newlib;
    for (oP = oldlib; *oP != NULL; oP++) {
        *nP++ = CopyWord(*oP);
    }
    if (isPlusNULL) *nP = NULL;
}

static string CopyWord(string word)
{
    string copy;
    char *cp, *wp;

    copy = (string) GetBlock(strlen(word) + 1);
    cp = copy;
    for (wp = word; *wp; wp++) {
        *cp++ = *wp;
    }
    *cp = '\0';
    return copy;
}