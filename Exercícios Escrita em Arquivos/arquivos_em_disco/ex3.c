/*
    Escreva um programa que armazene números primos numa matriz
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define N 3
void populate();

int matriz[N][N];

int main(void)
{
    FILE *file = fopen("matriz.txt", "w");
    setlocale(LC_ALL, "");
    srand(time(NULL));
    populate();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fprintf(file, "[%d]", matriz[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);

    return 0;
}

void populate()
{
    int i = 0;
    int j = 0;
    int x = 0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            x = rand() % 100;
            if (x % 2 != 0)
            {
                matriz[i][j] = x;
            }
        }
    }
}