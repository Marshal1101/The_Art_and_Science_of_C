/**
 * @file hangman.c
 * @brief exercise 14-12
 * @date 2023-05-25
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "genlib.h"
#include "simpio.h"
#include "random.h"

#define MaxElements      3

/* Private variables */
static char *candiate[MaxElements] = {
    "JUNK", "FRANCE", "ZERO"
};
static char *word;
static char *currentMatch;

/* Private functions */
static void GetInstructions(void);
static void PlayGame(void);
static void InitSecretWord();
static char Guess(void);
static void *ShowCurrentMatch(void);
static int CheckAnswer(char ans);
static int FindCharInWord(char ans, char *s);
static int CheckFinish(void);

int main()
{
    GetInstructions();
    PlayGame();
    return 0;
}

static void GetInstructions(void)
{
    printf("Let's play hangman! I will pci a secret word.\n");
    printf("On each turn, you guess a letter. If the letter\n");
    printf("is in the sectet word, I will show you where it\n");
    printf("appears. If you make an incorrect guess, part\n");
    printf("of your body gets strung up on the scaffold.\n");
    printf("The object is to guess the word before you are\n");
    printf("hanged.\n");
}

static void PlayGame(void)
{
    char ans;
    int try;

    InitSecretWord();
    try = 8;
    while (try > 0) {
        ShowCurrentMatch();
        printf("You have %d guesses left.\n", try);
        ans = Guess();
        if(!CheckAnswer(ans)) try--;
        if (CheckFinish()) {
            printf("You guessed the word: %s\n", word);
            printf("You Win.\n");
            return;
        }
    }
    printf("You lose. The word was %s\n", word);
}

static void InitSecretWord()
{
    
    int i, len;
    char *cp;

    Randomize();
    i = RandomInteger(0, MaxElements-1);
    word = candiate[i];
    len = strlen(word);
    currentMatch = (char *) malloc(len + 1);
    if (currentMatch == NULL) Error("currentMatch var memory error");
    for (i = 0; i < len; i++) {
        *(currentMatch + i) = '-';
    }
    *(currentMatch + i) = '\0';
}

static char Guess(void)
{
    char ans;
    string line;

    while (TRUE) {
        printf("your guess: ");
        line = GetLine();
        if (strlen(line) == 1) break;
        printf("guess only one character.\n");
    }
    return toupper(line[0]);
}

static void *ShowCurrentMatch(void)
{
    char *p;
    int len;

    len = strlen(currentMatch);
    p = (char *) malloc(len + 1);
    strncpy(p, currentMatch, len + 1);
    printf("The word now looks like this: %s\n", p);
}

static int CheckAnswer(char ans)
{
    char *cp;
    int i;

    if (FindCharInWord(ans, word) == -1) {
        printf("There are no %c's in the word.\n", ans);
        return 0;
    } else {
        cp = word;
        for (cp = word; *(cp + i); i++) {
            if (*(cp + i) == ans) {
                *(currentMatch + i) = ans;
            }
        }
        printf("That guess is correct.\n");
        return 1;
    }
}

static int FindCharInWord(char ans, char *s)
{
    char *cp;
    int i, len;

    len = strlen(s);
    cp = s;
    for (i = 0; i < len; i++) {
        if (*(cp + i) == ans) return i;
    }
    return -1;
}

static int CheckFinish(void)
{
    if (FindCharInWord('-', currentMatch) == -1) return 1;
    return 0;
}