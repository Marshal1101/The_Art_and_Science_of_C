/**
 * @file thisoldman.c
 * @author The Art of Programming C, exercise 4-2
 * @brief 'switch'
 * @version 0.1
 * @date 2023-05-12
 */

#include <stdio.h>
#include "genlib.h"

int main()
{
    int i;
    string word;

    for (i = 1; i <= 10; i++) {
        switch (i)
        {
        case 1: word = "thumb"; break;
        case 2: word = "shoe"; break;
        case 3: word = "knee"; break;
        case 4: word = "door"; break;
        case 5: word = "hive"; break;
        case 6: word = "sticks"; break;
        case 7: word = "heaven"; break;
        case 8: word = "pate"; break;
        case 9: word = "spine"; break;
        case 10: word = "shin"; break;
        default:
            break;
        }
        printf("This old man, he played %d.\n", i);
        printf("He played knick-knack on my %s.\n", word);
        printf("With a knick-knack, paddy-whack,\n");
        printf("Give your dog a bone.\n");
        printf("This old man came rolling home.\n");
    }
    return 0;
}