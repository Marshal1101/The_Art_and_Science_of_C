/**
 * @file stack.c
 * @brief 
 * @date 2023-06-01
 */

#include <stdio.h>

#include "genlib.h"
#include "strlib.h"
#include "stack.h"

/*
* Constants:
* --------------
* MaxStackSize -- Maximum number of elements in the Stack
*/

#define MaxStackSize 10

static int ext = 1;

static void ExtendStack(stackADT stack);
static stackADT ExtendNewStack(stackADT stack);
static string Copy(void *vp);


struct stackCDT {
    void **array;
    int ptr;
    int maxSize;
};

stackADT NewStack(void)
{
    stackADT stack;

    stack = New(stackADT);
    stack->array = (void **) GetBlock(ext * MaxStackSize * sizeof(long long));
    stack->ptr = 0;
    stack->maxSize = ext * MaxStackSize;
    return (stack);
}

void FreeStack(stackADT stack)
{
    FreeBlock(stack);
}

void Push(stackADT stack, void *obj)
{
    if (stack->ptr == stack->maxSize) {
        ExtendStack(stack);
    }
    stack->array[stack->ptr++] = obj;
}

static void ExtendStack(stackADT stack)
{
    stackADT newStack;
    int i, len;

    newStack = ExtendNewStack(stack);
    len = stack->ptr;
    for (i = 0; i < len; i++) {
        newStack->array[i] = stack->array[i];
    }
    FreeBlock(stack->array);
    stack->array = newStack->array;
    stack->maxSize = newStack->maxSize;
}

static stackADT ExtendNewStack(stackADT stack)
{
    stackADT newStack;

    ext = 2 * (stack->maxSize / MaxStackSize);
    newStack = NewStack();
    ext = 1;
    return newStack;
}

void *Pop(stackADT stack)
{
    void *result;
    int i;

    if (stack->ptr == 0) {
        printf("Pop of empty stack -- try Push\n");
        return NULL;
    }
    result = stack->array[--(stack->ptr)];
    return (result);
}

void Clear(stackADT stack)
{
    stack->ptr = 0;
}

int StackLength(stackADT stack)
{
    return stack->ptr;
}

void ShowStackElement(stackADT stack)
{
    int i, len;

    len = stack->ptr;
    for (i = 0; i < len; i++) {
        printf("%d:%s, ", i, stack->array[i]);
    }
    printf("maxSize: %d\n", stack->maxSize);
}