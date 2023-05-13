/**
 * @file functions.c
 * @brief prints a length of number given
 * @date 2023-05-14
 */

#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"

/* Constants */
#define Epsilon     0.0000000000000001            // 1e-15까지 오차발생, 1e-16에서 오차 발생하지 않는다.

/* Prototype Functions */
int NDigits(int n);                               // 5-7
int Round(double x);                              // 5-8
bool IsPerfectSquare(int n);                      // 5-9
bool ApproximatelyEqual(double x, double y);      // 5-10
bool GetYesOrNo(string ask);                      // 5-11

/* Main Function */
int main()
{
    while (TRUE) {
        printf("Game finished.\n");
        if (!GetYesOrNo("Would you like to play again? ")) break;
    }
    return 0;
}

int NDigits(int n)
{
    int length = 0;

    while (n > 0) {
        n /= 10;
        length++;
    }
    return length;
}

int Round(double x)
{
    int ret;

    if (x >= 0) {
        ret = x + 0.5;
    } else {
        ret = x - 0.5;
    }
    return ret;
}

bool IsPerfectSquare(int n)
{
    bool ret;
    int k;
    
    k = sqrt(n);
    return (k * k == n);
}

bool ApproximatelyEqual(double x, double y)
{
    bool ret;
    double abs, min;
    abs = fabs(x - y);
    min = (x < y ? x : y);
    return (abs / min < Epsilon);
}

bool GetYesOrNo(string ask)
{
    string ans;

    while (TRUE) {
        printf("%s", ask);
        ans = GetLine();
        if (StringEqual(ans, "yes")) {
            return (TRUE);
        } else if (StringEqual(ans, "no")) {
            return (FALSE);
        } else {
            printf("Please answer yes or no.\n");
        }
    }
}