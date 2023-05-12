#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

/* string is not a basic type in C. codes 'typedef char *string' for string.\n */

void main()
{
    string user;

    printf("What is your name? ");
    user = GetLine();
    printf("Hello, %s.\n", user);
}