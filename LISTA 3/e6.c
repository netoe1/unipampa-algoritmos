/*
    6) Faça um algoritmo que leia 2 valores inteiros e positivos: X e Y. O
     algoritmo deve calcular e escrever a função potência X Y.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "");
    int x = 0;
    int y = 0;
    do
    {
        printf("\nDigite um numero x inteiro e positivo:");
        scanf("%d", &x);
        printf("\nDigite um numero y inteiro e positivo:");
        scanf("%d", &y);
    } while (x < 0 || y < 0);

    int s = 1;

    for (int i = 1; i <= y; i++)
    {
        s *= x;
    }

    printf("\nexp(%d,%d):%d\n", x, y, s);
}