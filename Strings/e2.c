/*Faça um programa que receba o nome e o ano de nascimento de uma pessoa. Com base no ano
atual, calcule e mostre o nome seguido da idade dessa pessoa.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define ANO 2025

char nome[30];
int ano = 0;
int main(void)
{
    setlocale(LC_ALL, "");
    printf("\nDigite o seu nome:");
    fflush(stdin);
    fgets(nome, sizeof(nome) - 1, stdin);

    printf("\nDigite o seu ano de nascimento:");
    scanf("%d", &ano);

    printf("\nSeu nome é:%s\nE você tem idade:%d\n", nome, (ANO - ano));

    return 0;
}