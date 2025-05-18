/*
- Receber dois números e imprimi-los em ordem crescente.
*/

#include <stdio.h>

int main(void)
{
    int n1 = 0;
    int n2 = 0;

    printf("\nInforme n1:");
    scanf("%d", &n1);

    printf("\nInforme n2:");
    scanf("%d", &n2);

    if (n1 >= n2)
    {
        printf("\n[%d][%d]\n", n2, n1);
    }
    else if (n1 < n2)
    {
        printf("\n[%d][%d]\n", n1, n2);
    }
    return 0;
}