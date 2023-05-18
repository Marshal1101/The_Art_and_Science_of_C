/**
 * @file oldabbrev.c
 * @brief exercise 10-1
 * A couple of centuries ago, abbreviations were formed differently than they are today. 
 * Rather than comprising just the leading characters in a word, an old-style 
 * abbreviation consists instead of the leading consonants (or just the first letter if the 
 * word begins with a vowel), followed by the very last letter in the word. This style is 
 * preserved in the traditional abbreviations (not the two-letter postal abbreviation) of 
 * many state names, such as Connecticut Ct. Maine Me.
 * 
 * Florida Fla. Pennsylvania Pa.
 * Iowa Ia. Vermont Vt.
 * 
 * Write a function OldStyleAbbreviation that takes a string as argument and returns a string 
 * consisting of an old-style abbreviation formed by connecting in sequence the 
 * 
 * following pieces:
 * a. The initial consonant string, up to the first vowel. If the original string begins 
 *    with a vowel, use that vowel instead (see the Iowa example).
 * b. The last letter in the word.
 * c. A period
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"

string OldStyleAbbreviation(string word);
bool IsVowel(char ch);

int main()
{
    string word;

    while (TRUE) {
        printf("This program tests OldStyleAbbreviation.\n");
        word = GetLine(); 
        word = OldStyleAbbreviation(word);
        printf("%s\n", word);
    }
    return 0;
}

string OldStyleAbbreviation(string word)
{
    string head, tail, ret;
    int i, len;

    len = StringLength(word);
    if (len < 3) return word;
    if (IsVowel(IthChar(word, 0))) {
        head = SubString(word, 0, 0);
        tail = SubString(word, len-1, len-1);
        return Concat(Concat(head, tail), ".");
    }
    for (i = 1; i < len; i++) {
        if (IsVowel(IthChar(word, i))) {
            head = SubString(word, 0, i-1);
            tail = SubString(word, len-1, len-1);
            return Concat(Concat(head, tail), ".");
        }
    }
    return word;
}

bool IsVowel(char ch)
{
    switch (ch)
    {
    case 'a': case 'e': case 'i': case 'o': case 'u':
        return (TRUE);
    default:
        return (FALSE);
    }
}