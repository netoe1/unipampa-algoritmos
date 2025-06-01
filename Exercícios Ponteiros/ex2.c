/*
    Escreva uma função mm que receba um vetor inteiro v[10] e os
endereços de duas variáveis inteiras, digamos min e max, e deposite
nessas variáveis o valor do elemento mínimo e o valor de um
elemento máximo do vetor. Escreva também uma função main que
use a função mm
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mm(int v[10], int *p_min, int *p_max);
void populate(int *v);
void print(int *v);
int main(void)
{
    srand(time(NULL));
    int v[10] = {0};
    int min = 0, max = 0;
    populate(&v[0]);
    mm(v, &min, &max);
    print(&v[0]);
    printf("\nMax:%d", max);
    printf("\nMin:%d", min);
    printf("\n");
    return 0;
}

void mm(int v[10], int *p_min, int *p_max)
{
    *p_max = v[0];
    *p_min = v[0];
    for (int i = 1; i < 10; i++)
    {

        if (v[i] > *p_max)
        {
            *p_max = v[i];
        }
        if (v[i] < *p_min)
        {
            *p_min = v[i];
        }
    }
}

void populate(int *v)
{
    for (int i = 0; i < 10; i++)
    {
        v[i] = rand() % 100;
    }
}

void print(int *v)
{
    int i = 0;
    puts("Print Vetor:");
    for (i; i < 10; i++)
    {
        printf("[%d] ", v[i]);
    }
    printf("\n");
}