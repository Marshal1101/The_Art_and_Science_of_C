/**
 * @file exercise.c
 * @brief 
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "scanner.h"
#include "labelseq.h"
#include "fill.h"


void exercise7(void);
string ReverseSentense(string line);
void exercise8(void);
void exercise9(void);
void exercise11(void);
void exercise12(void);
string PrimesPrompt(int low, int high);
bool IsPrimeNumber(int num);


int main()
{
    exercise12();
    // exercise9();
    // exercise8();
    // exercise7();
    return 0;
}

void exercise7()
{
    string line, ans;
    
    printf("Enter a line: ");
    line = GetLine();
    ans = ReverseSentense(line);
    printf("%s\n", ans);
    return;
}

string ReverseSentense(string line)
{
    string ret, token;
    int length;
    char ch;

    ret = "";
    InitScanner(line);
    while (!AtEndOfLine()) {
        token = GetNextToken();
        length = StringLength(token);
        ch = IthChar(token, length - 1);
        if (!isalnum(ch) && (ch != ' ')) token = SubString(token, 0, length-2);
        ret = Concat(token, ret);
    }
    return ret;
}

void exercise8(void)
{
    string line, token;

    printf("Enter a line: ");
    line = GetLine();
    InitScanner(line);
    ReturnUppercaseTokens(TRUE);
    while (!AtEndOfLine()) {
        token = GetNextToken();
        printf("\"%s\"\n", token);
    }
    return;
}

void exercise9(void)
{
    string line, token;
    
    printf("This Program tests ReturnOnlyWords in scanner.h\n");
    printf("Enter a line: ");
    line = GetLine();
    InitScanner(line);
    ReturnOnlyWords(TRUE);
    while (!AtEndOfLine()) {
        token = GetNextToken();
        printf("%s", token);
    }
}

void exercise11(void)
{
    string label;
    int i, number;

    printf("This program tests the labelseq abstraction.\n");
    printf("Prefix to use for labels: ");
    label = GetLine();
    printf("Starting number: ");
    number = GetInteger();
    InitLabelseq();
    SetLabelPrefix(label);
    SetLabelNumber(number);
    for (i = 0; i < 5; i++) {
        printf("%s\n", GetNextLabel());
    }
}

void exercise12(void)
{
    string prompt;

    prompt = PrimesPrompt(1, 200);
    SetFillMargin(55);
    PrintFilledString(prompt);
}

string PrimesPrompt(int low, int high)
{
    string ret;
    int i, limit, length;

    ret = "The primes between ";
    ret = Concat(ret, IntegerToString(low));
    ret = Concat(ret, " and ");
    ret = Concat(ret, IntegerToString(high));
    ret = Concat(ret, " are: ");
    if (low <= 2) {
        ret = Concat(ret, "2, ");
        low = 3;
    }
    for (i = low; i <= high; i++) {
        if (IsPrimeNumber(i)) {
            ret = Concat(ret, IntegerToString(i));
            ret = Concat(ret, ", ");
        }
    }
    length = StringLength(ret);
    return Concat(SubString(ret, 0, length-3), ".");
}

bool IsPrimeNumber(int num) {
    int i, limit;

    limit = sqrt(num) + 1;
    for (i = 2; i <= limit; i++) {
        if (num % i == 0) return FALSE;
    }
    return TRUE;
}