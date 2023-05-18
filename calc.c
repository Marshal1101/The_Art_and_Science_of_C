/**
 * @file calc.c
 * @brief exercise 10-10
 * Write a program calc.c that implements a simple arithmetic calculator. Input to the 
 * calculator consists of lines composed of integer constants separated by the five 
 * arithmetic operators used in C: +, -, *, /, and %. For each line of input, your program 
 * should display the result of applying the operators to the surrounding terms. 
 */

#include <stdio.h>

#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "scanner.h"

int main()
{
    string line, exp;
    bool opturn;
    char op;
    int num, ans;

    printf("This program implements a simple calculator.\n");
    printf("When the > prompt apperas, enter an expression\n");
    printf("consisting of interger constants and the operators\n");
    printf("+, -, *, / and %%. To stop, enter a blank line.\n");
    while (TRUE) {
        printf("> ");
        line = GetLine();
        if (StringEqual(line, "")) break;
        InitScanner(line);
        ReturnOnlyWords(TRUE);
        opturn = FALSE;
        op = '+';
        ans = 0;
        while (!AtEndOfLine()) {
            exp = GetNextToken();
            if (opturn) {
                op = IthChar(exp, 0);
                opturn = FALSE;
            } else {
                num = StringToInteger(exp);
                switch (op)
                {
                case '+': ans += num; break;
                case '-': ans -= num; break;
                case '*': ans *= num; break;
                case '/': ans /= num; break;
                case '%': ans %= num; break;
                default: Error("Incorrect expression."); break;
                }
                opturn = TRUE;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}