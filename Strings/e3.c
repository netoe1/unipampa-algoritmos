/*
    Faça um programa em que leia quatro strings pelo teclado. Depois, concatene todas as strings
lidas em uma única variável. Imprima a variável concatenada.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(void)
{
    char buffer[128];
    char cat[30];
    int i = 0;

    while (i != 4)
    {
        printf("\n[%d]Digite quatro nomes:", i);
        setbuf(stdin, NULL);
        fgets(cat, sizeof(cat) - 1, stdin);
        cat[strcspn(cat,"\n")] = '\0';
        strcat(buffer, cat);
        strcpy(cat, " ");
        i++;
    }

    printf("\nNomes concatenados:%s", buffer);

    return 0;
}