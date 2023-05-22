/*
* File: gymjudge.c
* ----------------------
* This program averages a set of five gymnastic scores.
*/
#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"
#include "sort.h"

/*
* Contants 
* ------------
* Njudges – Number of judges
*/
#define Njudges 6

/* Prototype Functions */
double Mean(double array[], int n);                     // exercise 11-2
double StandardDeviation(double array[], int n);        // exercise 11-3
double Median(double array[], int n);                   // exercise 12-5
double Mode(double array[], int n);                     // exercise 12-6

/* Main program */
int main()
{
    int i;
    double gymnasticScores[Njudges];
    double total, average;

    for (i = 0; i < Njudges; i++) {
        printf ("Score for judge #%d: ", i);
        gymnasticScores[i] = GetReal();
    }
    printf("The average score is %.2f\n", Mean(gymnasticScores, Njudges));
    printf("The standard deviation score is %.2f\n", StandardDeviation(gymnasticScores, Njudges));
    printf("The median score is %.2f\n", Median(gymnasticScores, Njudges));
    printf("The mod score is %.2f\n", Mode(gymnasticScores, Njudges));
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

double Median(double array[], int n)
{
    SortRealArray(array, n);
    if (n % 2 != 0) return array[n/2];
    else return (array[n/2] + array[n/2-1]) / 2;
}

double Mode(double array[], int n)
{
    int i, cnt, spos, maxi, maxc;

    SortRealArray(array, n);
    maxi = maxc = cnt = spos = 0;
    for (i = 0; i < n; i++) {
        if (array[spos] == array[i]) {
            cnt++;
        }
        else {
            if (cnt > maxc) {
                maxi = spos;
                maxc = cnt;
            }
            spos = i;
            cnt = 1;
        }
    }
    return array[maxi];
}