/**
 * @file wc.c
 * @brief exercise 15-1
 * @date 2023-05-26
 * wc.c reads a file and report how many lines, words,
 * and character appear in it. For the purposes of
 * this program, a word consists of a consecutive sequence
 * of any characters except white-space characters. 
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "genlib.h"
#include "simpio.h"


static int CountWordInLine(string line);
static int CountCharInLine(string line);

int main()
{
    string filename, line;
    FILE *infile;
    int ch, lineCnt, wordCnt, charCnt, tmp1, tmp2;
    bool isWord;

    printf("This program tests file wc.c\n");
    while (TRUE) {
        printf("enter a filename: ");
        filename = GetLine();                   // lear.txt
        infile = fopen(filename, "r");
        if (infile != NULL) break;
        printf("File %s not found -- try agian.\n", filename);
    }
    lineCnt = 0;
    wordCnt = charCnt = 0;
    isWord = FALSE;
    while ((line = ReadLine(infile)) != NULL) {
        // charCnt += CountCharInLine(line);
        // wordCnt += CountWordInLine(line);
        tmp2 = CountWordInLine(line);
        wordCnt += tmp2;
        tmp1 = CountCharInLine(line);
        charCnt += tmp1;
        lineCnt++;
        printf("%s\n", line);
        printf("line %d: %d words, %d chars\n", lineCnt, tmp2, tmp1);
    }
    fclose(infile);
    printf("File: %s\n", filename);
    printf("Lines: %5d\n", lineCnt);
    printf("Words: %5d\n", wordCnt);
    printf("Chars: %5d\n", charCnt);

    return 0;
}

static int CountWordInLine(string line)
{
    int count;
    char *cp;
    bool isWord;

    count = 0;
    isWord = FALSE;
    for (cp = line; *cp; cp++) {
        if (isWord) {
            if (isspace(*cp) || (*cp ==',')) {
                isWord = FALSE;
            }
        } else {
            if (isalnum(*cp)) {
                isWord = TRUE;
                count++;
            }
        }
    }
    return count;
}

static int CountCharInLine(string line)
{
    return strlen(line);
}