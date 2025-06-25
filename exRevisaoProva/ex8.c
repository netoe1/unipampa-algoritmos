/*

8: Cadastro de Pessoas em Arquivo Binário
Crie um programa que permita ao usuário cadastrar pessoas em um arquivo binário chamado
pessoas.bin. Cada pessoa terá os seguintes campos:
• nome (máximo de 50 caracteres)
• idade (inteiro)
O programa deve:
1. Cadastrar uma pessoa (nome e idade).
2. Exibir a pessoa cadastrada a partir do arquivo binário
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int idade;
} Pessoa;

void sgets(char *s, size_t size)
{
    setbuf(stdin, NULL);
    fgets(s, size, stdin);
    s[strcspn(s, "\n")] = '\0';
}

void cadastrarPessoa()
{
    Pessoa nova;
    FILE *file = fopen("pessoas.bin", "ab");
    printf("\nDigite o nome da pessoa:");
    sgets(nova.nome, 49);

    printf("\nDigite a idade:");
    scanf("%d", &nova.idade);

    fwrite(&nova, sizeof(Pessoa), 1, file);
    fclose(file);
}

void mostrarPessoa()
{
    FILE *file = fopen("pessoas.bin", "rb");
    Pessoa ler;
    rewind(file);

    while (fread(&ler, sizeof(Pessoa), 1, file) == 1)
    {
        printf("\nNome:%s\nIdade:%d", ler.nome, ler.idade);
    }
    fclose(file);
}
int main(void)
{
    setlocale(LC_ALL, "");
    mostrarPessoa();
    return 0;
}