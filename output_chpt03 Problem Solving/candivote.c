/**
 * @file candivote.c
 * @author The Art and Science of C. problem 3-12
 * @brief making a table with each candidate and vote.
 * @version 0.1
 * @date 2023-05-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    int n, i, vote;
    string candidate;
    printf("how many candidates? ");
    n = GetInteger();
    for (i = 0; i < n; i++) {
        printf("a candidate name? ");
        candidate = GetLine();
        printf("the one's votes? ");
        vote = GetInteger();
        printf("%-15.15s%4d\n", candidate, vote);
    }
    return 0;
}