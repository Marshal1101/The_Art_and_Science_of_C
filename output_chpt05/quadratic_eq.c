/**
 * @file quadratic_eq.c
 * @brief this program prints the solutions from coefficients(a, b, c)
 *        exec 5-2
 * @date 2023-05-13
 */

#include <stdio.h>
#include <math.h>

#include "genlib.h"
#include "simpio.h"
#include "strlib.h"

double GetA(void);
void QuadraticEq(double a, double b, double c);

int main()
{
    double a, b, c;
    string ans;

    while (TRUE) {
        printf("Enter coefficients for the quadratic equation:\n");
        a = GetA();
        printf("b (linear's co): ");
        b = GetReal();
        printf("c (constant): ");
        c = GetReal();
        QuadraticEq(a, b, c);
        printf("Do you want to finish? (y/n) ");
        ans = GetLine();
        if (StringEqual(ans, "y")) break;
    }
    return 0;
}

/**
 * Function: GetA
 * Usage: a = GetA();
 * ------------------
 * GetA returns 'a', square's coefficient from user input.
 * GetA reject a value 0 
 */
double GetA(void)
{
    double a;

    while (TRUE) {
        printf("a (square's co.): ");
        a = GetReal();
        if (a != 0) return a;
        printf("a is assumed not 0.\n");
    }
}

/**
 * Function: QuadraticEq
 * Usage: QuadraticEq(a, b, c);
 * ------------------
 * QuadraticEq print real solution of the equation
 * with coefficient a, b, c given.
 */
void QuadraticEq(double a, double b, double c)
{
    double root, s1, s2;

    root = b * b - 4 * a * c;
    if (root < 0) {
        printf("there are no real solutions\n");
        return;
    }
    s1 = (-b + sqrt(root)) / (2*a);
    printf("The first solution is %lf\n", s1);
    s2 = (-b - sqrt(root)) / (2*a);
    printf("The second solution is %lf\n", s2);
}
