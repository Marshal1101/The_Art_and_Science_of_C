/**
 * @file madlibs_simple.c
 * @brief exercise 15-6
 * @date 2023-05-27
 */

#include <stdio.h>
#include <string.h>
#include "genlib.h"
#include "simpio.h"


static FILE *OpenUserFile(string prompt, string mode);
static string CopyWord(char buffer[], int n);
static string AskMadlibWord(string madkey);
static void WriteWord(string word, FILE *outfile);

int main()
{
    FILE *infile, *outfile;
    string temp, madkey, ans;
    char buffer[101];
    int n, ch;
    bool isMadlib;

    infile = OpenUserFile("Input file: ", "r");         // hamlet.mad
    temp = tmpnam(NULL);
    outfile = fopen(temp, "w");
    if (outfile == NULL) Error("Can't open temporary file");
    isMadlib = FALSE;
    while ((ch = getc(infile)) != EOF) {
        if (isMadlib) {
            if (ch == '>') {
                buffer[n] = '\0';
                madkey = CopyWord(buffer, n);
                ans = AskMadlibWord(madkey);
                WriteWord(ans, outfile);
                isMadlib = FALSE;
            } else {
                buffer[n++] = ch;
            }
        } else {
            if (ch == '<') {
                n = 0;
                isMadlib = TRUE;
            } else {
                putc(ch, outfile);
            }
        }
    }
    fclose(infile);
    fclose(outfile);
    infile = fopen(temp, "r");
    while ((ch = getc(infile)) != EOF) {
        putchar(ch);
    }

    return 0;
}

static string AskMadlibWord(string madkey) {
    printf("    %s: ", madkey);
    return GetLine();
}

static void WriteWord(string word, FILE *outfile)
{
    char *ch;

    ch = word;
    while (*ch) putc(*ch++, outfile);
}

static string CopyWord(char buffer[], int n)
{
    char *cp, *bp;
    string copy;

    copy = (char *) GetBlock(n + 1);
    if (copy == NULL) Error("CopyWord:copy:memory error");
    cp = copy;
    for (bp = buffer; *bp; bp++) {
        *cp++ = *bp;
    }
    *cp = '\0';
    return copy;
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