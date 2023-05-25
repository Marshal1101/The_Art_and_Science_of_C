/**
 * @file exercise.c
 * @brief exercise chpt 14
 * @date 2023-05-24
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "genlib.h"
#include "simpio.h"
#include "scanner.h"

void exe12(void);
int ArrStrlen(char str[]);
int PtrStrlen(char *str);
void exe3(void);
int ArrStrcmp(char s1[], char s2[]);
int PtrStrcmp(char *s1, char *s2);
void exe4(void);
string Acronym(string line);
void exe5(void);
void ReverseString(char carray[]);
void exe6(void);
string EncodeString(string str, int key);
char CyclicCipher(char ch, int key);
void exe7(void);
string SubString(string s, int p1, int p2);
void exe8(void);
int FindString(char *s, char *text, int start);
void exe9(void);
char *ConvertToUpperCase(char *s);
void exe10(void);


int main()
{
    // exe12()
    // exe3();
    // exe4();
    // exe5();
    // exe6();
    // exe7();
    // exe8();
    // exe9();
    exe10();
    
    return 0;
}

void exe12(void)
{
    string line;

    line = "7777777";
    printf("arrlen: %d\n", ArrStrlen(line));
    printf("ptrlen: %d\n", PtrStrlen(line));
}


int ArrStrlen(char str[])
{
    int i;

    for (i = 0; str[i]; i++);
    return i;
}

int PtrStrlen(char *str)
{
    char *cp;

    for (cp = str; *cp; cp++);
    return (cp - str);
}

void exe3(void)
{
    string line1, line2;

    printf("This program tests strcmp function.\n");
    printf("1) ? ");
    line1 = GetLine();
    printf("2) ? ");
    line2 = GetLine();
    printf("1: %s, 2: %s are %s\n", line1, line2, (ArrStrcmp(line1, line2) ? "same" : "different"));
    printf("1: %s, 2: %s are %s\n", line1, line2, (PtrStrcmp(line1, line2) ? "same" : "different"));
}

int ArrStrcmp(char s1[], char s2[])
{
    int i, len1, len2;

    for (i = 0; s1[i]; i++);
    len1 = i;
    for (i = 0; s2[i]; i++);
    len2 = i;
    if (len1 != len2) return 0;
    for (i = 0; i < len1; i++) {
        if (s1[i] != s2[i]) return 0;
    }
    // printf("i:%d, len1:%d, len2:%d\n", i, len1, len2);
    return 1;
}

int PtrStrcmp(char *s1, char *s2)
{
    char *cp;
    int i, len1, len2;

    for (cp = s1; *cp; cp++);
    len1 = cp - s1;
    for (cp = s2; *cp; cp++);
    len2 = cp - s2;
    if (len1 != len2) return 0;
    while (*s1) {
        if (*s1++ != *s2++) return 0;
    }
    return 1;
}

void exe4(void)
{
    string line;

    printf("This program tests Acronym using 'string.h'\n");
    printf("sentense: ");
    line = GetLine();
    printf("%s\n", Acronym(line));
}

string Acronym(string line)
{
    char *cp, *rp;
    int i, wordCnt;
    bool isSpace;

    wordCnt = 0;
    isSpace = TRUE;    
    for (cp = line; *cp; cp++) {
        if (isSpace) {
            if (*cp != ' ') {
                wordCnt++;
                isSpace = FALSE;
            }
        } else {
            if (*cp == ' ') {
                isSpace = TRUE;
            }
        }
    }
    rp = (char *) malloc(wordCnt + 1);
    i = 0;
    isSpace = TRUE;
    for (cp = line; *cp; cp++) {
        if (isSpace) {
            if (*cp != ' ') {
                *(rp + i++) = *cp;
                isSpace = FALSE;
            }
        } else {
            if (*cp == ' ') {
                isSpace = TRUE;
            }
        }
    }
    *(rp + i) = '\0';
    return rp;
}

void exe5(void)
{
    string line;

    printf("This program tests ReverseString Function.\n");
    printf("string carray: ");
    line = GetLine();
    ReverseString(line);
    printf("reversed: %s\n", line);
}

void ReverseString(char carray[])
{
    char tmp;
    int i, len;

    len = strlen(carray);
    for (i = 0; i < len/2; i++) {
        tmp = carray[i];
        carray[i] = carray[len-1-i];
        carray[len-1-i] = tmp;
    }
}

void exe6(void)
{
    int key;
    string msg;

    printf("This program encodes a message using a cyclic cipher.\n");
    printf("Enter the numeric key: ");
    key = GetInteger();
    printf("Enter a message: ");
    msg = GetLine();
    printf("Encoded message: %s\n", EncodeString(msg, key));
}

string EncodeString(string str, int key)
{
    char *cp, *rp;
    int i, length;

    length = strlen(str);
    rp = (char *) malloc(length + 1);
    i = 0;
    for (cp = str; *cp; cp++) {
        *(rp + i++) = CyclicCipher(*cp, key);
    }
    return rp;
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

void exe7(void)
{
    string line;
    int p1, p2;

    printf("This program tests SubString function.\n");
    printf("string: ");
    line = GetLine();
    printf("start pos: ");
    p1 = GetInteger();
    printf("end pos: ");
    p2 = GetInteger();
    printf("substring: %s\n", SubString(line, p1, p2));

}
string SubString(string s, int p1, int p2)
{
    char *rp;
    int i, len;

    len = strlen(s);
    if (p1 < 0) p1 = 0;
    if (p2 > len - 1) p2 = len - 1;
    if (p1 > p2) {
        rp = (char *) malloc(1);
        *rp = '\0';
        return rp;
    }
    rp = (char *) malloc(p2 - p1 + 2);
    for (i = 0; i <= p2 - p1; i++) {
        *(rp + i) = *(s + p1 + i);
    }
    *(rp + i) = '\0';
    return rp;
}

void exe8(void)
{
    char *s, *text;
    int start;

    printf("This program tests FindString function.\n");
    printf("text: source?: ");
    text = GetLine();
    printf("s: wanna find?: ");
    s = GetLine();
    printf("start pos: ");
    start = GetInteger();
    printf("%s founded %d\n", s, FindString(s, text, start));
}
int FindString(char *s, char *text, int start)
{
    char *cp; 
    int i, tlen, slen;

    slen = strlen(s);
    tlen = strlen(text);
    for (i = start; i < tlen && strncmp(s, text + i, slen); i++);
    if (i < tlen) return (i);
    return (-1);
}

void exe9(void)
{
    char *line;

    printf("This program test ConvertToUpperCase function.\n");
    printf("sentence?: ");
    line = GetLine();
    printf("%s\n", ConvertToUpperCase(line));
}
char *ConvertToUpperCase(char *s)
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

void exe10(void)
{
    string line, token;

    printf("This program tests scanner.h with string.h\n");
    printf("sentence: ");
    line = GetLine();
    InitScanner(line);
    ReturnOnlyWords(TRUE);
    while (!AtEndOfLine()) {
        token = GetNextToken();
        printf("token: %s\n", token);
    }
}