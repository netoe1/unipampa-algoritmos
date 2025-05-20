/*
    Mostre na tela os N primeiros termos da
    sequência de Fibonacci
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main(void)
{
    setlocale(LC_ALL, "");
    int n;

    printf("Digite quantos termos da sequência de Fibonacci você quer ver: ");
    scanf("%d", &n);

    printf("\nSequência de Fibonacci com %d termos:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fib(i));
    }

    printf("\n");
    return 0;
}
