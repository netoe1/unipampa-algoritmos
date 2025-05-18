/*
    Faça um programa que preencha um matriz 3x3 com números inteiros e
que leia um número inteiro n entre 0 e 2. Calcule e mostre na tela a soma
dos elementos da linha n e também a soma dos elementos da coluna n
– Ex. de saída: Soma linha 1 = 5
Soma coluna 1 = 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void push(int m[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int z = 0; z < 3; z++)
        {
            m[i][z] = rand() % 100;
        }
    }
}
void print(int m[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int z = 0; z < 3; z++)
        {
            printf("[%d]", m[i][z]);
        }
        printf("\n");
    }
}

int main(void)
{
    setlocale(LC_ALL, "");
    int matriz[3][3];
    int sumi = 0;
    int sumj = 0;
    int n = 0;
    push(matriz);
    print(matriz);
    printf("\nEntre um número para ler da matriz:");
    scanf("%d", &n);

    if (n > 2 || n < 0)
    {
        printf("\nNúmero inválido.");
        return -1;
    }

    for (int k = 0; k < 3; k++)
    {
        sumi += matriz[n][k];
        sumj += matriz[k][n];
    }

    printf("\nSoma linhas:%d\nSoma Colunas:%d\n", sumi, sumj);

    return 0;
}