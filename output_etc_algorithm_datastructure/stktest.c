/**
 * @file qtest.c
 * @brief exercise 17-7 
 * @date 2023-05-31
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "stack.h"
#include "scanner.h"


int main(void)
{
    stackADT stk;
    string comline, token;
    int com;

    printf("This program tests Stack\n");
    stk = NewStack();
    while (TRUE) {
        printf("com elem? ");
        comline = GetLine();
        InitScanner(comline);
        ReturnOnlyWords(TRUE);
        com = StringToInteger(GetNextToken());
        if (com == 0) {
            while (!AtEndOfLine()) {
                token = GetNextToken();
                Push(stk, token);
                printf("Push %s\n", token);
            }
        } else if (com == 1) {
            printf("Pop %s\n", Pop(stk));
        } else if (com == 2) {
            Clear(stk);
            printf("Clear Stack.\n");
        }
        ShowStackElement(stk);
    }

    return 0;
}

