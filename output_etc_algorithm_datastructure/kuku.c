#include <stdio.h>

#define nElements   9


int sum(int x1, int x2)
{
    return x1 + x2;
}

int mul(int x1, int x2)
{
    return x1 * x2;
}

// void kuku(int(*calc) (int, int))
void kuku(int calc(int, int))
{
    int i, j;
    for (i = 1; i <= nElements; i++) {
        for (j = 1; j <=nElements; j++) {
            // printf("%3d", (*calc)(i, j));
            printf("%3d", calc(i, j));
        }
        putchar('\n');
    }
}

int main(void)
{
    puts("sum");
    kuku(sum);
    puts("mul");
    kuku(mul);
    printf("�̰Կ־ȵ�?\n");
    return 0;
}