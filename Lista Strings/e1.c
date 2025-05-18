/*
    Escreva um programa C que leia um texto pelo teclado (com espaços).
     Em seguida imprima o número de caracteres digitados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define BMAX 128
int main(void)
{
    setlocale(LC_ALL, "");
    char text[BMAX];
    puts("Digite um texto aleatório:");
    fflush(stdin);
    fgets(text, BMAX - 1, stdin);

    printf("O texto digitado possui %d caracteres.\n", (int)strlen(text));
    return 0;
}