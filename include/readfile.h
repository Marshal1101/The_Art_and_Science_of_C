/**
 * @file readfile.h
 * @brief reads a file to get a line unit every call
 * @date 2023-05-26
 */

#ifndef _readfile_h
#define _readfile_h

#include "genlib.h"


string *ReadFile(FILE *infile);
string GetNextLine(void);
bool AtEndOfFile(void);
int GetTotalLineCnt(void);

#endif