/*
    Implemente a a função troca(), que troca o valor de duas variáveis.
    A função recebe como argumento dois endereços de memória, que
    são atribuídos a dois ponteiros.
*/

#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b);

int main(void)
{
    int valorA = 1;
    int valorB = 0;

    printf("\nA:%d\nB:%d", valorA, valorB);
    troca(&valorA, &valorB);
    printf("\nValor apos troca:\nA:%d\nB:%d", valorA, valorB);

    return 0;
}

void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}