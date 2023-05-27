/**
 * @file greek.c
 * @brief exercise 15-2
 * @date 2023-05-26
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "genlib.h"
#include "simpio.h"
#include "random.h"

static string GetGreekFromLine(string line);
static char RandomAlpha(char ch);

int main()
{
    string filename, line;
    FILE *infile;
    
    printf("It's all Greek to me. - Julius Caesar\n");
    printf("This program makes a random paper from a file.\n");
    while (TRUE) {
        printf("Enter a filename: ");
        filename = GetLine();                   // troilus.dat
        infile = fopen(filename, "r");
        if (infile != NULL) break;
        printf("File %s not found -- try agian.\n", filename);
    }
    // Randomize();
    while ((line = ReadLine(infile)) != NULL) {
        printf("%s\n", GetGreekFromLine(line));
    }
    fclose(infile);
    return 0;
}

static string GetGreekFromLine(string line)
{
    char *cp, *ret, *rp;
    int len;

    len = strlen(line);
    ret = (char *) malloc(len + 1);
    if (ret == NULL) Error("GetGreekFromLine:rp:memory error");
    rp = ret;
    for (cp = line; *cp; cp++) {
        if (isalpha(*cp)) *rp++ = RandomAlpha(*cp);
        else *rp++ = *cp;
    }
    *rp = '\0';
    return ret;
}

static char RandomAlpha(char ch)
{
    int d;

    d = RandomInteger(0, 25);
    if (isupper(ch)) {
        return ((ch - 'A' + d) % 26) + 'A';
    } else {
        return ((ch - 'a' + d) % 26) + 'a';
    }
}