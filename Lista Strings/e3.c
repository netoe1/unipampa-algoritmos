/*
    3) Escreva um programa C que leia três strings
     e as imprima em ordem alfabética - a ordem em que elas apareceriam em um dicionário.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "");
    char str1[30];
    char str2[30];
    char str3[30];
    char temp[30];

    puts("Informe a string 1:");
    fflush(stdin);
    fgets(str1, 29, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    puts("Informe a string 2:");
    fflush(stdin);
    fgets(str2, 29, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    puts("Informe a string 3:");
    fflush(stdin);
    fgets(str3, 29, stdin);
    str3[strcspn(str3, "\n")] = '\0';

    if (strcmp(str1, str2) > 0)
    {
        strcpy(temp, str1);
        strcpy(str1, str2);
        strcpy(str2, temp);
    }

    if (strcmp(str1, str3) > 0)
    {
        strcpy(temp, str1);
        strcpy(str1, str3);
        strcpy(str3, temp);
    }

    if (strcmp(str2, str3) > 0)
    {
        strcpy(temp, str2);
        strcpy(str2, str3);
        strcpy(str3, temp);
    }

    printf("String1:%s,\nString2:%s\nString3:%s\n", str1, str2, str3);

    return 0;
}