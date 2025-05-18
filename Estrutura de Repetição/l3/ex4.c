/*
    4. Criar um algoritmo que entre com uma palavra e imprima conforme exemplo a
seguir:
Exemplo: SONHO
Como a palavra SONHO tem 5 letras a impressão ficaria assim:
SONHO
SONHO SONHO
SONHO SONHO SONHO
SONHO SONHO SONHO SONHO
SONHO SONHO SONHO SONHO SONHO
Repare que foram impressos 5 vezes na horizontal e 5 na vertical
*/

#include <stdio.h>

int main(void)
{
    const char palavra[] = {"SONHO"};
    for (int i = 0; i < strlen(palavra); i++)
    {
        for (int j = 0; j <= i; j++)
            printf("%s", palavra);
        printf("\n");
    }
    return 0;
}
