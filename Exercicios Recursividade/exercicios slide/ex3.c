/*
    Mostre na tela o somatório de 1 a 15;
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int sum(int cont)
{
    printf("\nValor de N:%d", cont);
    if (cont == 15)
    {
        return 15;
    }
    else
    {
        return sum(cont + 1) + cont;
    }
}
int main(void)
{
    setlocale(LC_ALL, "");
    sum(1);
    printf("\n");
    return 0;
}