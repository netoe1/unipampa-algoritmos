/*
    2 - Escreva um programa que leia 5 números inteiros positivos
     (utilize uma função que leia esse número e verifique se ele é positivo).
    Para cada número informado escrever a soma de seus divisores (exceto ele mesmo).
    Utilize a função SomaDivisores para obter a soma.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define VSIZE 5

void getn(int v[VSIZE])
{
    int i = 0;
    int x = 0;

    puts("Digite 5 números por favor!");
    for (i = 0; i < VSIZE; i++)
    {
        scanf("%d", &v[i]);
        if (v[i] < 0)
        {
            i--;
            puts("O número deve ser negativo.");
            continue;
        }
    }
}
int somaDivisores(int v[VSIZE])
{
    int x = 0;
    int i = 0;
    int soma = 0;
    for (i = 0; i < VSIZE; i++)
    {
        for (x = 1; x < v[i]; x++)
        {
            if (v[i] % x == 0)
            {
                printf("\n%d -> %d", v[i], x);
                soma += x;
            }
        }

        printf("\n A soma de todos os divisores de \"%d\" é de:%d", v[i], soma);
        soma = 0;
    }
}
int main(void)
{
    setlocale(LC_ALL, "");
    int n[5];
    getn(n);
    somaDivisores(n);
    return 0;
}