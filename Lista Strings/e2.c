/*
    2) Escreva um programa C que declare duas strings com capacidade para 20 caracteres.
    Leia a primeira string. Em seguida, copie o texto da primeira string para a segunda.
    Imprima no final o conteúdo das duas strings.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "");
    char str1[20];
    char str2[20];

    puts("Informe um conteúdo para o buffer 1:");
    fflush(stdin);
    fgets(str1, 19, stdin);

    strcpy(str2, str1);

    printf("\nConteúdo da str1:%s\nConteúdo da str2:%s", str1, str2);

    printf("\n");
    return 0;
}