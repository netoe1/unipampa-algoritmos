/*
    Escrever um algoritmo que lê um vetor K(20) e o escreve. Troque, a
seguir, os elementos de ordem ímpar com os de ordem par imediatamente
seguintes e escreva o vetor, assim modificado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#define VMAX 20
#define RAND 100

void populate(int *v)
{
    for (int i = 0; i < VMAX; i++)
    {
        v[i] = rand() % RAND;
    }
}

void print(int *v)
{
    printf("\nArray:");
    for (int i = 0; i < VMAX; i++)
    {
        printf("[%d] ", v[i]);
    }
    printf("\n");
}

int main(void)
{
    setlocale(LC_ALL, "");
    int n[VMAX];
    populate(&n[0]);
    int pImpar = 0;
    int pPar = 0;
    int swap = 0;

    puts("Vetor não modificado:");
    print(&n[0]);
    
    for (int i = 0; i < VMAX; i++)
    {
        if (n[i] % 2 == 0)
        {
            pPar = i;
        }
        else
        {
            pImpar = i;
        }
        swap = n[pPar];
        n[pPar] = n[pImpar];
        n[pImpar] = swap;
    }

    puts("Vetor modificado:");
    print(&n[0]);

    return 0;
}