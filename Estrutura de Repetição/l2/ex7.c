#include <stdio.h>

/*
    7 - Fazer um programa que gere a saída:
* * * * * * * * * * * *
O,2,4,6,8,10,12,14
* * * * * * * * * * * *
*/

#define MAX 12

int main(void)
{
    int i = 0;
    int n = 0;
    for (i = 0; i < MAX; i++)
    {
        printf("* ");
    }
    printf("\n");

    for (i = 0; i < 7; i++)
    {
        n += 2;
        printf("%d-", n);
    }
    printf("\n");
    for (i = 0; i < MAX; i++)
    {
        printf("* ");
    }
    printf("\n");
    return 0;
}