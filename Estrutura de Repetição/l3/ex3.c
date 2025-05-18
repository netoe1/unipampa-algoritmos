/*
Receber do teclado uma mensagem e imprimir quantas letras A, E, I, O, U tem
esta mensagem. Considerar minúscula e maiúscula.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int i = 0;
int vog = 0;

int main(void)
{
    char msg[64];
    printf("\nInforme uma msg:");
    setbuf(stdin, NULL);
    fgets(msg, 63, stdin);

    for (int i = 0; i < strlen(msg); i++)
    {
        if (tolower(msg[i]) == 'a' ||
            tolower(msg[i]) == 'e' ||
            tolower(msg[i]) == 'i' ||
            tolower(msg[i]) == 'o' ||
            tolower(msg[i]) == 'u')
        {
            vog++;
        }
    }

    printf("\nMensagem:%s", msg);
    printf("\nNro de vogais:%d", vog);
    printf("\n");
    return 0;
}