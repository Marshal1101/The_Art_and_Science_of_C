/**
 * file: fill.c
 */

#include <stdio.h>

#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "scanner.h"

static int width;

/*
* Function: SetFillMargin
* -----------------------------------------
* SetFillMargin controls static int width.
*/
void SetFillMargin(int margin)
{
    width = margin;
}


/*
* Funciton: PrintFilledString
* ---------------------------------------
* The string str is displayed on the screen, starting from 
* where the last string left off. Spaces and newline characters 
* in the strin are treated specially. If a space character
* appears in an argument, the function may choose to divide 
* the string at that point by moving to the next line.
* Such division occurs when the next word would not fit
* within the margin established by SetFillMargin. A newline 
* character in the string froces the cursor to advance to the
* beginning of the next line.
*/
void PrintFilledString(string str)
{
    string token;
    int len, length;

    length = 0;
    InitScanner(str);
    while (!AtEndOfLine()) {
        token = GetNextToken();
        len = StringLength(token);
        if (length == 0 && StringEqual(token, " ")) {
            continue;
        } else if (length + len < width) {
            printf("%s", token);
            length += len;
        } else if (length + len == width) {
            printf("%s", token);
            printf("\n");
            length = 0;
        } else {
            printf("\n");
            printf("%s", token);
            length = len;
        }
    }
}