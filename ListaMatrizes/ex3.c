/*
    3. Faça programa que leia uma matriz 3 x 6 com valores reais.

(a) Imprima a soma de todos os elementos das colunas ímpares.
(b) Imprima a média aritmética dos elementos da segunda e quarta colunas.
(c) Substitua os valores da sexta coluna pela soma dos valores das colunas 1 e 2.
(d) Imprima a matriz modificada.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

void populate(int m[3][6])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            m[i][j] = rand() % 10;
        }
    }
}

void printm(int m[3][6])
{
    puts("Matriz:");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("[%d]", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printImpar(int m[3][6])
{
    puts("Colunas Ímpares:");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (j % 2 != 0)
            {
                printf("[%d]", m[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void mediaColunas(int m[3][6])
{
    puts("Média Colunas:");
    float m1 = 0;
    float m2 = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (j == (2 - 1))
            {
                m1 += m[i][j];
            }
            else if (j == (4 - 1))
            {
                m2 += m[i][j];
            }
        }
    }

    m1 = m1 / 3;
    m2 = m2 / 3;

    printf("\nMédia Aritmética da coluna 2:%.2f", m1);
    printf("\nMédia Aritmética da coluna 4:%.2f", m2);
    printf("\n");
}

void swap(int m[3][6])
{
    puts("Swap colunas  1 e 2");
    float sum1 = 0.0;
    float sum2 = 0.0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (j == (1 - 1))
            {
                sum1 += m[i][j];
            }
            else if (j == (2 - 1))
            {
                sum2 += m[i][j];
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        m[i][5] = sum1 + sum2;
    }

    printm(m);
}

int main(void)
{
    setlocale(LC_ALL, "");
    srand(time(NULL));

    int m[3][6];
    populate(m);
    printm(m);
    printImpar(m);
    mediaColunas(m);
    swap(m);
    return 0;
}