/*
    1. Implemente um método recursivo que receba como entrada um número inteiro
positivo N e retorne o seguinte cálculo:
 1 + 2 + 3 + 4 + ... + N.
*/

#include <stdio.h>
#include <stdlib.h>

int soma_n(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return (n + soma_n(n - 1));
    }
}
int main(void)
{
    int n = 4;
    printf("\nSoma %d:%d", n, soma_n(n));
    return 0;
}