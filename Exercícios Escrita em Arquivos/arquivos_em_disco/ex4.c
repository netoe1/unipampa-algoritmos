// 4 - Escreva um nome, num arquivo.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(void)
{
    setlocale(LC_ALL, "");
    char str[30];
    FILE *out = fopen("ex4.txt", "w");
    printf("\nDigite o seu nome:");
    scanf("%s\n", str);
    fprintf(out, "%s", str);
    fclose(out);
    return 0;
}