/*
    Crie uma struct Produto com os campos nome e preco.
Cadastre 3 produtos. Depois, crie uma função atualizarPreco() que receba um ponteiro para
struct e aumente o preço em 10%.
Use ponteiros para passar cada produto para a função e mostrar os preços atualizados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    char nome[10];
    float preco;
} Produto;

void sgets(char *s, size_t size)
{
    setbuf(stdin, NULL);
    fgets(s, size, stdin);
    s[strcspn(s, "\n")] = '\0';
}

void cadastrarProduto(Produto *p)
{
    printf("\nDigite o nome do produto:");
    sgets(p->nome, sizeof(p->nome) - 1);

    printf("\nDigite o preço do produto:");
    scanf("%f", &p->preco);
}

void mostrarPrecos(Produto *p)
{
    printf("\nNome:%s\nValor do produto:%.2f\n", p->nome, p->preco);
}

void atualizarProduto(Produto *p)
{
    p->preco *= 1.1;
}

int main(void)
{
    setlocale(LC_ALL, "");
    Produto produtos[3];

    for (int i = 0; i < 3; i++)
    {
        printf("\nProdutos %d:\n",i  + 1);
        cadastrarProduto(&produtos[i]);
    }

    puts("Preços antigos:");
    for (int i = 0; i < 3; i++)
    {
        mostrarPrecos(&produtos[i]);
    }
    puts("Preços Atualizados:");
    for (int i = 0; i < 3; i++)
    {
        atualizarProduto(&produtos[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        mostrarPrecos(&produtos[i]);
    }
    return 0;
}