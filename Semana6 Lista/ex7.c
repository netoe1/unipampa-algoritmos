#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

float power(int base, int exp)
{
    float aux = 1.0;

    for (int i = 0; i < abs(exp); i++)
    {
        aux *= (float)base;
    }

    if (exp < 0)
    {
        return 1 / aux;
    }

    return aux;
}

int main(void)
{
    setlocale(LC_ALL, "");
    int x = 0;
    int y = 0;
    printf("\nDigite um valor de potencia x^y:\n");
    scanf("%d %d", &x, &y);

    printf("\nResultado:%.8f\n", power(x, y));
    return 0;
}