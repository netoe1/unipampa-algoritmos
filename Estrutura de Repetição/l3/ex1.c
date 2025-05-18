/*
Escrever seu nome na tela 10 vezes. Um nome por linha.
*/
#include <stdio.h>

int main(void)
{
    char buffer[120];
    printf("\nDigite o seu nome:");
    setbuf(stdin, NULL);
    fgets(buffer, 119, stdin);

    for (int i = 0; i < 10; i++)
    {
        printf("\n%s", buffer);
    }
    return 0;
}