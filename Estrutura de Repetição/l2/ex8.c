/*
    8- Solicitar a idade de várias pessoas e imprimir: Total de pessoas com menos de 21 anos. Total
de pessoas com mais de 50 anos. O programa termina quando idade for =-99.
*/

#include <stdio.h>

int idade = 0;
int tIdade21 = 0;
int tIdade50 = 0;
int main(void)
{
    printf("\nDigite a sua idade, digite -99 para sair!");
    scanf("%d", &idade);

    while (idade != -99)
    {
        printf("\nDigite a sua idade, digite -99 para sair!");
        scanf("%d", &idade);

        if (idade < 21)
        {
            tIdade21++;
        }
        else if (idade > 50)
        {
            tIdade50++;
        }
    }

    printf("\nIdades > 50:%d", tIdade50);
    printf("\nIdades < 21:%d\n", tIdade21);
    return 0;
}