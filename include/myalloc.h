/**
 * @file myalloc.h
 * @brief exercise 13-7
 * Allocate nBytes during a program running
 * @date 2023-05-23
 */

#ifndef _myalloc_h
#define _myalloc_h


#include "genlib.h"

/**
 * @brief Initiate MyGetBlock
 */
// void InitMalloc(void);


/**
 * @brief Return a pointer allocated with size of nBytes.
 * @param nBytes 
 * @return void* 
 */
void *MyGetBlock(int nBytes);


#endif