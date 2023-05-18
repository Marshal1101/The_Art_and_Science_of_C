/**
 * @brief labelseq.c
 * This source is implementation of labelseq.h
 */

#include <stdio.h>
#include "genlib.h"
#include "strlib.h"
#include "labelseq.h"

static string label;
static int number;

/**
 * Function: InitLabelseq
 * -----------------------------
 * Initiates the Labelseq module with
 * a prifix "Label" basically.
 * @param prefix 
 */
void InitLabelseq(void)
{
    label = "Label";
    number = 1;
}

/**
 * Function: GetNextLabel
 * -----------------------------
 * returns token label with a number sequentially.
 * @return string 
 */
string GetNextLabel(void)
{
    return (Concat(label, IntegerToString(number++)));
}

/**
 * Function: SetLabelPrefix
 * -------------------------------
 * This Functoin controls 'static string label'
 * @param prefix 
 */
void SetLabelPrefix(string prefix)
{
    label = prefix;
}

/**
 * Function: SetLabelNumber
 * -------------------------
 * This Functoin controls 'static int number'
 * @param nextNumber 
 */
void SetLabelNumber(int nextNumber)
{
    number = nextNumber;
}