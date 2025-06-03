/*
    1 - Ler um vetor de 10 posições inteiras. Percorrer o vetor e gravar em um arquivo em disco
os elementos que forem pares e substituir por 0, no vetor, os que forem ímpares.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void print(int *v);

int main(void)
{
    setlocale(LC_ALL, "");
    int v[10];
    FILE *file = fopen("ex1.txt", "w");
    for (int i = 0; i < 10; i++)
    {
        printf("\n[%d]Digite um número:", i);
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            v[i] = 0;
            continue;
        }

        fprintf(file, "\nNúmero do vetor[10]:[%d]\n", v[i]);
    }

    fclose(file);
    print(&v[0]);
    return 0;
}

void print(int *v)
{
    for (int i = 0; i < 10; i++)
    {
        printf("[%d]", v[i]);
    }
    printf("\n");
}