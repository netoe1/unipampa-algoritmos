/*
    Escrever um algoritmo que lê um vetor V(10) e um valor escalar. Fazer o
produto do escalar pelo vetor V e escrever o vetor modificado e o valor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define VTAM 10

void print(int *v)
{
    printf("\nArray:");
    for (int i = 0; i < VTAM; i++)
    {
        printf("[%d]", v[i]);
    }
    printf("\n");
}

void populate(int *v)
{
    for (int i = 0; i < VTAM; i++)
    {
        v[i] = rand() % 100;
    }
}
int main(void)
{
    setlocale(LC_ALL, "");
    int escalar = 0;
    int vetor[VTAM];

    printf("\nDigite o valor o escalar:");
    scanf("%d", &escalar);

    populate(&vetor[0]);
    print(&vetor[0]);

    for (int i = 0; i < VTAM; i++)
    {
        vetor[i] = vetor[i] * escalar;
    }

    print(&vetor[0]);
    return 0;
}