/**
 * @file exercise.c
 * @brief 
 */

#include <stdio.h>
#include <ctype.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "random.h"
#include "caltools.h"


#define MinLetters      2
#define MaxLetters      8

typedef enum {
    North, East, South, West
} directionT;

directionT LeftFrom(directionT dir);                        // 9-1
string DirToStr(directionT dir);                            // 9-1
bool IsConsonant(char ch);                                  // 9-3
string RandomWord(void);                                    // 9-4
int ScrabbleScore(string word);                             // 9-5
int Scrabble(char ch);                                      // 9-5
string Capitalize(string str);                              // 9-6
bool EqualIgnoringCase(string s1, string s2);               // 9-7
string DateString(int day, int month, int year);            // 9-11
int GetRangeIngeter(string prompt, int low, int high);      // 9-11


int main()
{
    // 9-11
    int day, month, year;
    printf("This program prints a hyphen date string.\n");
    day = GetRangeIngeter("day? ", 1, 31);
    month = GetRangeIngeter("month? ", 1, 12);
    year = GetRangeIngeter("year? ", 1988, 2087);
    printf("%s\n", DateString(day, month, year));
    // // 9-7
    // string s1, s2;
    // printf("This program tests the EqualIgnoringCase.\n");
    // printf("word 1? ");
    // s1 = GetLine();
    // printf("word 2? ");
    // s2 = GetLine();
    // printf("These are %s.\n", (EqualIgnoringCase(s1, s2) ? "same" : "different"));

    // // 9-6
    // string word;
    // printf("This program tests the Capitalize Function.\n");
    // printf("Enter words, ending with a blank line.\n");
    // while (TRUE) {
    //     printf("Word: ");
    //     word = GetLine();
    //     printf("The basic score for '%s' is %s.\n", word, Capitalize(word));
    // }

    // // 9-5
    // string word;
    // printf("This program tests the ScrabbleScore Function.\n");
    // printf("Enter words, ending with a blank line.\n");
    // while (TRUE) {
    //     printf("Word: ");
    //     word = GetLine();
    //     printf("The basic score for '%s' is %d.\n", word, ScrabbleScore(word));
    // }

    // //9-4
    // int i;
    // Randomize();
    // printf("This progam generates 5 random words.\n");
    // for (i = 0; i < 5; i++) {
    //     printf("%s\n", RandomWord());
    // }

    // //9-3
    // int i;
    // printf("The English consonants are:\n");
    // for (i = 'A'; i <= 'Z'; i++) {
    //     if (IsConsonant(i)) printf("%c ", i);
    // }

    // 9-1
    // printf("This program tests the LeftFrom function.\n");
    // printf("LeftFrom(%s) = %s\n", DirToStr(North), DirToStr(LeftFrom(North)));
    // printf("LeftFrom(%s) = %s\n", DirToStr(East), DirToStr(LeftFrom(East)));
    // printf("LeftFrom(%s) = %s\n", DirToStr(South), DirToStr(LeftFrom(South)));
    // printf("LeftFrom(%s) = %s\n", DirToStr(West), DirToStr(LeftFrom(West)));
    return 0;
}

directionT LeftFrom(directionT dir)
{
    return (dir + 1) % 4;
}

string DirToStr(directionT dir)
{
    switch (dir)
    {
    case 0: return "North"; 
    case 1: return "East";
    case 2: return "South";
    case 3: return "West";
    }
}

bool IsConsonant(char ch)
{
    switch (tolower(ch))
    {
    case 'a': case 'e': case 'i': case 'o': case 'u': return FALSE;
    default: return TRUE;
    }
}

string RandomWord(void) {
    string ret;
    int i, length;

    ret = "";
    length = RandomInteger(MinLetters, MaxLetters);
    for (i = 0; i < length; i++) {
        ret = Concat(ret, CharToString(RandomInteger('A', 'Z')));
    }
    return ret;
}

int ScrabbleScore(string word)
{
    int i, length, point;

    point = 0;
    length = StringLength(word);
    for (i = 0; i < length; i++) {
        point += Scrabble(IthChar(word, i));
    }
    return point;
}

int Scrabble(char ch)
{
    switch (ch)
    {
    case 'A': case 'E': case 'I': case 'L': case 'N': case 'O':
    case 'R': case 'S': case 'T': case 'U':
        return 1;
    case 'D': case 'G':
        return 2;
    case 'B': case 'C': case 'M': case 'P':
        return 3;
    case 'F': case 'H': case 'V': case 'W': case 'Y':
        return 4;
    case 'K':
        return 5;
    case 'J': case 'X':
        return 8;
    case 'Q': case 'Z':
        return 10;
    default:
        return 0;
    }
}

string Capitalize(string str)
{
    string head, tail;
    int length;

    length = StringLength(str);
    head = ConvertToUpperCase(SubString(str, 0, 0));
    tail = ConvertToLowerCase(SubString(str, 1, length-1));
    return Concat(head, tail);
}

bool EqualIgnoringCase(string s1, string s2)
{
    return StringEqual(ConvertToLowerCase(s1), ConvertToLowerCase(s2));
}

string DateString(int day, int month, int year)
{
    string ret;

    ret = IntegerToString(day);
    ret = Concat(ret, "-");
    ret = Concat(ret, SubString(MonthName(month), 0, 2));
    ret = Concat(ret, "-");
    ret = Concat(ret, SubString(IntegerToString(year), 2, 3));
    return ret;
}

int GetRangeIngeter(string prompt, int low, int high)
{
    int ret;

    while (TRUE) {
        printf("%s ", prompt);
        ret = GetInteger();
        if (ret >= low && ret <= high) return ret;
        printf("Types a number above %d, below %d.\n", low, high);
    }
}