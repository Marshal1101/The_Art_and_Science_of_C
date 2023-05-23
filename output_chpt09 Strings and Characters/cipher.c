/**
 * @file cipher.c
 * @brief exercise 8-8
 * One of the simplest types of codes used to make it harder
 * for someone to read a message is a letter-substitution cipher,
 * in which each letter in the original message is replaced by
 * some different letter in the coded version of that message. 
 * A particularly simple type of letter-substitution cipher is
 * a cyclic cipher, in which each letter is This program tests
 * the ScrabbleScore function.
// Enter word, ending with a blank line.
// Word: XI
// The basic score for „XI‟ is 9.
// Word: HORN
// The basic score for „HORN‟ is 7.
// Word: SCRABBLE
// The basic score for „SCRABBLE‟ is 14.
// Word: QUIzZICAL
// The basic score for „QUIzZICAL‟ is 28.
// Word:
 * replaced by its counterpart a fixed distance ahead in the alphabet.
 * The word cyclic refers to the fact that if the operation of moving
 * ahead in the alphabet would take you past Z, you simply circle back
 * to the beginning and start over again with A.
 */


#include <stdio.h>
#include <ctype.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"


string EncodeString(string str, int key);       // 9-8
char CyclicCipher(char ch, int key);            // 9-8


int main()
{
    // 8-8
    int key;
    string msg;

    printf("This program encodes a message using a cyclic cipher.\n");
    printf("Enter the numeric key: ");
    key = GetInteger();
    printf("Enter a message: ");
    msg = GetLine();
    printf("Encoded message: %s\n", EncodeString(msg, key));
    return 0;
}

string EncodeString(string str, int key)
{
    string ret;
    int i, length;

    ret = "";
    i = 0;
    length = StringLength(str);
    for (i = 0; i < length; i++) {
        ret = Concat(ret, CharToString(CyclicCipher(IthChar(str, i), key)));
    }
    return ret;
}

char CyclicCipher(char ch, int key)
{
    int ret;
    if ((ch > 64 && ch < 91)) {
        return ((ch - 'A' + key + 26) % 26) + 'A';
    } else if (ch > 96 && ch < 123) {
        return ((ch - 'a' + key + 26) % 26) + 'a';
    } else {
        return (ch);
    }
}