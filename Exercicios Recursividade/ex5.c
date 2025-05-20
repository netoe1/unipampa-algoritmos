#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define N 10
int v[N];

void populate()
{
    int i;
    for (i = 0; i < N; i++)
    {
        v[i] = rand() % 100;
        printf("[%d]", v[i]);
    }
    printf("\n");
}

int sum(int i)
{
    if (i < N)
        return v[i] + sum(v[i + 1]);
}

int main(void)
{
    srand(time(NULL));
    setlocale(LC_ALL, "");
    populate();
    int i = 0;
    for (i = 0; i < N; i++)
    {
        printf("\nN:%d", sum(i));
    }
    printf("\n");
    return 0;
}