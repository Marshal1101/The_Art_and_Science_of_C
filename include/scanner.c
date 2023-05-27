/**
 * @file scanner.c
 * @brief This file implements the scanner.h interface.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "genlib.h"
// #include "strlib.h"
#include "scanner.h"

/**
 * Private variables
 * -----------------
 * buffer   -- Private copy of the string passed to InitScanner
 * buflen   -- Length of the buffer, saved for efficiency
 * cpos     -- Current character position in the buffer
 */

static string buffer;
static int buflen;
static int cpos;
static bool uppercaseFlag;
static bool lowercaseFlag;
static bool onlywordFlag;
static bool withoutSpaceFlag;

/**
 * Private funtions
 * ----------------
 * returns a string with UpperCase
 */
static char *ConvertToUpperCase(char *s);
static char *ConvertToLowerCase(char *s);
static char *SubString(char *s, int p1, int p2);

/**
 * Function: InitScanner
 * ---------------------
 * All this function has to do is initialize the private
 * variables used in the package.
 */
void InitScanner(string line)
{
    buffer = line;
    buflen = strlen(line);
    cpos = 0;
    uppercaseFlag = FALSE;
    lowercaseFlag = FALSE;
    onlywordFlag = FALSE;
    withoutSpaceFlag = FALSE;
}

/*
* Function: GetNextToken
* ---------------------------------
* The implementation of GetNextToken follows its behavioral
* description as given in the interface: if the next character
* is alphanumeric (i.e., a letter or digit), the function
* searches to find an unbroken string of such characters and 
* returns the entire string. If the current character is not
* a letter or digit, a one-character string containing that 
* character is returned.
*/
string GetNextToken(void)
{
    char ch, *rp;
    int start, rpos;

    if (cpos >= buflen) Error("No more tokens");
    if (onlywordFlag) while (cpos < buflen && !isalnum(*(buffer + cpos))) cpos++;
    if (withoutSpaceFlag) while (cpos < buflen && isspace(*(buffer + cpos))) cpos++;
    ch = *(buffer + cpos);
    if (!isalnum(ch)) {
        cpos++;
        rp = (char *) malloc(2);
        *rp = ch;
        *(rp + 1) = '\0';
        return rp;
    } else {
        start = cpos;
        if (withoutSpaceFlag) {
            while (cpos < buflen && !isspace(*(buffer + cpos))) {
                cpos++;
            }
        } else {
            while (cpos < buflen && isalnum(*(buffer + cpos))) {
                cpos++;
            }
        }
        rpos = cpos - 1;
        if (onlywordFlag) while (cpos < buflen && !isalnum(*(buffer + cpos))) cpos++;
        if (withoutSpaceFlag) while (cpos < buflen && isspace(*(buffer + cpos))) cpos++;
        return (
            uppercaseFlag ?
            ConvertToUpperCase(SubString(buffer, start, rpos))
            : (lowercaseFlag ?
            ConvertToLowerCase(SubString(buffer, start, rpos))
            : SubString(buffer, start, rpos))
        );
    }
}



/*
* Function: AtEndOfLine
* ------------------------------
* This implementation compares the current buffer position
* against the saved length.
*/
bool AtEndOfLine (void)
{
    return (cpos >= buflen);
}

/**
 * Function: ReturnUppercaseTokens
 * ----------------------------------
 * this function controls uppercaseFlag for GetNextToken
 * to return uppercase tokens.
 */
void ReturnUppercaseTokens(bool flag)
{
    uppercaseFlag = flag;
}

/**
 * Function: ReturnLowercaseTokens
 * ----------------------------------
 * this function controls LowercaseFlag for GetNextToken
 * to return Lowercase tokens.
 */
void ReturnLowercaseTokens(bool flag)
{
    lowercaseFlag = flag;
}

/**
 * Function: ReturnOnlyWords
 * ----------------------------
 * this function controls onlywordFlag for GetNextToken
 * to return only words with alphabets and numbers.
 */
void ReturnOnlyWords(bool flag)
{
    onlywordFlag = flag;
    withoutSpaceFlag = !flag;
}

/**
 * Function: ReturnWithoutSpace
 * ----------------------------
 * this function controls onlywordFlag for GetNextToken
 * to return words except for spaces.
 */
void ReturnWithoutSpace(bool flag)
{
    withoutSpaceFlag = flag;
    onlywordFlag = !flag;
}



static char *ConvertToUpperCase(char *s)
{
    int i, len;
    char *cp, *rp;

    len = strlen(s);
    rp = (char *) malloc(len + 1);
    if (rp == NULL) Error("ConvertToUpperCase memery error.");
    i = 0;
    for (cp = s; *cp; cp++) {
        if (isalpha(*cp)) {
            *(rp + i++) = toupper(*cp);
        }
        else {
            *(rp + i++) = *cp;
        }
    }
    *(rp + i) = '\0';
    return rp;
}

static char *ConvertToLowerCase(char *s)
{
    int i, len;
    char *cp, *rp;

    len = strlen(s);
    rp = (char *) malloc(len + 1);
    if (rp == NULL) Error("ConvertToLowerCase memery error.");
    i = 0;
    for (cp = s; *cp; cp++) {
        if (isalpha(*cp)) {
            *(rp + i++) = tolower(*cp);
        }
        else {
            *(rp + i++) = *cp;
        }
    }
    *(rp + i) = '\0';
    return rp;
}

static char *SubString(char *s, int p1, int p2)
{
    char *rp;
    int i, len;

    len = strlen(s);
    if (p1 < 0) p1 = 0;
    if (p2 > len - 1) p2 = len - 1;
    if (p1 > p2) {
        rp = (char *) malloc(1);
        if (rp == NULL) Error("SubString memery error.");
        *rp = '\0';
        return rp;
    }
    rp = (char *) malloc(p2 - p1 + 2);
    if (rp == NULL) Error("SubString memery error.");
    for (i = 0; i <= p2 - p1; i++) {
        *(rp + i) = *(s + p1 + i);
    }
    *(rp + i) = '\0';
    return rp;
}