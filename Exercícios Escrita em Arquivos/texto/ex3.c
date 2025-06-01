/*
1. Escreva um programa que peça o nome, telefone e endereço. O
programa deve gravar o conteúdo em um arquivo texto da seguinte
maneira:
Nome: Fulano
Telefone: 53-99999999
Endereço: Sete de Setembro, 12345
2. Desenvolva um programa que leia o conteúdo do arquivo do
exercício anterior, para isso utilize o fgets().
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char nome[30];
    char telefone[30];
    char endereco[30];

    printf("\nDigite o seu nome:");
    fgets(nome, 29, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    printf("\nDigite o seu telefone:");
    scanf("%s", &telefone);
    fgets(telefone, 29, stdin);
    telefone[strcspn(telefone, "\n")] = '\0';
    printf("\nDigite o seu endereco:");
    fgets(endereco, 29, stdin);
    telefone[strcspn(endereco, "\n")] = '\0';

    FILE *output = fopen("ex3.txt", "w");

    char c = '0';
    fputs("Nome:", output);
    fputs(nome, output);
    fputc('\n', output);
    fputs("Telefone:", output);
    fputs(telefone, output);
    fputc('\n', output);
    fputs("Endereco:", output);
    fputs(endereco, output);
    fputc('\n', output);

    fclose(output);

    return 0;
}