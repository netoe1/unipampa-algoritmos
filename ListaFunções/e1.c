/*
    1 - Escreva uma função potencia(base, expoente) que, quando chamada, retorna base elevado no expoente. Por exemplo, potencia(3, 3) deve retornar 81.
    Assuma que expoente é um inteiro maior ou igual a 1.
*/

#include <stdio.h>
#include <stdlib.h>

int potencia(int base, unsigned int exp)
{
    int i = 0;
    int ret = 0;
    if (exp == 1)
    {
        return base;
    }
    else if (exp == 0)
    {
        return 1;
    }

    for (i = 1; i <= exp; i++)
    {
        ret = base * base;
    }
    return ret;
}
int main()
{
    printf("\np:%d",potencia(3,3));
    return 0;
}