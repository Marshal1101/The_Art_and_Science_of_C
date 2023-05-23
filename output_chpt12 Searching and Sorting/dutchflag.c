/**
 * @file dutchflag.c
 * @brief exercise 12-10
 * One of the most famous algorithmic problems taught at 
 * the introductory level is the Dutch National Flag problem, 
 * first proposed by Edsger Dijkstra. 
 * @date 2023-05-22
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "random.h"

#define MaxElements     14
#define Sentinel         0

char RandomCharRWB(void);
void RandomArrRWB(char array[], int n);
void SortDutchFlag(char array[], int low, int high);
static void SwapFlagElements(char array[], int p1, int p2);
static void PrintCharArray(char array[], int n);


int main()
{
    char flagArr[MaxElements];
    // char flagArr[15] = {'R', 'B', 'W', 'W', 'B', 'B', 'R', 'W', 'W', 'R', 'R', 'W', 'R', 'B', 'W'};

    Randomize();
    RandomArrRWB(flagArr, MaxElements);
    SortDutchFlag(flagArr, 0, MaxElements-1);
    return 0;
}

char RandomCharRWB(void)
{
    int d;
    
    d = RandomInteger(1, 3);
    switch (d)
    {
    case 1: return 'R';
    case 2: return 'W';
    case 3: return 'B';
    }
}

void RandomArrRWB(char array[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        array[i] = RandomCharRWB();
    }
}

void SortDutchFlag(char array[], int low, int high)
{
    int i, lp, rp;

    lp = i = low;
    rp = high;
    printf("Initial state:\n");
    PrintCharArray(array, high+1);
    while (i <= rp) {
        if (array[i] == 'R') {
            printf("Swapping poitions %d and %d\n", lp, i);
            SwapFlagElements(array, i++, lp++);
            PrintCharArray(array, high+1);
        } else if (array[i] == 'B') {
            printf("Swapping poitions %d and %d\n", i, rp);
            SwapFlagElements(array, i, rp--);
            PrintCharArray(array, high+1);
        } else {
            i++;
        }
    }
}

static void SwapFlagElements(char array[], int p1, int p2)
{
    char tmp;

    tmp = array[p1];
    array[p1] = array[p2];
    array[p2] = tmp;
}

static void PrintCharArray(char array[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("%c ", array[i]);
    }
    printf("\n");
}