/*
    7: Contar Linhas, Palavras e Caracteres de um Arquivo
Crie um programa que leia um arquivo texto chamado entrada.txt e conte:
• O número total de linhas
• O número total de palavras
• O número total de caracteres
Ao final, exiba esses três totais na tela.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

void main(void)
{
    setlocale(LC_ALL, "");
    int linhas = 0;
    int palavras = 0;
    int caracteres = 0;

    FILE *file = fopen("entradas.txt", "r");
    char ch = ' ';
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            linhas++;
        }

        else if (isspace(ch))
        {
            palavras++;
        }

        caracteres++;
    }

    printf("\nNro de caracteres:%d", caracteres);
    printf("\nNro de palavras:%d", palavras);
    printf("\nNro de linhas:%d\n", linhas);

    fclose(file);
    return;
}