/*
* File: gymjudge.c
* ----------------------
* This program averages a set of five gymnastic scores.
*/
#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

/*
* Contants 
* ------------
* Njudges – Number of judges
*/
#define Njudges 5

/* Prototype Functions */
double Mean(double array[], int n);                     // exercise 11-2
double StandardDeviation(double array[], int n);        // exercise 11-3


/* Main program */
int main()
{
    int i;
    double gymnasticScores[Njudges];
    double total, average;

    for (i = 0; i < Njudges; i++) {
        printf ("Score for judge #%d: ", i);
        gymnasticScores[i] = GetReal ();
    }
    printf ("The average score is %.2f\n", Mean(gymnasticScores, Njudges));
    printf ("The standard deviation score is %.2f\n", StandardDeviation(gymnasticScores, Njudges));
}

double Mean(double array[], int n)
{
    double total;
    int i;

    total = 0.0;
    for (i = 0; i < n; i++) total += array[i];
    return (total / n);
}

double StandardDeviation(double array[], int n)
{
    int i;
    double avg, diff, sum;

    diff = 0;
    avg = Mean(array, n);
    for (i = 0; i < n; i++) diff += pow(array[i] - avg, 2);
    return sqrt(diff / n);
}