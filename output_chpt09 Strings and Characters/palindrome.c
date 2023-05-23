/**
 * @file palindrome.c
 * @brief exercise 9-9, 9-10
 *  A palindrome is a word that reads identically backward and forward, such as level or 
noon. Write a predicate function IsPalindrome (str) that returns TRUE if the string str is a 
palindrome. 
 */

#include <stdio.h>
#include <ctype.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"

bool IsPalindrome(string str);


int main()
{
    string str;

    while (TRUE)
    {
        printf("This program checks for palindromes.\n");
        printf("Indicate the end of the input with a blank line.\n");
        printf("Enter a string: ");
        str = GetLine();
        printf("This is %sa palindrome.\n", (IsPalindrome(str) ? "" : "not "));
        return 0;
    }
}

bool IsPalindrome(string str)
{
    int i, mid, length;
    char c;
    string nstr, tmp;

    length = StringLength(str);
    printf("%s length is %d\n", str, length);
    mid = length / 2;
    nstr = "";
    for (i = 0; i < length; i++) {
        c = IthChar(str, i);
        tmp = CharToString(tolower(c));
        if (isalnum(c)) nstr = Concat(nstr, tmp);
    }
    // printf("new str [%s]\n", nstr);
    length = StringLength(nstr);
    for (i = 0; i < mid; i++) {
        if (IthChar(nstr, i) != IthChar(nstr, length-1-i)) return FALSE;
    }
    return TRUE;
}