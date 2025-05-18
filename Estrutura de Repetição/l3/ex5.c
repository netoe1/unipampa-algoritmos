/*Receber do teclado a sigla do estado de uma pessoa e imprimir uma das
seguintes mensagens:
 Carioca
 Paulista
 Mineiro
 Outros estados*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char uf[3];

void toLowerStr(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
}
int main(void)
{
    printf("\nDigite sua UF:");
    setbuf(stdin, NULL);
    fgets(uf, 2, stdin);

    toLowerStr(uf);
    if (strcmp("rs", uf) == 0)
    {
        printf("gaucho");
    }
    else if (strcmp("rj", uf) == 0)
    {
        printf("carioca");
    }
    else if (strcmp("mg", uf) == 0)
    {
        printf("mineiro");
    }
    else if (strcmp("sp", uf) == 0)
    {
        printf("sao paulo");
    }
    printf("\n");
    return 0;
}