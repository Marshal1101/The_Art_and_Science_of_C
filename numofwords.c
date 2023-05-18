/**
 * @file numofwords.c
 * @brief exercise 10-5
 *  Write a program that counts the number of words in input text entered by the user. 
 * The input may consits of serveral lines, with the end of the data indicated by a blank 
 * Enter a line: this is pig latin.
 * isThay isway igPay atinLay.
 * Enter a line: this is pig latin.
 * Isthay Isway Igpay Atinlay.
 * This program counts the number of words in a paragraph.
 * End the praragraph with a blank line.
 * We hold these truths to be self-evident, that all
 * men and women are created equal.
 * -- seneca Falls Declaration, 1848
 * 
 * Number of words: 19
 * line. A word should be counted only if it consists entirely of letters. One possible 
 * sample run of the program is
 */

#include <stdio.h>
#include <ctype.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "scanner.h"

static bool IsLegalWord(string token);

int main()
{
    string line, token;
    int count;

    printf("This program counts the number of wors in a paragraph.\n");
    printf("End the paragraph with a blank line.\n");
    count = 0;
    while (TRUE) {
        line = GetLine();
        if (StringEqual(line, "")) break;
        InitScanner(line);
        while (!AtEndOfLine()) {
            token = GetNextToken();
            if (IsLegalWord(token)) count++;
        }
    }
    printf("Number of words: %d\n", count);
    return 0;
}

static bool IsLegalWord(string token)
{
    int i;
    for (i = 0; i < StringLength(token); i++) {
        if (!isalnum(IthChar(token, i))) return (FALSE);
    }
    return (TRUE);
}