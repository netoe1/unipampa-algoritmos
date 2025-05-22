/*
a) Implementar uma função recursiva para encontrar o máximo divisor comum de
dois números naturais A e B. Se o resto (a % b == 0 ), então mdc = b, senão chamar
função passando (b, a % b).
Exemplo: mdc(8, 12) = 4, mdc(1989, 72) = 9
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int mdc(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return mdc(b, a % b);
    }
}
int main(void)
{
    setlocale(LC_ALL, ".UTF-8");
    int a = 0;
    int b = 0;
    puts("Esse programa calcula o mdc entre dois números");
    printf("\nDefina a:");
    scanf("%d", &a);

    printf("\nDefina b:");
    scanf("%d", &b);

    printf("\nO máximo divisor comum é:%d", mdc(a, b));
    return 0;
}