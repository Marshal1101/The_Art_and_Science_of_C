/**
 * @file qarithmetic.c
 * @brief This program is questioning random problems. exercise 8-8,9
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "random.h"


#define NumOfQuesions   5

#define SWAP(x, y)  {int t; t = x; x = y; y = t;}

int main()
{
    int n, tries, a, b, ans, reply, d;
    bool isPlus;
    string congrat;

    Randomize();
    printf("Welcome to Math Quiz!\n");
    n = NumOfQuesions;
    while (n-- > 0) {
        while (TRUE) {
            a = RandomInteger(1, 20);
            b = RandomInteger(1, 20);
            if (a < b) SWAP(a, b);
            if (RandomChance(0.5)) {
                ans = a + b;
                isPlus = TRUE;
            } else {
                ans = a - b;
                isPlus = FALSE;
            }
            if (ans > 0 && ans <= 20) break;
        }
        
        printf("what is %d %c %d? ", a, (isPlus ? '+' : '-'), b);
        reply = GetInteger();
        tries = 2;
        while (TRUE) {
            if (reply == ans) {
                d = RandomInteger(0, 4);
                switch (d)
                {
                case 1:
                    printf("Correct!\n");
                    break;
                case 2:
                    printf("Right!\n");
                    break;
                case 3:
                    printf("You got it! The answer is %d\n", ans);
                case 4:
                    printf("Easy peasy lemon squeezy.\n");
                default:
                    printf("That's the answer!\n");
                    break;
                }
                break;
            } else if (tries > 0) {
                printf("That's incorrect. Try a different answer: ");
                reply = GetInteger();
                tries--;
            } else {
                printf("No, the answer is %d.\n", ans);
                break;
            }
        }
    }
    return 0;
}