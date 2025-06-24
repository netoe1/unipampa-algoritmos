/*
1: Verificar Palíndromo
Peça ao usuário para digitar uma palavra. Verifique se essa palavra é um palíndromo (ou seja, se
é igual quando lida de trás para frente).

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char palavra[20];
    char palavra2[20];
    fseek(stdin, 0, SEEK_SET);

    printf("\nDigite uma palavra:");
    fgets(palavra, 19, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    strcpy(palavra2, palavra);

    for (int i = 0; i < strlen(palavra) + 1; i++)
    {
        palavra2[i] = palavra[strlen(palavra) - 1 - i];
    }

    palavra2[strlen(palavra2) + 1] = '\0';

    puts(palavra);
    puts(palavra2);

    return 0;
}