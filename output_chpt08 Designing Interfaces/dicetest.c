/**
 * @file dicetest.c
 * @brief This program simulates rolling a die.
 */

#include <stdio.h>
#include "genlib.h"
#include "random.h"

/**
 * Constants
 * ---------
 * Ntrials -- Number of trials
 */

#define NTrials 10

/* Function prototypes */

int RollDie(void);

/* Main program */

int main()
{
    int i;

    Randomize();
    for (i = 0; i < NTrials; i++) {
        printf("%d\n", RollDie());
    }
    return 0;
}

int RollDie(void)
{
    return (RandomInteger(1, 6));
}
