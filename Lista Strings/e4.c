
/*
4) Escreva um programa C que leia duas strings. Se as strings forem iguais escreva “strings iguais”.
 Caso contrário, concatene as duas strings e imprima a string resultante.
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(void)
{
    setlocale(LC_ALL, "");
    char str1[30];
    char str2[30];
    puts("Informe a string 1:");
    fflush(stdin);
    fgets(str1, 29, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    puts("Informe a string 2:");
    fflush(stdin);
    fgets(str2, 29, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    char cat[strlen(str1) + strlen(str2) + 1];

    if (strcmp(str1, str2) != 0)
    {
        strcpy(cat, str1);
        strcat(cat, str2);
        printf("\nCat:%s", cat);
    }
    else
    {
        puts("As duas strings são iguais.");
    }

    return 0;
}
