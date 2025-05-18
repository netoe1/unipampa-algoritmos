/*
6 - Fazer um programa que receba um valor n no teclado e determine o maior. A condição de
término do programa é quando o usuário digitar zero.
*/

#include <stdio.h>

int maior = 0;
int entrada = 0;
int main(void)
{
    printf("\nPara sair, digite 0\nInforme um nro:");
    scanf("%d", &entrada);
    maior = entrada;

    do
    {
        printf("\nInforme um nro:");
        scanf("%d", &entrada);
        if (entrada > maior)
        {
            maior = entrada;
        }
    } while (entrada != 0);

    printf("\nO maior nro digitado foi:%d\n", maior);

    return 0;
}