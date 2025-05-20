#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int imprimir10a1(int n)
{
    printf("\nValor de n:%d", n);
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return imprimir10a1(n - 1);
    }
}

int main(void)
{
    setlocale(LC_ALL, "");
    imprimir10a1(10);
    return 0;
}