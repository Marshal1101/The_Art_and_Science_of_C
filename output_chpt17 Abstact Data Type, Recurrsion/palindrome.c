/**
 * @file palindrome.c
 * @brief exercise 17-3
 * @date 2023-05-30
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"


bool IsPalindrome(string str);
static bool isPalindromeStoE(string str, int s, int e);

int main(void)
{
    string str;

    printf("This program tests IsPalindrome with Recursion\n");
    printf("string: ");
    str = GetLine();
    printf("%s is %s\n", str, (IsPalindrome(str) ?
                                "palindrome" : "not IsPalindrome"));
    return 0;
}

bool IsPalindrome(string str)
{
    isPalindromeStoE(str, 0, StringLength(str)-1);
}

static bool isPalindromeStoE(string str, int s, int e)
{
    if (s == e || s > e) {
        return TRUE;
    } else {
        return (str[s] == str[e]) * isPalindromeStoE(str, s+1, e-1);
    }
} 