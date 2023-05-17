/**
 * @file repfirst.c
 * @brief This file implements and tests the function ReplaceFirst.
 */

#include <stdio.h>
#include "genlib.h"
#include "strlib.h"
#include "simpio.h"

/* Function prototypes */
string ReplaceFirst(string str, string pattern, string replacement);
string ReplaceAll(string str, string pattern, string replacement);

/* Main proram */

int main()
{
    string str, pattern, replacement;

    printf("This program edits a string by replacing all.\n");
    printf("instance of a pattern substring by a new string.\n");
    printf("Enter the string to be edited:\n");
    str = GetLine();
    printf("Enter the pattern string: ");
    pattern = GetLine();
    printf("Enter the replacement string: ");
    replacement = GetLine();
    str = ReplaceAll(str, pattern, replacement);
    printf("%s\n", str);
    return 0;
}

string ReplaceFirst(string str, string pattern, string replacement)
{
    string head, tail;
    int pos;

    pos = FindString(pattern, str, 0);
    printf("pos %d\n", pos);
    if (pos == -1) return (str);
    head = SubString(str, 0, pos - 1);
    tail = SubString(str, pos + StringLength(pattern), StringLength(str) - 1);
    return (Concat(Concat(head, replacement), tail));
}

string ReplaceAll(string str, string pattern, string replacement)
{
    string head, tail, ret;
    int strlength, patlength, lp, rp;

    lp = 0;
    rp = FindString(pattern, str, 0);
    if (rp == -1) return (str);
    ret = "";
    strlength = StringLength(str);
    patlength = StringLength(pattern);
    while (rp != -1) {
        ret = Concat(ret, SubString(str, lp, rp - 1));
        ret = Concat(ret, replacement);
        lp = rp + patlength;
        rp = FindString(pattern, str, lp);
        // printf("lp: %d, rp: %d, ret: %s\n", lp, rp, ret);
    }
    ret = Concat(ret, SubString(str, lp, strlength-1));
    return ret;
}