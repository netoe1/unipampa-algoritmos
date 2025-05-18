/*
    Escrever um algoritmo que lê um vetor N(20) e o escreve. Troque, a
seguir, o 1º pelo último, 2º pelo penúltimo, e assim por diante. Escreva
então o vetor modificado
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
    int v[VMAX];
    int buffer = 0;
    populate(&v[0]);
    puts("Array sem modificação!");
    print(&v[0]);

    for (int i = 0; i < VMAX / 2; i++)
    {
        buffer = v[i];
        v[i] = v[(VMAX - 1) - i];
        v[(VMAX - 1) - i] = buffer;
    }

    puts("Array modificado!");
    print(&v[0]);

    return 0;
}