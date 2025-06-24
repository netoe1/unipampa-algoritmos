/*
    2: Contar Vogais, Consoantes e Dígitos
Solicite ao usuário uma string (frase). Conte quantas vogais, consoantes e dígitos numéricos ela
contém.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char frase0[30];

    setlocale(LC_ALL, "");
    puts("Digite uma frase:");
    fgets(frase0, sizeof(frase0) - 1, stdin);
    frase0[strcspn(frase0, "\n")] = '\0';

    int vogais = 0;
    int consoantes = 0;
    int numeros = 0;

    for (int i = 0; i <= strlen(frase0); i++)
    {
        frase0[i] = tolower(frase0[i]);
        if (frase0[i] == 'a' || frase0[i] == 'e' || frase0[i] == 'i' || frase0[i] == 'o' || frase0[i] == 'u')
            vogais++;

        else if (isalpha(frase0[i]))
        {
            consoantes++;
        }
        else if (isdigit(frase0[i]))
        {
            numeros++;
        }
    }

    printf("\nNro de vogais:%d\nNro de consoantes:%d\nNro de Números:%d\n", vogais, consoantes, numeros);
}