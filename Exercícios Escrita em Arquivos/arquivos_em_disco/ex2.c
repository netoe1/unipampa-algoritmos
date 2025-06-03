/*
    2 - Ler números inteiros e armazená-los no arquivo (numeros.txt). Ler o arquivo
numeros.txt) e armazenar no arquivo (pares.txt) os valores pares e no (impares.txt) os
ímpares.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "");
    FILE *numeros = fopen("numeros.txt", "w");
    FILE *pares = fopen("pares.txt", "w");
    FILE *impares = fopen("impares.txt", "w");
    int v[10];
    printf("\nDigite 10 números:");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &v[i]);
        fprintf(numeros, "%d\n", v[i]);
    }

    fclose(numeros);
    numeros = fopen("numeros.txt", "r");
    int num;

    while (fscanf(numeros, "%d", &num) == 1)
    {
        if (num % 2 == 0)
        {
            fprintf(pares, "%d\n", num);
        }
        else
        {
            fprintf(impares, "%d\n", num);
        }
    }

    fclose(pares);
    fclose(impares);
    fclose(numeros);

    return 0;
}