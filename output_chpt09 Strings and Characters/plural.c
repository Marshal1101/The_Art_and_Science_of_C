/**
 * @file plural.c
 * @brief
 * a function RegularPluralForm (word) that returns the plural of word
 * formed by following these standard English rules:
 * a. If the word ends in s, x, z, ch, or sh, add es to the word.
 * b. If the word ends in y and the y is preceded by a consonant, change the y to ies.
 * c. In all other cases, add just an s.
 * Write a test program and design a set of test cases to verify that your program works.
 */

#include <stdio.h>
#include <ctype.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"

string RegularPluralForm(string word);
bool IsConsonant(char ch);


int main()
{
    string word;

    printf("This program tests the RegularPluralForm function.\n");
    printf("a test word? ");
    word = GetLine();
    printf("%s\n", RegularPluralForm(word));
    return 0;
}

string RegularPluralForm(string word)
{
    string ret;
    char bnd, end;
    int length;

    length = StringLength(word);
    end = IthChar(word, length-1);
    switch (end)
    {
    case 's': case 'x': case 'z':
        ret = Concat(word, "es"); 
        break;
    case 'h':
        bnd = IthChar(word, length-2);
        if (length > 2 && (bnd == 'c' || bnd == 's')) {
            ret = Concat(word, "es");
        } else {
            ret = Concat(word, "s");
        }
        break;
    case 'y':
        bnd = IthChar(word, length-2);
        if (length > 2 && IsConsonant(bnd)) {
            ret = Concat(SubString(word, 0, length-2), "ies");
            break;
        }
    default:
        ret = Concat(word, "s");
        break;
    }
    return (ret);
}

bool IsConsonant(char ch)
{
    switch (tolower(ch))
    {
    case 'a': case 'e': case 'i': case 'o': case 'u': return FALSE;
    default: return TRUE;
    }
}

