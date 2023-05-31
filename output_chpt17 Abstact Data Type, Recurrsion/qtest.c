/**
 * @file qtest.c
 * @brief exercise 17-7 
 * @date 2023-05-31
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "queue.h"
#include "scanner.h"


int main(void)
{
    queueADT q;
    string comline, token;
    int com;

    printf("This program tests Queue\n");
    q = NewQueue();
    while (TRUE) {
        printf("com elem? ");
        comline = GetLine();
        InitScanner(comline);
        ReturnOnlyWords(TRUE);
        com = StringToInteger(GetNextToken());
        if (com == 0) {
            while (!AtEndOfLine()) {
                token = GetNextToken();
                Enqueue(q, token);
                printf("Enqueue %s\n", token);
            }
        } else {
            printf("Dequeue %s\n", Dequeue(q));
        }
        ShowQueueElement(q);
    }

    return 0;
}

