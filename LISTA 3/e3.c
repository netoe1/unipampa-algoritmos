/*
    3) Escreva um algoritmo que gere o números de 1000 a 1999 e
     escreva aqueles que dividido por 11 dão resto igual a 5.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "");

    for (int i = 1000; i != 1999; i++)
    {
        if ((1000 + i) % 11 == 5)
        {
            printf("\nNúmero [%d]", i);
        }
    }
    printf("\n");

    return 0;
}