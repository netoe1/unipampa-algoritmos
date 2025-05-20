#include <stdio.h>
#include <stdlib.h>

int imprimir(int n)
{
    if (n - 1 == 10)
    {
        return 0;
    }
    else
    {
        printf("\nN:%d", n);
        return imprimir(n + 1);
    }
}

int main(void)
{

    imprimir(0);
    printf("\n");
    return 0;
}