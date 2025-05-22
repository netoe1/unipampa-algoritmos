/*
2. Implemente um método recursivo que receba como entrada um número inteiro
positivo N e retorne o seguinte cálculo: 1/n
*/

#include <stdio.h>
#include <stdlib.h>

float ninverso(float n)
{
    if (n == 1)
    {
        return 1.0;
    }
    else
    {
        return (1.0 / n) + (1.0 / ninverso(n - 1.0));
    }
}
int main(void)
{
    int n = 2;
    printf("\nsum(1/n):%f", ninverso(n));
    printf("\n");
    return 0;
}