/*
7 - Faça um programa que converta letras minúsculas em maiúsculas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "");
    char c = ' ';
    printf("\nDigite uma letra:");
    scanf("%c", &c);

    if (c >= 'A' && c <= 'Z')
    {
        c = c - 32;
    }
    else if (c >= 'a' && c <= 'z')
    {
        c = c + 32;
    }

    printf("Maiusculo:%c\n", c);
}