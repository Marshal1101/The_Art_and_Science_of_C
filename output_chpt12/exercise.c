/**
 * @file exercise.c
 * @brief 
 * @date 2023-05-21
 */

#include <stdio.h>
#include <math.h>

#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "random.h"

/* Constants */
#define NBandColor      10
#define MaxElements    250

/* Prototype Functions */
void exe01(void);
int FindColorInArray(string array[], string color);
int GetBandNumber(string array[]);
void GiveInstructions(string array[]);
void exe02(void);
bool GetYesOrNo(void);
void exe03(void);
bool IsSortd(int array[], int n);
int GetIntegerArray(int array[], int max, int sentinel);
void exe07(void);
int RemoveZeroElements(int array[], int n);
static void SwapIntegerElements(int array[], int p1, int p2);
void exe08(void);
int RemoveDuplicates(int array[], int n);


int main()
{
    // exe01();
    // exe02();
    // exe03();
    // exe07();
    exe08();
    return 0;
}

void exe01(void)
{
    string colorNameArr[NBandColor] = {
        "Black", "Brown", "Red", "Orange", "Yellow",
        "Green", "Blue", "Violet", "Gray", "White",
    };
    string first, second, third;
    int i, tend, unitd, expod;

    printf("This program interpretes the resister color code.\n");
    printf("Color of first band: ");
    tend = GetBandNumber(colorNameArr);
    printf("Color of second band: ");
    unitd = GetBandNumber(colorNameArr);
    printf("Color of third band: ");
    expod = GetBandNumber(colorNameArr);
    printf("tend: %d, unitd: %d, expod: %d, pow: %lf\n", tend, unitd, expod, pow(10, expod));
    printf("Resistance = %g ohms.\n", (tend*10 + unitd) * pow(10.0, expod));
}

int FindColorInArray(string array[], string color)
{
    int i;

    for (i = 0; i < NBandColor; i++) {
        if (StringEqual(array[i], color)) return i;
    }
    return -1;
}

int GetBandNumber(string array[])
{
    int num;
    string color;

    while (TRUE) {
        printf("Color of first band: ");
        color = GetLine();
        num = FindColorInArray(array, color);
        if (num != -1) return num;
        GiveInstructions(array);
    }
}

void GiveInstructions(string array[])
{
    int i;

    printf("COLOR TABLE ======================\n");
    for (i = 0; i < NBandColor; i += 2) {
        printf("%-3d%-12s%-3d%-12s\n", i, array[i], i+1, array[i+1]);
    }
    printf("COLOR TABLE ======================\n");
    printf("Choose one color in the table.\n");
}

void exe02(void)
{
    int lp, rp, mid;
    string ans;

    printf("Think of a number between 1 and 100 and I'll guess it.\n");
    lp = 1;
    rp = 100;
    while (lp <= rp) {
        mid = (lp + rp) / 2;
        printf("Is it %d? ", mid);
        if (GetYesOrNo()) {
            printf("I guessed the number!\n");
            return;
        }
        printf("Is it less than %d? ", mid);
        if (GetYesOrNo()) {
            rp = mid - 1;
        } else {
            lp = mid + 1;
        }
    }
    printf("you lied.\n");
}

bool GetYesOrNo(void)
{
    string ans;

    while (TRUE) {
        ans = GetLine();
        if (StringEqual(ans, "yes")) return TRUE;
        if (StringEqual(ans, "no")) return FALSE;
        printf("please answer yes or no >> ");
    }
}

void exe03(void)
{
    int arr[MaxElements];
    int i, n;

    n = GetIntegerArray(arr, MaxElements, -1);
    printf("This array is %s.\n", (IsSortd(arr, n) ? "sorted" : "not sorted"));
}

bool IsSortd(int array[], int n)
{
    int i;

    for (i = 0; i < n-1; i++) {
        if (array[i] > array[i+1]) return FALSE;
    }
    return TRUE;
}

int GetIntegerArray(int array[], int max, int sentinel)
{
    int n, value;

    n = 0;
    printf("Input Integers to make an array. end is -1.\n");
    while (TRUE) {
        printf("value of index %d? ", n);
        value = GetInteger();
        if (value == sentinel) break;
        if (value < 0) {
            printf("value is above 0.\n");
            continue;
        }
        if (n == max) Error("Too many input items for array");
        array[n] = value;
        n++; 
    }
    return (n);
}

void exe07(void)
{
    int n, nn;
    int array[MaxElements];

    printf("This program tests RemoveZeroElements Funcion.\n");
    n = GetIntegerArray(array, MaxElements, -1);
    nn = RemoveZeroElements(array, n);
    printf("%d %d", n, nn);
    printf("The number of removed elements is %d\n", n-nn);
}

int RemoveZeroElements(int array[], int n)
{
    int i, zpos, cnt;

    zpos = -1;
    for (i = 0; i < n; i++) {
        if (array[i] == 0) {
            zpos = i;
            break;
        }
    }
    if (zpos == -1) return n;

    cnt = zpos;
    for (i = zpos + 1; i < n; i++) {
        if (array[i] != 0) {
            SwapIntegerElements(array, zpos, i);
            zpos = ++cnt;
        }
    }
    return cnt;
}

static void SwapIntegerElements(int array[], int p1, int p2)
{
    int tmp;

    tmp = array[p1];
    array[p1] = array[p2];
    array[p2] = tmp;
}

void exe08(void)
{
    int n, nn;
    int array[MaxElements];

    printf("This program tests RemoveDuplicates Funcion.\n");
    n = GetIntegerArray(array, MaxElements, -1);
    nn = RemoveDuplicates(array, n);
    printf("%d %d", n, nn);
    printf("The number of removed elements is %d\n", n-nn);
}

int RemoveDuplicates(int array[], int n)
{
    if (n <= 0) return n;

    int i, spos;
    bool seqflag;

    seqflag = FALSE;
    spos = 0;
    for (i = 1; i < n; i++) {
        if (array[spos] == array[i]) {
            if (!seqflag) {
                seqflag = TRUE;
            }
        } else {
            if (seqflag) {
                array[++spos] = array[i];
                seqflag = FALSE;
            } else {
                if (spos + 1 != i) array[++spos] = array[i];
                else spos++;
            }
        }
    }

    return spos + 1;
}