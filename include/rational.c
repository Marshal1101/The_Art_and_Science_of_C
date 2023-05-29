/**
 * @file rational.c
 * @brief exercise 16-5
 * @date 2023-05-29
 */

#include <stdio.h>
#include <ctype.h>

#include "rational.h"
#include "simpio.h"
#include "strlib.h"


static rationalT Getdisjoint(rationalT r);
static bool IsDigit(string str);



/**
 * @brief Create a Rational object
 * A function CreateRational (num, den), which returns the rational
 * @param num 
 * @param den 
 * @return rationalT 
 */
rationalT CreateRational(int num, int den)
{
    rationalT r;

    r.num = num;
    r.den = den;
    return r;
}

/**
 * @brief A function AddRational (r1, r2), 
 * which returns the sum of two rational numbers. 
 * @param r1 
 * @param r2 
 * @return rationalT 
 */
rationalT AddRational(rationalT r1, rationalT r2)
{
    rationalT r;

    r.num = (r1.num * r2.den + r2.num * r1.den);
    r.den = (r1.den * r2.den);
    return Getdisjoint(r);
}

/**
 * @brief A function MultiplyRational (r1, r2),
 * which returns the product of two rational numbers.
 * @param r1 
 * @param r2 
 * @return rationalT 
 */
rationalT MultiplyRational(rationalT r1, rationalT r2)
{
    rationalT r;

    r.den = r1.den * r2.den;
    r.num = r1.num * r2.num;
    return Getdisjoint(r);
}

/**
 * @brief Get the Rational object
 * A function GetRational (r), which reads
 * a retinal number from the user
 * in the from num/den.
 * @return rationalT 
 */
rationalT GetRational(void)
{
    rationalT r;
    string line, head, tail;
    int i, len;

    while (TRUE) {
        line = GetLine();
        len = StringLength(line);
        if (len > 2) {
            i = FindChar('/', line, 0);
            if (i != -1) {
                head = SubString(line, 0, i-1);
                tail = SubString(line, i+1, len-1);
                if (IsDigit(head) && IsDigit(tail)) {
                    r.num = StringToInteger(head);
                    r.den = StringToInteger(tail);
                    break;
                }
            }
        }
        printf("Error format -- input: x/y\n");
    }
    return r;
}

rationalT GetStringToRational(string r)
{
    rationalT result;
    string head, tail;
    int i, len;

    len = StringLength(r);
    if (len > 2) {
        i = FindChar('/', r, 0);
        if (i != -1) {
            head = SubString(r, 0, i-1);
            tail = SubString(r, i+1, len-1);
            if (IsDigit(head) && IsDigit(tail)) {
                result.num = StringToInteger(head);
                result.den = StringToInteger(tail);
                return result;
            }
        }
    }
    // printf("Error format -- input: x/y\n");
    result.den = 0;
    result.num = 0;
    return result;
}

/**
 * @brief A function PrintRational (r), 
 * which displays the number as 
 * a fraction on the screen.
 * @param r 
 */
void PrintRational(rationalT r)
{
    printf("%d/%d\n", r.num, r.den);
}


static rationalT Getdisjoint(rationalT r)
{
    rationalT disjoint;
    int i;

    i = (r.den < r.num ? r.den : r.num);
    while (i > 1) {
        if (r.den % i == 0 && r.num % i == 0) {
            r.den /= i;
            r.num /= i;
            i = (r.den < r.num ? r.den : r.num);
        } else {
            i--;
        }
    }
    return r;
}

static bool IsDigit(string str)
{
    char *cp;

    for (cp = str; *cp; cp++) {
        if (!isdigit(*cp)) return FALSE;
    }
    return TRUE;
}