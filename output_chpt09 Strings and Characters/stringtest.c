/**
 * @file stringtest.c
 * @brief tests for exercise problems
 */

#include <stdio.h>
#include "genlib.h"
#include "random.h"
#include "strlib.h"


char RandomLetter(void);

int main()
{
    int i;



    i = 97;
    printf("%c -- %d\n", i++, StringLength("ABCDE"));
    // printf("%c -- %d\n", i++, StringLength(""));
    // printf("%c -- %d\n", i++, StringLength("\a"));
    // printf("%c -- %c\n", i++, IthChar("ABC", 2));
    // printf("%c -- %s\n", i++, Concat("12", ".00"));
    // printf("%c -- %s\n", i++, CharToString('2'));
    // printf("%c -- %s\n", i++, SubString("ABCDE", 0, 3));
    // printf("%c -- %s\n", i++, SubString("ABCDE", 4, 1));
    // printf("%c -- %s\n", i++, SubString("ABCDE", 3, 9));
    // printf("%c -- %s\n", i++, SubString("ABCDE", 3, 3));

    // i = 97;
    // printf("%c -- %d\n", i++, StringEqual("ABCDE", "abcde"));
    // printf("%c -- %d\n", i++, StringCompare("ABCDE", "ABCDE"));
    // printf("%c -- %d\n", i++, StringCompare("ABCDE", "ABC"));
    // printf("%c -- %d\n", i++, StringCompare("ABCDE", "abcde"));
    // printf("%c -- %d\n", i++, FindChar('a', "Abracadabra", 0));
    // printf("%c -- %s\n", i++, FindChar("ra", "Abracadabra", 3));         // "ra" 자리에는 char 요구
    // printf("%c -- %s\n", i++, FindChar("is", "This is a test.", 0));
    // printf("%c -- %s\n", i++, FindChar("This is a test.", "test", 0));
    // printf("new test.\n");

    // i = 97;
    // printf("%c -- %s\n", i++, ConvertToLowerCase("Catch-22"));
    // printf("%c -- %s\n", i++, IntegerToString(22));
    // printf("%c -- %g\n", i++, StringToReal("3.1419"));
    // printf("%c -- %d\n", i++, StringToInteger("22"));
    // printf("%c -- %d\n", i++, StringToInteger(SubString("Catch-22", 5, 7)));
    // printf("%c -- %s\n", i++, RealToString(3.140));
    // printf("%c -- %s\n", i++, Concat(IntegerToString(4 / 3), " pi"));

    return 0;
}

char RandomLetter(void)
{
    return RandomInteger('A', 'Z');
}