/*
    6. Informe dois nomes, imprimir o tamanho de cada um e mostrá-los.
*/

#include <stdio.h>

char nome1[64];
char nome2[64];

int main(void)
{
    printf("\nDigite o nome1:");
    setbuf(stdin, NULL);
    fgets(nome1, 63, stdin);

    printf("\nDigite o nome2:");
    setbuf(stdin, NULL);
    fgets(nome2, 63, stdin);

    int s1 = strlen(nome1);
    int s2 = strlen(nome2);

    if (s1 == s2)
    {
        printf("\nAs duas strings são iguais.");
    }
    else if (s1 < s2)
    {
        printf("\nAs duas strings são iguais.");
    }
    return 0;
}