/**
 * @file underscore.c
 * @brief exercise 15-4
 * @date 2023-05-26
 */


#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "genlib.h"
#include "simpio.h"


static FILE *OpenUserFile(string prompt, string mode);
static void CopyFileWithUnderscore(FILE *infile, FILE *outfile);


int main()
{
    string filename, paper, npaper;
    FILE *infile, *outfile;
    int n, ch, size;


    printf("This program tests to export a file with printing underscore.\n");
    infile = OpenUserFile("import file: ", "r");        // undertest.txt
    outfile = OpenUserFile("export file: ", "w");       // out_undertest.txt
    CopyFileWithUnderscore(infile, outfile);
    fclose(infile);
    fclose(outfile);
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

static void CopyFileWithUnderscore(FILE *infile, FILE *outfile)
{
    int ch, nch;
    bool underFlag;

    underFlag = FALSE;
    while ((ch = getc(infile)) != EOF) {
        if (underFlag) {
            if (ch == '*') {
                underFlag = FALSE;
            } else {
                if (ch != '\n') {
                    putc('_', outfile);
                    putc('\b', outfile);
                }
                putc(ch, outfile);
            }
        } else {
            if (ch == '*') {
                nch = getc(infile);
                if (isspace(nch)) {
                    putc(ch, outfile);
                    putc(nch, outfile);
                } else {
                    ungetc(nch, infile);
                    underFlag = TRUE;
                }
            } else {
                putc(ch, outfile);
            }
        }
    }
}