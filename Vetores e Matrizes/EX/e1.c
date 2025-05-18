/*
    1) Escrever um algoritmo que lê um vetor A(10) e escreve todos as posições
com valor igual a 10 nesse vetor.
*/

#include <stdio.h>
#include <stdlib.h>

struct Pessoa
{
    int idade;
    void *mostrarPessoa;
};

void mostrarPessoa(struct Pessoa *p)
{
    printf("\nIdade da pessoa:%d\n", p->idade);
}

int main(void)
{
    struct Pessoa pessoa;

    pessoa.mostrarPessoa = (void *)mostrarPessoa;

    pessoa.mostrarPessoa(&pessoa);

    return 0;
}