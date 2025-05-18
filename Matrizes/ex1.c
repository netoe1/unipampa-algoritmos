/*
    Faça um programa que preencha uma matriz 3x2 (três linhas e duas
colunas) com números reais, calcule e mostre na tela a quantidade de
elementos cuja parte fracionária é zero
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(void)
{
    setlocale(LC_ALL, "");

    float m[3][2];
    int i = 0;
    int j = 0;
    int sum = 0;
    int k = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("\nInforme um número para a matriz[%d][%d]:", i + 1, j + 1);
            scanf("%f", &m[i][j]);
        }
        int k = m[i][j];
        if (k - m[i][j] == 0)
        {
            sum++;
        }
    }

    printf("\n A matriz tem %d elementos inteiros!", sum);
}