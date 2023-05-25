/*
* File: piglatin.c
* -------------------
* This program translates a line of text from English
* to pig latin. The rules for forming pig Latin words
* are as follows:
*
* o If the word begins with a vowel, add "way" to the 
* end of the word.
* o If the word begins with a consonat, extract the set
* of consonants up to the first vowel, move that set
* of consonants to the end of the word, and add "ay".
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "genlib.h"
#include "simpio.h"
#include "scanner.h"

/* Private function prototypes */
static void TranslateLine(string line);
static string TranslateWord(string word);
static bool IsLegalWord(string token);
static int FindFirstVowel(string word);
static bool IsVowel(char ch);
static char *ConvertToUpperCase(char *s);
static char *SubString(char *s, int p1, int p2);
static char *ConvertToLowerCase(char *s);
static char *Concat(char *s1, char *s2);

/* Main program */
int main()
{
    string line;

    printf("This program tests pig latin word.\n");
    printf("Enter a line: ");
    line = GetLine();
    TranslateLine(line);
    return 0;
}

/*
* Function: TranslateLine
* Usage: TranslateLine(line);
* -------------------------------------
* This function takes a line of text and translates
* the words in the line to Pig Latin, displaying the
* translation as it goes.
*/
static void TranslateLine(string line)
{
    string token;
    InitScanner (line);
    while (!AtEndOfLine()) {
        token = GetNextToken();
        if (IsLegalWord(token)) token = TranslateWord(token);
        printf ("%s", token);
    }
    printf ("\n");
}

/*
* Function: TranslateWord
* Usage: word = TranslateWord (word)
* -------------------------------------------------
* This function translates a word from English to Pig Latin
* and returns the translated word.
*/
static string TranslateWord(string word)
{
    int vp;
    string head, tail;
    bool cap;

    cap = (*(word + 0) < 97 ? TRUE : FALSE);
    vp = FindFirstVowel(word);
    if (vp == -1) {
        return (word);
    } else if (vp == 0) {
        return (Concat(word, "way"));
    } else {
        head = ConvertToLowerCase(SubString(word, 0, vp - 1));
        if (cap) {
            tail = ConvertToUpperCase(SubString(word, vp, vp));
            tail = Concat(tail, SubString(word, vp + 1, strlen(word) - 1));
        } else {
            tail = SubString(word, vp, strlen(word) - 1);
        }
        return (Concat(tail, Concat(head, "ay")));
    }
}

/*
* Function: IsLegalWord (token)…
* Usage: if (IsLegalWord (token))…
* --------------------------------------------
* IsLegalWord returns TRUE if every character in the argument
* token is alphabetic.
*/
static bool IsLegalWord(string token)
{
    int i;
    for (i = 0; i < strlen(token); i++) {
        if (!isalpha(*(token + i))) return (FALSE);
    }
    return (TRUE);
}

/*
* Function: FindFirstVowel
* Usage: k = FindFirstVowel (word);
* ---------------------------------------------
* FindFirstVowel returns the index position of the first vowel 
* in word. If word does not contain a vowel, FindFirstVowel
* returns –1.
*/
static int FindFirstVowel(string word)
{
    int i;
    for (i = 0; i < strlen(word); i++) {
        if (IsVowel(*(word + i))) return (i);
    }
    return (-1);
}

/*
* Function: Isvowel
* Usage: if (IsVowel (ch))…
* ----------------------------------
* IsVowel returns TRUE if ch is a vowel. This function
* recognizes vowels in either upper or lower case.
*/
static bool IsVowel(char ch)
{
    switch (tolower(ch)) {
    case 'a': case 'e': case 'i': case 'o': case 'u':
        return (TRUE);
    default:
        return (FALSE);
    }
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

static char *Concat(char *s1, char *s2)
{
    char *s;
    int len1, len2;

    len1 = strlen(s1);
    len2 = strlen(s2);
    s = (char *) malloc(len1 + len2 + 1);
    if (s == NULL) Error("Concat memory error");
    strcpy(s, s1);
    strcpy(s + len1, s2);
    return (s);
}