/*
    Os números Tribonacci são definidos pela seguinte recursão
Implemente um método recursivo que receba por parâmetro um número inteiro positivo
N e mostre e retorne o N-ésimo número da sequência de Tribonacci
*/

#include <stdio.h>
#include <stdlib.h>

int tribonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else if (n > 2)
    {
        printf("[%d]->", n);
        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
}
int main(void)
{
    int n = 3;
    printf("\n%d", tribonacci(n));
    return 0;
}