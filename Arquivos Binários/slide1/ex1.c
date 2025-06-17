#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void showFile(FILE *file)
{
    fseek(file, 0, SEEK_SET);

    if (!file)
    {
        puts("Não é possível abrir o arquivo binário");
        return;
    }
    int c = 0;

    while (fread(&c, sizeof(int), 1, file) == 1)
    {
        printf("%d\n", c);
    }
}

int main(void)
{
    setlocale(LC_ALL, "");
    int n = 1;
    FILE *file = fopen("ex1.bin", "wb");
    if (!file)
    {
        puts("[ERROR]: Erro ao abrir o arquivo!");
        return 1;
    }

    while (n > 0)
    {
        puts("\nDigite um número de [1,n]\nSe quiser sair digite números menores que 0:");
        scanf("%d", &n);
        if (n <= 0)
        {
            puts("Saindo...");
            break;
        }
        fwrite(&n, sizeof(int), 1, file);
    }

    fclose(file);

    file = fopen("ex1.bin", "rb");
    if (file)
    {
        puts("Conteúdo do arquivo:");
        showFile(file);
        fclose(file);
    }
    else
    {
        puts("[ERROR]: Erro ao abrir o arquivo para leitura!");
    }

    return 0;
}
