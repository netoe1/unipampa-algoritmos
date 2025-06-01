/*
2. Desenvolva um programa que leia, caracter a caracter
(variável=fgetc(arquivo)), o conteúdo de um arquivo. O programa deve
ser encerrado quando o final do arquivo (EOF) for encontrado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *arq = fopen("arquivo.txt", "r");

    if (!arq)
    {
        puts("Erro ao abrir o arquivo.");
        return 0;
    }

    char x;
    while ((x = fgetc(arq)) != EOF)
    {
        printf("%c", x);
    }
    printf("\n");
    fclose(arq);
    return 0;
}