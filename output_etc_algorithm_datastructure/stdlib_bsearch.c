#include <stdio.h>
#include <stdlib.h>

#include "genlib.h"
#include "simpio.h"

int int_cmp(const void *a, const void *b);


#define nElements    10

int main(void)
{
    int i, key;
    int *p, array[nElements];


    for (i = 0; i < nElements; i++) array[i] = i;
    key = GetInteger();
    p = bsearch(&key, array, nElements, sizeof(int), (int(*)(const void *, const void *))int_cmp);
    if (p == NULL) printf("NULL\n");
    printf("%d %d\n", p, *p);
    return 0;
}

/* 내림차순 비교함수 */
int int_cmp(const void *a, const void *b)
{
    if (*(int *)a < *(int *)b) return -1;
    else if (*(int *)a > *(int *)b) return 1;
    else return 0; 
}