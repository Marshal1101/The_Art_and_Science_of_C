/**
 * @file randtest.c
 * @brief This program tests the ANSI rand function. exercise 8-1,2,3,4,5
 */

#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"
#include "random.h"

/**
 * Constants
 * ---------
 * NTrials -- Number of trials
 */
#define NTrials 10

/* Prototype functions */
void CheckRandMax(void);                        // 8-1
int RandomEvenInteger(int low, int high);       // 8-2
void RandomUSPN(void);                          // 8-3
void RandomCard(void);                          // 8-4
void Head3times(void);                          // 8-5

/* Main program */
int main()
{
    int i, r;
    volatile string s;

    Randomize();
    printf("Here are the results of %d calls to Random US PN:\n", NTrials);
    for (i = 0; i < NTrials; i++) {
        RandomCard();
    }
    Head3times();
    return 0;
}

int RandomRandInteger(int low, int high)
{
    int k;
    double d;
    rand();
    d = (double) rand() / ((double) RAND_MAX + 1);
    k = (int) (d * (high - low + 1));
    return (low + k);
}


void CheckRandMax(void)
{
    int i, r;

    printf("On this computer, RAND_MAX = %d.\n", RAND_MAX);
    printf("Here are the results of %d calls to rand:\n", NTrials);
    for (i = 0; i < NTrials; i++) {
        r = rand();
        printf("%10d\n", r);
    }
}

int RandomEvenInteger(int low, int high)
{
    int k;
    double d;

    if (low <= 0) Error("num needs to be above 0.");
    rand();     // 첫 정수가 반복되는 경향이 있음. 버리기 사용.
    d = (double) rand() / (double) (RAND_MAX + 1);
    k = (int) (d * (high - low + 1));
    // printf("%d origin\n", n);
    return ((low + k) % 2 > 0 ? low + k + 1 : low + k);
}

void RandomUSPN(void)
{
    // string ret;
    int h1, h2, h3, tail;

    h1 = RandomInteger(2, 9);
    h2 = RandomInteger(2, 9);
    h3 = RandomInteger(0, 9);
    tail = RandomInteger(0, 9999);
    printf("%d%d%d-%04d\n", h1, h2, h3, tail);
    // ret = "%d%d%d-%4d", h1, h2, h3, tail;
    // return ret;
}

void RandomCard(void)
{
    string num, shape;
    int n, s;
    
    n = RandomRandInteger(1, 13);
    s = RandomRandInteger(1, 4);
    switch (n)
    {
    case  1: num = "ace"; break;
    case 11: num = "jack"; break;
    case 12: num = "queen"; break;
    case 13: num = "king"; break;
    default: num = NULL;    
    }

    switch (s)
    {
    case 1: shape = "Clubs"; break;
    case 2: shape = "Diamodns"; break;
    case 3: shape = "Hearts"; break;
    case 4: shape = "Spades"; break;    
    default: Error("s is a 1~4 integer.");
    }

    if (num != NULL) {
        printf("%s of %s\n", num, shape);
    } else {
        printf("%d of %s\n", n, shape);
    }
}

void Head3times(void)
{
    int t, cnt;

    t = cnt = 0;
    while (cnt != 3) {
        if(RandomChance(0.5)) {
            cnt++;
            printf("heads\n");
        } else {
            cnt = 0;
            printf("tails\n");
        }
        t++;
    }
    printf("It took %d flips to get heads 3 consecutive times.\n", t);
}