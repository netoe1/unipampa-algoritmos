/*
2. Faça um programa que permita ao usuário entrar com uma matriz de 3 x 3 nu ́meros inteiros. Em seguida, gere um array unidimensional pela soma dos nu ́meros de cada coluna da matriz e mostrar na tela esse array. Por exemplo, a matriz:

5   -8   10

1     2    15

25  10   7

Vai gerar um vetor, onde cada posição é a soma das colunas da matriz. A primeira posição será 5 + 1 + 25, e assim por diante:

31    4    3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void printm(int m[3][3])
{
    puts("Matriz:");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("[%d]", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printarr(int arr[3])
{
    puts("Array:");
    for (int i = 0; i < 3; i++)
    {
        printf("[%d]", arr[i]);
    }
    printf("\n");
}
int main(void)
{
    setlocale(LC_ALL, "");
    int m[3][3] = {0};
    int arr[3] = {0};
    int i = 0;
    int j = 0;

    printm(m);
    printarr(arr);
    puts("Informe valores para a matriz quadrada de ordem 3:");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("\nMatriz[%d][%d]:", i, j);
            scanf("%d", &m[i][j]);
            arr[j] += m[i][j];
        }
    }

    printm(m);
    printarr(arr);
    return 0;
}
