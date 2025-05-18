#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define MMAX 10
int m[MMAX][MMAX];
int i = 0;
int j = 0;
int swap = 0;

void populate(int m[MMAX][MMAX])
{
    for (i = 0; i < MMAX; i++)
    {
        for (j = 0; j < MMAX; j++)
        {
            m[i][j] = rand() % 100;
        }
    }
}

void print(int m[MMAX][MMAX])
{
    for (i = 0; i < MMAX; i++)
    {
        for (j = 0; j < MMAX; j++)
        {
            printf("[%d]", m[i][j]);
        }
        printf("\n");
    }
}
int main(void)
{
    setlocale(LC_ALL, "");
    srand(time(NULL));
    populate(m);
    puts("Padrão:");
    print(m);

    j = 0;
    i = 0;
    puts("Linhas 2 e 8:");
    for (i = 0; i < MMAX; i++)
    {
        // linha dois e 8
        swap = m[1][i];
        m[1][i] = m[1][i];
        m[7][i] = swap;

        // linha 4 com a 8
        swap = m[3][i];
        m[3][i] = m[9][i];
        m[9][i] = swap;
    }

    print(m);

    // diagonal principal com a secundária i+j = n + 1

    puts("Diagonais");
    for (i = 0; i < MMAX; i++)
    {
        for (j = 0; j < MMAX; j++)
        {
            if (i == j)
            {
                swap = m[i][j];
                m[i][j] = m[i][MMAX - 1 - i];
                m[i][MMAX - 1 - i] = swap;
            }
        }
    }
    print(m);
    puts("Linhas 5 e 10");
    print(m);
    for (i = 0; i < MMAX; i++)
    {

        swap = m[4][i];
        m[4][i] = m[9][i];
        m[9][i] = swap;
    }
    puts("Final:");
    print(m);
}