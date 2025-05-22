/*
Implementar uma função recursiva POTENCIA que recebe uma base (real) e um
expoente (inteiro) e retorna o valor da Base elevada ao expoente;

*/

#include <stdio.h>
#include <stdlib.h>

float potencia(float real, int exp)
{
    if (exp == 0)
    {
        return 1;
    }

    else if (exp > 0)
    {
        return (real * potencia(real, exp - 1));
    }

    else
    {
        return 1 / potencia(real, -exp);
    }
}

int main(void)
{

    printf("\n%f", potencia(2, -4));
    return EXIT_SUCCESS;
}