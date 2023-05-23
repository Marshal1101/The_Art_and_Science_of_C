/**
 * @file halflife.c
 * @brief This problem simulates 1 year half-life
 */

#include <stdio.h>
#include "genlib.h"
#include "random.h"


int main()
{
    int i, year, atoms, decay;

    year = 0;
    atoms = 10000;
    printf("Year             Atoms left\n");
    printf("----            ------------\n");
    while (atoms > 0) {
        printf("%3d%23d\n", year++, atoms);
        decay = 0;
        for (i = 0; i < atoms; i++) {
            if (RandomChance(0.5)) decay++;
        }
        atoms -= decay;
    }
    printf("%3d%23d\n", year++, atoms);
    return 0;
}