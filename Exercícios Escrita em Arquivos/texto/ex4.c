#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char buffer[120];
    FILE *arq = fopen("ex3.txt", "r");
    if (!arq)
    {
        puts("Erro ao abrir o arquivo.");
    }

    while (fgets(buffer, 119, arq) != NULL)
    {
        puts(buffer);
    }
    fclose(arq);
    return 0;
}