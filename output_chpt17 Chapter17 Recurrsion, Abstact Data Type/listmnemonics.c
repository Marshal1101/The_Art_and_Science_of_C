/**
 * @file listmnemonics.c
 * @brief exercise 17-6
 * @date 2023-05-30
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"


void ListMnemonics(string num);
static void InitListMnemonics(string phone[]);
static void ListPrefix(string num, string phone[], string indexed, int len);
static void PrintIndexedPhone(string num, string phone[], string indexed);

int main(void)
{
    string num;

    printf("This program tests ListMnemonics Recursion\n");
    printf("num? ");
    num = GetLine();
    ListMnemonics(num);
    return 0;
}

void ListMnemonics(string num)
{
    string phone[11];

    InitListMnemonics(phone);
    ListPrefix(num, phone, "", 0);
}

static void InitListMnemonics(string phone[])
{
    int i, j;
    char ch;
    char *cp;

    ch = 'A';
    for (i = 2; i < 10; i++) {
        phone[i] = NewArray(4, char);
        cp = phone[i];
        for (j = 0; j < 3; j++) {
            if (ch == 'Q') ch++;
            *cp++ = ch++;
        }
        *cp = '\0';
    }
    phone[i] = NULL;
    phone[0] = IntegerToString(0);
    phone[1] = IntegerToString(1);
}

static void ListPrefix(string num, string phone[], string indexed, int len)
{
    int i;

    if (len == StringLength(num)) {
        PrintIndexedPhone(num, phone, indexed);
        return;
    }

    if (num[len] == '0' || num[len] == '1') {
        ListPrefix(num, phone, Concat(indexed, "0"), len + 1);
        if (len == 0) printf("\n");
        return;
    }

    for (i = 0; i < 3; i++) {
        ListPrefix(num, phone, Concat(indexed, IntegerToString(i)), len + 1);
        if (len == 0) printf("\n");
    }
}

static void PrintIndexedPhone(string num, string phone[], string indexed)
{
    int i;
    string ans;
    char *cp;

    ans = (string) GetBlock(4);
    cp = ans;
    for (i = 0; i < StringLength(num); i++) {
        *cp++ = phone[num[i] - '0'][indexed[i] - '0'];
    }
    *cp = '\0';
    printf("%s ", ans);
}