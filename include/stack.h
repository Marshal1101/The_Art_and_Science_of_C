#ifndef _stack_h
#define _stack_h

#include "genlib.h"

typedef struct stackCDT *stackADT;

stackADT NewStack(void);

void FreeStack(stackADT stack);

void Push(stackADT stack, void *obj);

void *Pop(stackADT stack);

void Clear(stackADT stack);

int StackLength(stackADT stack);

void ShowStackElement(stackADT stack);


#endif