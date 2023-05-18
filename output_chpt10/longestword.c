/**
 * @file longestword.c
 * @brief exercise 10-6
 * Write a function LongestWord (line) that returns the longest word in line. Test your 
 * function with a main program that can duplicate this sample run:
 * 
 * Enter a line: 
 * All mimsy were the borogoves.
 * The longest word is “borogoves”
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "scanner.h"

string LongestWord(string line);

int main()
{
    string line, ans;

    printf("Enter a line: ");
    line = GetLine();
    ans = LongestWord(line);
    printf("The longest word is \"%s\".\n", ans);
    return 0;
}

string LongestWord(string line)
{
    string ret, token;
    int len, maxlen;

    maxlen = 0;
    InitScanner(line);
    while (!AtEndOfLine()) {
        token = GetNextToken();
        len = StringLength(token);
        if (len > maxlen) {
            maxlen = len;
            ret = token;
        }
    }
    return ret;
}