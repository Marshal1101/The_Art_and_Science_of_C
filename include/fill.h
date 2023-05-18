/*
* fill.h
* -----
* This file is the interface to an abstraction that enables 
* you to display filled output. To use the package, you first 
* call SetFillMargin to set an output margin and then make
* calls to PrintFilledString to display the output. These
* functions are described in more detail below.
*/

#ifndef _fill_h
#define _fill_h
#include "genlib.h"

/*
* Function: SetFillMargin
* Usage: SetFillMargin (margin);
* -----------------------------------------
* This function sets the fill margin to the value given by the 
* margin parameter. When strings are displayed using the 
* function PrintFilledString, the output will be broken up
* into separate lines so that no lines extend past the margin.
* If no margin is set explicitly, the package uses 65 for the 
* fill margin as a default.
*
* The primes between 0 and 200 are: 2, 3, 5, 7, 11, 13, 
* 17, 19, 23, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
* 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 
* 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 
* 193, 197, 199,
*/
void SetFillMargin(int margin);

/*
* Funciton: PrintFilledString
* Usage: PrintFilledString (str);
* ---------------------------------------
* The string str is displayed on the screen, starting from 
* where the last string left off. Spaces and newline characters 
* in the strin are treated specially. If a space character
* appears in an argument, the function may choose to divide 
* the string at that point by moving to the next line.
* Such division occurs when the next word would not fit
* within the margin established by SetFillMargin. A newline 
* character in the string froces the cursor to advance to the
* beginning of the next line.
*/
void PrintFilledString(string str);


#endif