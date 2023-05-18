/*
* File: scanner.h
* --------------------
* Thi file is the interface to a package that divides 
* a line into individual "tokens”."A token is defined
* to be either 
*
* 1. a string of consecutive letters and digits representing
* a word, of
*
* 2. a one-character string representing a separator
* character, such as a space or a punctuation mark.
*
* To use this package, you must first call
*
* InitScanner (line);
*
* Where line is the string (typically a line returned by
* GetLine) that is to be divided into tokes. To retrieve
* each token in turn, you call
*
* token = getNextToken ();
*
* When the last token has been read, the predicate function
* AtEndOfLine returns TRUE, so that the loop structure
*
* while (!AtEndOfLine ()) {
* token = GetNextToken ();
* …process the token…
* }
*
* serves as an idiom for processing each token on the line.
*
* Further details for each function are given in the
* individual descriptions below.
*/

#ifndef _scanner_h
#define _scanner_h


#include "genlib.h"

/*
* Function: InitScanner
* Usage: InitScanner (line);
* ---------------------------------
* This function initializes the scanner and sets it up so that 
* it reds tokens from line. After InitScanner has been called, 
* the first call to GetNextToken will return the first token
* on the line, the next call will reutnr the second token,
* and so on.
*/
void InitScanner(string line);

/*
* Function: GetNextToken
* Usage: word = GetNextToken
* ---------------------------------------
* This function returns thenext token on the line.
*/
string GetNextToken(void);

/*
* Function: AtEndOfLine
* Usage: if (AtEndOfLine ())…
* -------------------------------------
* This function returns TRUE when the scanner has reached
* the end of the line.
*/
bool AtEndOfLine(void);

/**
 * Function: ReturnUppercaseTokens
 * Usage: ReturnUppercaseTokens(TRUE)
 * ----------------------------------
 * if the argument is TRUE,
 * then GetNextToken returns Uppercase Tokens.
 */
void ReturnUppercaseTokens(bool flag);

/**
 * Function: ReturnOnlyWords
 * Usage: ReturnOnlyWords(TRUE)
 * ----------------------------
 * if the argument is TRUE,
 * then GetNextToken returns only word tokens.
 */
void ReturnOnlyWords(bool flag);


#endif