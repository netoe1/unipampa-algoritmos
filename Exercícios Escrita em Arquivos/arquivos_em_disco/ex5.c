// 6 - Escreva um programa que conte os números de linhas de um arquivo.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int linha = 0;

int main(void)
{
    setlocale(LC_ALL, "");
    FILE *arq = fopen("ex5.txt", "r");
    char ch;
    while ((ch = fgetc(arq)) != EOF)
    {
        if (ch == '\n')
        {
            linha++;
        }
    }
    printf("\nO arquivo que você abriu tem %d linhas.\n", linha);
    fclose(arq);
    return 0;
}