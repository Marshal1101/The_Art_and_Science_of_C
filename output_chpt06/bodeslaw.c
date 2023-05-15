/**
 * @file bodeslaw.c 
 * @brief exercise 6-6
    Mathematicians and other scientists sometimes find unexpected applications for 
    power series approximation. In 1772, the astronomer J.E. bode proposed a rule for 
    calculating the distance from the sun to each of the planets known at that time. To 
    apply that rule, which subsequently became known as Bode’s law, you begin by 
    writing down the sequence

    b1 = 1, b2 = 3, b3 = 6, b4 = 12, b5 = 24, b6 = 48
    
    where each subsequent element in the sequence is twice the preceding one. It turns 
    out that an approximate distance to the ith planet can be computed from this series by 
    applying the formula
    
    di = (4 + b1) / 10
    
    The distance is given in astronomical units; an astronomical unit (AU) is the 
    average distance from the sun to the earth, which is approximately 93,000,000 miles. 
    Except for a disconcerting gap between Mars and Jupiter, Bode’s law gives 
    reasonable approximations for the distances to the seven planets known in Bode’s 
    day:

    Mercury 0.5 AU
    Venus 0.7 AU
    Earth 1.0 AU
    Mars 1.6 AU
    ? 2.8 AU
    Jupiter 5.2 AU
    Saturn 10.0 AU
    Uranus 19.6 AU
    
    Concern about the gap in the sequence led astronomers to discover the asteroid belt, 
    which they decided was left over after the destruction of a planet that had once 
    orbited the sun at distance specified by the missing entry in Bode’s table.
    Write a program to display the above table, using Bode’s formula to calculate 
    the distances.
 */

#include <stdio.h>
#include "genlib.h"

int main()
{
    int i, b;
    double d;
    string arr[9] = {
        "Mercury",
        "Venus",
        "Earth",
        "Mars",
        "?",
        "Jupiter",
        "Saturn",
        "Uranus"
    };

    b = 1;
    d = (4 + b) / 10.0;
    printf("%-10s%.1f AU\n", arr[0], d);
    b = 3;
    for (i = 1; i < 8; i++) {
        d = (4 + b) / 10.0;
        printf("%-10s%.1f AU\n", arr[i], d);
        b *= 2;
    }

    return 0;
}