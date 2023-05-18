/**
 * @file labelseq.h
 * @brief exercise 10-11 
 * Your interface should export a function GetNextLabel
 * that takes no arguments and returns the next label
 * in the sequence. If no explicit initialization is performed,
 * the labels should use the string “Label” as the prefix and
 * begin with sequence number 1. Clients, however, should be
 * able to change these defaults by calling SetLabelPrefix (prefix)
 * and SetLabelNumber (nextNumber) to set the prefix
 * and sequence number, respectively, for the next label.
 * Implement the interface by writing the corresponding labelseq.c file.
 */

#ifndef _labelseq_h
#define _labelseq_h

#include "genlib.h"

/**
 * Function: InitLabelseq
 * Usage: InitLabelseq()
 * -----------------------------
 * Initiates the Labelseq module with
 * a prifix "Label" basically.
 * @param prefix 
 */
void InitLabelseq(void);

/**
 * Function: GetNextLabel
 * Usage: token = GetNextLabel()
 * -----------------------------
 * returns token label with a number sequentially.
 * @return string 
 */
string GetNextLabel(void);

/**
 * Function: SetLabelPrefix
 * Usage: SetLabelPrefix("Figure")
 * -------------------------------
 * set the prefix of this label to one string argument.
 * @param prefix 
 */
void SetLabelPrefix(string prefix);

/**
 * Function: SetLabelNumber
 * Usage: SetLabelNumber(0)
 * -------------------------
 * set the next number of the label to one integer argument.
 * @param nextNumber 
 */
void SetLabelNumber(int nextNumber);


#endif