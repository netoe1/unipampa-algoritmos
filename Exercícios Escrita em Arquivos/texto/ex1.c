/*
Desenvolva um programa que recebe frases digitadas pelo usuário e
grave este conteúdo, caracter a caracter (variável = getchar()), em um
arquivo. O programa deve ser encerrado quando o usuário digitar a
tecla ENTER (\n).
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *arquivo = NULL;

    arquivo = fopen("texto.txt", "w");
    if (!arquivo)
    {
        puts("Não foi possível abrir o arquivo!");
    }

    char c = ' ';
    while ((c = getchar()) != '\n')
    {
        fputc(c, arquivo);
    }
    fclose(arquivo);

    return 0;
}