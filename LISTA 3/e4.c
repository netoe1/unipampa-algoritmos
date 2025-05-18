/*

    4) Escreva um algoritmo que lê um valor n inteiro
    e positivo e que calcula a seguinte soma: S := 1 + 1/2 + 1/3 + 1/4 + ... + 1/n
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "");
    int n = 0;
    float soma = 0.0;
    printf("\nDigite um valor n inteiro e positivo:");
    scanf("%d", &n);

    if (n < 0)
    {
        return 0;
    }

    for (int z = 1; z <= n; z++)
    {
        soma += 1.0 / z;
        printf("\nNumero:%.2f", (float)(1.0 / z));
        printf("\nSoma:%.2f\n", soma);
    }

    printf("\nSoma:%.2f\n", soma);

    return 0;
}