/**
 * @file myalloc.c
 * @brief exercise 13-7
 * Allocate nBytes during a program running
 * @date 2023-05-23
 */

#include "genlib.h"
#include "myalloc.h"

static char heap[1000];
static char *ptr = heap;
static char *end = &heap[999];

// void InitMalloc(void)
// {
//     char array[1000];
//     heap = array;
//     ptr = heap;
//     end = &array[999];
// }

void *MyGetBlock(int nBytes)
{
    void *p;

    // printf("addr = %lu\n", (long long) &cp);
    printf("nBytes: %d\n", nBytes);
    printf("ptr: %lu, nBytes: %d, end: %lu\n", ptr, nBytes, end);
    if (ptr + nBytes > end) Error("memoery! exceed!");
    p = ptr;
    ptr += nBytes;
    return p;
}