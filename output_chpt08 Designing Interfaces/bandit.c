/**
 * @file bandit.c
 * @brief a one-armed slot machine with three symbols. exercise 8-12
 */

#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "random.h"

#define FirstMoney   50

bool GetYesOrNo(string prompt);
void Instruction(void);
int PlayGame(void);
int CountPoint(int symbol);
string SymToStr(int sym);

int main()
{
    int money, pays;
    string ans;

    Randomize();
    // 도움말 묻기
    if (GetYesOrNo("Would you like instructions?")) Instruction();
    money = FirstMoney;
    while (money > 0) {
        // 게임실행 묻기
        printf("You have $%d. ", money);
        if (GetYesOrNo("Would you like to play?")) {
            money -= 1;
            pays = PlayGame();
            money += pays;
        } else {
            return 0;
        }
    }
    printf("you don't have money anymore. see you!\n");
    return 0;
}

bool GetYesOrNo(string prompt)
{
    string ans;

    while (TRUE) {
        printf("%s ", prompt);
        ans = GetLine();
        if (StringEqual(ans, "yes")) {
            return (TRUE);
        } else if (StringEqual(ans, "no")) {
            return (FALSE);
        } else {
            printf("Please reply only yes or no.\n");
        }
    }
}

void Instruction(void)
{
    int i, s1, s2, s3, point;

    printf("This is your win case. get the pays!\n");
    for (i = 666; i > 99; i--) {
        s1 = i / 100;
        s2 = (i % 100) / 10;
        s3 = i % 10;
        point = CountPoint(i);
        if (point > 0) printf("%-9s%-9s%-9s    pays   $%d\n", SymToStr(s1), SymToStr(s2), SymToStr(s3), point);
    }
}

int PlayGame(void)
{
    int i, s1, s2, s3, symbol, pays;

    s1 = RandomInteger(1, 6);
    s2 = RandomInteger(1, 6);
    s3 = RandomInteger(1, 6);
    symbol = s1*100 + s1*10 + s3;
    pays = CountPoint(symbol);
    printf("%s %s %s -- ", SymToStr(s1), SymToStr(s2), SymToStr(s3));
    if (pays > 0) {
        printf("You win %d\n", pays);
    } else {
        printf("You lose\n");
    }
    return pays;
}

int CountPoint(int symbol)
{
    int pays;

    switch (symbol)
    {
    case 666: pays = 250; break;
    case 556: case 555: pays = 20; break;
    case 446: case 444: pays = 14; break;
    case 336: case 333: pays = 10; break;
    case 111: pays = 7; break;
    case 110: pays = 5; break;
    case 100: pays = 2; break;
    default: pays = 0; break;
    }
    return (pays);
}

string SymToStr(int sym)
{
    switch (sym)
    {
    case 1: return "CHERRY"; break;
    case 2: return "LEMON"; break;
    case 3: return "ORANGE"; break;
    case 4: return "PLUM"; break;
    case 5: return "BELL"; break;
    case 6: return "BAR"; break;
    default: return "-"; break;
    }
}