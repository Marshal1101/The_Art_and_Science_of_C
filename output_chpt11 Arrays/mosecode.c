/**
 * @file mosecode.c
 * @brief exercise 11-6
 * In May of 1833, Samuel F.B. Morse set the message ―What hath God 
 * Wrought!‖ by telegraph from Washington to Baltimore, heralding the 
 * beginning of the age of electronic communication. 
 * @date 2023-05-20
 * 
 * In Mores code, the 26 letters of the alphabet are represented by the 
 * following codes:
 * A ·━ J • ━ ━ ━ S • • •
 * B ━ • • • K ━ • ━ T ━
 * C ━ • ━ • L • ━ • • • U • • ━
 * D ━ • • M ━ ━ V • • • ━
 * E • N ━ • W • ━ ━
 * F • • ━ • O ━ ━ ━ X ━ • • ━
 * G ━ ━ • P • ━ ━ • Y ━ • ━ ━
 * H • • • • Q ━ ━ • ━ Z ━ ━ • •
 * I • • R • ━ •
 * 
 * output:
 * This program translates a lie into Mores code.
 * Enter English text: What hath God wrought
 * .-- .... .- -
 * .... .- - ....
 * --. --- -..
 * .-- .-. --- ..- --. .... -
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "scanner.h"


string MoseCode(string sentence);


int main()
{
    string sentence, code;
    printf("This program translates a line into Morse code.\n");
    printf("Enter English text: ");
    sentence = GetLine();
    printf("%s\n", MoseCode(sentence));
    return 0;
}

string MoseCode(string sentence)
{
    sentence = ConvertToUpperCase(sentence);

    string code;
    char ch;
    int i, length;
    string moseArr[26] = {
        ".- ", "-... ", "-.-. ", "-.. ", ". ", "..-. ", "--. ", ".... ", ".. ",
        ".--- ", "-.- ", ".-.. ", "-- ", "-. ", "--- ", ".--. ", "--.- ", ".-. ",
        "... ", "- ", "..- ", "...- ", ".-- ", "-..- ", "-.-- ", "--.. ",
    };
    code = "";
    length = StringLength(sentence);
    for (i = 0; i < length; i++) {
        ch = IthChar(sentence, i);
        if (ch == ' ') code = Concat(code, "\n");
        else code = Concat(code, moseArr[ch-'A']);
    }
    return code;
}